#include <stdio.h>
#include <string.h>
#define MAX 987654321

int visit[21];
int map[22][22];
int N, MIN;

int abs(int a)
{
    return a < 0 ? -1 * a : a;
}

void C(int cur, int n)
{
    if (n == N/2)
    {
        int team_1 = 0;
        int team_2 = 0;
        int team_bal = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (visit[i] == 1 && visit[j] == 1)
                {
                    team_1 += map[i][j];
                }
                else if (visit[i] == 0 && visit[j] == 0)
                {
                    team_2 += map[i][j];
                }
            }
        }
        team_bal = abs(team_1 - team_2);
        if (MIN > team_bal)
            MIN = team_bal;

        return;
    }

    for (int i = cur + 1; i < N; i++)
    {
        visit[i] = 1;
        C(i, n + 1);
        visit[i] = 0;
    }

    return;
}


int main()
{
    MIN = MAX;
    scanf("%d",&N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        visit[i] = 1;
        C(i, 1);
        visit[i] = 0;
    }


    printf("%d\n", MIN);
    return 0;
}