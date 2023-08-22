#ifndef _PRINTF_H_
#define _PRINTF_H_
#include <stdarg.h>
#include <stdlib.h>

#include <unistd.h>
#include <stdio.h>

/**
* struct sp_char - sturct for the special character
*@ch: symbole of the speacial character
*@fun: pointer to fun to print the argurment
*/
typedef struct sp_char
{
	char ch;
	int (*fun)(va_list, int *);
} spChar;
#define FLAGS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
/**
 *struct params-t - parameters struct
 *@unsign: unsign flag
 *@zero: 0
 *@space: space
 *@window: # sign
 *@plus: + sign
 *@minus: - sign
 *@width: width
 *@precision: % sign
 *@h_modifier: short
 *@l_modifier: long
 */
typedef struct params_t
{
        unsigned int unsign : 1;
        unsigned int zero : 1;
        unsigned int window : 1;
        unsigned int space : 1;
         unsigned int plus : 1;
        unsigned int minus : 1;
        unsigned int width;
        unsigned int precision;
        unsigned int h_modifier : 1;
        unsigned int l_modifier : 1;
} params;

/**
*struct signs - sturct for the special character
*@ch: symbole of the signs
*@fun: pointer to fun to print sign
*/
typedef struct signs
{
	char ch;
	void (*fun)(int, char, int, va_list, int *);
} sign;

int _printf(const char *format, ...);

int _putchar(char c);

int _strlen(char *s);

int spIndex(char ch, struct sp_char *p);

int _puts(char *str, int len);

void _putInt(unsigned int num, int *params);


int print_str(va_list pa, int *params);

int print_ch(va_list pa, int *params);

int print_int(va_list pa, int *params);

int print_bi(va_list pa, int *params);


int print_unsigned(va_list pa, int *params);

int print_octal(va_list pa, int *params);

int print_lowerhex(va_list pa, int *params);

int print_upperhex(va_list pa, int *params);


int print_rev(va_list pa, int *params);

int print_nonch(va_list pa, int *params);

int print_rot13(va_list pa, int *params);

int print_addr(va_list pa, int *params);

int signIndex(char ch, struct signs *p);

void postive_sign(int flag, char ch, int j, va_list ap, int *params);

void space_sign(int flag, char ch, int j, va_list ap, int *params);

void window_sign(int flag, char ch, int j, va_list ap, int *params);


#endif

