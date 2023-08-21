#include "main.h"

/**
*print_bi - print binary num
*@pa: points to the list of arguments
*@params: pointer to counter
*
*Return: 0
*/
int print_bi(va_list pa, __attribute__((unused))int *params)
{
	unsigned int num = va_arg(pa, unsigned int);
	char buffer[50];
	int i;

	i = 0;
	if (num == 0)
	{
		_putchar('0');
		(*params)++;
		return (1);
	}
	/* devide on base 2 */
	for (i = 0; num > 0; i++)
	{
		buffer[i] = (num % 2) + '0';
		num /= 2;
	}

	i--;
	/* print it in backword */
	for (; i >= 0; i--)
	{
		_putchar(buffer[i]);
		(*params)++;
	}
	return (0);
}

