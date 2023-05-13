#include <iostream>
#include <math.h>
using namespace std;

int grid[30], count = 0;
int place(int pos)
{
    int i;
    for (i = 1; i < pos; i++)
    {
        if ((grid[i] == grid[pos]) || ((abs(grid[i] - grid[pos]) == abs(i - pos))))
            return 0;
    }
    return 1;
}
void print_sol(int n)
{
    int i, j;
    count++;
    cout<<"\n\nsolution#"<< count << endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (grid[i] == j)
                printf("Q\t");
            else
                printf(".\t");
        }
        printf("\n");
    }
}
void queen(int n)
{
    int k = 1;
    grid[k] = 0;
    while (k != 0)
    {
        do
        {
            grid[k]++;
        } while ((grid[k] <= n) && !place(k));
        if (grid[k] <= n)
        {
            if (k == n)
                print_sol(n);
            else
            {
                k++;
                grid[k] = 0;
            }
        }
        else
            k--;
    }
}
int main()
{
    int n;
    cout<<"Enter the number of Queens : ";
    cin>>n;
    queen(n);
    cout<<"\nTotal solution = " << count;
}