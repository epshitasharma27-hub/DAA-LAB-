// UNDIRECT DJIKSTRA 
#include <stdio.h>
#define V 9
#define INF 99999
int main()
{
    int g[V][V] = {
        {0,4,0,0,8,0,0,0,0},
        {4,0,8,0,11,0,0,0,0},
        {0,8,0,7,0,0,4,0,2},
        {0,0,7,0,0,0,14,9,0},
        {8,11,0,0,0,1,0,0,7},
        {0,0,0,0,1,0,2,0,6},
        {0,0,4,14,0,2,0,10,0},
        {0,0,0,9,0,0,10,0,0},
        {0,0,2,0,7,6,0,0,0}
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
            if(g[u][j] && !vis[j] &&
               d[u] + g[u][j] < d[j])
                d[j] = d[u] + g[u][j];
    }
    printf("Shortest distances from vertex 0:\n");
    for(i = 0; i < V; i++)
        printf("Vertex %d = %d\n", i, d[i]);
    return 0;
}
