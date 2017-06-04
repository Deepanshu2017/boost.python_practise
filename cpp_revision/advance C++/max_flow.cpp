#include <bits/stdc++.h>
using namespace std;
const long long inf = 1LL << 62;
int N = 0, M = 0;
int source = 0, sink = 0;
int top = 0;

struct Edge {
	int vertex, next;
	long long capacity;
};
struct Edge e[1 << 17];
int g[1 << 17], d[1 << 17], q[1 << 17], child[1 << 17];

bool init(void) {
	memset(g, -1, sizeof(g));
	memset(d, -1, sizeof(d));
	memset(q, 0, sizeof(q));
	memset(child, 0, sizeof(child));
	return true;
}

bool addEdge(int x, int y, long long capacity) {
	e[top] = (Edge) {y, g[x], capacity};
	g[x] = top++;	
	e[top] = (Edge) {x, g[y], capacity};
	g[y] = top++;
	return true;
}

bool dinic_bfs() {
	memset(d, -1, sizeof(d));
	d[q[0] = source] = 0;
	int qh = 0, qt = 1;
	while(qh < qt) {
		int v = q[qh++];
		for(int p = g[v]; p != -1; p = e[p].next) {
			if(e[p].capacity > 0 && d[e[p].vertex] == -1) {
				d[e[p].vertex] = d[v] + 1;
				q[qt++] = e[p].vertex;				
			}
		}
	}
	return d[sink] >= 0;
}

long long dinic_dfs(int v, long long capacity) {
	if(v == sink)
		return capacity;
	long long used = 0;
	for(int p = child[v]; p != -1 && capacity > used; p = e[p].next) {
		child[v] = p;
		if(e[p].capacity > 0 && d[e[p].vertex] == d[v] + 1) {
			long long cap = 0;
			cap += dinic_dfs(e[p].vertex, min(capacity - used, e[p].capacity));
			used += cap;
			e[p].capacity -= cap;
			e[p ^ 1].capacity += cap;
		}
	}
	return used;
}

long long dinic(void) {
	long long max_flow = 0;
	while(dinic_bfs()) {
		memcpy(child, g, sizeof(g));
		max_flow += dinic_dfs(source, inf);
	}
	return max_flow;
}

int main(void) {
	
	init();
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; ++i) {
		int x = 0, y = 0;
		long long w = 0;
		scanf("%d %d %lld", &x, &y, &w);
		addEdge(x - 1, y - 1, w);
	}

	source = 0;
   	sink = N - 1;
	cout << dinic() << "\n";

	return 0;
}
