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
    frange(k, t)
    {
        int n;
        scd(n);
        vi vec1(n + 1, -1);
        vi vec2(n + 1, -1);
        vi vec11(n, -1);
        vi vec12(n, -1);
        seti not_set1;
        seti not_set2;
        int a;
        forr(i, 1, n + 1, 1)
        {
            not_set1.emplace_hint(not_set1.end(), i);
            not_set2.emplace_hint(not_set2.end(), i);
        }
        bool out = false;
        frange(i, n)
        {
            scd(a);
            if (vec2[a] == -1)
            {
                vec2[a] = i;
                vec12[i] = a;
                not_set2.erase(a);
            }
            else if ((vec1[a] == -1))
            {
                vec1[a] = i;
                vec11[i] = a;
                not_set1.erase(a);
            }
            else
                out = true;
        }

        frange(i, n)
        {
            if (vec11[i] != -1)
            {
                auto itr = not_set2.upper_bound(vec11[i]);
                if (itr == not_set2.begin())
                {
                    out = true;
                }
                else
                {
                    itr--;
                    vec12[i] = *itr;
                    not_set2.erase(itr);
                }
            }
            else if (vec12[i] != -1)
            {
                auto itr = not_set1.upper_bound(vec12[i]);
                if (itr == not_set1.begin())
                {
                    out = true;
                }
                else
                {
                    itr--;
                    vec11[i] = *itr;
                    not_set1.erase(itr);
                }
            }
        }
        if (out)
        {
            cout << "NO \n";
        }
        else
        {
            cout << "YES \n";
            for (int e : vec11)
                cout << e << " ";
            cout << "\n";
            for (int e : vec12)
                cout << e << " ";
            cout << "\n";
        }
    }
    return 0;
}