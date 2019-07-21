#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_tetrimino
{
	char		content[6][7];
	char 		name;
}				t_tetrimino;

#endif

//exit, open, close, write, read, malloc and free.