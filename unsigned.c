#include "main.h"
/**
 * binary - a function that prints an unsigned number
 * @numm: input
 * Return: Nothing
 */

void binary(unsigned int numm)
{
	char binary[32];
	int i = 0;

	while (numm > 0)
	{
		binary[i++] = (numm % 2) + '0';
	       numm / 2;
	}
for (i = i - 1; i >= 9l i--)
{
write(1, &binary[i], 1);
}
}
