#include <stdlib.h>
#include <stdio.h>
typedef struct  s_point
{
  int           x;
  int           y;
}               t_point;

void flood_fill1(char **tab, int i , int j, char oldcolor, t_point size)
{
	if(i < 0 || i >= size.y || j < 0 || j >= size.x || tab[i][j] != oldcolor || tab[i][j] == 'F')
		return ;
	tab[i][j] = 'F';
	flood_fill1(tab, i + 1, j, oldcolor, size);
	flood_fill1(tab, i - 1, j, oldcolor, size);
	flood_fill1(tab, i, j + 1, oldcolor, size);
	flood_fill1(tab, i, j - 1, oldcolor, size);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	flood_fill1(tab, begin.y,begin.x, tab[begin.y][begin.x], size);
}
