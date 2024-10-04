/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:00:43 by mafaisal          #+#    #+#             */
/*   Updated: 2024/02/19 19:17:20 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}

void	render_map(t_solong *map)
{
	size_t	i;
	size_t	j;

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
}

void	init_images(t_solong *map)
{
	map->mlx.c_image = mlx_xpm_file_to_image(map->mlx.mlxptr,
			"textures/collectible.xpm", &(map->mlx.x), &(map->mlx.y));
	if (!map->mlx.c_image)
		exit_failure(map, "Could not open collectible image\n");
	map->mlx.w_image = mlx_xpm_file_to_image(map->mlx.mlxptr,
			"textures/bluewall.xpm", &(map->mlx.x), &(map->mlx.y));
	if (!map->mlx.w_image)
		exit_failure(map, "Could not open wall image\n");
	map->mlx.ce_image = mlx_xpm_file_to_image(map->mlx.mlxptr,
			"textures/closedoor.xpm", &(map->mlx.x), &(map->mlx.y));
	map->mlx.oe_image = mlx_xpm_file_to_image(map->mlx.mlxptr,
			"textures/opendoor.xpm", &(map->mlx.x), &(map->mlx.y));
	if (!map->mlx.ce_image || !map->mlx.oe_image)
		exit_failure(map, "Could not open one of the door images\n");
	map->mlx.f_image = mlx_xpm_file_to_image(map->mlx.mlxptr,
			"textures/floor.xpm", &(map->mlx.x), &(map->mlx.y));
	if (!map->mlx.f_image)
		exit_failure(map, "Could not open floor image\n");
	map->mlx.pr_image = mlx_xpm_file_to_image(map->mlx.mlxptr,
			"textures/player_r.xpm", &(map->mlx.x), &(map->mlx.y));
	map->mlx.pl_image = mlx_xpm_file_to_image(map->mlx.mlxptr,
			"textures/player_l.xpm", &(map->mlx.x), &(map->mlx.y));
	if (!map->mlx.pr_image || !map->mlx.pl_image)
		exit_failure(map, "Could not open one of player images\n");
	map->mlx.p_image = map->mlx.pr_image;
}

void	open_window(t_solong *map)
{
	map->mlx.mlxptr = mlx_init();
	if (!map->mlx.mlxptr)
		exit_failure(map, "MLX Error\n");
	map->mlx.mlxwin = mlx_new_window(map->mlx.mlxptr,
			map->width * 40, map->height * 40, "so_long");
	if (!map->mlx.mlxwin)
		exit_failure(map, "MLX Error\n");
	init_images(map);
	mlx_hook(map->mlx.mlxwin, 2, 0, action, map);
	mlx_hook(map->mlx.mlxwin, 17, 0, exit_success, map);
	render_map(map);
	mlx_loop(map->mlx.mlxptr);
}
