#include <math.h>
#include <stdio.h>


int gerarAleatorio(int min, int max)
{
	return min + rand() % (max - min + 1);
}

int main(void)
{
	int n =0;
	int i = 0;

	while(n < 20)
	{
		i = gerarAleatorio(1, 100);
		printf("%d\n", i);
		n++;
	}
}
