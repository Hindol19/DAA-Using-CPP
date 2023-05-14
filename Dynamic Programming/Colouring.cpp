#include <iostream>
#include <fstream>
using namespace std;

int G[100][100];
int m = 4, n;

void readGraph()
{
    FILE *fp;
    fp = fopen("adj.txt", "r");
    fscanf(fp, "%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            fscanf(fp, "%d", &G[i][j]);
        }
    }
    fclose(fp);
}
void printAr(int ar[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("C%d ", ar[i]);
    }
    cout << endl;
}

int x[100];

void printGraph(int ar[100][100], int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}

void nextVal(int start)
{
    int j;
    while (1)
    {
        x[start] = (x[start] + 1) % (m + 1);
        if (x[start] == 0)
            return;
        for (j = 1; j <= start - 1; j++)
        {
            if (G[j][start] == 1 && x[j] == x[start])
            {
                break;
            }
        }
        if (j == start)
            return;
    }
}
int c = 0;
void Colouring(int start)
{
    while (true)
    {
        // printAr(x, n);
        nextVal(start);
        if (x[start] == 0)
            return;
        if (start == n)
        {
            c++;
            printAr(x, n);
        }
        else
            Colouring(start + 1);
    }
}

int main()
{
    readGraph();
    cout << "Graph is:" << endl;
    printGraph(G, n);
    cout << endl
         << "Colouring Combinations are: " << endl;
    Colouring(1);
    cout << "No of solutions = " << c << endl;
    return 0;
}