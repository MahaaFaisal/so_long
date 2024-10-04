/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:18:11 by mafaisal          #+#    #+#             */
/*   Updated: 2024/02/19 14:22:35 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*get_moves_str(t_solong *map)
{
	char	*moves;
	char	*moves_str;

	moves = ft_itoa(map->moves);
	if (!moves)
		exit_failure(map, "Memory error happened\n");
	moves_str = ft_strjoin("Move: ", moves);
	free(moves);
	if (!moves_str)
		exit_failure(map, "Memory Error Happened\n");
	return (moves_str);
}

void	ft_wait(int i)
{
	int	j;

	j = 0;
	while (j < i)
		j++;
}
