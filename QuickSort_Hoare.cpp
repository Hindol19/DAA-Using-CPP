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
void swap(int ar[], int i, int j)
{
    int temp = ar[i];
    ar[i] = ar[j];
    ar[j] = temp;
}
int Partition(int ar[], int low, int high)
{
    int i = low, j = high;
    int pivot = ar[high];
    while (true)
    {
        while (ar[i] < pivot)
        {
            i++;
        }
        while (ar[j] > pivot)
        {
            j--;
        }

        if (j <= i)
            return j;

        swap(ar, i, j);
    }
}
void quickSort(int ar[], int low, int high)
{
    if (low < high)
    {
        int pi = Partition(ar, low, high);
        quickSort(ar, low, pi - 1);
        quickSort(ar, pi + 1, high);
    }
}
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: " << endl;
    printArray(arr, n);
    return 0;
}
