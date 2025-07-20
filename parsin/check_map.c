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
					write(2, "Error: Multiple players found in map\n", 37);
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int check_walls_top_bottom(char **map, int map_height)
{
	int j;
	int len;

	len = ft_strlen(map[0]);
	while (len > 0 && (map[0][len - 1] == '\r' || map[0][len - 1] == '\n'))
		len--;
	j = 0;
	while (j < len && map[0][j] == ' ')
		j++;
	while (j < len)
	{
		if (map[0][j] != '1')
		{
			printf("Error: map is not surrounded by walls\n");
			return (1);
		}
		j++;
	}

	len = ft_strlen(map[map_height - 1]);
	while (len > 0 && (map[map_height - 1][len - 1] == '\r' || map[map_height - 1][len - 1] == '\n'))
		len--;
	j = 0;
	while (j < len && map[map_height - 1][j] == ' ')
		j++;
	while (j < len)
	{
		if (map[map_height - 1][j] == ' ')
			j++;
		else if (map[map_height - 1][j] != '1')
		{
			printf("Error: map is not surrounded by walls\n");
			return (1);
		}
		j++;
	}
	return (0);
}

int check_walls_left_right(char **map, int map_height)
{
	int i;
	int j;
	int len;

	i = 0;
	while (i < map_height)
	{
		if (!map[i])
		{
			printf("Error: Invalid map row\n");
			return (1);
		}
		len = ft_strlen(map[i]);

		while (len > 0 && (map[i][len - 1] == '\r' || map[i][len - 1] == '\n'))
			len--;
		j = 0;
		while (j < len && map[i][j] == ' ')
			j++;
		if (j >= len || map[i][j] != '1')
		{
			printf("Error :map is not surrounded by walls\n");
			return (1);
		}
		j = len - 1;
		while (j >= 0 && map[i][j] == ' ')
			j--;
		if (j < 0 || map[i][j] != '1')
		{
			printf("Error: map is not surrounded by walls\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int check_invalid_spaces(char **map, int map_height)
{
	int i;
	int j;
	int len;
	i = 1;

	while (i < map_height)
	{
		j = 1;
		len = ft_strlen(map[i]);
		while (j < len - 1)
		{
			if (map[i][j] == '0' || map[i][j] == 'N' ||
				map[i][j] == 'S' || map[i][j] == 'E' || 
				map[i][j] == 'W')
			{
				if ((i - 1 >= 0 && map[i - 1][j] == ' ') ||
					(i + 1 < map_height && map[i + 1][j] == ' ') ||
					(j - 1 >= 0 && map[i][j - 1] == ' ') ||
					(j + 1 < len && map[i][j + 1] == ' '))
				{
					printf("Error: Invalid space in the map\n");
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int check_valid_characters(char **map, int map_height)
{
	int i;
	int j;

	i = 0;
	while (i < map_height)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\r' || map[i][j] == '\n')
			{
				j++;
				continue;
			}
			if (map[i][j] != '0' && map[i][j] != '1' &&
				map[i][j] != 'N' && map[i][j] != 'S' &&
				map[i][j] != 'E' && map[i][j] != 'W' &&
				map[i][j] != ' ')
			{
				write(2, "Error: Invalid character in map\n", 26);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
