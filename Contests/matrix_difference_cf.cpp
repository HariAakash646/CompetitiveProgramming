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
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
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
    while (t--)
    {
        int n;
        scd(n);
        vvi vec(n, vi(n, 0));
        vec[0][0] = 1;
        seti dif;
        seti avail;
        forr(i, 2, n * n + 1, 1)
        {
            avail.insert(i);
        }
        for (int i = n * n - 1; i >= 1; --i)
        {
            if (dif.find(i) != dif.end())
                continue;
            bool done = false;
            frange(r, n)
            {
                frange(c, n)
                {
                    if (vec[r][c] != 0)
                        continue;
                    if (r != 0)
                    {
                        int a = vec[r - 1][c];
                        if (a != 0)
                        {
                            auto itr = avail.find(a - i);
                            if (itr == avail.end())
                                itr = avail.find(a + i);
                            if (itr != avail.end())

                            {
                                vec[r][c] = *itr;
                                dif.insert(i);
                                avail.erase(itr);
                                done = true;
                                if (r != 0 && vec[r - 1][c] != 0)
                                    dif.insert(abs(vec[r][c] - vec[r - 1][c]));
                                if (r != n - 1 && vec[r + 1][c] != 0)
                                    dif.insert(abs(vec[r][c] - vec[r + 1][c]));
                                if (c != 0 && vec[r][c - 1] != 0)
                                    dif.insert(abs(vec[r][c] - vec[r][c - 1]));
                                if (r != n - 1 && vec[r][c + 1] != 0)
                                    dif.insert(abs(vec[r][c] - vec[r][c + 1]));
                                break;
                            }
                        }
                    }
                    if (r != n - 1)
                    {
                        int a = vec[r + 1][c];
                        if (a != 0)
                        {
                            auto itr = avail.find(a - i);
                            if (itr == avail.end())
                                itr = avail.find(a + i);
                            if (itr != avail.end())

                            {
                                vec[r][c] = *itr;
                                dif.insert(i);
                                avail.erase(itr);
                                done = true;
                                if (r != 0 && vec[r - 1][c] != 0)
                                    dif.insert(abs(vec[r][c] - vec[r - 1][c]));
                                if (r != n - 1 && vec[r + 1][c] != 0)
                                    dif.insert(abs(vec[r][c] - vec[r + 1][c]));
                                if (c != 0 && vec[r][c - 1] != 0)
                                    dif.insert(abs(vec[r][c] - vec[r][c - 1]));
                                if (r != n - 1 && vec[r][c + 1] != 0)
                                    dif.insert(abs(vec[r][c] - vec[r][c + 1]));
                                break;
                            }
                        }
                    }
                    if (c != 0)
                    {
                        int a = vec[r][c - 1];
                        if (a != 0)
                        {
                            auto itr = avail.find(a - i);
                            if (itr == avail.end())
                                itr = avail.find(a + i);
                            if (itr != avail.end())
                            {
                                vec[r][c] = *itr;
                                dif.insert(i);
                                avail.erase(itr);
                                done = true;
                                if (r != 0 && vec[r - 1][c] != 0)
                                    dif.insert(abs(vec[r][c] - vec[r - 1][c]));
                                if (r != n - 1 && vec[r + 1][c] != 0)
                                    dif.insert(abs(vec[r][c] - vec[r + 1][c]));
                                if (c != 0 && vec[r][c - 1] != 0)
                                    dif.insert(abs(vec[r][c] - vec[r][c - 1]));
                                if (r != n - 1 && vec[r][c + 1] != 0)
                                    dif.insert(abs(vec[r][c] - vec[r][c + 1]));
                                break;
                            }
                        }
                    }
                    if (c != n - 1)
                    {
                        int a = vec[r][c + 1];
                        if (a != 0)
                        {
                            auto itr = avail.find(a - i);
                            if (itr == avail.end())
                                itr = avail.find(a + i);
                            if (itr == avail.end())
                            {
                                vec[r][c] = *itr;
                                dif.insert(i);
                                avail.erase(itr);
                                done = true;
                                if (r != 0 && vec[r - 1][c] != 0)
                                    dif.insert(abs(vec[r][c] - vec[r - 1][c]));
                                if (r != n - 1 && vec[r + 1][c] != 0)
                                    dif.insert(abs(vec[r][c] - vec[r + 1][c]));
                                if (c != 0 && vec[r][c - 1] != 0)
                                    dif.insert(abs(vec[r][c] - vec[r][c - 1]));
                                if (r != n - 1 && vec[r][c + 1] != 0)
                                    dif.insert(abs(vec[r][c] - vec[r][c + 1]));
                                break;
                            }
                        }
                    }
                }
                if (done)
                    break;
            }
            // if(!done) {
            //     not_done.insert(i);
            // }
        }
        for (int e : avail)
        {
            bool done = false;
            frange(r, n)
            {
                frange(c, n)
                {
                    if (vec[r][c] == 0)
                    {
                        vec[r][c] = e;
                        if (r != 0 && vec[r - 1][c] != 0)
                            dif.insert(abs(vec[r][c] - vec[r - 1][c]));
                        if (r != n - 1 && vec[r + 1][c] != 0)
                            dif.insert(abs(vec[r][c] - vec[r + 1][c]));
                        if (c != 0 && vec[r][c - 1] != 0)
                            dif.insert(abs(vec[r][c] - vec[r][c - 1]));
                        if (r != n - 1 && vec[r][c + 1] != 0)
                            dif.insert(abs(vec[r][c] - vec[r][c + 1]));
                        done = true;
                        break;
                    }
                }
                if (done)
                    break;
            }
        }
        // cout << dif.size() << "\n";
        for (auto v : vec)
        {
            for (auto e : v)
            {
                printf("%d ", e);
            }
            printf("\n");
        }
    }
}