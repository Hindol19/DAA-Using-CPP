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
void InsertionSort(int ar[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            if (ar[j] < ar[j - 1])
                swap(ar, j, j - 1);
            else
                break;
        }
    }
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    InsertionSort(arr, n);
    cout << "Sorted array: " << endl;
    printArray(arr, n);
    return 0;
}