// Not working
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
typedef vector<lli> vll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int main()
{
    int t;
    cin >> t;
    frange(_, t)
    {
        int k;

        string str;
        cin >> str;
        cin >> k;
        set<pair<int, int>> st;
        int mv = 10;
        int mi = -1;
        bool zero = false;
        frange(i, k + 1)
        {
            if (str[i] == '0')
            {
                zero = true;
                st.insert({str[i] - '0', i});
            }
            else if (!zero && str[i] - '0' < mv)
            {
                mv = str[i] - '0';
                mi = i;
                st = {};
            }
            else
            {
                st.insert({str[i] - '0', i});
            }
        }
        str = str.substr(mi);
        k -= mi;
        while (k > 0)
        {
            mv = (*st.begin()).f;
            mi = (*st.begin()).s - mi;
            forr(i, st.size(), k + 1)
            {
                if (str[i] - '0' < mv)
                {
                    mv = str[i - st.size()] - '0';
                    mi = i - st.size();
                    st = {};
                }
                else
                {
                    st.insert({str[i] - '0', i});
                }
            }
            if (mi + 1 < str.size())
                str = str[0] + str.substr(mi + 1);
            else
                str = str[0];
            k -= mi;
        }
        cout << str << "\n";
    }
}