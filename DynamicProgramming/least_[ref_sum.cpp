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
    int t;
    scd(t);
    frange(_, t)
    {
        int n, m;
        scd(n);
        scd(m);
        vi vec(n);
        frange(i, n)
        {
            scd(vec[i]);
        }
        vector<lli> pref(n);
        pref[0] = vec[0];
        forr(i, 1, n)
        {
            pref[i] = pref[i - 1] + vec[i];
        }
        int op = 0;
        lli diff = 0;
        priority_queue<int> pq;
        for (int i = m - 1; i >= 0; i--)
        {

            if (pref[i] < pref[m - 1] - diff)
            {
                diff += 2 * pq.top();
                pq.pop();
                op++;
            }
            pq.push(vec[i]);
        }
        diff = 0;
        pq = {};
        forr(i, m, n)
        {
            pq.push(-vec[i]);
            if (pref[i] < pref[m - 1] - diff)
            {
                diff += 2 * (pq.top());
                pq.pop();
                op++;
            }
        }
        printf("%d\n", op);
    }
}