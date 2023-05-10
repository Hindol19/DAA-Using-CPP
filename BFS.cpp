#include <iostream>
#include <fstream>
using namespace std;
#define SIZE 100

int n;
int adj[100][100];

class Queue
{
    int ar[SIZE];

public:
    int f, r;
    Queue()
    {
        f = -1;
        r = -1;
    }
    int isEmpty()
    {
        if (f == -1 || r == -1 || f > r)
        {
            f = -1;
            r = -1;
            return 1;
        }
        else
            return 0;
    }
    void insert(int x)
    {
        if (r == SIZE - 1)
        {
            // Queue is full
            return;
        }
        if (f == -1 || r == -1)
        {
            // Queue is empty
            f++;
        }
        r++;
        ar[r] = x;
    }
    int peek()
    {
        if (isEmpty())
            return -999;
        return ar[f];
    }
    void del()
    {
        if (f == -1 || r == -1 || f > r)
        {
            f = -1;
            r = -1;
            // Queue is empty
            return;
        }
        f++;
    }
    void dispQ()
    {
        if (f == -1 || r == -1 || f > r)
        {
            f = -1;
            r = -1;
            // Queue is empty
            return;
        }
        for (int i = f; i <= r; i++)
        {
            cout << ar[i] << " ";
        }
        cout << endl;
    }
};

void readGraph()
{
    FILE *fp;
    fp = fopen("./adj.txt", "r");
    if (fp == NULL)
    {
        cout << "File reading failed" << endl;
        return;
    }
    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(fp, "%d", &adj[i][j]);
        }
    }
    fclose(fp);
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
void printAr(int ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
}
void BFS(int start)
{
    Queue q;
    int visited[n] = {0};
    int count = start;
    int res[n];
    int k = 0;
    q.insert(count);
    while (!q.isEmpty())
    {
        if (visited[count] == 0)
        {
            res[k] = count;
            k++;
        }
        visited[count] = 1;
        for (int i = 0; i < n; i++)
        {
            if (adj[count][i] == 1 && visited[i] == 0)
            {
                q.insert(i);
            }
        }

        q.del();
        count = q.peek();
    }
    cout << "\nBFS TRAVERSAL IS:" << endl;
    printAr(res, n);
}

int main()
{
    // Queue q;
    readGraph();

    cout << "ADJACENCY MATRIX IS:" << endl;
    printMat(adj, n);
    BFS(0);
}