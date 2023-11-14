#include "main.h"

/**
 * _printf - A custom print f function
 * @format: stirng
 * Return: length of the string
 */

int _printf(const char *format, ...)
{
	va_list list_arg;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(list_arg, format);
	int count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += write(1, &va_arg(args, int), 1);
					break;
				case 's':
					count += write(1, va_arg(args, char *), 5);
					break;
				case '%':
					count += write(1, "%", 1);
					break;
				default:
					count += write(1, "%", 1);
					count += write(1, format, 1);
					break;
			}
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}
	va_end(list_arg);
	return (count);
}
