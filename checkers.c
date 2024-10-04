/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:37:28 by mafaisal          #+#    #+#             */
/*   Updated: 2024/02/16 16:15:17 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_chars(t_solong *map, char c)
{
	if (!ft_strchr("01PCE", c))
		exit_failure(map, "Map contains invalid charcters\n");
	if (c == 'P')
	{
		if (map->players == 0)
			map->players++;
		else
			exit_failure(map, "Only one player allowed\n");
	}
	if (c == 'E')
	{
		if (map->exit == 0)
			map->exit++;
		else
			exit_failure(map, "Only one exit allowed\n");
	}
	if (c == 'C')
		map->collectibles++;
}

void	check_walls(t_solong *map, size_t i, size_t j)
{
	if (((i == 0 || !(map->map_array[i + 1]))
			&& map->map_array[i][j] != '1')
		|| ((j == 0 || j == ft_strlen(map->map_array[i]) - 1)
			&& map->map_array[i][j] != '1'))
		exit_failure(map, "Map is not surrounded by walls\n");
}

void	check_shape( t_solong *map, int i)
{
	if (map->width != ft_strlen(map->map_array[i]))
		exit_failure(map, "Map is not rectangular\n");
}

int	valid_path(t_solong *map, char **temp, int i, int j)
{
	if ((i >= 0 && i < (int)map->height)
		&& (j >= 0 && j < (int)map->width))
	{
		if (temp[i][j] == 'E')
		{
			map->exit--;
			temp[i][j] = '1';
		}
		if (temp[i][j] != '1')
		{
			if (temp[i][j] == 'C')
				map->collectibles--;
			temp[i][j] = '1';
			valid_path(map, temp, i, j + 1);
			valid_path(map, temp, i, j - 1);
			valid_path(map, temp, i + 1, j);
			valid_path(map, temp, i - 1, j);
		}
	}
	if (map->collectibles == 0 && map->exit == 0)
		return (1);
	return (0);
}

void	isvalid(t_solong *map)
{
	int		i;
	int		j;

	i = -1;
	while (map->map_array[++i])
	{
		j = -1;
		check_shape(map, i);
		while (map->map_array[i][++j])
		{
			check_chars(map, map->map_array[i][j]);
			if (map->map_array[i][j] == 'P')
			{
				map->iposition = i;
				map->jposition = j;
			}
			check_walls(map, i, j);
		}
	}
	if (!map->collectibles)
		exit_failure(map, "There should be at least one collectible\n");
	if (!map->exit)
		exit_failure(map, "There should be exactly one exit\n");
	if (!map->players)
		exit_failure(map, "There should be exactly one player\n");
}
