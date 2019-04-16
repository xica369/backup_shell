#include "shell.h"

char *_strtok(char *str, char *separator)
{
	char *tok = NULL;
	int i, j, n = 0, len = 0;
	static int cont = 0;


	for (i = cont; str[i]; i++)
	{
		for (j = 0; separator[j]; j++)
		{
			if (str[i] == separator[j])
				n = 1;
		}
		if (n == 1)
			break;
		len++;
	}
	if (len != 0)
		tok = malloc(sizeof(char) * len);
	if (tok == NULL)
	{
		return(NULL);
	}
	for (i = cont, n = 0; str[i]; i++)
	{
		cont++;
		for (j = 0; separator[j]; j++)
		{
			if (str[i] == ':' && str[i + 1] == ':'
			    && separator[j] == ':')
			{
				tok[0] = ':';
				return (tok);
			}
			if (str[i] == separator[j])
			{
				return (tok);
			}
		}
		tok[n] = str[i];
		n++;
	}
	return (tok);
}
