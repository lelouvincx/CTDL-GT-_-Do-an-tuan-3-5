//
//  main.cpp
//  QuickSort
//
//  Created by Ngọc xinh đẹp on 16/10/2022.
//

#include <iostream>
using namespace std;
#define MAX 1000001
int partition (int arr[], int left, int right)
{
    int pivot = arr[right];
    int vt = left-1;
    for(int i=left;i<=right-1;i++){
        if(arr[i]<pivot){
            vt++;
            swap(arr[i],arr[vt]);
        }
    }
    vt = vt+1;
    swap(arr[vt],arr[right]);
    return vt;
}
void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int pi = partition(arr, left, right);
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int a[MAX];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<"  ";
    }
    return 0;
}
