#include <iostream>
using namespace std;

int p[] = {2, 3, 5, 2, 4};

int M[20][20] = {0};
int S[20][20] = {0};
// int n = 8;
int n;

void printMat(int ar[20][20], int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }
}
void matrixChainOrder()
{
    n = sizeof(p) / sizeof(p[0]) - 1;
    // Making diagonals of M = 0:
    for (int i = 1; i <= n; i++)
    {
        M[i][i] = 0;
    }

    for (int len = 2; len <= n; len++)
    {

        cout << "M Matrix:" << endl;
        printMat(M, n);
        // cout << endl;
        cout << "S Matrix:" << endl;
        printMat(S, n);

        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            M[i][j] = 9999;
            for (int k = i; k <= j - 1; k++)
            {
                int cost = M[i][k] + M[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < M[i][j])
                {
                    M[i][j] = cost;
                    S[i][j] = k;
                }
            }
        }
    }
}
void printOP(int i, int j)
{
    if (i == j)
        cout << 'A' << i;
    else
    {
        cout << '(';
        printOP(i, S[i][j]);
        printOP(S[i][j] + 1, j);
        cout << ')';
    }
}
int main()
{
    matrixChainOrder();
    printOP(1, n);
    return 0;
}