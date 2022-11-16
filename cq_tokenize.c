#include "main.h"
/**
 * cq_tokenize - creates an array of tokens from user input
 * @line: pointer to user string
 * Return: pointer to array created
 */
char **cq_tokenize(char *line)
{
	int i = 0;
	int cap = 0;
	char **tokens;
	char *delim = " \n";
	char *token;

	cap = _splitstring(line);
	if (!cap)
		return (NULL);

	tokens = malloc((cap + 1) * sizeof(char *));
	if (tokens == NULL)
		exit(1);

	token = strtok(line, delim);
	while (token != NULL)
	{
		tokens[i] = _strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
/**
 * _PATHsplt - counts number of path members
 * @s: pointer to string to be counted
 * Return: number counted
 */
int _PATHsplt(char *s)
{
	int i;
	int flag = 1;
	int count = 0;

	for (i = 0; s[i]; i++)
	{
		if (s[i] != ':' && flag == 1)
		{
			count += 1;
			flag = 0;
		}
		if (s[i + 1] == ':')
			flag = 1;
	}
	return (count);
}
/**
 * strcmpPATH - compares PATH with environ to find PATH value
 * @s: pointer to PATH string
 * @s1: pointer to environ string
 * Return: 0 on success
 */
int strcmpPATH(const char *s, const char *s1)
{
	int i;

	for (i = 0; s1[i] != '='; i++)
	{
		if (s[i] != s1[i])
			return (-1);
	}
	return (0);
}
/**
 * _concat - concats user string with PATH member string and /
 * @tmp: static array to store concatenated string
 * @argv: pointer to array of user strings
 * @token: pointer to PATH token
 * Return: 0 on success
 */
char *_concat(char *tmp, char **argv, char *token)
{
	int l = 0;

	_memset(tmp, 0, 256);
	l = _strlen(token) + _strlen(argv[0]) + 2;
	_strcat(tmp, token);
	_strcat(tmp, "/");
	_strcat(tmp, argv[0]);
	tmp[l - 1] = '\0';
	return (tmp);
}
