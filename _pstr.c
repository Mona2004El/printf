include "main.h"
#include <unistd.h>


/**
*_puts - print string
*@s: pointer to the string
*@len: length of the string
*Return: -1 if error, 1 otherwise
*/
int _puts(char *s, int len)
{
	return (write(1, s, len));
}
