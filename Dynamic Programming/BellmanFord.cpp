#include <iostream>
#include <fstream>
using namespace std;
int n;
int G[100][100];
void readGraph()
{
    FILE *fp;
    fp = fopen("weighted-digraph.txt", "r");
    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(fp, "%d", &G[i][j]);
        }
    }
    fclose(fp);
}
// int n = 3;
// int G[3][3] = {{0, 10, 0},
//                {0, 0, 10},
//                {0, -30, 0}};

void Relax(int u, int v, int dist[])
{
    if (dist[u] != 999 && dist[u] + G[u][v] < dist[v])
    {
        dist[v] = dist[u] + G[u][v];
    }
}

void printAr(int ar[], int n)
{
    for (int u = 0; u < n; u++)
    {
        printf("Vertex:%d\tDist:%d\n", u, ar[u]);
    }
}
void printArray(int ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
}
void BellmanFord(int start)
{
    int dist[n];
    for (int i = 0; i < n; i++)
    {
        dist[i] = 999;
    }

    dist[start] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        printArray(dist, n);
        for (int u = 0; u < n; u++)
        {
            for (int v = 0; v < n; v++)
            {
                if (G[u][v] != 0)
                    Relax(u, v, dist);
            }
        }
    }
    // Check for -ve weight cycle:
    for (int u = 0; u < n; u++)
    {
        for (int v = 0; v < n; v++)
        {
            if (G[u][v] != 0)
            {
                if (dist[u] + G[u][v] < dist[v])
                {
                    cout << "The graph contains negative edge cycle" << endl;
                    return;
                }
            }
        }
    }
    printAr(dist, n);
    return;
}

main()
{
    readGraph();
    BellmanFord(0);
    return 0;
}