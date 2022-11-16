#include "main.h"
/**
 * cq_read - reads input from stdin and stores it in a buffer
 * Return: a pointer to the buffer
 */
char *cq_read(void)
{
	char *buffer = NULL;
	size_t len = 0;
	ssize_t count = 0;
	int i;

	count = getline(&buffer, &len, stdin);
	if (count == -1)
	{
		free(buffer);
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
	if (buffer[count - 1] == '\n' || buffer[count - 1] == '\t')
		buffer[count - 1] = '\0';

	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] == '#' && buffer[i - 1] == ' ')
		{
			buffer[i] = '\0';
			break;
		}
	}
	return (buffer);
}
/**
 * _fullpathbuffer - finds the string to call execve on
 * @av: pointer to array of user of strings
 * @PATH: pointer to PATH string
 * @copy: pointer to copy of PATH string
 * Return: a pointer to string to call execve on
 */
char *_fullpathbuffer(char **av, char *PATH, char *copy)
{
	char *tok, *fullpathbuffer = NULL, *concatstr = NULL;
	static char tmp[256];
	int PATHcount = 0, fullpathflag = 0, z = 0, toklen = 0;
	struct stat h;

	copy = NULL;
	copy = _strdup(PATH);
	PATHcount = _PATHsplt(copy);
	tok = strtok(copy, ": =");
	while (tok != NULL)
	{
		concatstr = _concat(tmp, av, tok);
		if (stat(concatstr, &h) == 0)
		{
			fullpathbuffer = concatstr;
			fullpathflag = 1;
			break;
		}
		if (z < PATHcount - 2)
		{
			toklen = _strlen(tok);
			if (tok[toklen + 1] == ':')
			{
				if (stat(av[0], &h) == 0)
				{
					fullpathbuffer = av[0];
					fullpathflag = 1;
					break;
				}
			}
		}
		z++;
		tok = strtok(NULL, ":");
	}
	if (fullpathflag == 0)
		fullpathbuffer = av[0];
	free(copy);
	return (fullpathbuffer);
}
/**
 * checkbuiltins - check if first user string is a built-in
 * @av: pointer to array of user of strings
 * @buffer: pointer to user string
 * @exitstatus: exit status of execve
 * Return: 1 if user string is equal to env or 0 otherwise
 */
int checkbuiltins(char **av, char *buffer, int exitstatus)
{
	int i;

	if (_strcmp(av[0], "env") == 0)
	{
		_env();
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
		free(buffer);
		return (1);
	}
	else if (_strcmp(av[0], "exit") == 0)
	{
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
		free(buffer);
		exit(exitstatus);
	}
	else
		return (0);
}
