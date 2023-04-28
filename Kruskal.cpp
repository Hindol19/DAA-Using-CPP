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
    Edge e[100];
    int nov, noe;
    Graph()
    {
        nov = 0;
        noe = 0;
    }
    void readGraph()
    {
        int w[100][100];
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

    void Sort()
    {
        for (int i = 0; i < noe - 1; i++)
        {
            for (int j = 0; j < noe - i - 1; j++)
            {
                if (e[j].wt > e[j + 1].wt)
                {
                    Edge temp = e[j];
                    e[j] = e[j + 1];
                    e[j + 1] = temp;
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
int Find(int p[], int i)
{
    while (p[i] > 0)
    {
        i = p[i];
    }
    return i;
}
void simpleUnion(int p[], int i, int j)
{
    int u = Find(p, i);
    int v = Find(p, j);
    p[u] = v;
}

void DisplayParent(int ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
}
Graph Kruskal(Graph G)
{
    Graph MST;
    // int *parent = new int(G.nov + 1);
    int parent[G.nov];

    G.Sort();
    for (int i = 0; i < G.nov; i++)
    {
        parent[i] = -1;
    }

    for (int i = 0; i < G.noe; i++)
    {
        // DisplayParent(parent, G.nov);
        if (Find(parent, G.e[i].v1) != Find(parent, G.e[i].v2))
        {
            MST.e[MST.noe] = G.e[i];
            MST.noe++;
            simpleUnion(parent, G.e[i].v1, G.e[i].v2);
        }
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
    Graph G_mst = Kruskal(G);
    cout << "MINIMUM SPANNING TREE IS :=>" << endl;
    G_mst.DispGraph();
    return 0;
}