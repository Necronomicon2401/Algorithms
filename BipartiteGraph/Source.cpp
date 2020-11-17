#include <iostream> 
#include <queue> 
#define V 5 

using namespace std;

bool isBipartite(int M[][V], int start)
{

	int arr[V]; // ������ ������ ������
	for (int i = 0; i < V; ++i)
		arr[i] = -1; // ������ -1 ��� ������������ ������ 


	arr[start] = 1;
	queue <int> q;
	q.push(start);

	while (!q.empty())
	{

		int u = q.front();
		q.pop();

		// ������� false, ���� ���� ����� 
		if (M[u][u] == 1)
			return false;

		for (int v = 0; v < V; ++v)
		{
			if (M[u][v] == 1 && arr[v] == -1)
			{
				arr[v] = 1 - arr[u]; // ���������� ������� ����� ������� �������
				q.push(v);
			}

			// ��������, ���� ������� ������� ��� ��������� � �� ����� �� ������� ���������� ����, ��� �������� � ��������� ����� -
			// �� ����������� ����� 
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
					{ 1, 1, 0, 0, 0} // ������� ���������� ����; ���� ��������� �� ���, �� ������ ������ ������ ������ ������� ������� :)
	};

	isBipartite(M, 0) ? cout << "Yes" : cout << "No";
	return 0;
}