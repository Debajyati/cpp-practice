#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <vector>
#include <iostream>

#define pb push_back
#define all(x) (x).begin(), (x).end()

#define eprintf(...) 0

using namespace std;

template<class T> inline void umax(T &a,T b){if(a < b) a = b;}
template<class T> inline void umin(T &a,T b){if(a > b) a = b;}
template<class T> inline T abs(T a){return a > 0 ? a : -a;}

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int inf = 1e9 + 143;
const ll longinf = 1e18 + 143;

inline int read(){int x;scanf(" %d",&x);return x;}

const unsigned M = (1ll << 31) - 1;
const int MAX = 1 << 26;
const int K = 16;
const int MSK = (1 << K) - 1;

int kb[1 << K];
unsigned f[MAX];

int main(){

  int n = read();
  unsigned s, p, q;
  cin >> s >> p >> q;

  f[s >> 5] |= 1u << (s & 31);
  for (int i = 1; i < n; i++) {
    s = (s * p + q) & M;
    f[s >> 5] |= 1u << (s & 31);
  }

  for (int i = 0; i < (1 << K); i++) {
    kb[i] = kb[i >> 1] + (i & 1);
  }

  int res = 0;
  for (int i = 0; i < MAX; i++) {
    res += kb[f[i] >> 16] + kb[f[i] & MSK];
  }
  printf("%d\n", res);

  return 0;
}
