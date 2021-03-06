// @problem_url: https://codeforces.com/problemset/problem/340/D
#include<bits/stdc++.h>
using namespace std;

// @include: dynamic-programming/lis.cpp

const int N = 2e5;

int main() {
  int n;

  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  cout << lis(v) << endl;
}
