/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brezenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:41:02 by mmahasim          #+#    #+#             */
/*   Updated: 2019/11/09 18:41:04 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <math.h>
#define MAX(a, b) (a > b ? a : b)
#define MOD(i) (i < 0 ? -i : i)

void	ft_free(t_m *m)
{
	int i;

	i = 0;
	free(m->mlx_ptr);
	free(m->win_ptr);
	while (!m->top_z)
	{
		free(m->top_z[i]);
		i++;
	}
	free(m->top_z);
	free(m);
}

void	ft_start(t_m *m)
{
	m->shift_x = 600;
	m->shift_y = 540;
	m->shift_zy = 350;
	m->shift_zx = 250;
	m->ugol_x = 0.8;
	m->ugol_y = 0.8;
	m->r_z = 5;
	m->r_y = 1;
	m->k_color = 1;
}

void	ft_3d(float *x, float *y, int z, t_m *m)
{
	*x = (*x - *y / m->r_y / 3) * (cos(m->ugol_x));
	*y = (*x / m->r_y / 3 + *y) * (sin(m->ugol_y)) - z * m->r_z;
}

void	ft_brezenham(t_cor *cor, t_m *m, int color)
{
	float		st_x;
	float		st_y;
	int			max;

	cor->x = cor->x * m->cube + m->shift_zx - 500;
	cor->y = cor->y * m->cube + m->shift_zy - 500;
	cor->x1 = cor->x1 * m->cube + m->shift_zx - 500;
	cor->y1 = cor->y1 * m->cube + m->shift_zy - 500;
	ft_3d(&cor->x, &cor->y, cor->z, m);
	ft_3d(&cor->x1, &cor->y1, cor->z1, m);
	cor->x += m->shift_x;
	cor->y += m->shift_y;
	cor->x1 += m->shift_x;
	cor->y1 += m->shift_y;
	st_x = cor->x1 - cor->x;
	st_y = cor->y1 - cor->y;
	max = MAX(MOD(st_x), MOD(st_y));
	st_x /= max;
	st_y /= max;
	while ((int)(cor->y - cor->y1) || (int)(cor->x - cor->x1))
	{
		mlx_pixel_put(m->mlx_ptr, m->win_ptr, cor->x, cor->y, color);
		cor->x += st_x;
		cor->y += st_y;
	}
}
