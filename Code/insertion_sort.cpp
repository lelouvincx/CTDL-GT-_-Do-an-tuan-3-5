
#include <iostream>
using namespace std;
#define MAX 100001
void insertionSort(int a[],int n){
    int k=1;
    while(k<n){
        int x = a[k];
        int vt = k-1;
        while(a[vt] > x && vt>=0){
            a[vt+1] = a[vt];
            vt--;
        }
        a[vt+1] = x;
        k++;
    }
}

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int a[MAX];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    insertionSort(a, n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<"  ";
    }
    return 0;
    return 0;
}
