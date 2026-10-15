// DIRECTED GRAPH DJIKSTRA
#include <stdio.h>
#define V 5
#define INF 99999
int main()
{
    int g[V][V] = {
        {0, 10, 5, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 3, 0, 9, 2},
        {0, 0, 0, 0, 0},
        {2, 0, 0, 6, 0}
    };
    int d[V], vis[V] = {0};
    int i, j, u, min;
    for(i = 0; i < V; i++)
        d[i] = INF;
    d[0] = 0;
    for(i = 0; i < V; i++)
    {
        min = INF;
        u = -1;
        for(j = 0; j < V; j++)
            if(!vis[j] && d[j] < min)
                min = d[j], u = j;
        if(u == -1)
            break;
        vis[u] = 1;
        for(j = 0; j < V; j++)
            if(g[u][j] != 0 && !vis[j] &&
               d[u] + g[u][j] < d[j])
                d[j] = d[u] + g[u][j];
    }
    printf("Shortest distances from A:\n");
    for(i = 0; i < V; i++)
        printf("%c = %d\n", 'A' + i, d[i]);
    return 0;
}
