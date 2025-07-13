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

# define BUFFER_SIZE 1024

typedef struct s_config
{
	char *no_texture;
	char *so_texture;
	char *we_texture;
	char *ea_texture;
	int floor_color_r;
	int floor_color_g;
	int floor_color_b;
	int ceiling_color_r;
	int ceiling_color_g;
	int ceiling_color_b;
	char **map;
	int map_width;
	int map_height;
} t_config;


//get_next_line part
char *get_next_line(int fd);
char *my_strjoin(char *s1, char *s2);
char *my_strdup(char *s);
char *my_strchar(char *str, int c);
size_t my_strlen(char *s);
//helper functions
size_t ft_strlen(const char *str);
int check_range_rgb(int color);
char	**ft_split(char const *s, char c);
int all_six_config(t_config *config);
//extension check
int check_extension(char *filename);
//map check
int check_map(char **map);
int once_player(char **map);

#endif