#include "main.h"

/**
*print_upperhex - prints hexadecimal numbers in uppercase
*@pa: points to the list of arguments
*@params: pointer to counter
*Return: count of characters printed
*/
int print_upperhex(va_list pa, int *params)
{
unsigned int num = va_arg(pa, unsigned int);
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

