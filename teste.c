#include <math.h>
#include <stdio.h>


int gerarAleatorio(int min, int max)
{
	return min + rand() % (max - min + 1);
}

int main(void)
{
	int n =0;
	int i;
	while(n < 20)
	{
		i = rand();
		printf("%d\n", i);
		n++;
	}
}
