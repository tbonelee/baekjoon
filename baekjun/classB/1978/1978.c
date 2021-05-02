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

int N;

int main()
{
	int ret = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		int temp; scanf("%d", &temp);
		if (ft_is_prime(temp) == 1)
			ret++;
	}
	printf("%d\n", ret);
}