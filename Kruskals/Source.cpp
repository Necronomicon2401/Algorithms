#include <vector>
#include <algorithm> 
#include <iostream>

using namespace std;

const int N = 1000;

long p[10000000];
long rk[10000000];

void init_dsu() {
    for (int i = 0; i < 100000; i++) {
        p[i] = i;
        rk[i] = 1;
    }
}

int get_root(int v) {
    if (p[v] == v) {
        return v;
    }
    else {
        return p[v] = get_root(p[v]); 
    }
}

bool merge(int a, int b) {
    int ra = get_root(a), rb = get_root(b);

    if (ra == rb) {
        return false;
    }
    else {
        if (rk[ra] < rk[rb]) {
            p[ra] = rb;
        }
        else if (rk[rb] < rk[ra]) {
            p[rb] = ra;
        }
        else {
            p[ra] = rb;
            rk[rb]++;
        }

        return true;
    }
}

struct edge {
    int start, end, weight;

    bool operator<(const edge& other) {
        return weight < other.weight;
    }
};

int main() {
    vector<edge> edges;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            edge e;
            e.start = i;
            e.end = j;
            e.weight = rand();
            edges.push_back(e);
        }
    }

    sort(edges.begin(), edges.end());

    int mst_weight = 0;

    init_dsu();

    for (edge e : edges) {
        if (merge(e.start, e.end)) {      
            mst_weight += e.weight;    
        }
    }

    cout << "Minimum spanning tree weight: " << mst_weight << endl;
}