/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 07:40:45 by ybouchra          #+#    #+#             */
/*   Updated: 2023/12/31 13:56:28 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	increment(char *line, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == c)
			count++;
		i++;
	}
	if (count == 1)
		return (1);
	else
		return (2);
}

int	is_exist(char *str, int c)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	nbr_item(char *s, char c)
{
	int	i;
	int	cp;

	cp = 0;
	i = -1;
	if (!s)
		return (0);
	while (s[++i])
	{
		if (s[i] == c)
			cp++;
	}
	return (cp);
}

int	is_digit(char *arr)
{
	int	i;

	i = 0;
	if (!arr || !arr[0])
		return (0);
	if (arr[0] == '+')
		i++;
	while (arr[i])
	{
		if (!(arr[i] >= '0' && arr[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
