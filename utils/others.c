/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnafiai <bnafiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:30:14 by bnafiai           #+#    #+#             */
/*   Updated: 2025/09/10 14:38:55 by bnafiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	array_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	check_for_commas(char *str)
{
	int	i;
	int	commas;

	i = 0;
	commas = 0;
	while (str[i])
	{
		if (str[i] == ',')
			commas++;
		i++;
	}
	return (commas);
}

void	free_config(t_config *config)
{
	int	i;

	i = 0;
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
		while (i < config->map_height)
		{
			free(config->map[i]);
			i++;
		}
		free(config->map);
	}
	free(config);
}

int	create_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

int	check_duplicate(int texture_line)
{
	if (texture_line > 4)
	{
		write(2, "Error : duplicate textures\n", 27);
		return (1);
	}
	return (0);
}
