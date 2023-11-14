#include "main.h"

/**
 * _printf - A custom print f function
 * @format: stirng
 * Return: length of the string
 */
void binary(unsigned int numm)
{
	char binaryy[32];
	int i = 0;

	while (numm > 0)
	{
		binaryy[i++] = (numm % 2) + '0';
		numm /= 2;
	}
	for (i = i - 1; i >= 0; i--)
	{
		write(1, &binaryy[i], 1);
	}
}

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, num, len, strlen = 0;
	char cc, buffer[20], *str;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					cc = va_arg(args, int);
					count += write(1, &cc, 1);
					break;
				case 's':
					str = va_arg(args, char*);
					while (str[strlen] != '\0')
						strlen++;
					write(1, str, strlen);
					break;
				case 'd':
				case 'i':
					{
						num = va_arg(args, int);
						len = snprintf(buffer, sizeof(buffer), "%d", num);
						count += write(1, buffer, len);
					}
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
	va_end(args);
	return (count);
}
