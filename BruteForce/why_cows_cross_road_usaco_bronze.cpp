#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

int main()
{
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    vector<char> lis(52);
    frange(i, 52)
    {
        scc(lis[i]);
    }
    int cross = 0;
    vector<char> done;
    frange(i, 52)
    {
        char l = lis[i];
        if (find(all(done), l) != done.end())
            continue;
        vector<char> curr;
        forr(j, i + 1, 52)
        {
            char c = lis[j];
            if (c == l)
                break;
            auto itr = find(all(curr), c);
            if (itr != curr.end())
                curr.erase(itr);
            else
                curr.pb(c);
        }
        done.pb(l);
        cross += curr.size();
    }
    printf("%d", cross / 2);
}