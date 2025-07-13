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

#include "cub.h"

size_t ft_strlen(const char *str)
{
	size_t length = 0;

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