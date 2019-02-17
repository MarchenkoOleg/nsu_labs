#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

void print_path(int * pathBack, int from, int to) {
	int current = to;
	while (current != from) {
		if (pathBack[current] == -1) {
			printf("no path");
			return;
		}

		if (pathBack[current] == -2) {
			printf("overflow");
			return;
		} else {
			current = pathBack[current];
		}
	}

	for (int i = to; i != from; i = pathBack[i]) {
		printf("%d ", i + 1);
	}
	printf("%d", from + 1);
}

int main() {
	int N;
	scanf("%d", &N);

	if (N < 0 || N > 5000) {
		printf("bad number of vertices");
		return 0;
	}

	int S, F;
	scanf("%d %d", &S, &F);
	if (S <= 0 || F <= 0 || S > N || F > N)
	{
		printf("bad vertex");
		return 0;
	}
	S--;
	F--;

	int M;
	scanf("%d", &M);
	if (M < 0 || M > N*(N - 1) / 2) {
		printf("bad number of edges");
		return 0;
	}

	Graph * graph = graph_create(N);

	int from, to, length;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &from, &to, &length);
		if (from <= 0 || to <= 0 || from > N || to > N) {
			printf("bad vertex");
			return 0;
		}
		if (length < 0) {
			printf("bad length");
			return 0;
		}

		graph_set_edge_length(graph, from - 1, to - 1, length);
	}

	Edge * lengths = malloc(sizeof(Edge)*N);
	int * path = malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++) path[i] = -1;

	graph_dijkstra_run(graph, S, path, lengths);

	for (int i = 0; i < N; i++)	{
		printf("%s ", edge_to_string(lengths[i]));
	}

	printf("\n");
	print_path(path, S, F);
	graph_free(graph);
}