#include "main.h"
/**
*call_sp - get the function and call it and check
*                for signs.
*@format: the str format
*@i: pointer to the index of our format
*@p: pointer to out struct
*@params: pointer to our counter
*@pa:pointer to our arguments
*/
void call_sp(const char *format, int *i, struct sp_char *p,
int *params, va_list pa)
{
	int j, k = 3;
	va_list ap;
	int index = *i;
	int flagg = 0;
	sign flag[] = {{'+', postive_sign}, {' ', space_sign}, {'#', window_sign},
		{'\0', NULL}};

	va_copy(ap, pa);
	while (signIndex(format[index], flag) != -1)
	{
		for (k = 0; flag[k].ch != '\0'; k++)/* if there are flags */
		{
			if (format[index] == flag[k].ch)
			{
				if (format[index] == '+' && flagg < 2)
					flagg = 1;
				else if (format[index] == '#')
					flagg = 2;
				index++;
				break;
			}
		}
	}
	j = spIndex(format[index], p);/* index of flagg */
	if (j != -1)
	{
		if (flag[k].ch != '\0')
			flag[k].fun(flagg, flag[k].ch, j, ap, params);/* print flag */
		p[j].fun(pa, params); /*print the argument  */
		*i = index;
	}
	else
	{
		_putchar('%');
		(*i)--;
		*params += 1;
		return;
	}
}


/**
*_printf - function that do same as printf
*@format: the string format
*Return: num of charchter printed
*/
int _printf(const char *format, ...)
{
	va_list pa; /* points to the arguments list */
	int i, sum = 0;
	int *params = &sum;
	spChar type[] = {
		{'s', print_str}, {'c', print_ch}, {'d', print_int},
		{'i', print_int}, {'b', print_bi}, {'r', print_rev},
		{'u', print_unsigned}, {'o', print_octal}, {'S', print_nonch},
		{'x', print_lowerhex}, {'X', print_upperhex}, {'R', print_rot13},
		{'p', print_addr}, {'\0', NULL}};

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(pa, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]); /* print the char */
			*params += 1;
		}
		else if (format[i] == '%' && format[i + 1] != '%')
		{
			i++;/* get the char after the % */
			call_sp(format, &i, type, params, pa);

		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			i++;
			_putchar(format[i]);
			*params += 1;
		}
	}
	va_end(pa);
	return (sum);
}

