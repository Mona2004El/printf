#include "main.h"

/**
 * print_hex - Prints hexadecimal.
 * @num: num we want to covert
 * @params: Pointer to counter
 * Return:0
 */
int print_hex(unsigned long int num, int *params)
{
	char buffer[32];
	int i;

	i = 0;
	if (num == 0)
	{
		_putchar('0');
		(*params)++;
		return (1);
	}

	while (num > 0)
	{
		buffer[i] = (num % 16) + (num % 16 > 9 ? 'a' - 10 : '0');
		num /= 16;
		i++;
	}
	i--;
	while (i >= 0)
	{
		_putchar(buffer[i]);
		i--;
		(*params)++;
	}
	return (0);
}

/**
 * print_addr - function that print the address
 * @pa: Points to the list of arguments
 * @params: Pointer to counter
 * Return: 1 to nothing, 0 otherwise
 */
int print_addr(va_list pa, int *params)
{
	void *addr;
	char *str = "(nil)";
	unsigned long int num;

	addr = va_arg(pa, void *);

	if (addr == NULL)
	{
		_puts(str, _strlen(str));
		*params += _strlen(str);
		return (1);
	}


	_putchar('0');
	_putchar('x');
	*params += 2;

	num = (unsigned long int)addr;
		   print_hex(num, params);


return (0);
}

