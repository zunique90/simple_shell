#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>

extern char **environ;

char **cq_tokenize(char *line);
char *cq_read(void);
int cq_exec(char **argv, char *buffer, char *fullpathbuffer);
int _strlen(char *s);
char *_getenv(const char *name);
int _env(void);
void _puts(char *str);
int _putchar(char c);
char *_memset(char *s, char b, unsigned int n);
char *_fullpathbuffer(char **av, char *PATH, char *copy);
int checkbuiltins(char **av, char *buffer, int exitstatus);
int _PATHsplt(char *s);
int strcmpPATH(const char *s, const char *s1);
char *_concat(char *tmp, char **argv, char *token);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *s);
int _splitstring(char *s);

#endif /* MAIN_H */
