#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <algorithm>

using namespace std;

/* Disjoint Set */

class DisjointSet {
    private:
        int *parents;
        int *ranks;

    public:
        DisjointSet(int size) {
            parents = new int[size];
            ranks = new int[size];

            for (int u = 0; (u < size); u++) {
                parents[u] = u;
                ranks[u] = 0;
            }
        }

        ~DisjointSet() {
            delete[] parents;
            delete[] ranks;

            parents = nullptr;
            ranks = nullptr;
        }

        int find(int u) {
            int x = parents[u];

            return (x == u) ? x : (parents[u] = find(x));
        }

        void unite(int u, int v) {
            link(find(u), find(v));
        }

        void link(int x, int y) {
            if (ranks[x] > ranks[y]) {
                parents[y] = x;
            } else {
                parents[x] = y;

                if (ranks[x] == ranks[y]) {
                    ranks[y]++;
                }
            }
        }
};

/* Graph */

typedef struct { int u, v, w; } Edge;

int n_vertices;
int n_edges;
Edge *edges;

/* Kruskal Algorithm */

bool is_heavier(Edge e1, Edge e2) { return (e1.w > e2.w); }

int kruskal() {
    sort(edges, edges+n_edges, is_heavier);

    DisjointSet set(n_vertices);
    
    int result = 0;
    int count = 0;

    for (int i = 0; (i < n_edges); i++) {
        Edge edge = edges[i];

        int x = set.find(edge.u);
        int y = set.find(edge.v);

        if (x == y) continue;

        set.link(x, y);
        result += edge.w;

        if (++count == n_vertices-1) break;
    }

    return result;
}

/* Solver */

int main(void) {
    assert(scanf("%d%d", &n_vertices, &n_edges) == 2);
    assert(n_vertices >= 1);
    assert(n_edges >= 0);

    edges = new Edge[n_edges];

    for (int i = 0; (i < n_edges); i++) {
        assert(scanf("%d", &edges[i].u) == 1);
        assert(edges[i].u > 0);
        assert(edges[i].u <= n_vertices);

        assert(scanf("%d", &edges[i].v) == 1);
        assert(edges[i].v > 0);
        assert(edges[i].v <= n_vertices);

        assert(scanf("%d", &edges[i].w) == 1);
        assert(edges[i].w >= 0);

        edges[i].u--;
        edges[i].v--;
    }

    printf("%d\n", kruskal());

    delete[] edges;

    return EXIT_SUCCESS;
}
