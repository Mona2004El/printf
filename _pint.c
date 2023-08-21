#include "main.h"
/**
*_putInt - function that print an int
*@num: the integer is print
*@params:pointer to the counter
*
*Return: void
*/
void _putInt(unsigned int num, int *params)
{
	/* if its negative num */
	if ((int)num < 0)
	{
		_putchar('-');
		*params += 1;
		num *= -1;
	}
	/* check if the num not one digit */
	if (num / 10)
		_putInt(num / 10, params); /* call the fun again if not one digit */
	/* print the num in ascii by adding 48  */
	_putchar(num % 10 + '0');
	*params += 1;
}
