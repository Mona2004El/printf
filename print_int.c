#include "main.h"

/**
*print_int - fun that print int
*@pa: points to the list of arguments
*@params: pointer to counter
*Return: 0
*/
int print_int(va_list pa, int *params)
{
	unsigned int  num = va_arg(pa, int);

	_putInt(num, params);

	return (0);
}
