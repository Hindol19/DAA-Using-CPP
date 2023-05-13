#include <iostream>
using namespace std;
class Data
{
public:
    int n;
    float p[100];
    float w[100];
    void insertData()
    {
        cout << "Enter Number of objects: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cout << "Enter Profit for Object " << i + 1 << ": ";
            cin >> p[i];
            cout << "Enter Weight/Cost for Object " << i + 1 << ": ";
            cin >> w[i];
            cout << endl;
        }
    }
};
void PrintData(int n, float p[], float w[])
{
    for (int i = 0; i < n; i++)
    {
        printf("Object %d\tProfit=%f\tWeight=%f\n", i + 1, p[i], w[i]);
    }
}

void swap(float ar[], int i, int j)
{
    float temp = ar[i];
    ar[i] = ar[j];
    ar[j] = temp;
}
int Partition(float pw[], float p[], float w[], int low, int high)
{
    int i = low, j = high;
    float pivot = pw[high];
    while (true)
    {
        while (pw[i] < pivot)
        {
            i++;
        }
        while (pw[j] > pivot)
        {
            j--;
        }

        if (j <= i)
            return j;

        swap(pw, i, j);
        swap(p, i, j);
        swap(w, i, j);
    }
}
void quickSort(float pw[], float p[], float w[], int low, int high)
{
    if (low < high)
    {
        int pi = Partition(pw, p, w, low, high);
        quickSort(pw, p, w, low, pi - 1);
        quickSort(pw, p, w, pi + 1, high);
    }
}

float Knapsack(float p[], float w[], int n, int M)
{
    float pwRatio[n];

    // O(N)
    for (int i = 0; i < n; i++)
    {
        pwRatio[i] = p[i] / w[i];
    }

    // O(NlogN)
    quickSort(pwRatio, p, w, 0, n - 1);
    
    float maxProfit = 0.0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (M > 0 && w[i] <= M)
        {
            M = M - w[i];
            maxProfit = maxProfit + p[i];
        }

        else if (M > 0)
        {
            maxProfit = maxProfit + p[i] * (M / w[i]);
            M = 0;
        }
    }

    return maxProfit;
}

int main()
{
    Data d;

    d.insertData();

    int M = 20;
    cout << "INPUTED DATA: " << endl;
    PrintData(d.n, d.p, d.w);
    printf("\n");
    float profit = Knapsack(d.p, d.w, d.n, M);
    printf("\n\n Max Profit = %f", profit);
    return 0;
}