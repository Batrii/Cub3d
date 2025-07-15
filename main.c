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


int assign_texture(t_config *config, char *line)
{
	int i;
	if (line[0] == 'N' && line[1] == 'O')
	{
		i = 2;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		char **split_no_texture = ft_split(line + i, ' ');
		if (!split_no_texture || !split_no_texture[0])
		{
			write(2, "Invalid NO texture format\n", 26);
			return (1);
		}
		if (split_no_texture[1] == NULL)
		{
			config->no_texture = my_strdup(split_no_texture[0]);
		}
		else
		{
			write(2, "Invalid NO texture format\n", 26);
			return (1);
		}
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		i = 2;
		while (line[i] == ' ')
			i++;	
		char **split_so_texture = ft_split(line + i, ' ');
		if (!split_so_texture || !split_so_texture[0])
		{
			write(2, "Invalid SO texture format\n", 26);
			return (1);
		}
		if (split_so_texture[1] == NULL)
		{
			config->so_texture = my_strdup(split_so_texture[0]);
		}
		else
		{
			write(2, "Invalid SO texture format\n", 26);
			return (1);
		}
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		i = 2;
		while (line[i] == ' ')
			i++;
		char **split_we_texture = ft_split(line + i, ' ');
		if (!split_we_texture || !split_we_texture[0])
		{
			write(2, "Invalid WE texture format\n", 26);
			return (1);
		}
		if (split_we_texture[1] == NULL)
		{
			config->we_texture = my_strdup(split_we_texture[0]);
		}
		else
		{
			write(2, "Invalid WE texture format\n", 26);
			return (1);
		}
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		i = 2;
		while (line[i] == ' ')
			i++;
		char **split_ea_texture = ft_split(line + i, ' ');
		if (!split_ea_texture || !split_ea_texture[0])
		{
			write(2, "Invalid EA texture format\n", 26);
			return (1);
		}
		if (split_ea_texture[1] == NULL)
		{
			config->ea_texture = my_strdup(split_ea_texture[0]);
		}
		else
		{
			write(2, "Invalid EA texture format\n", 26);
			return (1);
		}
	}
	else
	{
		write(2, "Invalid texture line\n", 21);
		return (1);
	}
	return (0);
}
int assign_colors(t_config *config, char *line)
{
	if (line[0] == 'F')
	{
		char **split_colors;

		split_colors = ft_split(line + 2, ',');
		if (!split_colors || !split_colors[0] || !split_colors[1] || !split_colors[2])
		{
			write(2, "Invalid floor color format\n", 27);
			return (1);
		}
		if (check_valid_colors(split_colors) != 0)
			return (1);
		if (check_range_rgb(atoi(split_colors[0])) == 0 &&
			check_range_rgb(atoi(split_colors[1])) == 0 &&
			check_range_rgb(atoi(split_colors[2])) == 0)
		{
			config->floor_color_r = atoi(split_colors[0]);
			config->floor_color_g = atoi(split_colors[1]);
			config->floor_color_b = atoi(split_colors[2]);
		}
		else
		{
			write(2, "Invalid floor color values\n", 27);
			return (1);
		}
	}
	else if (line[0] == 'C')
	{
		char **split_ceiling_colors;

		split_ceiling_colors = ft_split(line + 2, ',');
		if (!split_ceiling_colors || !split_ceiling_colors[0] || !split_ceiling_colors[1] || !split_ceiling_colors[2])
		{
			write(2, "Invalid ceiling color format\n", 29);
			return (1);
		}
		if (check_valid_colors(split_ceiling_colors) != 0)
			return (1);
		if (check_range_rgb(atoi(split_ceiling_colors[0])) == 0 &&
			check_range_rgb(atoi(split_ceiling_colors[1])) == 0 &&
			check_range_rgb(atoi(split_ceiling_colors[2])) == 0)
		{
			config->ceiling_color_r = atoi(split_ceiling_colors[0]);
			config->ceiling_color_g = atoi(split_ceiling_colors[1]);
			config->ceiling_color_b = atoi(split_ceiling_colors[2]);
		}
		else
		{
			write(2, "Invalid ceiling color values\n", 29);
			return (1);
		}
	}
	else
	{
		write(2, "Invalid color line\n", 19);
		return (1);
	}
	return (0);
}

int assign_map(t_config *config, char *line)
{
	char **new_map;
	int i;
	if (valid_line(line) == 0)
	{
		new_map = malloc(sizeof(char *) * (config->map_height + 2));
		if (!new_map)
		{
			write(2, "Memory allocation failed for map\n", 33);
			return (1);
		}
		i = 0;
		while (i < config->map_height)
		{
			new_map[i] = config->map[i];
			i++;
		}
		new_map[i] = my_strdup(line);
		new_map[i + 1] = NULL;
		free(config->map);
		config->map = new_map;
		config->map_height++;
		if (config->map_width < ft_strlen(line))
			config->map_width = ft_strlen(line);
		return (0);
	}
	return (1);
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
	config->in_map = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!config->in_map && (line[0] == '\0' || line[0] == '\n'))
		{
			free(line);
			line = get_next_line(fd);
			continue;
		}
		if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E')
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
		else if (all_six_config(config) == 0)
		{
			config->in_map = 1;
			if (assign_map(config, line) != 0)
			{
				free(line);
				close(fd);
				return (1);
			}
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
	config->map = NULL;
	config->no_texture = NULL;
	config->so_texture = NULL;
	config->we_texture = NULL;
	config->ea_texture = NULL;
	config->floor_color_b = -1;
	config->ceiling_color_g = -1;
	config->floor_color_r = -1;
	config->ceiling_color_b = -1;
	config->ceiling_color_r = -1;
	config->ceiling_color_g = -1;
	config->map_width = 0;
	config->map_height = 0;
	if (create_map(argv[1], config))
		return (1);
	return (0);
}