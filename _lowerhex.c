#include "main.h"

/**
 * print_lowerhex - Prints hexadecimal in lowercase
 * an unsigned int
 * @pa: Points to the list of arguments
 * @params: Pointer to counter
 * Return: Number of characters printed
 */
int print_lowerhex(va_list pa, int *params)
{
unsigned int num = va_arg(pa, unsigned int);
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

