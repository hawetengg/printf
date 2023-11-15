#include "main.h"

/**
 * _printf - A custom print f function
 * @format: stirng
 * Return: length of the string
 */
void binary(unsigned int numm)
{
	char bits[32];
	int i = 0;
	char digit;

	if (numm == 0)
	{
		write(1, "0", 1);
		return;
	}

	while (numm > 0)
	{
		bits[i++] = (numm % 2) + '0';
		numm /= 2;
	}
	for (--i; i >= 0; i--)
	{
		write(1, &bits[i], 1);
	}
}

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int count = 0;
	char buffer[20];

	while (*format)
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
					count += write(1, va_arg(args, char *))
						break;
				case 'd': 
				case 'i':
					{
						count += write(1, buffer, snprintf(buffer, sizeof(buffer), "%d", va_arg(args, int)));
						break;
					}
				case 'b': 
					  print_binary(va_arg(args, unsigned int)); count += 32; 
					  break;
				case '%':
					count += write(1, "%", 1);
					break;
				default:count += write(1, "%", 1) + write(1, format, 1); 
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
