/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnafiai <bnafiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 19:46:59 by bnafiai           #+#    #+#             */
/*   Updated: 2025/07/12 19:46:59 by bnafiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

// int check_map()

int once_player(char **map)
{
	int i;
	int j;
	int count_player;

	i = 0;
	count_player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' ||
				map[i][j] == 'E' || map[i][j] == 'W')
			{
				count_player++;
				if (count_player > 1)
				{
					write(2, "Multiple players found in map\n", 31);
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int check_walls_top_bottom(char **map, int map_height, int map_width)
{
	int i;
	int j;

	j = 0;
	while (map[0][j] == ' ')
		j++;
	while (map[0][j])
	{
		if (map[0][j] != '1')
		{
			printf("map is not surrounded by walls\n");
			return (0);
		}
		j++;
	}
	j = 0;
	while (map[map_height - 1][j] == ' ')
		j++;
	while (map[map_height - 1][j])
	{
		if (map[map_height - 1][j] != '1')
		{
			printf("map is not surrounded by walls\n");
			return (0);
		}
		j++;
	}
}

// int check_walls_right_left(char **map, int map_height, int map_width)
// {
// 	int i;
// 	int j;

// 	i = 1;
// 	while (map[i][j])
// 	{
// 		if (map[i][j] == ' ')
// 			j++;
// 		if (map[i][j] )
// 	}
// }
