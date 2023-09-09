#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

/// # of divs, sum of divs, count of coprime, smallest prime factor
int tau[N], sigma[N], phi[N], spf[N];

int main() {
  for (int i = 2; i < N; ++i) if (!spf[i]) {
    for (int j = i; j < N; j += i) if (!spf[j]) spf[j] = i;
  }

  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i) ++tau[j], sigma[j] += i;
  }

  for (int i = 1; i < N; ++i) phi[i] = i;
  for (int i = 2; i < N; ++i) if (phi[i] == i) {
    for (int j = i; j < N; j += i) phi[j] -= phi[j] / i;
  }

  /// inclusion-exclusion
  int n, l;
  vector <int> p(n);
  int ans = 0;
  for (int mask = 0; mask < 1 << n; ++mask) {
    int product = 1;
    for (int i = 0; i < n; ++i) {
      if (mask & 1 << i) product *= p[i];
    }
    if (__builtin_popcount(mask) & 1) ans -= l / product;
    else ans += l / product;
  }
  cout << ans << '\n';
  return 0;
}


