#include <iostream>
#include <fstream>
using namespace std;

class Edge
{
public:
    int v1, v2, wt;
    Edge()
    {
        v1 = 0;
        v2 = 0;
        wt = 0;
    }
};

class Graph
{
public:
    Edge e[100];
    int w[100][100];
    int nov, noe;
    Graph()
    {
        nov = 0;
        noe = 0;
    }
    void readGraph()
    {
        FILE *fp;
        fp = fopen("graph.txt", "r");
        fscanf(fp, "%d", &nov);
        for (int i = 0; i < nov; i++)
        {
            for (int j = 0; j < nov; j++)
            {
                fscanf(fp, "%d", &w[i][j]);
            }
        }
        fclose(fp);
        // Converting it to graph:
        for (int i = 0; i < nov; i++)
        {
            for (int j = 0; j < nov; j++)
            {
                if (j > i && w[i][j] != 0)
                {
                    e[noe].v1 = i;
                    e[noe].v2 = j;
                    e[noe].wt = w[i][j];
                    noe++;
                }
            }
        }
    }
    void dispGraph()
    {

        for (int i = 0; i < noe; i++)
        {

            printf("Vertices : [ %d and %d ]\t| Weight : %d\n", e[i].v1, e[i].v2, e[i].wt);
        }
    }
};

void printMat(int ar[100][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }
}

int minKey(int sptSet[], int dist[], int n)
{
    int min = 9999, minInd;
    for (int i = 0; i < n; i++)
    {
        if (dist[i] < min && sptSet[i] == 0)
        {
            min = dist[i];
            minInd = i;
        }
    }
    return minInd;
}

void showPath(int dest, int pred[])
{
    if (dest == -1)
        return;
    else
    {
        showPath(pred[dest], pred);
        printf("%4d", dest);
    }
}

void Dijkstra(Graph G)
{
    int dist[G.nov];
    int pred[G.nov];
    int sptSet[G.nov];
    for (int i = 0; i < G.nov; i++)
    {
        dist[i] = 9999;
        sptSet[i] = 0;
    }
    dist[0] = 0;
    pred[0] = -1;
    for (int i = 0; i < G.nov - 1; i++)
    {
        int u = minKey(sptSet, dist, G.nov);
        sptSet[u] = 1;

        for (int v = 0; v < G.nov; v++)
        {
            if (G.w[u][v] != 0 && sptSet[v] == 0 && G.w[u][v] < dist[v])
            {
                pred[v] = u;
                dist[v] = G.w[u][v];
            }
        }
    }

    for (int i = 1; i < G.nov; i++)
    {
        printf("Path from 0 to %d ===", i);
        showPath(i, pred);
        // printf("\n");
        printf("\tCost=%d\n", dist[i]);
    }
}

int main()
{
    Graph G;
    G.readGraph();
    cout << "ORINGINAL GRAPH IS :=>" << endl;
    G.dispGraph();
    cout << endl;
    Dijkstra(G);
    return 0;
}