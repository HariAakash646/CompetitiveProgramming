#include "sequence.h"

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
  int N;
  assert(1 == scanf("%d", &N));

  std::vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    assert(1 == scanf("%d", &A[i]));
  }

  int result = sequence(N, A);
  printf("%d\n", result);
  return 0;
}
