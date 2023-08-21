#include "main.h"
/**
*print_str - fun that print string
*@pa: points to the list of arguments
*@params: pointer to counter
*Return: 1 if no error , -1 otherwise
*/
int print_str(va_list pa, int *params)
{
	char *str;

	str = va_arg(pa, char *);
	if (str == NULL)
	{
		str = "(null)";
	}

	if (_puts(str, _strlen(str)) != -1)
		*params += _strlen(str);
	else
		return (-1);

	return (1);
}

/**
*print_ch - fun that print char
*@pa: points to the list of arguments
*@params: pointer to counter
*Return: 1 in sucess , -1 otherwise
*/
int print_ch(va_list pa, int *params)
{
	if (_putchar((unsigned char)va_arg(pa, int)) != -1)
		*params += 1;
	else
		return (-1);

	return (1);
}

