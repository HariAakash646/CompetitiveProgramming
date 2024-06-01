#include "purwokerto.h"

#include <cassert>
#include <cstdio>
#include <utility>
#include <vector>

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}


int main() {
  usaco();
  int N, M;
  assert(2 == scanf("%d %d", &N, &M));

  std::vector<int> T(M);
  for (int i = 0; i < M; i++) {
    assert(1 == scanf("%d", &T[i]));
  }

  std::pair<long long, int> res = purwokerto(N, M, T);

  printf("%lld %d\n", res.first, res.second);
  return 0;
}
