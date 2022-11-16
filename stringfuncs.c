#include "main.h"
/**
 * _strlen - returns the length of a string
 * @s: string to be counted
 * Return: string length
 */
int _strlen(char *s)
{
	int l = 0;

	while (s[l] != '\0')
		l++;

	return (l);
}
/**
 * _strcat - concatenates string in *src to the string in *dest
 * @dest: the destination string
 * @src: the source string
 * Return: a pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int l1 = 0;
	int l2 = 0;
	int i;

	i = 0;
	while (dest[i] != '\0')
	{
		l1++;
		i++;
	}
	i = 0;
	while (src[i] != '\0')
	{
		l2++;
		i++;
	}

	for (i = 0; i <= l2; i++)
	{
		dest[l1 + i] = src[i];
	}
	return (dest);
}
/**
 * _strcmp - Compares two strings
 * @s1: first string
 * @s2: second string
 * Return: an integer
 */
int _strcmp(char *s1, char *s2)
{
	int flag, i;

	flag = 0;
	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] - s2[i] != 0)
		{
			flag = s1[i] - s2[i];
			break;
		}
	}
	if (flag == 0 && s1[i] == '\0')
		flag = s1[i] - s2[i];

	return (flag);
}
/**
 * _strdup - duplicates a string
 * @s: pointer to string to duplicate
 * Return: pointer to duplicated string
 */
char *_strdup(char *s)
{
	int i;
	char *dest;

	if (s == NULL)
		return (NULL);
	for (i = 0; s[i] != '\0'; i++)
		;
	dest = malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	for (i = 0; s[i] != '\0'; i++)
		dest[i] = s[i];
	dest[i] = '\0';
	return (dest);
}
/**
 * _splitstring - counts the words in a string
 * @s: pointer to string to be counted
 * Return: number of words in the string
 */
int _splitstring(char *s)
{
	int i;
	int flag = 1;
	int count = 0;

	for (i = 0; s[i]; i++)
	{
		if (s[i] != ' ' && flag == 1)
		{
			count += 1;
			flag = 0;
		}
		if (s[i + 1] == ' ')
			flag = 1;
	}
	return (count);
}
