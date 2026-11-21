#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
	int u, v, w, id;
} Edge;

int compare(const void *a, const void *b) {
	Edge *e1 = (Edge *)a;
	Edge *e2 = (Edge *)b;
	if (e1->w != e2->w) {
		return e1->w - e2->w;
	}
	return e1->id - e2->id;
}

void kruskalMST(int **cost, int V) {
	int max_edges = V * (V - 1) / 2;
	Edge *edges = (Edge *)malloc(max_edges * sizeof(Edge));
	int edge_count = 0;

	for (int i = 0; i < V; i++) {
		for (int j = i + 1; j < V; j++) {
			if (cost[i][j] != 9999) {
				edges[edge_count].u = i;
				edges[edge_count].v = j;
				edges[edge_count].w = cost[i][j];
				edges[edge_count].id = edge_count;
				edge_count++;
			}
		}
	}

	qsort(edges, edge_count, sizeof(Edge), compare);

	int *parent = (int *)malloc(V * sizeof(int));
	for (int i = 0; i < V; i++) {
		parent[i] = i;
	}

	int min_cost = 0;
	int edges_printed = 0;

	for (int i = 0; i < edge_count; i++) {
		int u = edges[i].u;
		int v = edges[i].v;
		
		int root_u = u;
		while (parent[root_u] != root_u) {
			root_u = parent[root_u];
		}
		
		int root_v = v;
		while (parent[root_v] != root_v) {
			root_v = parent[root_v];
		}

		if (root_u != root_v) {
			printf("Edge %d:(%d, %d) cost:%d\n", edges_printed, u, v, edges[i].w);
			min_cost += edges[i].w;
			parent[root_u] = root_v;
			edges_printed++;
			if (edges_printed == V - 1) {
				break;
			}
		}
	}

	printf("Minimum cost= %d\n", min_cost);

	free(edges);
	free(parent);
}


int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}