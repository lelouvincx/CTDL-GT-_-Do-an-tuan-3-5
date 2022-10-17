#include <iostream>
using namespace std;
#define MAX 100001
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
int main(){
    int arrsize;
    cin>>arrsize;
    int arr[MAX];
    for(int i=0;i<arrsize;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;
    int result = binarySearch(arr,0,arrsize-1, x);
   (result == -1)? cout<<"Element is not present in array"
                 : cout<<"Element is present at index " <<result;
   return 0;
}
