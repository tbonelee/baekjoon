#include <iostream>
#include <climits>

using namespace std;

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

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int min = INT_MAX;
	int sum = 0;
	int m, n; cin >> m >> n;
	for (int i = m; i <= n; i++){
		if (ft_is_prime(i)){
			sum += i;
			if (i < min)
				min = i;
		}
	}
	if (sum == 0)
		cout << -1 << "\n";
	else
		cout << sum << "\n" << min << "\n";
}