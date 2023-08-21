#include "main.h"

/**
*put_hex_upper - fun that print hex num
*@num: num we want to print
*@params: counter
*Return: 1 if no num , 0 otherwise
*/
int put_hex_upper(int num, int *params)
{
	char buffer[32];
	int i;
	int sum = 0;
	char hex_digits[] = "0123456789ABCDEF";

	i = 0;
	if (num == 0)
	{
		_putchar('0');
		(*params)++;
		return (1);
	}

	while (num > 0)
	{
		buffer[i] = hex_digits[num % 16];
		num /= 16;
		i++;
	}
	i--;
	while (i >= 0)
	{
		_putchar(buffer[i]);
		i--;
		(*params)++;
		sum++;
	}
	return (0);
}

/**
*print_nonch -fun that print none char in hex upper
*@pa: points to the list of arguments
*@params: pointer to counter
*Return: success(0)
*/
int print_nonch(va_list pa, int *params)
{
	char *str = va_arg(pa, char *);
	int i;

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			*params += 2;
			if (str[i] < 16)
			{
				_putchar('0');
				*params += 1;
			}
			put_hex_upper(str[i], params);
		}
		else
		{
			_putchar(str[i]);
			*params += 1;
		}
	}
	return (0);
}

