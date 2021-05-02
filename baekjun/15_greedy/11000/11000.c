
	// 기존 회의실 배정 문제를 반복해서 남는 것이 없을 때까지 돌려봄 -> 시간초과

	// 리스트의 회의들을 한 번씩만 체크하는 알고리즘 필요

	// 우선 회의를 1) 시작시간 빠른 순서대로 2) 종료시간 빠른 순서대로 정렬(기존 회의실 문제와 동일)
	// 그 후 맨 앞의 회의부터 체크하면서 회의실 배정
	// 처음에 배정된 회의가 없으면 해당 회의에 회의실 배정
	// i번째 회의를 체크할 때 앞에서 이미 회의실에 배정된 회의의 종료시간보다 늦게 시작하면 해당 회의실에 이어서 배정
	// 시작시간이 종료시간보다 빨라서 겹치면 새 회의실 배정

	// 이 과정을 우선순위 큐로 구현.
	// 우선순위는 종료시간으로 설정(큐에 넣을 때는 그냥 종료 시간만 넣음)
	// 배정된 회의가 아무 것도 없을 때는 우선순위 큐에 종료시간을 삽입
	// 배정된 회의가 있는 경우(우선순위 큐에 요소가 있는 경우),
	// 	우선순위 큐 맨 앞(가장 종료시간 빠른 회의)의 값보다 현재 체크하는 회의의 시작시간이 빠르면 그냥 큐에 새 회의 삽입.
	// 	현재 체크하는 회의의 시작시간이 더 늦으면 현재 가장 최우선순위의 큐를 pop하고 새 회의를 삽입.
	// 이런 식으로 반복하면 큐에 있는 원소 하나는 각 회의실에서 가장 마지막 회의의 종료 시간이 되고, 우선순위큐의 사이즈가 배정된 회의실의 갯수가 된다.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 분명 맞다고 생각했는데 자꾸 틀리다고 나와서 다른 사람 c풀이를 보고 비교해봤으나 다른 부분을 찾지 못함.

// 그런데 대충 보고 넘겼던 compare함수에서 문제가 있었다.
// 기존 회의실 문제와 정렬 기준이 다른데 이를 꼼꼼하게 체크하지 않았던 것.
// 다른 풀이에서 함수 가져올 때는 꼭 제대로 하나하나 확인하기로..


#include <stdio.h>
#include <stdlib.h>

#define left(num) (2 * num)
#define right(num) (2 * num + 1)
#define parent(num) (num / 2)

typedef struct s_input{
	int start;
	int end;
}	t_input;

// int prq[200005];
int *prq;
int prq_size = 0;


int compare(const void *a, const void *b)
{

	t_input *temp_a = (t_input *)a;
	t_input *temp_b = (t_input *)b;
	if (temp_a->start == temp_b->start)
		return (temp_a->end - temp_b->end);
	else
		return (temp_a->start - temp_b->start);

}

void swap (int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void		max_heapify(int nod)
{
	int max = nod;

	if (left(nod) <= prq_size && prq[left(nod)] < prq[nod])
		max = left(nod);
	if (right(nod) <= prq_size && prq[right(nod)] < prq[max])
		max = right(nod);
	if (max != nod)
	{
		swap(&prq[nod], &prq[max]);
		max_heapify(max);
	}
}

void		building_heap(void)
{
	for (int i = prq_size / 2; i >= 1; i--)
		max_heapify(i);
}

void		insert_heap(int to_put)
{
	int i;
	prq_size++;
	prq[prq_size] = to_put;
	i = prq_size;
	while (i > 1)
	{
		if (prq[i] < prq[parent(i)])
			swap(&prq[i], &prq[parent(i)]);
		else
			break;
		i = parent(i);
	}
}



void find(int N, t_input info[])
{

	qsort(info + 1, N, sizeof(t_input), &compare);
	int i = 1;
	insert_heap(info[i].end);
	i++;
	while (i <= N)
	{
		if (prq[1] <= info[i].start)
		{
			prq[1] = info[i].end;
			max_heapify(1);
		}
		else
			insert_heap(info[i].end);
		i++;

	}
}

int main()
{
	int N;
	scanf("%d", &N);
	t_input *info = calloc(N + 1,sizeof(t_input));
	// t_input info[200005];
	prq = calloc(N + 1, sizeof(int));
	info[0].start = 0; info[0].end = 0;
	for (int i = 1; i <= N; i++)
		scanf("%d %d", &info[i].start, &info[i].end);

	find(N, info);
	printf("%d\n", prq_size);
	free (info);
	free (prq);
	return 0;
}