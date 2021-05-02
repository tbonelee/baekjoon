// #include <iostream>
// #include <cstdio>

// #define left(nod) (nod * 2)
// #define right(nod) (nod * 2 + 1)
// #define parent(nod) (nod / 2)

// using namespace std;

// void insert_heap(int temp);
// void delete_heap(void);

// int heap[100001];
// int leng = 0;

// int main()
// {
// 	int n; cin >> n;
// 	int temp;
// 	for (int i = 0; i < n; i++)
// 	{
// 		scanf("%d", &temp);
// 		if (temp > 0)
// 			insert_heap(temp);
// 		else
// 		{
// 			if (leng == 0)
// 				printf("0\n");
// 			else
// 				delete_heap();
// 		}
// 	}
// }

// void swap(int &a, int &b)
// {
// 	int temp = a;
// 	a = b;
// 	b = temp;
// }

// void insert_heap(int temp)
// {
// 	heap[leng++ + 1] = temp;
// 	for (int i = leng; parent(i) >= 1; i = parent(i))
// 	{
// 		if (heap[i] < heap[parent(i)])
// 			swap(heap[i], heap[parent(i)]);
// 		else
// 			break ;
// 	}
// }

// void delete_heap(void)
// {
// 	printf("%d\n", heap[1]);
// 	heap[1] = heap[leng--];

// 	int temp;
// 	for (int i = 1; left(i) <= leng; )
// 	{
// 		temp = i;
// 		if (heap[left(i)] < heap[temp])
// 			temp = left(i);
// 		if (right(i) <= leng && heap[right(i)] < heap[temp])
// 			temp = right(i);
// 		if (temp == i)
// 			break;
// 		else
// 		{
// 			swap(heap[i], heap[temp]);
// 			i = temp;
// 		}
// 	}
// }







#include <iostream>
#include <cstdio>
#include <queue>
#include <functional>

using namespace std;


int main()
{
	int n; cin >> n;
	int temp;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		if (temp > 0)
			pq.push(temp);
		else
		{
			if (pq.size() == 0)
				printf("0\n");
			else
			{
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
	}
}
