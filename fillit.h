#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_tetrimino
{
	char		content[4][5];
	int 		min_pos[2][4];
	char 		name;
}				t_tetrimino;

#endif

//exit, open, close, write, read, malloc and free.