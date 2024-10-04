/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:51:16 by mafaisal          #+#    #+#             */
/*   Updated: 2023/11/16 17:40:51 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	numdigits(int n)
{
	unsigned int	digits;

	digits = 0;
	if (n < 0)
		n = -n;
	while (n >= 1)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

void	pos_itoa(char *str, int n, int i)
{
	*(str + i) = '\0';
	i--;
	while (i >= 0)
	{
		*(str + i) = (n % 10) + 48;
		n = n / 10;
		i--;
	}
}

void	neg_itoa(char *str, int n, int i)
{
	*(str) = '-';
	*(str + i + 1) = '\0';
	n = -n;
	while (i > 0)
	{
		*(str + i) = (n % 10) + 48;
		n = n / 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = numdigits(n);
	if (n > 0)
	{
		str = malloc((numdigits(n) + 1) * sizeof(char));
		if (!str)
			return (NULL);
		pos_itoa(str, n, i);
	}
	else if (n < 0)
	{
		str = malloc((numdigits(n) + 2) * sizeof(char));
		if (!str)
			return (NULL);
		neg_itoa(str, n, i);
	}
	else
		return (ft_strdup("0"));
	return (str);
}
