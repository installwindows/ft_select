#include <stdlib.h>
#include <stdio.h>

typedef struct s_case
{
	int index;
	int x;
	int y;
	char *value;
} t_case;

int main()
{
	t_case **cases;
	int x = 4;
	int y = 3;
	int i = 0;
	int index = 0;
	int j;

	cases = (t_case**)malloc(sizeof(t_case*)*y);
	while (i < y)
	{
		cases[i] = (t_case*)malloc(sizeof(t_case)*x);
		j = 0;
		while (j < x)
		{
			cases[i][j].index = index++;
			cases[i][j].x = j;
			cases[i][j].y = i;
			j++;
		}
		i++;
	}
	for (i=0;i<y;i++)
	{
		for (j=0;j<x;j++)
			printf("%2d [%2d, %2d]  ", cases[i][j].index, cases[i][j].x, cases[i][j].y);
		printf("\n");
	}
}
