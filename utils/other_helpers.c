/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnafiai <bnafiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:02:17 by bnafiai           #+#    #+#             */
/*   Updated: 2025/09/13 17:30:27 by bnafiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	check_valid_texture(int *texture_lines, char **texture, char *line)
{
	(*texture_lines)++;
	if (check_duplicate(*texture_lines) != 0)
		return (1);
	if (valid_tex(line, texture) != 0)
		return (1);
	return (0);
}

int	check_args(char *line)
{
	char	**split_line;

	split_line = utils_split(line, ' ');
	if (array_size(split_line) != 2)
	{
		if (array_size(split_line) == 3 && split_line[2][0] == '\n')
		{
			free_split(split_line);
			return (0);
		}
		free_split(split_line);
		return (1);
	}
	free_split(split_line);
	return (0);
}
