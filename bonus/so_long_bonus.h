/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:36:24 by mafaisal          #+#    #+#             */
/*   Updated: 2024/02/19 19:46:51 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_mlx
{
	int		x;
	int		y;
	void	*mlxptr;
	void	*mlxwin;
	void	*p_image;
	void	*pr_image;
	void	*pl_image;
	void	*c_image;
	void	*w_image;
	void	*f_image;
	void	*ce_image;
	void	*oe_image;
	void	*enemy;
	void	*enemy1;
	void	*enemy2;
}	t_mlx;

typedef struct s_solong
{
	char	**map_array;
	int		collectibles;
	int		exit;
	int		players;
	int		iposition;
	int		jposition;
	int		moves;
	size_t	width;
	size_t	height;
	t_mlx	mlx;
}	t_solong;

void	parse_map(t_solong *map, char *map_file);
void	exit_failure(t_solong *map, char *str);
void	isvalid(t_solong *map);
int		valid_path(t_solong *map, char **temp, int i, int j);
void	free_array(char **map_array);
void	open_window(t_solong *map);
int		action(int keycode, t_solong *map);
int		exit_success(t_solong *map, char *str);
void	render_map(t_solong *map, char *str);
char	*get_moves_str(t_solong *map);
void	init_images(t_solong *map);
void	init_players(t_solong *map);
void	ft_wait(int i);
#endif
