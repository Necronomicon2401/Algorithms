#include <iostream>
#define V 5

using namespace std;


bool use[100];
int component[100];

void dfs(int M[][V], int v, int comp_number)
{
	use[v] = true;
	component[v] = comp_number;

	for (int i = 0; i < V; i++) {
		if (M[v][i] == 1 && !use[i]) {
			dfs(M, i, comp_number);
		}
	}
}

int main()
{
	int comp_number = 0; // пор€дковый номер компоненты св€зности
	int M[][V] = {  { 0, 1, 0, 0, 0},
					{ 1, 0, 0, 0, 0},
					{ 0, 0, 0, 1, 0},
					{ 0, 0, 1, 0, 1},
					{ 0, 0, 0, 1, 0}
	};

	for (int i = 0; i < V; i++) {
		if (!use[i]) {
			dfs(M, i, comp_number);
			comp_number++;
		}
	}

	if (comp_number == 1) cout << "We can introduce all participants" << endl; // если у нас одна компонента св€зности, то мы можем всех перезнакомить
	else {
		cout << "We can't introduce all participants" << endl;
		int max = 0;
		int* arr = new int[comp_number - 1]; // создаем массив, в котором будем хранить количество вершин графа компоненты

		for (int i = 0; i < comp_number; i++) {
			arr[i] = 0;
		}

		for (int i = 0; i < V; i++) {
			arr[component[i]] += 1;
		}

		for (int i = 0; i < comp_number; i++) {
			if (max < arr[i]) max = arr[i];
		}

		cout << "Maximum number of participiants, that we can introduce to each other - " << max << endl;
	}

	system("pause");
	return 0;
}