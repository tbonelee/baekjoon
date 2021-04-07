#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_list t_list;
typedef struct s_graph t_graph;

int		g_q_head;
int		g_q_tail;
int		g_q_length;
t_graph	*g_Q[1500];

struct s_list
{
	t_list	*prev;
	t_list	*next;
	int		vert;
};

struct s_graph
{
	int		idx;
	bool	visited;
	t_graph	*pred;
};

int		compare_int(t_list *a, t_list *b)
{
	if (a->vert > b->vert)
		return 1;
	else if (a->vert == b->vert)
		return 0;
	else
		return -1;
}

void	insert_list(t_list *vert_head[], int temp_ancestor, int temp_decendent, int (*comp)(t_list *, t_list*))
{
	t_list *to_insert = (t_list *)malloc(sizeof(t_list));
	t_list *idx = vert_head[temp_ancestor];

	to_insert->vert = temp_decendent;

	// 우선 idx->next가 널이 아닐 때 값 비교 가능하므로 while 조건으로 넣음
	while (idx->next != NULL)
	{
		// 넣으려는 값이 넣으려는 자리 다음에 있는 값보다 크면 정렬 안 되어 있으므로 다음 인덱스로 넘어간다
		if (comp(to_insert, idx->next) == 1)
			idx = idx->next;
		// 넣으려는 값과 비교하는 값이 같으면 중복된 값이므로 함수 호출 종료
		else if (comp(to_insert, idx->next) == 0)
			return ;
		// 넣으려는 값이 제 위치인 경우에 while 문 탈출
		else
			break ;
	}
	to_insert->prev = idx;
	to_insert->next = idx->next;
	if (idx->next != NULL)
		idx->next->prev = to_insert; // idx->next != NULL일 때만
	idx->next = to_insert;

}

void	enque(t_graph *Q[], t_graph *elem)
{
	Q[g_q_tail] = elem;

	if (g_q_tail == g_q_length)
		g_q_tail = 0;
	else
		g_q_tail++;
}

t_graph	*deque(t_graph *Q[])
{
	t_graph *ret = Q[g_q_head];

	if (g_q_head == g_q_length)
		g_q_head = 0;
	else
		g_q_head++;
	return (ret);
}

void	BFS(int N, int V, t_graph *graph[], t_list *vert_head)
{
	for (int i = 1; i <= N; i++)
	{
		graph[i]->pred = NULL;
		graph[i]->visited = false;
	}

	graph[V]->visited = true;
	enque(g_Q, graph[V]);
	while (g_q_head != g_q_tail)
	{
		t_graph *temp = deque(g_Q);
		//////////////////////////////////////////////////////////////여기 하다 말았음.
		///////////////////// 인접배열 조건 비교하는 조건문 만들어야 함.
		/////////////////// 연결 리스트라서 단순 for문은 ㄴㄴ
	}

	V--;
	vert_head++;
}

int		main()
{
	// 배열의 인덱스 i 요소가 각 정점 i에 대한 연결 리스트의 head 포인터
	t_list *vert_head[1001];
	for (int i = 1; i <= 1000; i++)
	{
		// 보초(sentinel) 역할 하는 더미 요소 insert
		vert_head[i] = (t_list *)malloc(sizeof(t_list));
		vert_head[i]->prev = NULL;
		vert_head[i]->next = NULL;
	}

	int N, M, V;
	scanf("%d %d %d", &N, &M, &V);

	// 그래프의 정점들을 담는 구조체
	t_graph *graph[1001];
	g_q_length = 1001;
	// 없어도 되는데 테스트할 때는 필요
	for (int i = 1; i <= 1000; i++)
	{
		graph[i] = NULL;
	}



	// ancestor에 decendent의 predecessor vertex를 할당한다.
	int temp_ancestor, temp_decendent;
	for (int i = 1; i <= M; i++)
	{
		scanf("%d %d", &temp_ancestor, &temp_decendent);
		// 양방향 간선이므로 인접리스트에 양쪽 모두 넣어준다.
		insert_list(vert_head, temp_ancestor, temp_decendent, &compare_int);
		insert_list(vert_head, temp_decendent, temp_ancestor, &compare_int);
		graph[temp_ancestor] = (t_graph *)malloc(sizeof(t_graph));
		graph[temp_decendent] = (t_graph *)malloc(sizeof(t_graph));

		graph[temp_ancestor]->idx = temp_ancestor;
		graph[temp_decendent]->idx = temp_decendent;
		graph[temp_ancestor]->visited = false;
		graph[temp_decendent]->visited = false;
	}




	printf("===인접 리스트에 올바른 값이 들어가있는지 확인 ===\n");
	for (int i = 1; i <= M; i++)
	{
		t_list *idx = vert_head[i];
		while (idx->next != NULL)
		{
			printf("%d %d\n", i, idx->next->vert);
			idx = idx->next;
		}
	}
	printf("\n");
	printf("===인접 리스트에서 체크되었어야 할 정점들이 제대로 있는지 확인===\n");
	for (int i = 1; i <= 1000; i++)
	{
		if (graph[i] != NULL)
			printf("%d inserted\n", i);
	}
	printf("\n");
	printf("========큐 연산 제대로 되는지 확인=======\n");

	enque(g_Q, graph[1]);
	enque(g_Q, graph[2]);
	enque(g_Q, graph[4]);
	enque(g_Q, graph[3]);

	printf("first deque = %d\n", deque(g_Q)->idx);
	printf("second deque = %d\n", deque(g_Q)->idx);
	printf("third deque = %d\n", deque(g_Q)->idx);
	printf("fourth deque = %d\n", deque(g_Q)->idx);


}