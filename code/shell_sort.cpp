#include <cstdio>
#include <iostream>
using namespace std;
const int MAX = 1e6;

void shell_sort(int a[], int n) {}

int main() {
  int n;
  cin >> n;
  int a[MAX];
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  shell_sort(a, n);
  for (int i = 0; i < n; ++i)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
