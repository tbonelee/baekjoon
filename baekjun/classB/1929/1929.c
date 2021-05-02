#include <stdio.h>

int		ft_is_prime(int nb)
{
	unsigned int i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (((unsigned int)nb) % i != 0 && i * i <= (unsigned int)nb)
		i++;
	if (i * i > (unsigned int)nb)
		return (1);
	else
		return (0);
}

int M, N;

int main()
{
	scanf("%d %d", &M, &N);
	for (int i = M; i <= N; i++)
	{
		if (ft_is_prime(i) == 1)
			printf("%d\n", i);
	}
}