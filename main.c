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

void append_map(char ***map, char *line, int *map_height)
{
	char **new_map;
	int i;

	new_map = malloc(sizeof(char *) * (*map_height + 2));
	if (!new_map)
	{
		write(2, "Memory allocation failed for map\n", 33);
		exit(1);
	}
	i = 0;
	while (i < *map_height)
	{
		new_map[i] = (*map)[i];
		i++;
	}
	new_map[i] = my_strdup(line);
	new_map[i + 1] = NULL;
	free(*map);
	*map = new_map;
	(*map_height)++;
}

int create_map(char *filename, t_config *config)
{
	int fd;
	char *line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error opening file\n", 19);
		return 1;
	}
	int in_map_section = 0;
	line = get_next_line(fd);
	while (line)
	{
		// printf("Line: %s\n", line);
		if (is_line_empty(line) && !in_map_section)
		{
			free(line);
			line = get_next_line(fd);
			continue;
		}
		else if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E')
		{
			if (assign_texture(config, line) != 0)
			{
				free(line);
				close(fd);
				return (1);
			}
		}
		else if (line[0] == 'F' || line[0] == 'C')
		{
			if (assign_colors(config, line) != 0)
			{
				free(line);
				close(fd);
				return (1);
			}
		}
		else if (all_six_config(config)  && (line[0] == '1' || line[0] == ' '))
		{
			in_map_section = 1;
			append_map(&(config->map), line, &(config->map_height));
			if (ft_strlen(line) > config->map_width)
				config->map_width = ft_strlen(line);
		}
		else
		{
			write(2, "Invalid line in configuration\n", 30);
			free(line);
			close(fd);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

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