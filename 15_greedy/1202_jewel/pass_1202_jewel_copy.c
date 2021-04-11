// N + K ≡ A로 정의.

// 정렬 O(A * log A)
// building_heap은 O(힙 원소)인데 처음에 한 개로 빌딩하므로 O(1)
// insert_heap은 n를 힙의 원소라 하면 O(log n)
// n은 min{N, K}보다 크지 않으므로
// insert_heap은 O(log (min{N, K})).
// 그런데 insert_heap을 min{N, K}번 하므로
// O(min{N, K} * log (min{N, K}))

// 종합하면 전체 시간복잡도는 max {O(A * log A)}

// ===========================================================
// 아이디어 :
// 어떻게 풀든 일단 정렬이 필요할 것이라 생각
// 병합 정렬 통해 가방과 보석 모두 정렬
// 가장 가치가 큰 보석을 가장 작은 가방부터 넣는 문제로 생각했으나,
// O(N *K)로 최대 90억의 시간복잡도가 나옴.
// 예상대로 타임아웃

// 최대한 보석을 한 번만 체크하면서 분류하는 방법이 필요하다고 생각.(시간복잡도가 제곱 이상의 꼴이 되지 않게)
// 또한 탐욕법의 해가 완전 탐색의 해가 되려면
// 일단 어떻게 풀든 더 작은 가방에 들어갈 수 있는 보석이 굳이 그 가방에 들어가지 않고 더 큰 가방에 들어가는 일이 없어야 한다고 생각.
// 따라서 작은 가방부터 해당 가방에 들어갈 수 있는 보석부터 우선 채워넣는 것으로 아이디어를 생각함.
// 이러한 것이 그리디 솔루션이라 해보자.

// 	탐욕해 : 가장 작은 가방부터 해당 가방에 들어올 수 있는 보석 중 가장 비싼 보석을 선택.
// 	전체 최적 해 : 가장 비싼 보석부터 해당 보석이 들어갈 수 있는 가장 작은 크기의 가방에 넣기.

// 1) 보통 일반적인 탐욕해 정당성 증명
// =====================================================
// 1. greedy choice property : 특정 가방이 주어져있을 때 해당 가방에서 가장 비싼 보석을 고르자(탐욕법)
// 	이러한 탐욕적 선택이 globally 최적 해가 된다.
// 	탐욕 해에서 가장 작은 가방에서 해당 가방에 들어올 수 있는 보석 중 가장 비싼 보석을 넣는다고 했을 때,
// 	해당 보석과 가방 조합을 포함하는 global optimum이 항상 존재함을 보이자.
// (증명) 전역적 최적 해에서는 가장 비싼 보석부터 들어갈 수 있는 가장 작은 가방에 넣으려한다.
// 	가장 비싼 보석이 가장 작은 가방에 들어갈 수 있는 크기라면(case1) 해당 가방에 들어가고,
// 	가장 작은 가방에 들어올 수 있는 가장 비싼 보석이 들어온 것이므로 case1에 대해서는 증명 완료.

// 	case1을 제외한 나머지 케이스에서는 다음과 같다.
// 	가장 비싼 보석이 가장 작은 가방에 들어갈 수 없는 크기라면 가장 비싼 보석은 가장 작은 가방보다는 큰 가방에 들어가고,
// 	그 다음 비싼 보석을 탐색할 것이다.
// 	이런 식으로 점점 저렴한 보석을 향해서 탐색하다가 가장 작은 가방에 들어갈 수 있는 보석을 발견하면, 해당 보석을 가장 작은 가방에 넣을 것이다.
// 	그리고 해당 보석이 가장 작은 가방에 들어갈 수 있는 보석 중 가장 비싼 보석일 것이다.
// 	따라서 두 가지 경우에 대해 증명이 완료된다.



// 2. optimal substructure : 전체의 최적 해가 하부 구조의 최적 해를 포함하는 경우 성립.
// 	전체의 최적 해는 가장 큰 보석을 들어갈 수 있는 가장 작은 가방에 차근차근 넣는 것.
// (증명) 탐욕법의 첫 단계에서 매칭된 가방과 보석을 제외시키고(없다고 생각하고),
// 	다시 그 중 가장 작은 가방에 들어갈 수 있는 가장 비싼 보석을 매칭시키면 이 또한 global optimum의 부분 집합
// 	(∵ 전역적 최적해의 한 (보석, 가방)조합을 제외시킨 후 나머지에 대해 최적해를 구해도 이는 제외시키지 않은 경우의 최적해의 부분 집합이므로)

// 1.2.가 만족되므로 탐욕해는 전역적 최적.
// ================================================
// 2) 그냥 통으로 정당성 증명해보기

// 	귀류법을 통해 탐욕해가 전체 최적 해의 부분 집합임을 보이고자 한다.

// 	우선 탐욕해가 전체 최적 해의 부분집합이 아니라고 해보자.
// 	그러면 가장 비싼 보석부터 탐욕해의 솔루션에서 매칭되는 가방에 넣었을 때,
// 	해당 보석이 들어갈 수 있는 가장 작은 크기의 가방에 들어가지 않는(더 큰 가방에 들어가는 격) 보석이 하나 이상 존재할 것이다.


// 	그 중 가장 먼저 등장하는 보석(그런 보석들 중 가장 비싼 보석)을 j, j가 최적 해였다면 들어갔을 가방을 a, 탐욕해에서 들어간 가방을 b라고 놓자. (a의 크기 < b의 크기)
// 	(처음 등장한 최적해를 깨는 보석이므로 그 보석보다 비싼 보석들은 최적해와 겹칠 것이다)
// 	j를 방문했을 다이세 가방 a를 선택할 수 있는 상황이라는 것은 j<=k인 임의의 보석 k 중 a를 선택한 보석이 없다는 것이다.
// 	그런데 지금 하는 행위는 탐욕법으로 얻은 솔루션을 전역적 최적 해와 일치하는지 보기 위해 전역적 최적 해를 구하는 단계에 따라 분류해 보는 것임을 명심하자.
// 	탐욕해의 관점에서 보면 가방 a에서 보석을 탐색할 때 j보다 가치가 큰 보석(담을 수 있는 보석 중에)이 있었기 때문에 j가 아닌 j보다 가치가 큰 보석을 a에 담았다는 것이고,
// 	가방 b가 되어서야 보석 j를 담았음을 의미한다.
// 	하지만 j의 무게 이상인 보석들부터 훑어내려올 때 a를 선택한 보석은 없음을 위에서 확인했다.
// 	따라서 논리적으로 모순이 있음을 확인했으니 탐욕해가 전체 최적 해의 부분집합이어야 함을 확인했다.
// 	∴탐욕해 ⊂ global optimum


// 	탐욕해에서는 작은 가방부터 체크하므로 a에 들어갈 보석을 먼저 찾을 것이다.
// 	가장 큰 보석부터 최적해방식으로
// 	탐욕해에서 a에 j를 넣지 않으므로 a에 넣게 되는 보석(k라 부르기로 함)은 j보다 크거나 같은 보석이다.
// 	그러면 k 무게 < a < b이므로 최적 해에서는 k를 j보다 먼저 선택할 때 최소한 b에는 넣지 않았을 것이다.
// ============================================================================================
// 그리디 솔루션의 방향은 잡았으나 우선순위 큐에 대한 학습이 없어서 어떻게 구현할지 몰랐음.
// 결국 다른 사람의 풀이를 보고 우선순위 큐를 사용한 것을 확인하여 구현 방향을 잡음.
// ==========================================================================================

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
///////////////////////////////////////////////////////////
#define left(nod) (2 * nod)
#define right(nod) ((2 * nod) + 1)
#define parent(nod) (nod / 2)

/////////////////////////////////////////////////////////////
// typedef int		t_bag;
typedef struct	s_data	t_data;
struct s_data{
	int M;
	int V;
};
// struct s_bag{
// 	int num;
// 	bool visited;
// };
////////////////////////////////////////////////////////////////////
void		mergesort(t_data arr[], int start, int end);
void		merge(t_data arr[], int start, int mid, int end);

long long	find(t_data arr[], int N, int K);

void		max_heapify(int	nod);
void		building_heap(void);
void		insert_heap(t_data to_put);
t_data		deque(void);

//////////////////////////////////////////////////////////////////
t_data		g_q_heap[300001];
int			g_q_length;

//////////////////////////////////////////////////////////////
// // 큐 테스트용
// void	test_q(void)
// {
// 	t_jewel a,b,c,d;
// 	a.M = 5;
// 	b.M = 3;
// 	c.M = 9;
// 	d.M = 10;

// 	insert_heap(a);
// 	insert_heap(b);
// 	insert_heap(c);
// 	insert_heap(d);

// 	printf("%d ", deque().M);
// 	printf("%d ", deque().M);
// 	printf("%d ", deque().M);
// 	printf("%d ", deque().M);
// }

////////////////////////////////////////////////
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	t_data arr[600001];
	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &arr[i].M, &arr[i].V);
	}
	for (int i = N + 1; i <= N + K; i++)
	{
		scanf("%d", &arr[i].M);
		// 가방과 보석을 같은 구조체에 담는데 가방은 값의 데이터가 없으므로
		// 멤버 V를 -1로 할당하여 가방이라는 것을 표시한다.
		arr[i].V = -1;
	}
	mergesort(arr, 1, N + K);

	long long result = find(arr, N, K);

	printf("%lld\n", result);

}


///////////////////////////////////////////////////////////////////////
long long	find(t_data arr[], int N, int K)
{
	long long	ret = 0;
	t_data		temp;

	for (int i = 1; i <= N + K; i++)
	{
		if (arr[i].V != -1)
		{
			insert_heap(arr[i]);
		}
		else
		{
			if (g_q_length != 0)
			{
				temp = deque();
				ret += temp.V;
			}
		}
	}

	return (ret);

}

/////////////// 병합정렬


void	mergesort(t_data arr[], int start, int end)
{
	if (start == end)
		return ;

	int mid = (start + end) / 2;
// printf("here");
	mergesort(arr, start, mid);
	mergesort(arr, mid + 1, end);
	merge(arr, start, mid, end);
}

void	merge(t_data arr[], int start, int mid, int end)
{
	t_data max; max.M = INT_MAX;
	t_data temp1[600001];
	t_data temp2[600001];
// printf("here");
	int i = start;
	for (; i <= mid; i++)
	{
		temp1[i] = arr[i];
	}
	temp1[i] = max;

	int j = mid + 1;
	for (; j <= end; j++)
	{
		temp2[j] = arr[j];
	}
	temp2[j] = max;

	int idx = start;
	for (i = start, j = mid + 1; (i != mid + 1 || j != end + 1); idx++)
	{
		// printf("deepest");
		if (temp1[i].M <= temp2[j].M)
		{
			arr[idx] = temp1[i++];
		}
		else
		{
			arr[idx] = temp2[j++];
		}
	}

}

///////////////우선순위 큐(큐의 인덱스는 1부터 시작하게 설정)
///////////////우선순위는 보석의 가치가 클수록 높다

// 해당 자식 노드와 그 이하로는 모두 힙 구조임을 가정하고
// 부모 노드와 자식 노드 사이에 힙 구조가 아닐 수 있음을 가정.
// 그 상태에서 힙 상태를 만드는 함수
void		max_heapify(int nod)
{
	int max = nod;

	if (left(nod) <= g_q_length && g_q_heap[left(nod)].V > g_q_heap[nod].V)
		max = left(nod);
	if (right(nod) <= g_q_length && g_q_heap[right(nod)].V > g_q_heap[max].V)
		max = right(nod);
	if (max != nod)
	{
		t_data temp = g_q_heap[max];
		g_q_heap[max] = g_q_heap[nod];
		g_q_heap[nod] = temp;
		max_heapify(max);
	}
}

void		building_heap(void)
{
	for (int i = g_q_length / 2; i >= 1; i--)
		max_heapify(i);
}

void		insert_heap(t_data to_put)
{
	int i;
	g_q_length++;
	g_q_heap[g_q_length] = to_put;
	i = parent(g_q_length);
	for (; i >= 1; i = parent(i))
	{
		max_heapify(i);
	}
}

t_data		deque(void)
{
	t_data ret = g_q_heap[1];
	g_q_heap[1] = g_q_heap[g_q_length];
	g_q_length--;
	max_heapify(1);
	return (ret);
}