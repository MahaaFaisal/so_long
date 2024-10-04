/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:47:05 by mafaisal          #+#    #+#             */
/*   Updated: 2024/02/19 19:46:44 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_players(t_solong *map)
{
	if (map->mlx.pr_image)
		mlx_destroy_image(map->mlx.mlxptr, map->mlx.pr_image);
	if (map->mlx.pl_image)
		mlx_destroy_image(map->mlx.mlxptr, map->mlx.pl_image);
}

void	destroy_enemies(t_solong *map)
{
	if (map->mlx.enemy1)
		mlx_destroy_image(map->mlx.mlxptr, map->mlx.enemy1);
	if (map->mlx.enemy2)
		mlx_destroy_image(map->mlx.mlxptr, map->mlx.enemy2);
}

void	free_array(char **map_array)
{
	int	i;

	i = 0;
	while (map_array[i])
	{
		free(map_array[i]);
		i++;
	}
	free(map_array);
}

int	exit_success(t_solong *map, char *str)
{
	ft_printf("%s", str);
	free_array(map->map_array);
	destroy_players(map);
	destroy_enemies(map);
	mlx_destroy_image(map->mlx.mlxptr, map->mlx.c_image);
	mlx_destroy_image(map->mlx.mlxptr, map->mlx.oe_image);
	mlx_destroy_image(map->mlx.mlxptr, map->mlx.ce_image);
	mlx_destroy_image(map->mlx.mlxptr, map->mlx.f_image);
	mlx_destroy_image(map->mlx.mlxptr, map->mlx.w_image);
	mlx_destroy_window(map->mlx.mlxptr, map->mlx.mlxwin);
	free(map->mlx.mlxptr);
	exit (0);
}

void	exit_failure(t_solong *map, char *str)
{
	if (map)
	{
		free_array(map->map_array);
		destroy_players(map);
		destroy_enemies(map);
		if (map->mlx.c_image)
			mlx_destroy_image(map->mlx.mlxptr, map->mlx.c_image);
		if (map->mlx.ce_image)
			mlx_destroy_image(map->mlx.mlxptr, map->mlx.ce_image);
		if (map->mlx.oe_image)
			mlx_destroy_image(map->mlx.mlxptr, map->mlx.oe_image);
		if (map->mlx.f_image)
			mlx_destroy_image(map->mlx.mlxptr, map->mlx.f_image);
		if (map->mlx.w_image)
			mlx_destroy_image(map->mlx.mlxptr, map->mlx.w_image);
		if (map->mlx.mlxwin)
			mlx_destroy_window(map->mlx.mlxptr, map->mlx.mlxwin);
		if (map->mlx.mlxptr)
			free(map->mlx.mlxptr);
	}
	ft_putstr_fd ("Error\n", 2);
	ft_putstr_fd (str, 2);
	exit (1);
}
