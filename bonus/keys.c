/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 09:43:46 by mafaisal          #+#    #+#             */
/*   Updated: 2024/02/19 19:46:44 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_player(t_solong *map, int i, int j)
{
	if ((i >= 0 && i < (int)map->height) && (j >= 0 && j < (int)map->width))
	{
		if ((map->moves + 1) < 0)
			exit_failure(map, "You exceeded the limit of moves, try again\n");
		if (map->map_array[i][j] == '*')
			exit_success(map, "You lost for your enemy.\n");
		else if (map->map_array[i][j] != '1' && map->map_array[i][j] != 'E')
		{
			if (map->map_array[i][j] == 'C')
				map->collectibles--;
			map->map_array[i][j] = 'P';
			map->map_array[map->iposition][map->jposition] = '0';
			map->iposition = i;
			map->jposition = j;
			map->moves++;
			render_map(map, get_moves_str(map));
		}
		if (map->map_array[i][j] == 'E' && map->collectibles == 0)
			exit_success(map, ft_strdup("You won!!!.\n"));
	}
}

int	action(int keycode, t_solong *map)
{
	if (keycode == 53)
		exit_success(map, ft_strdup("See you next time.\n"));
	else if (keycode == 0 || keycode == 123)
	{
		map->mlx.p_image = map->mlx.pl_image;
		render_map(map, get_moves_str(map));
		move_player(map, map->iposition, (map->jposition) - 1);
	}
	else if (keycode == 1 || keycode == 125)
		move_player(map, (map->iposition) + 1, map->jposition);
	else if (keycode == 2 || keycode == 124)
	{
		map->mlx.p_image = map->mlx.pr_image;
		render_map(map, get_moves_str(map));
		move_player(map, map->iposition, map->jposition + 1);
	}
	else if (keycode == 13 || keycode == 126)
		move_player(map, map->iposition - 1, map->jposition);
	return (0);
}
