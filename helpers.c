#include "main.h"
/**
 * _getenv - gets PATH member from the environ
 * @name: pointer to PATH
 * Return: NULL if not found, else pointer to PATH member
 */
char *_getenv(const char *name)
{
	int i, res;

	for (i = 0; environ[i]; i++)
	{
		res = strcmpPATH(name, environ[i]);
		if (res == 0)
		{
			return (environ[i]);
		}
	}
	return (NULL);
}
/**
 * _env - prints the environ
 * Return: (0) always success
 */
int _env(void)
{
	int i = 0;

	for (; environ[i]; i++)
		_puts(environ[i]);
	return (0);
}
/**
 * _puts - prints a string followed by a new line
 * @str: string we are to print
 */
void _puts(char *str)
{
	while (*str)
		_putchar(*str++);
	_putchar('\n');
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _memset - fills the first 'n' bytes of memory area
 * pointed to be 's' with a constant byte 'b'
 * @n: n bytes we want to fill
 * @s: pointer to memory area to be filled
 * @b: constant to fill the memory area with
 * Return: s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;


	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}
