/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnafiai <bnafiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:32:11 by bnafiai           #+#    #+#             */
/*   Updated: 2025/07/12 16:32:11 by bnafiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void free_split(char **split)
{
	int i;

	if (!split)
		return;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int is_line_empty(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n' && line[i] != '\r')
			return (0);
		i++;
	}
	return (1);
}


int ft_strlen(const char *str)
{
	int length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return length;
}

int check_range_rgb(int color)
{
	if (color < 0 || color > 255)
	{
		write(2, "Error : Color value out of range (0-255)\n", 34);
		return (1);
	}
	return (0);
}
int all_six_config(t_config *config)
{
	if (config->no_texture && config->so_texture && config->we_texture &&
		config->ea_texture && config->floor_color_r != -1 &&
		config->ceiling_color_r != -1)
	{
		return (1);
	}
	return (0);
}


int valid_line(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (1);
	while (line[i] && line[i] != '\n')
	{
		if (my_strchar("01NSEW ", line[i]) == NULL)
		{
			write(2, "Invalid character in line\n", 26);
			return (1);
		}
		i++;
	}
	return (0);
}


int check_valid_colors(char **colors)
{
	int i;
	int j;

	i = 0;
	while (colors[i])
	{
		printf("Checking color string: %s\n", colors[i]);
		j = 0;
		while (colors[i][j])
		{
			if (colors[i][j] == 13 || colors[i][j] == '\n')
				break;
			if (colors[i][j] < '0' || colors[i][j] > '9')
			{
				write(2, "Invalid color value\n", 20);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
