#include "fillit.h"
#include "libft/libft.h"

void 	init_tetr_content(char content[6][7])
{
	int 	i;
	int 	j;

	i = -1;
	while(++i < 6)
	{
		j = -1;
		while (++j < 7)
			content[i][j] = '.';
		content[i][j] = 0;
	}
}

void 			show_tetr(char content[6][7])
{
	int 	i;

	i = -1;
	while(++i < 6)
	{
		ft_putstr(content[i]);
		ft_putchar(10);
	}
}

int 			check_tetr_line(char *line)
{
	while (*line)
		if (*line != '.' && *line != '#')
			return (0);
	return (1);
}

t_tetrimino		*check_tetrimino(int fd, t_tetrimino *tetr)
{
	int 	ret;
	int 	i;
	char 	c;

	
	tetr = (t_tetrimino*)malloc(sizeof(t_tetrimino));
	init_tetr_content(tetr->content);
	show_tetr(tetr->content);
	if (tetr)
	{
		i = 1;
		while (ret = read(fd, tetr->content[i] + 1, 4))
		{
			if (ret == 4 && read(fd, &c, 1))
			{
				if (!check_tetr_line(tetr->content[i] + 1))
					return (NULL):
			}
		}
	}
	return (tetr);
}

int 	main(int argc, char **argv)
{
	int 			fd;
	int 			*x;
	t_tetrimino 	*tetr;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (tetr = check_tetrimino(fd, tetr))
		{
			ft_putstr("correct file");
		}
		else
		{
			ft_putstr("error");
		}	
	}
	else
		ft_putstr("usage: ./fillit source file");
	ft_putchar(10);
	return (0);
}