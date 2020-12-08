#include <iostream>
#include <vector>
#include <set>
#include <algorithm> 

using namespace std;

int min(int a, int b) {
	if (a < b)
		return a;
	else return b;
}

int max(int a, int b) {
	if (a > b)
		return a;
	else return b;
}


struct road
{
	int start, end, len;
	bool operator<(const road& other) {
		return len > other.len; // для сортировки по убыванию
	}
};

int main()
{
	int n, k;
	cout << "Enter number of houses: ";
	cin >> n;
	cout << "Enter numbers of roads: ";
	cin >> k;

	vector<road> roads;
	for (int i = 0; i < k; i++) {
		road r;
		do {
			r.start = rand() % n + 0;
			r.end = rand() % n + 0;
		} while (r.start == r.end);
		r.len = rand() % 1000 + 1;
		roads.push_back(r);
	}

	sort(roads.begin(), roads.end());
	// Все дороги
	//for (road r : roads) {
	//	cout << r.start << " " << r.end << " " << r.len << endl;
	//}

	int** mtrx = new int* [n];
	for (int i = 0; i < n; i++)
	{
		mtrx[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			mtrx[i][j] = 1111;
		}
	}
	
	for (road r : roads) {
		mtrx[r.start][r.end] = r.len;
		mtrx[r.end][r.start] = r.len;
	}

	// Матрица смежности
	//for (int j = 0; j < n; j++) {
	//	for (int i = 0; i < n; i++) {
	//		cout << mtrx[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	for (int k = 0; k < n; k++) {
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++) {
				mtrx[i][j] = min(mtrx[i][j], mtrx[i][k] + mtrx[k][j]);
			}
		}
	}

	int *e = new int[n];
	for (int i = 0; i < n; i++) {
		e[i] = 0;
	}
	// Нахождение эксцентриситета
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			e[i] = max(e[i], mtrx[i][j]);
		}
	}
	int rad = INT_MAX, diam = 0;
	// Нахождение диаметра и радиуса
	for (int i = 0; i < n; i++) {
		rad = min(rad, e[i]);
		diam = max(diam, e[i]);
	}
	// Нахождение центра
	set <int> c;
	for (int i = 0; i < n; i++) {
		if (e[i] == rad) {
			c.insert(i);
		}
	}

	cout << *(c.begin()) << '\n';

	system("pause");
	return 0;
}