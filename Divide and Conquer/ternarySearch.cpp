#include<iostream>
using namespace std;

int ternarySearch(int low, int high, int key, int arr[]){
    int mid1 = low + (high - low) / 3;
    int mid2 = high - (high - low) / 3;

    if (arr[mid1] == key)
        return mid1;
    else if (arr[mid2] == key)
        return mid2;    
    else{
        if (key < arr[mid1])
            return ternarySearch(low, mid1-1, key, arr);
        
        else if (key > arr[mid1] && key < arr[mid2])
            return ternarySearch(mid1+1, mid2-1, key, arr);
        
        else
            return ternarySearch(mid2+1, high, key, arr);
    }
    return -1;
}

int main(void){
    int n;
    cout<<"\nEnter the array size : ";
    cin>>n;
    int arr[n];
    int key;
    cout<<"\nEnter the array...."<<endl;
    for (int i = 0 ; i < n ; i++)
        cin>>arr[i];
    cout<<"\nEnter the element you want to search : ";
    cin>>key;
    int ans = ternarySearch(0,n,key, arr);
    if (ans == -1)
        cout<<"ELement not found...."<<endl;
    else
        cout<<"Element found at index "<<ans<<endl;
    return 0;
}