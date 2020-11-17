#include <iostream> 
#include <queue> 
#define V 5 

using namespace std;

bool isBipartite(int M[][V], int start)
{

	int arr[V]; // массив цветов вершин
	for (int i = 0; i < V; ++i)
		arr[i] = -1; // ставим -1 для неокрашенных вершин 


	arr[start] = 1;
	queue <int> q;
	q.push(start);

	while (!q.empty())
	{

		int u = q.front();
		q.pop();

		// Вернуть false, если есть петля 
		if (M[u][u] == 1)
			return false;

		for (int v = 0; v < V; ++v)
		{
			if (M[u][v] == 1 && arr[v] == -1)
			{
				arr[v] = 1 - arr[u]; // назначение другого цвета смежной вершине
				q.push(v);
			}

			// Проверка, если смежная вершина уже покрашена и не имеют ли вершины одинаковый цвет, что приводит к нечетному циклу -
			// не двудольному графу 
			else if (M[u][v] == 1 && arr[v] == arr[u])
				return false;
		}
	}
	return true;
}

int main()
{
	int M[][V] = {  { 0, 0, 1, 1, 1},
					{ 0, 0, 1, 1, 1},
					{ 1, 1, 0, 0, 0},
					{ 1, 1, 0, 0, 0},
					{ 1, 1, 0, 0, 0} // простой двудольный граф; если проверить на нет, то вместо любого одного нолика сделать единицу :)
	};

	isBipartite(M, 0) ? cout << "Yes" : cout << "No";
	return 0;
}