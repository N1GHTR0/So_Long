#include "so_long.h"

int	find_digit(int x)
{
	int	dig;

	dig = 0;
	if (x < 0)
	{
		x = -x;
		dig++;
	}
	while (x > 0)
	{
		x = x / 10;
		dig++;
	}
	return (dig);
}

char    *ft_itoa(int x)
{
        char    *str;
        int     i;

        if (x == -2147483648)
                return ("-2147483648");
        i = find_digit(x);
        if ((!(str = malloc(sizeof(char) * (i + 1)))))
                return (NULL);
        if (x < 0)
        {
                str[0] = '-';
                x = -x;
        }
        str[i] = '\0';
        i--;
        while (x > 0)
        {
                str[i] = x % 10 + 48;
                x = x / 10;
                i--;
        }
        return (str);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
