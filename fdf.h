/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:06:16 by mmahasim          #+#    #+#             */
/*   Updated: 2019/10/23 20:06:21 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include "libft/libft.h"
# include "mlx.h"
# define WIDHT 1480
# define HEIGHT 1080
# define BUFF_SIZE 1

typedef struct		s_tops_z
{
	int				z;
}					t_tops_z;

typedef	struct		s_cor
{
	int				z;
	int				z1;
	float			x;
	float			x1;
	float			y;
	float			y1;
}					t_cor;

typedef struct		s_m
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			**m;
	char			**k;
	int				len_x;
	int				len_y;
	int				cube;
	int				shift_x;
	int				shift_y;
	int				shift_zx;
	int				shift_zy;
	double			ugol_x;
	double			ugol_y;
	float			r_z;
	float			r_y;
	float			k_color;
	struct s_tops_z **top_z;
}					t_m;

int					ft_color(t_cor *cor, t_m *m);
int					ft_cube(int d_x, int d_x1);
int					get_next_line(const int fd, char **line);
int					ft_len_y(char *argv);
char				**ft_m(char *argv, t_m *m);
void				ft_brezenham(t_cor *cor, t_m *m, int color);
void				ft_3d(float *x, float *y, int z, t_m *m);
void				ft_draw(t_m *m);
int					ft_key(int key, t_m *m);
void				ft_start(t_m *m);
int					ft_cor_z(t_m *m);
void				ft_shaurma(int key, t_m *m);
t_cor				*ft_pambukhchyan(float i, float j, float i1, float j1);
void				ft_free(t_m	*m);

#endif
