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
	config->floor_color = -1;
	config->ceiling_color_r = -1;
	config->ceiling_color_g = -1;
	config->ceiling_color_b = -1;
	config->ceiling_color = -1;
	config->map = NULL;
	config->map_width = 0;
	config->map_height = 0;
}

void free_config(t_config *config)
{
	if (config->no_texture)
		free(config->no_texture);
	if (config->so_texture)
		free(config->so_texture);
	if (config->we_texture)
		free(config->we_texture);
	if (config->ea_texture)
		free(config->ea_texture);
	if (config->map)
	{
		for (int i = 0; i < config->map_height; i++)
			free(config->map[i]);
		free(config->map);
	}
	free(config);
}

int create_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
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
	{
		free_config(config);
		return (1);
	}
	// printf("NO Texture: %s\n", config->no_texture);
	// printf("SO Texture: %s\n", config->so_texture);
	// printf("WE Texture: %s\n", config->we_texture);
	// printf("EA Texture: %s\n", config->ea_texture);
	// printf("Floor Color: %d, %d, %d\n", config->floor_color_r, config->floor_color_g, config->floor_color_b);
	// printf("Ceiling Color: %d, %d, %d\n", config->ceiling_color_r, config->ceiling_color_g, config->ceiling_color_b);
	// int i = 0;
	// int j;
	// while (i < config->map_height)
	// {
	// 	j = 0;
	// 	while (config->map[i][j])
	// 	{
	// 		printf("%c", config->map[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
	// printf("Floor Color (RGB): %d\n", config->floor_color);
	// printf("Ceiling Color (RGB): %d\n", config->ceiling_color);
	if (once_player(config->map) != 0 || check_walls_top_bottom(config->map, config->map_height) != 0 ||
		check_walls_left_right(config->map, config->map_height) != 0 ||
		check_invalid_spaces(config->map, config->map_height) != 0 ||
		check_valid_characters(config->map, config->map_height) != 0)
	{
		free_config(config);
		return (1);
	}
	free_config(config);
	return (0);
}
