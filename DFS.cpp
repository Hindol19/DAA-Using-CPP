#include <iostream>
#include <fstream>
#define SIZE 100
using namespace std;

int adj[100][100];
int n;
int visited[10] = {0};

class Stack
{
    int ar[SIZE];

public:
    int top;
    Stack()
    {
        top = -1;
    }
    int isEmpty()
    {
        if (top == -1)
            return 1;
        else
            return 0;
    }
    void push(int x)
    {
        if (top == SIZE - 1)
            return;
        top++;
        ar[top] = x;
    }
    void pop()
    {
        if (top == -1)
            return;
        top--;
    }
    int peek()
    {
        if (top == -1)
            return -999;
        return ar[top];
    }
    void display()
    {
        if (top == -1)
            return;
        for (int i = 0; i <= top; i++)
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
        cout << "FILE READ FAILED!" << endl;
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

void DFS(int start)
{
    visited[start] = 1;
    cout << start << " ";
    for (int i = 0; i < n; i++)
    {
        if (adj[start][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

int main()
{
    readGraph();
    printMat(adj, n);
    DFS(0);
}