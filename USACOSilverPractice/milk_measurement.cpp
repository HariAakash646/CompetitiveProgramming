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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    int n, g;
    cin >> n >> g;
    set<pii> cows = {{0, 0}};
    vi cowvec(n + 1);
    set<pair<int, pii>> upd;
    mpii idx;
    seti ivec;
    frange(_, n)
    {
        int day, id, v;
        char sign;
        cin >> day >> id >> sign >> v;
        ivec.insert(id);
        if (sign == '-')
        {
            upd.insert({day, {id, -v}});
        }
        else if (sign == '+')
        {
            upd.insert({day, {id, v}});
        }
    }
    int i = 0;
    for (auto e : ivec)
    {
        idx[e] = i;
        i++;
    }
    int c = 0;
    for (auto e : upd)
    {
        auto itr = cows.find({cowvec[idx[e.s.f]], e.s.f});
        int ma = (*prev(cows.end())).f;
        int pre = 0;
        if (cows.size() >= 2)
        {
            pre = (*prev(prev(cows.end()))).f;
        }
        int curr;
        if (itr == cows.end())
        {
            curr = 0;
        }
        else
        {
            curr = (*itr).f;
            cows.erase(itr);
        }
        cowvec[idx[e.s.f]] += e.s.s;
        // if ((curr == ma || cowvec[idx[e.s.f]] >= ma) && !((curr == ma && cowvec[idx[e.s.f]] >= ma) && pre != ma))
        // {
        //     c++;
        // }
        if (curr == ma)
        {
            if (e.s.s > 0 && pre == ma)
                c++;
            else
            {
                if (pre >= cowvec[idx[e.s.f]])
                    c++;
            }
        }
        else if (cowvec[idx[e.s.f]] >= ma)
            c++;
        cows.insert({cowvec[idx[e.s.f]], e.s.f});
    }
    printf("%d", c);
}