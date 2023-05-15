#include<iostream>
using namespace std;

class Pair{
    public:
        int min;
        int max;
        
        Pair()
        {
            this->min = -1;
            this->max = -1;
        }
        
        Pair(int mn,int mx){
            this->min = mn;
            this->max = mx;
        }
};

Pair max_min(int low, int high, int arr[]){    
    Pair p = Pair();
    Pair lp, rp;        // left pair, right pair
    int mid;
    if (low == high){
        p = Pair(arr[low], arr[low]);
        return p;
    }
    
    if (high == low+1){
        if (arr[low] > arr[high])
            p = Pair(arr[high], arr[low]);
        else
            p = Pair(arr[low], arr[high]);
        return p;
    }

    mid = (low + high) / 2;
    lp = max_min(low, mid, arr);
    rp = max_min(mid+1, high, arr);

    if (lp.min < rp.min)
        p.min = lp.min;
    else
        p.min = rp.min;

    if (lp.max > rp.max)
        p.max = lp.max;
    else
        p.max = rp.max;
    
    return p;
}

int main(void){
    int n;
    cout<<"Enter the number of elements : ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter the array elements : ";
    for (int i = 0 ; i < n ; i++)
        cin>>arr[i];
    Pair p = max_min(0, n-1, arr);
    cout<<"\nSmallest element in the array is : "<<p.min<<endl;
    cout<<"\nLargest element in the array is : "<<p.max<<endl;
    return 0;
}