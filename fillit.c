#include "fillit.h"
#include "libft/libft.h"

/* CHECK */
void 	init_tetr_content(char content[6][7])
{
	int 	i;
	int 	j;

	i = -1;
	while(++i < 6)
	{
		j = -1;
		while (++j < 6)
			content[i][j] = '.';
		content[i][j] = 0;
	}
}

int 			check_tetr_line(char *line)
{
	int 	i;
	
	i = -1;
	while(++i < 4)
		if (line[i] != '.' && line[i] != '#')
			return (0);
	return (1);
}

int 	is_correct_tetr(char tetr_check[6][7])
{
	int		i;
	int 	j;
	int 	counter;

	i = -1;
	counter = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (tetr_check[i + 1][j + 1] == '#')
			{
				if (tetr_check[i][j + 1] == '#')
					counter++;
				if (tetr_check[i + 2][j + 1] == '#')
					counter++;
				if (tetr_check[i + 1][j] == '#')
					counter++;
				if (tetr_check[i + 1][j + 2] == '#')
					counter++;
			}
	}
	if (counter == 6 || counter == 8)
		return (1);
	return (0);
}

int 		check_tetrimino(int fd, char tetr_check[6][7])
{
	int 			ret;
	int 			i;
	char 			c;
	
	init_tetr_content(tetr_check);
	i = 0;
	while ((ret = read(fd, tetr_check[++i] + 1, 4)))
	{
		if (ret == 4 && read(fd, &c, 1) && c == 10)
		{
			if (!(check_tetr_line(tetr_check[i] + 1)))
				return (0);
		}
		else
			return (0);
		if (i == 4 && is_correct_tetr(tetr_check))
		{
			i = 0;
			read(fd, &c, 1);
		}
	}
	if (i != 1)
		return (0);
	return (1);
}
/* ---------------------------------------------------- */

void 	make_tetr(int fd)
{
	t_tetrimino		tetr;
	int 			i;
	int 			j;
	int 			counter;
	char 			c;

	i = -1;
	while (read(fd, tetr.content[++i], 4))
	{
		tetr.content[i][4] = 0;
		if (i == 3)
			i = 0;
		read(fd, &c, 1);
	}
	i = -1;
	counter = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (tetr.content[i][j] == '#')
			{
				tetr.min_pos[0][counter] = i;
				tetr.min_pos[1][counter] = j;
			}
		counter++;
	}
	i = -1;
	while (++i < 4)
		printf("%d ", tetr.min_pos[0][i]);
	i = -1;
	while (++i < 4)
		printf("%d ", tetr.min_pos[1][i]);
}

int 	main(int argc, char **argv)
{
	int 			fd;
	char 			tetr_check[6][7];
	t_tetrimino 	tetr;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (check_tetrimino(fd, tetr_check))
		{
			close(fd);
			fd = open(argv[1], O_RDONLY);
			make_tetr(fd);
		}
		else
		{
			ft_putstr("error");
		}
		close(fd);
	}
	else
		ft_putstr("usage: ./fillit source file");
	// ft_putchar(10);
	return (0);
}