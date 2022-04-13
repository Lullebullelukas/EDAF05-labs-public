#include <stdio.h>
#include <stdlib.h>

typedef struct Edge Edge;

struct Edge
{
    int u, v, w, size;
    Edge *parent;
};

Edge *find(Edge *v)
{
    Edge *p = v;
    while (p->parent != NULL)
    {
        p = p->parent;
    }
    while (v->parent != NULL)
    {
        Edge *w = v->parent;
        v->parent = p;
        v = w;
    }
    return p;
}

void _union(Edge *u, Edge *v)
{
    u = find(u);
    v = find(v);

    if (u->size < v->size)
    {
        u->parent = v;
        v->size = u->size + v->size;
    }
    else
    {
        v->parent = u;
        u->size = u->size + v->size;
    }
}

int kruskal(Edge *edges)
{
}

int comp(const void *e1, const void *e2)
{
    const Edge *ed1 = e1;
    const Edge *ed2 = e2;
    if (ed1->w < ed2->w)
    {
        return -1;
    }
    else if (ed1->w > ed2->w)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n, m;
    Edge edges[m];

    scanf("%d %d", &n, &m);
    Edge cringe = {1, 2, 1};

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        edges[i].parent = NULL;
        edges[i].size = 1;
    }

    qsort(edges, m, sizeof(Edge), comp);

    for (int i = 0; i < m; ++i)
    {
        printf("%d<->%d: %d \n", edges[i].u, edges[i].v, edges[i].w);
    }

    kruskal(edges);
}
