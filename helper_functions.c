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
