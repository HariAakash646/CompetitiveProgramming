#include <stdio.h>
#include <assert.h>
#include "gondola.h"

int gondolaSequence[100001];
int replacementSequence[250001];

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

int main()
{
  usaco();
  int i, n, tag;
  int nr; 
  assert(scanf("%d", &tag)==1);
  assert(scanf("%d", &n)==1);
  for(i=0;i< n;i++)
    assert( scanf("%d", &gondolaSequence[i]) ==1);
  
  switch (tag){
  case 1: case 2: case 3:
    printf("%d\n", valid(n, gondolaSequence));
    break;

  case 4: case 5: case 6:
    nr = replacement(n, gondolaSequence, replacementSequence);
    printf("%d ", nr);
    if (nr > 0)
      {
	for (i=0; i<nr-1; i++)
	  printf("%d ", replacementSequence[i]);
	printf("%d\n", replacementSequence[nr-1]);
      }  
    else printf("\n");
    break;

  case 7: case 8: case 9: case 10:
    printf("%d\n",  countReplacement(n, gondolaSequence));  
    break;
  }

  return 0;
}
