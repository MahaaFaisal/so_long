/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:01:14 by mafaisal          #+#    #+#             */
/*   Updated: 2024/02/16 17:36:50 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	char		*map_file;
	t_solong	map;

	if (argc != 2)
		exit_failure(NULL, "Arguments should be: <program_name> <file_name>");
	map_file = argv[1];
	parse_map(&map, map_file);
	open_window(&map);
}
