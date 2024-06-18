#include <stdio.h>
#include <stdlib.h>

char *ft_itoa(int nbr)
{
	int nb;
	int count;
	
	nb = nbr;
	if (nb == -2147483648)
		return("-2147483648\0");
	
	count = 0;
	if(nb <= 0)
	{
		count++;
	}
	while(nb)
	{
		nb /= 10;
		count++;
	}

	char *result = (char *) malloc(sizeof(char) * (count + 1));
	if (result == NULL)
		return (NULL);
	result[count] = '\0';
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
	{
		result[0] = '0';
		return (result);
	}
	count--;
	while(nbr)
	{
		result[count] = nbr % 10 + 48;
		nbr /= 10;
		count--;
	}
	return (result);

}
#include <stdio.h>
#include <stdlib.h>

char *ft_itoa(int nbr);

int main()
{
    printf("%s\n", ft_itoa(0));
    printf("%s\n", ft_itoa(123));
    printf("%s\n", ft_itoa(-123));
    printf("%s\n", ft_itoa(2147483647));
    printf("%s\n", ft_itoa(-2147483648));

    return 0;
}