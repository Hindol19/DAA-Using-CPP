#include <iostream>
using namespace std;

class Job
{
public:
    int id, d, p;
};

void printSeq(Job j[], int n)
{
    printf("JOBS:    \t");
    for (int i = 0; i < n; i++)
    {
        printf("J%d\t", j[i].id);
    }
    printf("\nDEADLINE:\t");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", j[i].d);
    }
    printf("\nPROFIT:  \t");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", j[i].p);
    }
    printf("\n");
}

void swapJob(Job jb[], int i, int j)
{
    Job temp = jb[i];
    jb[i] = jb[j];
    jb[j] = temp;
}

void printAr(int ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
}

void BubSort(Job jb[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (jb[j].p < jb[j + 1].p)
            {
                swapJob(jb, j, j + 1);
            }
        }
    }
}

void JobSeq(Job job[], int n)
{
    // Sorting p in Descending Order:
    BubSort(job, n);
    int slot[n];

    for (int i = 0; i < n; i++)
        slot[i] = 0;

    int x[n] = {0};
    for (int i = 0; i < n; i++)
    {
        // printAr(slot, n);
        for (int j = min(job[i].d, n) - 1; j >= 0; j--)
        {
            if (slot[j] == 0)
            {
                x[j] = i;
                slot[j] = 1;
                break;
            }
        }
    }

    // Printing the result::
    for (int i = 0; i < n; i++)
    {
        if (slot[i])
        {
            cout << job[x[i]].id << " ";
        }
    }

    // printSeq(d, p, n);
}

int main()
{
    Job j[6] = {{1, 1, 200},
                {2, 4, 150},
                {3, 3, 250},
                {4, 4, 120},
                {5, 1, 100},
                {6, 3, 300}};
    int n = 6;
    printSeq(j, n);
    JobSeq(j, n);

    return 0;
}