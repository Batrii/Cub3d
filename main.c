/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnafiai <bnafiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:05:27 by bnafiai           #+#    #+#             */
/*   Updated: 2025/07/12 16:05:27 by bnafiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void initialize_config(t_config *config)
{
	config->no_texture = NULL;
	config->so_texture = NULL;
	config->we_texture = NULL;
	config->ea_texture = NULL;
	config->floor_color_r = -1;
	config->floor_color_g = -1;
	config->floor_color_b = -1;
	config->ceiling_color_r = -1;
	config->ceiling_color_g = -1;
	config->ceiling_color_b = -1;
	config->map = NULL;
	config->map_width = 0;
	config->map_height = 0;
}

int main(int argc, char **argv)
{
	t_config *config;

	if (argc != 2)
	{
		write(2, "Incorrect number of arguments\n", 30);
		return (1);
	}
	if (check_extension(argv[1]) == 0)
	{
		write(2, "Invalid file extension. Expected .cub\n", 39);
		return (1);
	}
	config = malloc(sizeof(t_config));
	if (!config)
	{
		write(2, "Memory allocation failed for config\n", 36);
		return (1);
	}
	initialize_config(config);
	if (create_map(argv[1], config))
		return (1);
	// printf("NO Texture: %s\n", config->no_texture);
	// printf("SO Texture: %s\n", config->so_texture);
	// printf("WE Texture: %s\n", config->we_texture);
	// printf("EA Texture: %s\n", config->ea_texture);
	// printf("Floor Color: %d, %d, %d\n", config->floor_color_r, config->floor_color_g, config->floor_color_b);
	// printf("Ceiling Color: %d, %d, %d\n", config->ceiling_color_r, config->ceiling_color_g, config->ceiling_color_b);
	// int i = 0;
	// int j;
	// while (config->map && config->map[i])
	// {
	// 	printf("line is %s\n", config->map[i]);
	// 	j = 0;
	// 	while (config->map[i][j])
	// 	{
	// 		printf("line character: [%c] [%d]\n", config->map[i][j], config->map[i][j]);
	// 		j++;
	// 	}
	// 	i++;
	// }
	if (once_player(config->map) != 0 || check_walls_top_bottom(config->map, config->map_height) != 0 ||
		check_walls_left_right(config->map, config->map_height) != 0 ||
		check_invalid_spaces(config->map, config->map_height) != 0 ||
		check_valid_characters(config->map, config->map_height) != 0)
	{
		free(config);
		return (1);
	}
	return (0);
}