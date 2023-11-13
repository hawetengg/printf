#include "main.h"

int _printf(const char *format, ...)
{
	int char_p = 0;
	va_list list_arg;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(list_arg, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			char_p++;
		}
		else
		{
			format++;
		if (*format == '\0')
		{
			break;
		}
		if (*format == '%')
		{
			write(1, format, 1);
			char_p++;
		}
		else if (*format == 'c')
		{
			char cc = va_arg(list_arg, int);

			write(1, &cc, 1);
			char_p++;
		}
		else if (*format == 's')
		{
			char *str = va_arg(list_arg, *char);
			int strLen = 0;

			while (str[strLen] != '\0')
				strLen++;
			write(1, str, strLen);
			char_p += strLen;
		}
		}
		format++;
	}
	va_end(list_arg);
	return (char_p);
}
