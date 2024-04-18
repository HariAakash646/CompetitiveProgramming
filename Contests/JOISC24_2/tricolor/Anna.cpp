#include "Anna.h"
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

namespace {

int variable_example = 0;

}

std::pair<std::string, int> anna(int n, std::string S) {
  string T = "";
  int l = min(n, 130);
  if(l < 130) {
    frange(i, n) {
      if(S[i] != 'R') T += 'R';
      else T += 'G';
    }
  }
  else {
    if(S[0] != 'R' && S[1] != 'R') {
      T += 'R';
      T += 'R';
    }
    else if(S[0] != 'G' && S[1] != 'G') {
      T += 'G';
      T += 'G';
    }
    else if(S[0] != 'B' && S[1] != 'B') {
      T += 'B';
      T += 'B';
    }
    set<char> st;
    st.insert('R');
    st.insert('G');
    st.insert('B');
    st.erase(T[1]);
    if(st.count(S[2])) st.erase(S[2]);
    T += *st.begin();
    forr(i, 3, n) {
      if(S[i] != 'R') T += 'R';
      else T += 'G';
    }
  } 

  return make_pair(T, l);
}
