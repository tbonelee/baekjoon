#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_list t_list;
typedef struct s_graph t_graph;

int		g_q_head;
int		g_q_tail;
int		g_q_length;
t_graph	*g_Q[3000];

struct s_list
{
	t_list	*prev;
	t_list	*next;
	int		vert;
};

struct s_graph
{
	int		num;
	bool	visited;
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

void	insert_list(t_list vert_head[], int temp_ancestor, int temp_decendent, int (*comp)(t_list *, t_list*))
{
	t_list *to_insert = (t_list *)malloc(sizeof(t_list));
	t_list *idx = &vert_head[temp_ancestor];

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

	if (g_q_tail == g_q_length - 1)
		g_q_tail = 0;
	else
		g_q_tail++;
}

t_graph	*deque(t_graph *Q[])
{
	t_graph *ret = Q[g_q_head];

	if (g_q_head == g_q_length - 1)
		g_q_head = 0;
	else
		g_q_head++;
	return (ret);
}

void	BFS(int V, t_graph graph[], t_list vert_head[])
{
	for (int i = 1; i <= 2000; i++)
	{
		graph[i].visited = false;
	}
	graph[V].visited = true;
	enque(g_Q, &graph[V]);
	printf("%d ", graph[V].num);
	// while문에 넣은 조건은 큐에 아무 것도 남지 않았음을 의미
	while (g_q_head != g_q_tail)
	{
		t_graph *temp = deque(g_Q);
		t_list	*idx = &vert_head[temp->num];
		while (idx->next != NULL)
		{
			if (graph[idx->next->vert].visited == false)
			{
				graph[idx->next->vert].visited = true;
				enque(g_Q, &graph[idx->next->vert]);
				printf("%d ", idx->next->vert);
			}
			idx = idx->next;
		}
	}
	printf("\n");
}


void	DFS_visit(int num_of_vert, t_graph graph[], t_list vert_head[])
{
	graph[num_of_vert].visited = true;

	t_list *idx = &vert_head[num_of_vert];
	while (idx->next != NULL)
	{
		if (graph[idx->next->vert].visited == false)
		{
			printf("%d ", idx->next->vert);
			DFS_visit(idx->next->vert, graph, vert_head);
		}
		idx = idx->next;
	}
}

void	DFS(int V, t_graph graph[], t_list vert_head[])
{
	for (int i = 1; i <= 2000; i++)
	{
		graph[i].visited = false;
	}
	graph[V].visited = true;
	printf("%d ", graph[V].num);

	t_list *idx = &vert_head[V];
	while (idx->next != NULL)
	{
		if (graph[idx->next->vert].visited == false)
		{
			printf("%d ", idx->next->vert);
			DFS_visit(idx->next->vert, graph, vert_head);
		}
		idx = idx->next;
	}
	printf("\n");
}

void	free_vert_head(t_list vert_head[])
{
	for (int i = 1; i <= 2000; i++)
	{
		t_list *temp;
		temp = &vert_head[i];
		while (temp->next != NULL)
		{
			temp = temp->next;
			if (temp->prev != &vert_head[i])
				free(temp->prev);
		}
	}
}

int		main()
{
	t_list vert_head[2001];
	for (int i = 1; i <= 2000; i++)
	{
		vert_head[i].prev = NULL;
		vert_head[i].next = NULL;
	}


	int N, M, V;
	scanf("%d %d %d", &N, &M, &V);
	t_graph graph[2001];
	g_q_length = 3000;

	int temp_ancestor, temp_decendent;
	for (int i = 1; i <= M; i++)
	{
		scanf("%d %d", &temp_ancestor, &temp_decendent);

		insert_list(vert_head, temp_ancestor, temp_decendent, &compare_int);
		insert_list(vert_head, temp_decendent, temp_ancestor, &compare_int);

		graph[temp_ancestor].num = temp_ancestor;
		graph[temp_decendent].num = temp_decendent;
	}


	DFS(V, graph, vert_head);

	BFS(V, graph, vert_head);

	free_vert_head(vert_head);


}