#include <iostream>
using namespace std;
#define MAX 100001
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
  
int main(void)
{
    int arrsize;
    cin>>arrsize;
    int arr[MAX];
    for(int i=0;i<arrsize;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;
    int result = search(arr, arrsize, x);
   (result == -1)? cout<<"Element is not present in array"
                 : cout<<"Element is present at index " <<result;
   return 0;
}
