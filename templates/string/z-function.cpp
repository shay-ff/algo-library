#include <bits/stdc++.h>
using namespace std;

struct ZFunction {
  // Compute Z-array for a given string
  static vector<int> build(const string &s) {
    int n = (int)s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
      if (i <= r)
        z[i] = min(r - i + 1, z[i - l]);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        z[i]++;
      if (i + z[i] - 1 > r) {
        l = i;
        r = i + z[i] - 1;
      }
    }
    return z;
  }
};

// Example usage
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  if (!(cin >> s))
    return 0;
  auto z = ZFunction::build(s);
  for (auto v : z)
    cout << v << " ";
  cout << "\n";
  return 0;
}
