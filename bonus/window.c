/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:00:43 by mafaisal          #+#    #+#             */
/*   Updated: 2024/02/19 19:46:44 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_image(t_solong *map, void *img, int i, int j)
{
	mlx_put_image_to_window(map->mlx.mlxptr,
		map->mlx.mlxwin, img, j * map->mlx.x, i * map->mlx.y);
}

void	render_image(t_solong *map, int i, int j)
{
	put_image(map, map->mlx.f_image, i, j);
	if (map->map_array[i][j] == 'C')
		put_image(map, map->mlx.c_image, i, j);
	else if (map->map_array[i][j] == 'P')
		put_image(map, map->mlx.p_image, i, j);
	else if (map->map_array[i][j] == 'E')
	{
		if (map->collectibles == 0)
			put_image(map, map->mlx.oe_image, i, j);
		else
			put_image(map, map->mlx.ce_image, i, j);
	}
	else if (map->map_array[i][j] == '1')
		put_image(map, map->mlx.w_image, i, j);
	else if (map->map_array[i][j] == '*')
		put_image(map, map->mlx.enemy, i, j);
}

void	render_map(t_solong *map, char *str)
{
	size_t	i;
	size_t	j;

	if (!str)
		exit_failure(map, "Memory Error\n");
	mlx_clear_window(map->mlx.mlxptr, map->mlx.mlxwin);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			render_image(map, i, j);
			j++;
		}
		i++;
	}
	mlx_string_put(map->mlx.mlxptr, map->mlx.mlxwin,
		42, 22, 0xfffffff, str);
	free(str);
}

int	render_animation(t_solong *map)
{
	static int	i;

	if (i < 10)
	{
		map->mlx.enemy = map->mlx.enemy2;
		render_map(map, get_moves_str(map));
		i++;
	}
	else if (i < 20)
		i++;
	else if (i < 30)
	{
		map->mlx.enemy = map->mlx.enemy1;
		render_map(map, get_moves_str(map));
		i++;
	}
	else if (i < 40)
		i++;
	if (i == 40)
		i = 0;
	return (0);
}

void	open_window(t_solong *map)
{
	map->mlx.mlxptr = mlx_init();
	if (!map->mlx.mlxptr)
		exit_failure(map, "MLX Error");
	map->mlx.mlxwin = mlx_new_window(map->mlx.mlxptr,
			map->width * 40, map->height * 40, "so_long");
	if (!map->mlx.mlxwin)
		exit_failure(map, "MLX Error");
	init_images(map);
	mlx_loop_hook(map->mlx.mlxptr, render_animation, map);
	mlx_hook(map->mlx.mlxwin, 2, 0, action, map);
	mlx_hook(map->mlx.mlxwin, 17, 0, exit_success, map);
	render_map(map, get_moves_str(map));
	mlx_loop(map->mlx.mlxptr);
}
