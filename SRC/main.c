/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:16:38 by mmahasim          #+#    #+#             */
/*   Updated: 2019/10/21 19:16:41 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			ft_cube(int d_x, int d_x1)
{
	int cube;

	cube = 50;
	if (d_x != d_x1)
	{
		ft_putstr("Found wrong line length. Exiting.\n");
		exit(0);
	}
	while (d_x * cube > HEIGHT)
	{
		cube = cube / 2;
	}
	return (cube);
}

int			ft_len_y(char *argv)
{
	int		j;
	char	*str;
	int		fd;
	int		error;

	j = 0;
	fd = open(argv, O_RDONLY);
	if (get_next_line(fd, &str) == 0)
	{
		ft_putstr("No data found.\n");
		exit(0);
	}
	j++;
	while ((error = get_next_line(fd, &str)) != 0)
	{
		if (error == -1)
		{
			ft_putstr("No data found.\n");
			exit(-1);
		}
		free(str);
		j++;
	}
	ft_cube(j, j);
	return (j);
}

char		**ft_m(char *argv, t_m *m)
{
	int		j;
	char	**str;
	int		fd;
	int		error;

	j = 0;
	fd = open(argv, O_RDONLY);
	if (!(str = (char **)malloc(sizeof(char *) * m->len_y)))
		return (0);
	while ((error = (get_next_line(fd, &str[j]))) != 0)
	{
		if (error == -1)
		{
			ft_putstr("No data found.\n");
			exit(-1);
		}
		j++;
	}
	return (str);
}

int			ft_cor_z(t_m *m)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(m->top_z = (t_tops_z **)malloc(sizeof(t_tops_z *) * m->len_y)))
		return (0);
	m->len_x = ft_count(m->m[0], ' ');
	while (j != m->len_y)
	{
		m->k = ft_strsplit(m->m[j], ' ');
		m->cube = ft_cube(m->len_x, ft_count(m->m[j], ' '));
		if (!(m->top_z[j] = (t_tops_z *)malloc(sizeof(t_tops_z) * m->len_x)))
			return (0);
		while (m->k[i] != 0)
		{
			m->top_z[j][i].z = ft_atoi(m->k[i]);
			i++;
		}
		j++;
		i = 0;
	}
	ft_del(m->k);
	return (0);
}

int			main(int argc, char **argv)
{
	t_m		*m;

	if (argc != 2)
	{
		ft_putstr("enter 1 fdf map\n");
		return (-1);
	}
	if (!(m = (t_m *)malloc(sizeof(t_m))))
		return (0);
	m->len_y = ft_len_y(argv[1]);
	m->m = ft_m(argv[1], m);
	ft_start(m);
	ft_cor_z(m);
	m->mlx_ptr = mlx_init();
	m->win_ptr = mlx_new_window(m->mlx_ptr, WIDHT, HEIGHT,
			ft_strjoin("Fdf - ", argv[1]));
	ft_draw(m);
	mlx_key_hook(m->win_ptr, ft_key, m);
	mlx_loop(m->mlx_ptr);
	return (0);
}
