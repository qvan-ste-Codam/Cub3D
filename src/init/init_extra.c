/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_extra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoossen <tgoossen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:30:31 by tgoossen          #+#    #+#             */
/*   Updated: 2025/02/10 16:44:22 by tgoossen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
#include <stdlib.h>
#define OFFSET 0.5

t_player	*init_player(int player_x, int player_y)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
	{
		return (NULL);
	}
	player->pos_x = player_x + OFFSET;
	player->pos_y = player_y + OFFSET;
	return (player);
}
