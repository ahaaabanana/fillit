/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandpa <tgrandpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:42:24 by tgrandpa          #+#    #+#             */
/*   Updated: 2019/07/23 14:31:25 by tgrandpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void	show_content(char content[4][5])
{
	int 	i = -1;

	while (++i < 4)
	{
		ft_putstr(content[i]);
		ft_putchar(10);
	}
	ft_putchar(10);
}

void	show_min_pos(int min_pos[4][2])
{
	int 	i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		printf("%d ", min_pos[i][0]);
		printf("%d\n", min_pos[i][1]);
	}
	ft_putchar(10);
}

void	show_all(t_tetrimino *tetr)
{
	while (tetr)
	{
		show_content(tetr->content);
		show_min_pos(tetr->min_pos);
		tetr = tetr->next;
	}
}

void	clean_tetr(char content[4][5])
{
	int 	i;
	int 	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			content[i][j] = '.';
	}
}

void	move_tetr(t_tetrimino *tetr)
{
	int		i;
	int		n;
	int		m;
	int		l;
	
	ft_putstr("SOMETEXT\n\n");
	clean_tetr(tetr->content);
	n = 0;
	m = -1;
	while (1)
	{	
		if (l == 2)
			break ;
		l = 0;
		++m;
		i = -1;
		while (++i < 4)
			tetr->content[tetr->min_pos[i][0] + n][tetr->min_pos[i][1] + m] = tetr->name;
		show_content(tetr->content);
		clean_tetr(tetr->content);
		i = -1;
		while (++i < 4)
			if ((tetr->min_pos[i][1] + m) == 3)
			{
				m = -1;
				n++;
				l = 1;
				break ;
			}
		i = -1;		
		while (++i < 4)
			if ((tetr->min_pos[i][0] + n) == 3 && l == 1)
				l++;
	}
}

int 	main(int argc, char **argv)
{
	int 			fd;
	t_tetrimino		*tetr;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (check_file(fd))
		{
			ft_putstr("correct file\n");
			close(fd);
			fd = open(argv[1], O_RDONLY);
			tetr = read_tetriminos(fd, tetr);
			show_all(tetr);
			move_tetr(tetr->next->next);
			close(fd);
		}
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("usage: ./fillit source file\n");
	return (0);
}