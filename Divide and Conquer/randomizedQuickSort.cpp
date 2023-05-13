#include <iostream>
#include<random>

using namespace std;

void swap(int i, int j, int arr[])
{
    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
}

int partition(int low, int high, int arr[])
{
    int pivot = arr[high]; // considering last element as the pivot element
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(i, j, arr);
        }
    }
    swap(i + 1, high, arr);
    return (i + 1);
}

void quickSort(int low, int high, int arr[])
{
    if (low < high)
    {
        if (high + low - 1 > 5){
            int pos = rand() % (high-low+1) + low;
            swap(pos, low, arr);
        }
        int p = partition(low, high, arr);
        quickSort(low, p - 1, arr);
        quickSort(p + 1, high, arr);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(void)
{
    int n;
    cout << "\n Entetr the array size : ";
    cin >> n;
    int arr[n];
    cout<<"enter the array elemnts :- "<<endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Array before sorting : ";
    printArray(arr, n);
    quickSort(0, n, arr);
    cout << "Array after sorting : ";
    printArray(arr, n);
    return 0;
}