#include <iostream>
using namespace std;

void swap(int ar[], int i, int j)
{
    int temp = ar[i];
    ar[i] = ar[j];
    ar[j] = temp;
}

void heapify(int ar[], int i, int n)
{
    int lc = i * 2;
    int rc = i * 2 + 1;
    int largest = i;

    if (lc <= n && ar[lc] > ar[largest])
    {
        largest = lc;
    }
    if (rc <= n && ar[rc] > ar[largest])
    {
        largest = rc;
    }
    if (largest != i)
    {
        swap(ar, i, largest);
        heapify(ar, largest, n);
    }
}

void buildHeap(int ar[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(ar, i, n);
    }
}

void heapSort(int ar[], int n)
{
    buildHeap(ar, n);
    for (int i = n; i >= 2; i--)
    {
        swap(ar, i, 1);
        heapify(ar, 1, i - 1);
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
int main()
{
    int ar[] = {3, 6, 5, 9, 1};
    printAr(ar, 5);
    heapSort(ar, 5);
    printAr(ar, 5);
}