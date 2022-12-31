#include <bits/stdc++.h>

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
#define PB push_back

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

    int n;
    lli x;
    scd(n);
    sclld(x);
    vector<lli> vec(n);
    frange(i, n) sclld(vec[i]);
    vector<lli> vec_copy = vec;
    sort(vec.begin(), vec.end());
    auto ptr1 = vec.begin();
    auto ptr2 = vec.end() - 1;
    auto ptr3 = ptr1 + 1;
    while (ptr1 != ptr2)
    {
        lli mas = 0;
        lli mis = 3e9 + 5;

        while (ptr3 != ptr2)
        {
            lli s = *ptr1 + *ptr2 + *ptr3;
            mas = max(s, mas);
            mis = min(mis, s);
            if (s == x)
            {
                auto a = find(vec_copy.begin(), vec_copy.end(), *ptr1);
                auto b = find(vec_copy.begin(), vec_copy.end(), *ptr2);
                auto c = find(vec_copy.begin(), vec_copy.end(), *ptr3);
                if (a == b && a == c)
                {
                    b = find(a + 1, vec_copy.end(), *ptr2);
                    c = find(b + 1, vec_copy.end(), *ptr3);
                }
                else if (a == b)
                    b = find(a + 1, vec_copy.end(), *ptr2);
                else if (b == c)
                    c = find(b + 1, vec_copy.end(), *ptr3);
                else if (a == c)
                    c = find(a + 1, vec_copy.end(), *ptr3);
                if (a == vec_copy.end() || b == vec_copy.end() || c == vec_copy.end())
                    continue;
                printf("%d %d %d", a - vec_copy.begin() + 1, b - vec_copy.begin() + 1, c - vec_copy.begin() + 1);
                return 0;
            }
            ptr3++;
        }

        if (mas < x)
            ptr1++;
        else if (mas > x)
            ptr2--;
        ptr3 = ptr1 + 1;
    }

    printf("IMPOSSIBLE");
    return 0;
}