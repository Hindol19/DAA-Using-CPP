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
    Edge(int ver1, int ver2, int w)
    {
        v1 = ver1;
        v2 = ver2;
        wt = w;
    }
};
class Graph
{
public:
    int w[100][100];
    Edge e[100];
    int nov, noe;
    Graph()
    {
        nov = 0;
        noe = 0;
    }
    Graph(int v, int e)
    {
        nov = v;
        noe = e;
    }
    void readGraph()
    {
        FILE *fp;
        fp = fopen("graph.txt", "r");
        if (fp == NULL)
        {
            printf("File open failed\n");
            return;
        }
        fscanf(fp, "%d", &nov);
        int i, j;
        for (i = 0; i < nov; i++)
        {
            for (j = 0; j < nov; j++)
            {
                fscanf(fp, "%d", &w[i][j]);
            }
        }
        fclose(fp);

        // Transfering Adjacency Matrix to Edge List
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

    void DispGraph()
    {
        // cout << "GRAPH => " << endl;
        for (int i = 0; i < noe; i++)
        {
            printf("V1 = %d | V2 = %d | Weight = %d\n", e[i].v1, e[i].v2, e[i].wt);
        }
    }
};

int minKey(int key[], int mstSet[], int n)
{
    int min = 9999;
    int minInd;
    for (int i = 0; i < n; i++)
    {
        if (mstSet[i] == 0 && key[i] < min)
        {
            min = key[i];
            minInd = i;
        }
    }
    return minInd;
}
void printAr(int ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
}
Graph Prims(Graph G)
{
    int parent[G.nov];
    int key[G.nov];
    int mstSet[G.nov];

    // #### Initialization ####
    for (int i = 0; i < G.nov; i++)
    {
        key[i] = 9999;
        mstSet[i] = 0;
    }

    parent[0] = -1;
    key[0] = 0;
    // ########################

    for (int count = 0; count < G.nov - 1; count++)
    {
        int u = minKey(key, mstSet, G.nov);
        mstSet[u] = 1;

        for (int v = 0; v < G.noe; v++)
        {
            if (G.w[u][v] && mstSet[v] == false && G.w[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = G.w[u][v];
            }
        }
    }
    // printAr(key, G.nov);
    // printAr(parent, G.nov);

    // Converting this to a Graph Object:
    Graph MST;
    MST.nov = G.nov;
    MST.noe = G.nov - 1;
    for (int i = 1; i < MST.nov; i++)
    {
        // cout << i << endl;
        MST.e[i - 1].v1 = parent[i];
        MST.e[i - 1].v2 = i;
        MST.e[i - 1].wt = key[i];
    }

    return MST;
}

int main()
{
    Graph G;
    G.readGraph();
    cout << "ORINGINAL GRAPH IS :=>" << endl;
    G.DispGraph();
    cout << endl;
    Graph G_mst = Prims(G);
    cout << "MINIMUM SPANNING TREE IS :=>" << endl;
    G_mst.DispGraph();
    return 0;
}