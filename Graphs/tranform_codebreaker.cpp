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

lli inf = 1e15 + 5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l, n;
    cin >> (l);
    cin >> (n);
    string str;
    cin >> str;
    vector<vector<lli>> adjmat(26, vector<lli>(26, inf));
    frange(i, n)
    {
        char c1, c2;
        lli cost;
        cin >> (c1);
        cin >> (c2);
        cin >> (cost);
        adjmat[c1 - 'a'][c2 - 'a'] = min(cost, adjmat[c1 - 'a'][c2 - 'a']);
    }
    vector<vector<pair<int, lli>>> graph(26);
    frange(i, 26)
    {
        frange(j, 26)
        {
            if (adjmat[i][j] != inf)
            {
                graph[i].pb({j, adjmat[i][j]});
            }
        }
    }
    vector<vector<lli>> distance(26, vector<lli>(26, inf));
    frange(i, 26)
    {
        distance[i][i] = 0;
        priority_queue<pair<lli, int>> pq;
        pq.push({0, i});
        vb processed(26, false);
        processed[i] = false;
        while (pq.size())
        {
            auto p = pq.top();
            pq.pop();
            if (processed[p.s])
                continue;
            processed[p.s] = true;
            for (auto e : graph[p.s])
            {
                if (distance[i][e.f] > -p.f + e.s)
                {
                    distance[i][e.f] = -p.f + e.s;
                    pq.push({-distance[i][e.f], e.f});
                }
            }
        }
    }
    string str2 = str;
    reverse(all(str2));
    lli tot = 0;
    frange(i, l / 2)
    {
        int i1 = str[i] - 'a';
        int i2 = str2[i] - 'a';
        lli mi = inf;
        frange(j, 26)
        {
            mi = min(mi, distance[i1][j] + distance[i2][j]);
        }
        tot += mi;
    }
    if (tot >= inf)
        printf("-1");
    else
        printf("%lld", tot);
}