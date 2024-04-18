#include <bits/stdc++.h>
#include "books.h"

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

//
// --- Sample implementation for the task books ---
//
// To compile this program with the sample grader, place:
//     books.h books_sample.cpp sample_grader.cpp
// in a single folder and run:
//     g++ books_sample.cpp sample_grader.cpp
// in this folder.
//

void solve(int n, int k, long long a, int S) {
    vi vec(n);
    frange(i, n) {
        vec[i] = skim(i+1);
    }
    vector<pair<lli, pii>> val;
    frange(i, n) {
        forr(j, i+1, n) {
            val.pb(mp(vec[i] + vec[j], mp(i+1, j+1)));
        }
    }

    for(auto p : val) {
        auto it = lower_bound(all(vec), a-p.f);
        if(it != vec.end() && *it + p.f <= 2*a) {
            vi out;
            out.pb(p.s.f);
            out.pb(p.s.s);
            out.pb(it - vec.begin() + 1);
            answer(out);
            return;
        }

    }
    impossible();

}