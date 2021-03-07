// @problem_url: https://www.spoj.com/problems/MUL/
#include<bits/stdc++.h>

using namespace std;
typedef long double ld;

// @include: math/fft-tourist.cpp

int main() {
  int n;
  cin >> n;

  while (n--) {
    string a, b;
    cin >> a >> b;

    int size = a.size() + b.size();
    while (size - (size & -size) != 0) size -= size & -size;
    size *= 2;

    vector<int> va(size);
    vector<int> vb(size);

    for (int i = 0; i < a.size(); i++) va[a.size() - i - 1] = a[i] - '0';
    for (int i = 0; i < b.size(); i++) vb[b.size() - i - 1] = b[i] - '0';

    auto ans = fft::multiply(va, vb);

    string answer;
    int goes = 0;

    for (auto c : ans) {
      int x = c + goes;

      goes = 0;
      if (x > 9) {
        goes = x / 10;
        x = x % 10;
      }

      answer.push_back(x + '0');
    }
    answer.push_back(goes + '0');

    while (answer.back() == '0') answer.pop_back();
    if (answer.empty()) answer.push_back('0');
    reverse(answer.begin(), answer.end());

    cout << answer << endl;
  }
}
