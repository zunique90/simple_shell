#include "main.h"
/**
 * main - runs the simple shell
 * Return: 0 on success
 */
int main(void)
{
	char *fullpathbuffer = NULL, *copy = NULL, *buffer = NULL;
	char **tokens;
	ssize_t count = 0;
	char *PATH = NULL;
	int exitstatus = 0;

	signal(SIGINT, SIG_IGN);
	PATH = _getenv("PATH");
	if (PATH == NULL)
		return (-1);

	while (1)
	{
		tokens = NULL;
		if (isatty(STDIN_FILENO) == 1)
		{
			count = write(STDOUT_FILENO, "$ ", 2);
			if (count == -1)
				exit(0);
		}
		buffer = cq_read();
		if (*buffer != '\0')
		{
			tokens = cq_tokenize(buffer);
			if (tokens == NULL)
			{
				free(buffer);
				continue;
			}
			fullpathbuffer = _fullpathbuffer(tokens, PATH, copy);
			if (checkbuiltins(tokens, buffer, exitstatus) == 1)
				continue;
			exitstatus = cq_exec(tokens, buffer, fullpathbuffer);
		}
		else
			free(buffer);
	}
	return (0);
}
