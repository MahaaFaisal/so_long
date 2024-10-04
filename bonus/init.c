/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:42:50 by mafaisal          #+#    #+#             */
/*   Updated: 2024/02/19 19:46:44 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_players(t_solong *map)
{
	map->mlx.pr_image = mlx_xpm_file_to_image(map->mlx.mlxptr,
			"textures/player_r.xpm", &(map->mlx.x), &(map->mlx.y));
	map->mlx.pl_image = mlx_xpm_file_to_image(map->mlx.mlxptr,
			"textures/player_l.xpm", &(map->mlx.x), &(map->mlx.y));
	if (!map->mlx.pr_image || !map->mlx.pl_image)
		exit_failure(map, "Could not open one of player images\n");
	map->mlx.p_image = map->mlx.pr_image;
}

void	init_images(t_solong *map)
{
	map->mlx.c_image = mlx_xpm_file_to_image(map->mlx.mlxptr,
			"textures/collectible.xpm", &(map->mlx.x), &(map->mlx.y));
	if (!map->mlx.c_image)
		exit_failure(map, "Could not open collectible image\n");
	map->mlx.w_image = mlx_xpm_file_to_image(map->mlx.mlxptr,
			"textures/bluewall.xpm", &(map->mlx.x), &(map->mlx.y));
	map->mlx.f_image = mlx_xpm_file_to_image(map->mlx.mlxptr,
			"textures/floor.xpm", &(map->mlx.x), &(map->mlx.y));
	if (!map->mlx.f_image || !map->mlx.w_image)
		exit_failure(map, "Could not open floor or wall image\n");
	map->mlx.ce_image = mlx_xpm_file_to_image(map->mlx.mlxptr,
			"textures/closedoor.xpm", &(map->mlx.x), &(map->mlx.y));
	map->mlx.oe_image = mlx_xpm_file_to_image(map->mlx.mlxptr,
			"textures/opendoor.xpm", &(map->mlx.x), &(map->mlx.y));
	if (!map->mlx.ce_image || !map->mlx.oe_image)
		exit_failure(map, "Could not open one of the door images\n");
	map->mlx.enemy1 = mlx_xpm_file_to_image(map->mlx.mlxptr,
			"textures/enemy1.xpm", &(map->mlx.x), &(map->mlx.y));
	map->mlx.enemy2 = mlx_xpm_file_to_image(map->mlx.mlxptr,
			"textures/enemy2.xpm", &(map->mlx.x), &(map->mlx.y));
	if (!map->mlx.enemy1 || !map->mlx.enemy2)
		exit_failure(map, "Could not open one of the enemy images\n");
	map->mlx.enemy = map->mlx.enemy1;
	init_players(map);
}
