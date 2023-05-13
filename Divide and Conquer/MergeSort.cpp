#include <iostream>
using namespace std;
void printArray(int ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
}

void Merge(int ar[], int low, int mid, int high)
{
    int M[high - low + 1];
    int i1 = low;
    int i2 = mid + 1;
    int i, j, t = 0;
    while (i1 <= mid && i2 <= high)
    {
        if (ar[i1] < ar[i2])
        {
            M[t] = ar[i1];
            i1++;
            t++;
        }
        else
        {
            M[t] = ar[i2];
            i2++;
            t++;
        }
    }
    while (i1 <= mid)
    {
        M[t] = ar[i1];
        t++;
        i1++;
    }
    while (i2 <= high)
    {
        M[t] = ar[i2];
        t++;
        i2++;
    }

    for (i = 0, j = low; j <= high; i++, j++)
    {
        ar[j] = M[i];
    }
}
void MergeSort(int ar[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(ar, low, mid);
        MergeSort(ar, mid + 1, high);
        Merge(ar, low, mid, high);
    }
}
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    MergeSort(arr, 0, n - 1);
    cout << "Sorted array: " << endl;
    printArray(arr, n);
    return 0;
}