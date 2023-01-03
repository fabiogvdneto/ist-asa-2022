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

        /**
         * Links subset u with subset v.
         * 
         * Time Complexity: O(1).
         */
        void Link(int u, int v) {
            if (ranks[u] > ranks[v]) {
                parents[v] = u;
            } else {
                parents[u] = v;

                if (ranks[u] == ranks[v]) {
                    ranks[v]++;
                }
            }
        }

    public:
        DisjointSet(int size) {
            parents = new int[size];
            ranks = new int[size];
        }

        ~DisjointSet() {
            delete[] parents;
            delete[] ranks;

            parents = nullptr;
            ranks = nullptr;
        }

        /**
         * Makes a new set, being u the only element.
         * 
         * Time Complexity: O(1).
         */
        void MakeSet(int u) {
            parents[u] = u;
            ranks[u] = 0;
        }

        /**
         * Returns pointer to the root of the subset where u belongs.
         * 
         * Uses Path Compression.
         * 
         * Time Complexity:
         * - Worst Case: O(V).
         * - Best Case: O(1).
         * - Average: O(alpha(V)).
         */
        int FindSet(int u) {
            return (u == parents[u]) ? u : (parents[u] = FindSet(parents[u]));
        }

        /**
         * Performs the union of two subsets:
         * 1. Finds subsets of u and v.
         * 2. If subsets are the same, returns false with no side effect.
         * 3. Otherwise, both subsets are linked, and true is returned.
         * 
         * Uses Union by Rank (when linking).
         * 
         * Time Complexity:
         * - Worst Case: O(V).
         * - Best Case: O(1).
         * - Average: O(alpha(V)).
         */
        bool Union(int u, int v) {
            if ((u = FindSet(u)) == (v = FindSet(v))) return false;
            
            Link(u, v);
            return true;
        }
};

/* Graph */

typedef struct { int u, v, w; } Edge;

int n_vertices;
int n_edges;
Edge *edges;

/* Kruskal */

/**
 * Applies Kruskal Algorithm to the graph to create a maximum spanning tree (MaST).
 * Returns the sum of the weights of the edges that are safe to the MST.
 * 
 * Time Complexity: O(E log(E)).
 */
int kruskal(void) {
    // Initialization (Sort): O(E log(E)).
    
    sort(edges, edges+n_edges, [](const Edge& a, const Edge& b) {
        return (a.w > b.w);
    });

    DisjointSet set(n_vertices);

    // MakeSet Operations: O(V).

    for (int u = 0; (u < n_vertices); u++) { set.MakeSet(u); }
    
    int result = 0;
    int count = 0;

    // Union (and FindSet) Operations: O(E alpha(V)).

    for (int i = 0; (i < n_edges); i++) {
        if (!set.Union(edges[i].u, edges[i].v)) continue;

        result += edges[i].w; // i is a safe edge to the MST
        
        if (++count == n_vertices-1) break;
    }

    return result;
}

/* Solver */

int main(void) {
    assert(scanf("%d %d", &n_vertices, &n_edges) == 2);
    
    assert(n_vertices >= 1);
    assert(n_edges >= 0);

    edges = new Edge[n_edges];

    // Scanning: O(E).
    for (int i = 0; (i < n_edges); i++) {
        assert(scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w) == 3);

        assert(edges[i].u > 0);
        assert(edges[i].u <= n_vertices);

        assert(edges[i].v > 0);
        assert(edges[i].v <= n_vertices);

        assert(edges[i].w >= 0);

        // make it compatible with disjoint set indexing (starting at 0).
        edges[i].u--;
        edges[i].v--;
    }

    printf("%d\n", kruskal());

    delete[] edges;

    return EXIT_SUCCESS;
}
