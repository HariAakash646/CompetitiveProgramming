#include <bits/stdc++.h>

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

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

// Don't write any code here. No global variables.

struct Alice
{
  // This structure acts as Alice's brain. You can store anything you would
  // like Alice to remember. You can also implement functions.

  vi vec;
  int n;
  vb pres;
  seti st;
  int k;
  int cnt = 0;
  int lo;
  int r;
  
  void init(int N, std::vector<int> v, int l) {
    n = N;
    k =v.size();
    vec = v;
    pres = vb(n);
    lo = k-1;
    r = n-1;
    for(auto e : vec) {pres[e] = true;st.insert(e);}
      int mid = (lo+r)/2;
    for(auto e : vec) {
      if(e <= mid) cnt++;
    }
  }
  
  int val = 0;
  
  int pos = 0;
  void receive(int bit) {
    if(lo==r) return;
    if(bit) val = val | (1<<pos);
    pos++;
    if(pos>=14) {
      int mid = (lo+r)/2;
      if(val+cnt>=k) r = mid;
      else lo = mid+1;
      // printf("%d %d\n", l, r);
      val = 0;
      cnt = 0;
      pos = 0;
      mid = (lo+r)/2;
      for(auto e : vec) if(e <= mid) cnt++;
    }
  }


  int send() {
      if(lo==r) return 0;
     if(cnt&(1<<pos)) return 1; 
     else return 0;
  }

  int answer() {
    return lo;
  }
};


struct Bob
{
  // This structure acts as Alice's brain. You can store anything you would
  // like Alice to remember. You can also implement functions.

  vi vec;
  int n;
  vb pres;
  seti st;
  int k;
  int cnt = 0;
  int lo;
  int r;
  
  void init(int N, std::vector<int> v, int l) {
    n = N;
    k =v.size();
    vec = v;
    pres = vb(n);
    lo = k-1;
    r = n-1;
    for(auto e : vec) {pres[e] = true;st.insert(e);}
    int mid = (lo+r)/2;
    for(auto e : vec) {
      if(e <= mid) cnt++;
    }
  }
  
  int val = 0;
  
  int pos = 0;
  void receive(int bit) {
    if(lo==r) return;
    if(bit) val = val | (1<<pos);
    pos++;
    if(pos>=14) {
      int mid = (lo+r)/2;
      if(val+cnt>=k) r = mid;
      else lo = mid+1;
      // printf("%d %d\n", l, r);
      val = 0;
      cnt = 0;
      pos = 0;
      mid = (lo+r)/2;
      for(auto e : vec) if(e <= mid) cnt++;
    }
  }


  int send() {
      if(lo==r) return 0;
     if(cnt&(1<<pos)) return 1; 
     else return 0;
  }

  int answer() {
    return lo;
  }
};


// Do not change anything below this line

int main() {
  // usaco();
  const int MAXN = 9999;
  const int MAXL = 200000;

  int n, k, l;
  std::cin >> n >> k >> l;

  if(n < 1 || n > MAXN) {
    std::cout << "Error in input. n doesn't satisfy constraints specified." << std::endl;
    return 0;
  }
  if(k < 1 || 2*k > n) {
    std::cout << "Error in input. k should be at least 1 and 2*k shouldn't exceed n." << std::endl;
    return 0;
  }
  if(l < 1 || l > MAXL) {
    std::cout << "Error in input. l doesn't satisfy constraints specified." << std::endl;
    return 0;
  }

  Alice a;
  Bob b;

  std::vector<int> vis(n, 0);
  std::vector<int> va, vb;
  for(int i = 0; i < k; i++) {
    int x;
    std::cin >> x;

    if(x < 0 || x >= n) {
      std::cout << "Error in input. Values should lie in [0, n-1]." << std::endl;
      return 0;
    }

    if(vis[x]) {
      std::cout << "Error in input. Values should not be repeated." << std::endl;
      return 0;
    }

    vis[x] = 1;
    va.push_back(x);
  }

  for(int i = 0; i < k; i++) {
    int x;
    std::cin >> x;
 
    if(x < 0 || x >= n) {
      std::cout << "Error in input. Values should lie in [0, n-1]." << std::endl;
      return 0;
    }

    if(vis[x]) {
      std::cout << "Error in input. Values should not be repeated." << std::endl;
      return 0;
    }

    vis[x] = 1;
    vb.push_back(x);
  }

  int actual_median = 0;
  int ct = 0;
  for(int i = 0; i < n; i++) {
    ct += vis[i];
    if(ct == k) {
      actual_median = i;
      break;
    }
  }

  std::sort(va.begin(), va.end());
  std::sort(vb.begin(), vb.end());
  a.init(n, va, l);
  b.init(n, vb, l);

  for(int i = 0; i < l; i++) {
    int u = a.send();
    int v = b.send();
    if(u != 0 && u != 1) {
      std::cout << "Error. Alice tried to send something other than 1 or 0." << std::endl;
      return 0;
    }
    if(v != 0 && v != 1) {
      std::cout << "Error. Bob tried to send something other than 1 or 0." << std::endl;
      return 0;
    }
    a.receive(v);
    b.receive(u);
  }

  int alice_ans = a.answer();
  int bob_ans = b.answer();
  if(alice_ans == actual_median && bob_ans == actual_median) {
    std::cout << "Passed." << std::endl;
  }
  else {
    std::cout << "WA." << std::endl;
    std::cout << "Actual median: " << actual_median << std::endl;
    std::cout << "Alice reported: " << alice_ans << std::endl;
    std::cout << "Bob reported: " << bob_ans << std::endl;
  }
}
