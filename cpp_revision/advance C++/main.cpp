#include <bits/stdc++.h>
using namespace std;

typedef long long captype;
static const captype flowlimit = 1LL << 60;

struct Dinic {
    static const int maxn = 5000, maxm = 30000;
    struct edge {
        int v, next;
        captype c;
        bool isrev;
    } e[maxm << 1];
    
    int g[maxn], next[maxn], q[maxn], d[maxn], n = 0, S = 0, T = 0, top = 0;
    captype maxflow = 0;
    void init(int nn, int SS, int TT) {
        n = nn, S = SS, T = TT, top = 0, maxflow = 0;
        memset(g, -1, sizeof(g[0]) * n);
    }
    inline int addedge(int u, int v, captype c) {
        e[top] = (edge ) { v, g[u], c, 0 };
        g[u] = top++;
        e[top] = (edge ) { u, g[v], 0, 1 }; //undirected: change 0 to c
        g[v] = top++;
        return top-2;
    }

    bool dinicBFS() {
        int qh = 0, qt = 1;
        memset(d, -1, sizeof(d[0]) * n);
        d[q[0] = S] = 0;
        while (qh < qt) {
            int v = q[qh++];
            for (int p = g[v]; p != -1; p = e[p].next) {
                if (e[p].c > 0 && d[e[p].v] == -1) {
                    d[e[p].v] = d[v] + 1;
                    q[qt++] = e[p].v;
                }
            }
        }
        return d[T] >= 0;
    }
    captype dinicDFS(int v, captype cap) {
        if (v == T)	return cap;
        captype used = 0;
        for (int p = next[v]; p != -1 && cap > used; p = e[p].next) {
            next[v] = p;
            if (e[p].c > 0 && d[e[p].v] == d[v] + 1) {
                captype inc = dinicDFS(e[p].v, min(cap - used, e[p].c));
                used += inc;
                e[p].c -= inc;
                e[p ^ 1].c += inc;
            }
        }
        return used;
    }
    captype dinic() {
        maxflow = 0;
        while (dinicBFS()) {
            memcpy(next, g, sizeof(g[0]) * n);
            maxflow += dinicDFS(S, flowlimit);
        }
        return maxflow;
    }
} dinic;

int main(void) {

    int n, m;
    scanf("%d%d", &n, &m);
    dinic.init(n, 0, n - 1);
    int x = 0, y = 0, c = 0;
    for(int i = 0; i < m; ++i) {
        scanf("%d%d%d", &x, &y, &c);
        dinic.addedge(x, y, c);
    }
    cout << dinic.dinic() << endl;

    return 0;
}
