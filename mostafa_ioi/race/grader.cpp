#include "race.h"
#include <stdio.h>
#include <stdlib.h>

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

#define MAX_N 500000

static int N, K;
static int H[MAX_N][2];
static int L[MAX_N];
static int solution;

inline 
void my_assert(int e) {if (!e) abort();}

void read_input()
{
  int i;
  my_assert(2==scanf("%d %d",&N,&K));
  for(i=0; i<N-1; i++)
    my_assert(3==scanf("%d %d %d",&H[i][0],&H[i][1],&L[i]));
  my_assert(1==scanf("%d",&solution));
}

int main()
{
  usaco();
  int ans;
  read_input();
  ans = best_path(N,K,H,L);
  if(ans==solution)
    printf("Correct.\n");
  else
    printf("Incorrect. Returned %d, Expected %d.\n",ans,solution);

  return 0;
}
