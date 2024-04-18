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
    int n, k;
    scd(n);
    scd(k);
    vi vec(n);
    frange(i, n)
    {
        scd(vec[i]);
    }
    mseti st;
    frange(i, k)
    {
        st.insert(vec[i]);
    }
    mseti st1, st2;
    int mid = (k + 1) / 2;
    int id = 0;
    for (auto e : st)
    {
        if (id < mid)
        {
            st1.insert(e);
        }
        else
        {
            st2.insert(e);
        }
        id++;
    }
    int med = *prev(st1.end());
    printf("%d ", med);
    // printf("\nst1: ");
    // for (auto e : st1)
    // {
    //     printf("%d ", e);
    // }
    // printf("\n");
    // printf("st2: ");
    // for (auto e : st2)
    // {
    //     printf("%d ", e);
    // }
    // printf("\n");
    forr(i, k, n)
    {
        int a = vec[i];
        int b = vec[i - k];
        if (b <= med)
        {
            st1.erase(st1.find(b));
            st2.insert(a);
            st1.insert(*st2.begin());
            st2.erase(st2.begin());
        }
        else
        {
            st2.erase(st2.find(b));
            st1.insert(a);
            st2.insert(*prev(st1.end()));
            st1.erase(prev(st1.end()));
        }
        med = *prev(st1.end());
        printf("%d ", med);
        // printf("\nst1: ");
        // for (auto e : st1)
        // {
        //     printf("%d ", e);
        // }
        // printf("\n");
        // printf("st2: ");
        // for (auto e : st2)
        // {
        //     printf("%d ", e);
        // }
        // printf("\n");
    }
}