#include "main.h"
/**
*print_rot13 - fun that print str under rot13
**@pa: points to the list of arguments
*@params: pointer to counter
*Return: always 0
*/
int print_rot13(va_list pa, int *params)
{
	char *str = va_arg(pa, char *);
	int i, j;
	char a[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
		'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
		'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
		'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
		'W', 'X', 'Y', 'Z'};
	char b[] = {'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',	'z',
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'N',
	'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A',
	'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'};

	if (str == NULL)
	{
		str = "(null)";
		_puts(str, _strlen(str));
		*params += _strlen(str);
		return (-1);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; (a[j] != '\0' && str[i] != a[j]);)
		{
			j++;
		}

		if (str[i] == a[j])
		{
			_putchar(b[j]);
			*params += 1;
		}
		else
		{
			_putchar(str[i]);
			*params += 1;
		}
	}
	return (0);
}

