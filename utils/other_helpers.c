/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnafiai <bnafiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:02:17 by bnafiai           #+#    #+#             */
/*   Updated: 2025/09/10 15:23:06 by bnafiai          ###   ########.fr       */
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
