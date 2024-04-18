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
typedef long double ld;

int findf(int x, vi &vec)
{
    while (x != vec[x])
    {
        x = vec[x];
    }
    return x;
}

void unionf(int x, int y, vi &vec, vi &siz)
{
    x = findf(x, vec);
    y = findf(y, vec);
    if (siz[x] < siz[y])
        swap(x, y);
    vec[y] = x;
    siz[x] = max(siz[x], siz[y] + 1);
}

int main() {
    int n;
    scd(n);
    vvi dist(n, vi(n));
    priority_queue<pair<int, pii>> pq;
    frange(i, n) {
        frange(j, n) {
            scd(dist[i][j]);
            pq.push(mp(-dist[i][j], mp(i, j)));
        }
    }
    vvi dis2(n, vi(n, 1e9+5));
    frange(i, n) {
        dist[i][i] = 0;
    }
    vi disset(n);
    frange(i, n) disset[i] = i;
    vi siz(n, 1);
    int c = 0;
    while(pq.size()) {
        auto p = pq.top();
        pq.pop();
        int co = p.f;
        int a = p.s.f; 
        int b = p.s.s;
        if(findf(a, disset) == findf(b, disset)) {
            if(co != dis2[a][b]) {
                printf("NO");
                return 0;
            }
        }
        else {
            unionf(a, b, disset, siz);
            frange(i, n) {
                dist[i][a] = min(dist[i][a], co + dist[i][b]);
                dist[b][i] = min(dist[b][i], co + dist[a][i]);
                dist[a][i] = dist[i][a];
                dist[i][b] = dist[b][i];
            }
            c++;
        }
        if(c >= n) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
}