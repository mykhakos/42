#include "../include/philo.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static int	is_num(char c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

static int	is_sign(char c)
{
	if ((c == '+') || (c == '-'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while (is_space(*str))
		str++;
	if (is_sign(*str))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (is_num(*str))
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}

long get_current_time_ms(t_philo **philo)
{
    struct timeval tv;
    int ret;

    ret = gettimeofday(&tv, NULL);
    if (ret != 0)
    {
        if (philo != NULL && *philo != NULL)
        {
            philo_free(philo);
        }
        perror("gettimeofday");
        exit(EXIT_FAILURE);
    }
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}


int mutex_safeinit(pthread_mutex_t *mutex, void **free_on_error)
{
    if (pthread_mutex_init(mutex, NULL) != 0)
    {
		if (free_on_error != NULL && *free_on_error != NULL)
		{
			free(*free_on_error);
			*free_on_error = NULL;
		}
        return (1);
    }
    return (0);
}
