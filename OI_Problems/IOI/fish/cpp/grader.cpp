#include "fish.h"

#include <cassert>
#include <cstdio>

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

  std::vector<int> X(M), Y(M), W(M);
  for (int i = 0; i < M; ++i) {
    assert(3 == scanf("%d %d %d", &X[i], &Y[i], &W[i]));
  }

  long long result = max_weights(N, M, X, Y, W);
  printf("%lld\n", result);
  return 0;
}
