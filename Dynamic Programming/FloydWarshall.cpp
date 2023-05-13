#include <iostream>
#include <fstream>
using namespace std;

int n;
int G[100][100];
void readGraph()
{
    FILE *fp;
    fp = fopen("weighted-digraph-for-FW.txt", "r");
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

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

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

void printSol(int ar[100][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Vertex %d to Vertex %d : %d\n", i, j, ar[i][j]);
        }
        cout << endl;
    }
}

void FloydWarshall()
{
    int D[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (G[i][j] == 0 && i != j)
            {
                D[i][j] = 9999;
            }
            else
            {
                D[i][j] = G[i][j];
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int u = 0; u < n; u++)
        {
            for (int v = 0; v < n; v++)
            {
                D[u][v] = min(D[u][v], D[u][k] + D[k][v]);
            }
        }
        cout << "D-Matrix " << k + 1 << endl;
        printMat(D, n);
        cout << endl;
    }
    printSol(D, n);
}

int main()
{
    readGraph();
    FloydWarshall();
    return 0;
}