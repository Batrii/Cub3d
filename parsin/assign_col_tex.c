/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_col_tex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnafiai <bnafiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:42:05 by bnafiai           #+#    #+#             */
/*   Updated: 2025/07/20 16:42:05 by bnafiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	validate_texture(char **split_texture)
{
	if (!split_texture || !split_texture[0])
	{
		write(2, "Error: Invalid texture format\n", 30);
		if (split_texture)
			free_split(split_texture);
		return (1);
	}
	if (split_texture[1] != NULL)
	{
		write(2, "Error: Invalid texture format\n", 30);
		free_split(split_texture);
		return (1);
	}
	return (0);
}

int	skip_spaces(const char *line, int index)
{
	while (line[index] == ' ' || line[index] == '\t')
		index++;
	return (index);
}

int	assign_texture(t_config *config, char *line)
{
	int		i;
	char	**split_so_texture;
	char	**split_we_texture;
	char	**split_ea_texture;
	char	**split_no_texture;

	if (line[0] == 'N' && line[1] == 'O')
	{
		i = skip_spaces(line, 2);
		split_no_texture = utils_split(line + i, ' ');
		if (validate_texture(split_no_texture) != 0)
			return (1);
		config->no_texture = my_strdup(split_no_texture[0]);
		free_split(split_no_texture);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		i = skip_spaces(line, 2);
		split_so_texture = utils_split(line + i, ' ');
		if (validate_texture(split_so_texture) != 0)
			return (1);
		config->so_texture = my_strdup(split_so_texture[0]);
		free_split(split_so_texture);
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		i = skip_spaces(line, 2);
		split_we_texture = utils_split(line + i, ' ');
		if (validate_texture(split_we_texture) != 0)
			return (1);
		config->we_texture = my_strdup(split_we_texture[0]);
		free_split(split_we_texture);
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		i = skip_spaces(line, 2);
		split_ea_texture = utils_split(line + i, ' ');
		if (validate_texture(split_ea_texture) != 0)
			return (1);
		config->ea_texture = my_strdup(split_ea_texture[0]);
		free_split(split_ea_texture);
	}
	else
	{
		write(2, "Error: Invalid texture line\n", 21);
		return (1);
	}
	return (0);
}

int	validate_colors(char **colors)
{
	if (!colors || !colors[0] || !colors[1] || !colors[2])
	{
		write(2, "Error: Invalid color format\n", 28);
		return (1);
	}
	if (check_valid_colors(colors) != 0)
		return (1);
	if (check_range_rgb(ft_atoi(colors[0])) == 0
		&& check_range_rgb(ft_atoi(colors[1])) == 0
		&& check_range_rgb(ft_atoi(colors[2])) == 0)
	{
		return (0);
	}
	else
	{
		write(2, "Error: Invalid color values\n", 28);
		return (1);
	}
}
