#include <bits/stdc++.h>
#include "secret.h"

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

vvi vec;
int n;
vi Av;

void rec(int l, int r, int d)
{
  if (l > r)
    return;
  // if (d >= 10)
  // {
  //   printf("Problem %d %d\n", l, r);
  //   return;
  // }
  if (l == r)
  {
    vec[l][d] = Av[l];
    return;
  }
  int mid = (l + r) / 2;
  vec[mid][d] = Av[mid];
  for (int i = mid - 1; i >= l; i--)
  {
    vec[i][d] = Secret(Av[i], vec[i + 1][d]);
  }
  if (r >= mid + 1)
    vec[mid + 1][d] = Av[mid + 1];
  forr(i, mid + 2, r + 1)
  {
    vec[i][d] = Secret(Av[i], vec[i - 1][d]);
  }
  rec(l, mid, d + 1);
  rec(mid + 1, r, d + 1);
}

int query(int l, int r, int lx, int rx, int d)
{
  int mid = (l + r) / 2;
  // if (d >= 10)
  // {
  //   printf("%d %d %d %d\n", l, r, lx, rx);
  //   return 0;
  // }
  // if(lx == rx) return
  if (lx == rx)
  {
    return Av[lx];
  }
  if (lx <= mid && rx > mid)
  {
    return Secret(vec[lx][d], vec[rx][d]);
  }
  if (lx <= mid)
    return query(l, mid, lx, rx, d + 1);
  else
    return query(mid + 1, r, lx, rx, d + 1);
}

void Init(int N, int a[])
{
  n = N;
  Av = vi(n);
  frange(i, n) Av[i] = a[i];

  vec = vvi(n, vi(11));
  rec(0, n - 1, 0);
}

int Query(int L, int R)
{
  return query(0, n - 1, L, R, 0);
}
