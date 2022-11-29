#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
    {
		write (1, &str[i], 1);
        i++;
    }
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
        {
            return (s1[i] - s2[i]);
        }
        i++;
	}
	return (0);
}

void	ft_strswap(char **str1, char **str2)
{
	char	*tmp;

	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}

void    ft_sort_args(char **strarr, int len)
{
    int i;

    i = 1;
    while (i < len - 1)
    {
        if (ft_strcmp(strarr[i], strarr[i + 1]) > 0)
        {
            ft_strswap(&strarr[i], &strarr[i + 1]);
            i = -1;
        }    
        i++;    
    }
}

int	main(int argc, char **argv)
{
    int i;

    ft_sort_args(argv, argc);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
		i++;
	}
	return (0);
}