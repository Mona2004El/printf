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

