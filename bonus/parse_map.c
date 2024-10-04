/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:39:27 by mafaisal          #+#    #+#             */
/*   Updated: 2024/02/19 19:46:44 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	arrdup(t_solong *map, char **dest)
{
	int	i;

	i = 0;
	while (map->map_array[i])
	{
		dest[i] = ft_strdup(map->map_array[i]);
		if (!dest[i])
		{
			free_array(dest);
			exit_failure(map, "Memory Error happened\n");
		}
		i++;
	}
	dest[i] = NULL;
}

void	file_to_array(t_solong *map, char *map_file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		exit_failure(NULL, "Could not open file\n");
	map->map_array = malloc((map->height + 1) * sizeof(char *));
	if (!map->map_array)
		exit_failure(NULL, "Memory Error happened\n");
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		map->map_array[i] = line;
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	map->map_array[i] = NULL;
	if (ft_strlen(map->map_array[0]) > 64)
	{
		free_array(map->map_array);
		exit_failure(NULL, "Map width should be less than 65 rows\n");
	}
}

int	count_lines(char *map_file)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		exit_failure(NULL, "Could not open file\n");
	count = 0;
	line = get_next_line(fd);
	if (!line)
		exit_failure(NULL, "No lines read\n");
	while (line)
	{
		free(line);
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	if (count > 34)
		exit_failure(NULL, "Map height should be less than 35 rows\n");
	return (count);
}

void	init_solong(t_solong *map, char *map_file)
{
	map->height = count_lines(map_file);
	file_to_array(map, map_file);
	map->width = ft_strlen(map->map_array[0]);
	map->collectibles = 0;
	map->exit = 0;
	map->players = 0;
	map->iposition = -1;
	map->jposition = -1;
	map->moves = 0;
	map->mlx.mlxptr = NULL;
	map->mlx.mlxwin = NULL;
	map->mlx.pr_image = NULL;
	map->mlx.pl_image = NULL;
	map->mlx.c_image = NULL;
	map->mlx.w_image = NULL;
	map->mlx.f_image = NULL;
	map->mlx.ce_image = NULL;
	map->mlx.oe_image = NULL;
	map->mlx.enemy1 = NULL;
	map->mlx.enemy2 = NULL;
}

void	parse_map(t_solong *map, char *map_file)
{
	char	**temp;
	int		collectibles;
	int		exit;

	if (ft_strncmp (map_file + (ft_strlen(map_file) - 4), ".ber", 5))
		exit_failure(NULL, "invalid file, not .ber\n");
	init_solong(map, map_file);
	isvalid(map);
	temp = malloc((map->height + 1) * sizeof(char *));
	if (!temp)
		exit_failure(map, "Memory error happened\n");
	arrdup(map, temp);
	collectibles = map->collectibles;
	exit = map->exit;
	if (!valid_path(map, temp, map->iposition, map->jposition))
	{
		free_array(temp);
		exit_failure(map, "No valid path found.\n");
	}
	free_array(temp);
	map->collectibles = collectibles;
	map->exit = exit;
}
