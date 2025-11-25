/**
"*    created: ${CURRENT_YEAR}-${CURRENT_MONTH}-${CURRENT_DATE}
${CURRENT_HOUR}:${CURRENT_MINUTE}:${CURRENT_SECOND}",
"**/ // mark each line "" to work with VSCode
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
#define show(x) cout << x << endl
#define sz(x) (int)(x.size())

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto solve_test = [&](int test_case) {

  };
  int T = 1;
  // cin >> T;
  for (int i = 0; i < T; ++i) {
    solve_test(i);
  }
}