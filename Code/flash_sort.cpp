#include <cstdio>
#include <iostream>
using namespace std;

const int MAX = 1e6;
const int MAX2 = 450010;
int last_index[MAX2], number_of_elements_in_class[MAX2];

int binary_search(int a[], int val, int left, int right) {
  if (right <= left) {
    if (val > a[left])
      return left + 1;
    else
      return left;
  }
  int mid = left + (right - left) / 2;
  if (val == a[mid])
    return mid + 1;
  if (val < a[mid])
    return binary_search(a, val, left, mid - 1);
  return binary_search(a, val, mid + 1, right);
}

void binary_insertion_sort(int a[], int left, int right) {
  for (int i = left + 1; i <= right; ++i) {
    int j = i - 1;
    int selected = a[i];
    int loc = binary_search(a, selected, 0, j);
    while (j >= loc) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = selected;
  }
}

int calculate_class(int x, int m, int min_val, int max_val) {
  return (m - 1) * (x - min_val) / (max_val - min_val);
}

void flash_sort(int a[], int n) {
  int min_val, max_val;
  min_val = max_val = a[0];
  for (int i = 1; i < n; ++i) {
    if (min_val > a[i])
      min_val = a[i];
    if (max_val < a[i])
      max_val = a[i];
  }

  int m = 0.45 * n;
  last_index[0] = -1;
  for (int i = 0; i < n; ++i) {
    int tmp = calculate_class(a[i], m, min_val, max_val);
    last_index[tmp]++;
    number_of_elements_in_class[tmp]++;
  }
  for (int i = 1; i < m; ++i)
    last_index[i] += last_index[i - 1];

  int number_of_moves = n;
  for (int moves = 0; moves < number_of_moves; ++moves) {
    int tmp = calculate_class(a[0], m, min_val, max_val);
    if (last_index[tmp] >= 0)
      swap(a[0], a[last_index[tmp]]);
    else
      break;
    last_index[tmp]--;
  }

  int left = 0, right = -1, i = 0;
  do {
    left = right + 1;
    right = left + number_of_elements_in_class[i++] - 1;
    binary_insertion_sort(a, left, right);
  } while (i < m);
}

int main() {
  int n;
  cin >> n;
  int a[MAX];
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  flash_sort(a, n);
  for (int i = 0; i < n; ++i)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
