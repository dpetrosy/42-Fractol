/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:06:01 by dapetros          #+#    #+#             */
/*   Updated: 2024/01/24 22:07:06 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_num_size(long num)
{
	size_t	size;

	size = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		++size;
		num /= 10;
	}
	return (size);
}

static void	ft_strrev(char *str, size_t index, size_t i)
{
	size_t	start;
	size_t	end;	
	char	temp;

	end = i - 1;
	start = index;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		++start;
		--end;
	}
}

static void	get_str(char *str, size_t index, long num)
{
	size_t	i;

	i = index;
	if (num == 0)
	{
		str[0] = '0';
		++i;
	}
	else
	{
		while (num != 0)
		{
			str[i] = (num % 10) + '0';
			num /= 10;
			++i;
		}
	}
	str[i] = '\0';
	ft_strrev(str, index, i);
}

char	*ft_itoa(int n)
{
	size_t	num_size;
	size_t	start_index;
	int		sign;
	long	num;
	char	*str;

	num = n;
	sign = 1;
	start_index = 0;
	num_size = get_num_size(num);
	if (num < 0)
	{
		sign = -1;
		start_index = 1;
		++num_size;
		num = -num;
	}
	str = (char *)malloc(num_size + 1);
	if (!str)
		return (NULL);
	if (sign == -1)
		str[0] = '-';
	get_str(str, start_index, num);
	return (str);
}
