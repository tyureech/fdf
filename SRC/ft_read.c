/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:04:22 by mmahasim          #+#    #+#             */
/*   Updated: 2019/10/23 19:04:28 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			ft_key(int key, t_m *m)
{
	if (key == 53)
		exit(0);
	else if (key == 126)
		m->shift_y -= 50;
	else if (key == 125)
		m->shift_y += 50;
	else if (key == 124)
		m->shift_x += 50;
	else if (key == 123)
		m->shift_x -= 50;
	else if (key == 69)
		m->size_pixel += 5;
	else if (key == 78)
		m->size_pixel -= 5;
	else if (key == 82)
		m->k_color += 0.05;
	else if (key == 65)
		m->k_color -= 0.05;
	ft_shaurma(key, m);
	mlx_clear_window(m->mlx_ptr, m->win_ptr);
	ft_draw(m);
	return (0);
}

void		ft_shaurma(int key, t_m *m)
{
	if (key == 86)
		m->ugol_y += 0.1;
	else if (key == 87)
		m->ugol_y -= 0.1;
	else if (key == 83)
		m->r_y += 1.4;
	else if (key == 84)
		m->r_y -= 1.4;
	else if (key == 91)
		m->r_z++;
	else if (key == 89)
		m->r_z--;
	else if (key == 13)
		m->shift_zy -= 50;
	else if (key == 1)
		m->shift_zy += 50;
	else if (key == 2)
		m->shift_zx += 10;
	else if (key == 0)
		m->shift_zx -= 10;
}

t_cor		*ft_pambukhchyan(float i, float j, float i1, float j1)
{
	t_cor *cor;

	if (!(cor = (t_cor*)malloc(sizeof(t_cor))))
		return (NULL);
	cor->x = i;
	cor->y = j;
	cor->x1 = i1;
	cor->y1 = j1;
	return (cor);
}

void		ft_draw(t_m *m)
{
	int		i;
	int		j;
	t_cor	*cor;

	j = 0;
	while (j < m->len_y)
	{
		i = 0;
		while (i < m->len_x)
		{
			if (i < m->len_x - 1)
			{
				cor = ft_pambukhchyan(i, j, (i + 1), j);
				ft_brezenham(cor, m, ft_color(cor, m));
			}
			if (j < m->len_y - 1)
			{
				cor = ft_pambukhchyan(i, j, i, (j + 1));
				ft_brezenham(cor, m, ft_color(cor, m));
			}
			i++;
		}
		j++;
	}
}

int			ft_color(t_cor *cor, t_m *m)
{
	int average;

	cor->z = m->top_z[(int)cor->y][(int)cor->x].z;
	cor->z1 = m->top_z[(int)cor->y1][(int)cor->x1].z;
	average = (cor->z + cor->z1 + 1) / 2;
	if (average < 0)
		average *= -1;
	return (m->k_color * 0x0a2125f * (average + 1));
}
