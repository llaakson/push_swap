#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int				sign;
	long long int	result;
	long long int	prev;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '-' || *str == '+' )
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		prev = result * 10 + *str++ - 48;
		if (prev / 10 != result && sign == -1)
			return (0);
		if (prev / 10 != result && sign == 1)
			return (-1);
		result = prev;
	}
	return (result * sign);
}

static int	array_counter(char const *s, char c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (*str == c)
		str++;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			i++;
		while (*str != c && *str)
			str++;
	}
	return (i);
}

static void	free_arr(char **arr, int i)
{
	while (0 < i)
	{
		i--;
		free(*(arr + i));
	}
	free(arr);
}

static char	**loop(char **arr, char const *s, char c)
{
	int	i;
	int	size;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			size = ft_strchr(s, c) - s;
			if (ft_strchr(s, c) == NULL)
				size = ft_strlen(s);
			arr[i] = ft_substr(s, 0, size);
			if (!*(arr + i))
			{
				free_arr(arr, i);
				return (NULL);
			}
			i++;
			s += size;
		}
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		j;

	if (!s)
		return (NULL);
	j = array_counter(s, c);
	arr = (char **)malloc(sizeof(char *) * (j + 1));
	if (arr == NULL)
		return (NULL);
	arr = loop(arr, s, c);
	return (arr);
}
