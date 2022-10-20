#include <iostream>

using namespace std;

void heapify_top_down(int A[], int n, int i) {
  // Max-Heap

  int largest, l, r;

  while (true) {
    l = 2 * i + 1;
    r = l + 1;

    if (l < n && A[l] > A[i])
      largest = l;
    else
      largest = i;

    if (r < n && A[r] > A[largest])
      largest = r;

    if (largest == i)
      break;

    swap(A[i], A[largest]);

    i = largest;
  }
}

void heapify_bottom_up(int A[], int n, int i) {
  // Max-Heap

  int parent;

  while (true) {
    if (i == 0)
      break;

    parent = (i - 1) / 2;

    if (A[i] > A[parent]) {
      swap(A[i], A[parent]);
      i = parent;
    } else
      break;
  }
}

struct priority_queue {
  int A[100];
  int N;
};

void push(priority_queue &pq, int x) {
  pq.A[pq.N] = x;
  heapify_bottom_up(pq.A, pq.N + 1, pq.N);
  ++pq.N;
}

bool empty(priority_queue pq) { return pq.N == 0; }

int top(priority_queue pq) { return pq.A[0]; }

void pop(priority_queue &pq) {
  swap(pq.A[0], pq.A[pq.N - 1]);
  heapify_top_down(pq.A, pq.N - 1, 0);
  --pq.N;
}

int main() {
  priority_queue pq;
  pq.N = 0; // phần tử con nhỏ hơn cha

  push(pq, 3);
  push(pq, 19);
  push(pq, 1);
  push(pq, 2);
  push(pq, 17);

  while (not empty(pq)) {
    cout << top(pq) << " ";
    pop(pq);
  }
  cout << endl;

  return 0;
}
