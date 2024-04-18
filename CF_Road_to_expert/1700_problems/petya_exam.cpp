#include <bits/stdc++.h>

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
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
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

int main()
{
    int n, m;
    scd(n);
    scd(m);
    set<pair<pii, pii>> info;
    vi vec(m);
    set<pii> exam;
    frange(i, m)
    {
        int si, di, ci;
        scd(si);
        scd(di);
        scd(ci);
        info.insert(mp(mp(si, i), mp(di, ci)));
        exam.insert({di, i});
        vec[i] = ci;
    }
    priority_queue<pii> pq;
    vi out(n + 1);
    bool done = true;
    forr(i, 1, n + 1)
    {
        while (info.size() && (*info.begin()).f.f == i)
        {
            pq.push({-(*info.begin()).s.f, (*info.begin()).f.s});
            info.erase(info.begin());
        }
        if (exam.size() && (*exam.begin()).f == i)
        {
            if (vec[(*exam.begin()).s] > 0)
            {
                printf("-1");
                done = false;
                break;
            }
            out[i] = m + 1;
            exam.erase(exam.begin());
        }
        else
        {
            if (pq.size())
            {
                auto p = pq.top();
                vec[p.s]--;
                out[i] = p.s + 1;
                if (vec[p.s] <= 0)
                    pq.pop();
            }
            else
            {
                out[i] = 0;
            }
        }
    }
    
    if (done)
    {
        forr(i, 1, n + 1)
        {
            printf("%d ", out[i]);
        }
    }
}