// Longest Increasing Subsequence - O(nlogn)
//
// dp(i) = max j<i { dp(j) | a[j] < a[i] } + 1
//

int lis(vector<int>& a) {
  vector<int> dp (a.size(), 0x3f3f3f3f);
  int res = 0;

  for (int v : a) {
    // increasing: lower_bound
    // non-decreasing: upper_bound
    int j = lower_bound(dp.begin(), dp.begin() + res, v) - dp.begin();
    dp[j] = min(dp[j], v);
    res = max(res, j + 1);
  }

  return res;
}
