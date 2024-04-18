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
    vi vec(n + 1, -1);
    vi num(n);
    int c = 0;
    frange(i, n)
    {
        int a;
        scd(a);
        num[i] = a;
        vec[a] = i;
        if (vec[a - 1] == -1)
            c++;
    }
    frange(_, m)
    {
        int a, b, ai, bi;
        scd(ai);
        scd(bi);
        ai--;
        bi--;
        a = num[ai];
        b = num[bi];
        num[ai] = b;
        num[bi] = a;
        if (a < b)
            swap(a, b);
        int oga = vec[a];
        int ogb = vec[b];
        swap(vec[a], vec[b]);
        if (a - 1 == b)
        {
            if (oga < ogb && vec[a] > vec[b])
                c--;
            else if (oga > ogb && vec[a] < vec[b])
                c++;
            if (a != n)
            {
                if (oga < vec[a + 1] && vec[a] > vec[a + 1])
                    c++;
                else if (oga > vec[a + 1] && vec[a] < vec[a + 1])
                    c--;
            }
            if (b != 1)
            {
                if (ogb > vec[b - 1] && vec[b] < vec[b - 1])
                    c++;
                else if (ogb < vec[b - 1] && vec[b] > vec[b - 1])
                    c--;
            }
        }
        else
        {
            if (oga > vec[a - 1] && vec[a] < vec[a - 1])
                c++;
            else if (oga < vec[a - 1] && vec[a] > vec[a - 1])
                c--;
            if (b != 1)
            {
                if (ogb > vec[b - 1] && vec[b] < vec[b - 1])
                    c++;
                else if (ogb < vec[b - 1] && vec[b] > vec[b - 1])
                    c--;
            }
            if (a != n)
            {
                if (oga < vec[a + 1] && vec[a] > vec[a + 1])
                    c++;
                else if (oga > vec[a + 1] && vec[a] < vec[a + 1])
                    c--;
            }
            if (ogb < vec[b + 1] && vec[b] > vec[b + 1])
                c++;
            else if (ogb > vec[b + 1] && vec[b] < vec[b + 1])
                c--;
        }
        printf("%d\n", c);
    }
}