/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnafiai <bnafiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:07:54 by bnafiai           #+#    #+#             */
/*   Updated: 2025/07/12 16:07:54 by bnafiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_config
{
    char *no_texture;
    char *so_texture;
    char *we_texture;
    char *ea_texture;
    int floor_color;
    int ceiling_color;
} t_config;

typedef struct s_map
{
    char **map;
    int width;
    int height;
} t_map;

typedef struct s_player
{
    float x;
    float y;
    float angle;
} t_player;

typedef struct s_cub
{
    t_map map;
    t_player player;
} t_cub;

size_t ft_strlen(const char *str);
int check_extension(char *filename);

#endif