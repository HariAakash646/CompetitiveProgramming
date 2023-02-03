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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    frange(_, t)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        set<char> st;
        vi vec1(n), vec2(n);
        frange(i, n)
        {
            char e = str[i];
            st.insert(e);
            vec1[i] = st.size();
        }
        st = {};
        frange(i, n)
        {
            char e = str[n - i - 1];
            st.insert(e);
            vec2[n - i - 1] = st.size();
        }
        int ma = 0;
        frange(i, n - 1)
        {
            ma = max(ma, vec1[i] + vec2[i + 1]);
        }

        printf("%d\n", ma);
    }
}
