#include "Bob.h"
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

// you may define some global variables, but it does not work if you try to transfer any information from function Alice() to function Bob() through these variables.
// you had better not use the same global variables in function Alice() and in function Bob().

long long Bob(std::vector<std::pair<int,int>> V){
	// add your code here
	vi deg(5001);
	for(auto p : V) {
		deg[p.f]++;
		deg[p.s]++;
	}
	pair<int, lli> ma=mp(0, 0);
	forr(i, 1, 5000+1) {
		ma = max(ma, mp(deg[i], lli(i)));
	}
    return ma.s; // change this into your code
}
