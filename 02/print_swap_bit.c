#include <unistd.h>
void print_bits(unsigned char octet)
{
	char *bit;
	int i = 8;

	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}


unsigned char swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}
