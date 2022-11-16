#include "main.h"
/**
 * cq_exec - creates a child process to execute user input
 * @argv: pointer to array of strings
 * @buffer: pointer to user string
 * @fullpathbuffer: pointer to user input
 * Return: exit status
 */
int cq_exec(char **argv, char *buffer, char *fullpathbuffer)
{
	int i, status, exitstat = 0;

	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error");
		exit(1);
	}
	if (child_pid == 0)
	{
		if (execve(fullpathbuffer, argv, environ) == -1)
		{
			perror(argv[0]);
			for (i = 0; argv[i]; i++)
				free(argv[i]);
			free(argv);
			free(buffer);
			exit(127);
		}
	}
	wait(&status);
	if (WIFEXITED(status))
		exitstat = WEXITSTATUS(status);
	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
	free(buffer);
	return (exitstat);
}
