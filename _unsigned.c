#include "main.h"

/**
*print_unsigned - prints unsigned numbers
*@pa: points to the list of arguments
*@params: pointer to counter
*Return: 0
*/
int print_unsigned(va_list pa, int *params)
{
unsigned int num = va_arg(pa, unsigned int);
char buffer[32];
int i, sum = 0;

i = 0;
if (num == 0)
{
_putchar('0');
sum++;
}
else
{
while (num > 0)
{
buffer[i] = (num % 10) + '0';
num /= 10;
i++;
}
i--;
while (i >= 0)
{
_putchar(buffer[i]);
i--;
sum++;
}
}
*params += sum;
return (0);
}
