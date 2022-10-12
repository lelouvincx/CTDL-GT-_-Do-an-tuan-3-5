#include <bits/stdc++.h>
#define llong long long
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define REP(i, b) for (int i = 0, _b = (b); i < _b; ++i)
#define FORE(i, a)                                                             \
  for (__typeof((a).begin()) i = (a).begin(); i != a.end(); ++i)
#define EACH(x, a) for (auto &x : a)
#define endl '\n'
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define taskname ""
#define file                                                                   \
  freopen(taskname ".inp", "r", stdin);                                        \
  freopen(taskname ".out", "w", stdout)
#define debug(...)                                                             \
  cout << "#" << __LINE__ << ": [" << #__VA_ARGS__ << "] = [", DBG(__VA_ARGS__)

using namespace std;

string to_string(const string &s) { return '"' + s + '"'; }
void DBG() { cout << "]" << endl; }
template <class H, class... T> void DBG(H h, T... t) {
  cout << to_string(h);
  if (sizeof...(t))
    cout << ", ";
  DBG(t...);
}

template <class T> inline bool minimize(T &x, const T &y) {
  if (x >= y) {
    x = y;
    return true;
  }
  return false;
}

template <class T> inline bool maximize(T &x, const T &y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

template <class A> void read(vector<A> &v);
template <class A, size_t S> void read(array<A, S> &a);
template <class T> void read(T &x) { cin >> x; }
void read(double &d) {
  string t;
  read(t);
  d = stod(t);
}

template <class H, class... T> void read(H &h, T &...t) {
  read(h);
  read(t...);
}
template <class A> void read(vector<A> &x) { EACH(a, x) read(a); }
template <class A, size_t S> void read(array<A, S> &x) { EACH(a, x) read(a); }

string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b ? "true" : "false"; }
string to_string(const char *s) { return string(s); }
string to_string(string s) { return s; }
string to_string(vector<bool> v) {
  string res;
  REP(i, v.size()) res += char('0' + v[i]);
  return res;
}

template <size_t S> string to_string(bitset<S> b) {
  string res;
  REP(i, S)
  res += char('0' + b[i]);
  return res;
}
template <class T> string to_string(T v) {
  bool f = 1;
  string res;
  EACH(x, v) {
    if (!f)
      res += ' ';
    f = 0;
    res += to_string(x);
  }
  return res;
}

template <class A> void write(A x) { cout << to_string(x); }
template <class H, class... T> void write(const H &h, const T &...t) {
  write(h);
  write(t...);
}
void print() { write('\n'); }
template <class H, class... T> void print(const H &h, const T &...t) {
  write(h);
  if (sizeof...(t))
    write(' ');
  print(t...);
}
void writes() { write(' '); }
template <class H, class... T> void writes(const H &h, const T &...t) {
  write(h);
  if (sizeof...(t))
    write(' ');
  writes(t...);
}
// ----------------------------------------------------------
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class V>
using ordered_map =
    tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

typedef pair<int, int> ii;
const int inf = 1e6 + 1;
const int mod = 1e9 + 7;
#define left __lft
#define right __rght
#define maxn

// ----------------------------------------------------------

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
long rand(long a, long b) {
  return uniform_int_distribution<long>(a, b)(mt_rng);
}

signed main() {
  const int inf = 1e9;
  vector<int> Size{1000, 3000, 10000, 30000, 100000};
  vector<string> State{"sorted", "reversed", "random"};

  for (auto state : State) {
    for (auto size : Size) {
      string filename = state;
      filename += '_';
      filename += to_string(size);
      filename += ".txt";
      ofstream cout(filename);
      vector<int> arr(size);
      for (auto &x : arr)
        x = rand(-inf, inf);
      if (state == "sorted")
        sort(arr.begin(), arr.end());
      if (state == "reversed")
        sort(arr.rbegin(), arr.rend());

      cout << arr.size() << endl;
      for (auto x : arr)
        cout << x << " ";
      cout << endl;
    }
  }

  return 0;
}
