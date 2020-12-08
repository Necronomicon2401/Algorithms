#include<vector>
#include<iostream>
#include <queue>

using namespace std;

const int INF = 1e9 + 7;
const int N = 1000;

vector<pair<int, int>> graph[N];
bool used[1000000];
long cost[N][N];

int main()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            graph[i].push_back({ rand(), j });
        }
        graph[i].push_back({ 0, i });
    }

    int mst_weight = 0;     

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push({ 0, 0 });   

    while (!q.empty()) {
        pair<int, int> c = q.top();
        q.pop();

        int dst = c.first, v = c.second;

        if (used[v]) {     
            continue;
        }

        used[v] = true;
        mst_weight += dst;

        for (pair<int, int> e : graph[v]) {
            int u = e.first, len_vu = e.second;

            if (!used[u]) {
                q.push({ len_vu, u });
            }
        }
    }

    cout << "Minimum spanning tree weight: " << mst_weight << endl;
}