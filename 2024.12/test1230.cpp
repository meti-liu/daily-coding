#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    Edge road[] = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3},
        {1, 3, 8}, {1, 4, 5}, {2, 4, 7},
        {3, 4, 9}
    };

    int e = 7;
    sort(road, road + e, [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    for (int i = 0; i < e; i++) {
        cout << "Edge: " << road[i].u << "-" << road[i].v << " Weight: " << road[i].w << endl;
    }

    return 0;
}

