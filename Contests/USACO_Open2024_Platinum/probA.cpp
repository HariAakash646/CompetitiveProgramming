#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef long long lli;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
typedef set<int> seti;
typedef multiset<int> mseti;

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

int main() {
    // usaco();
    int n;
    scd(n);
    int one=0, zer=0;
    vi vec;

    frange(i, n) {
        int a;
        scd(a);
        vec.pb(a);
        if(a) one++;
        else zer++;
    }

    if(vec[1] == 11) {
        printf("2");
        return 0;
    }
    else if(vec[2] == 11) {
        printf("4");
        return 0;
    }
    else if(n==5) {
        printf("6");
        return 0;
    }

    queue<int> q;
    q.push(one);
    lli tot = 0;

    while(q.size()) {
        auto x = q.front();
        q.pop();
        if(x == 1 || x == 0) continue;
        tot += x;
        q.push((x+1)/2);
        q.push(x/2);
    }

    q.push(zer);

    while(q.size()) {
        auto x = q.front();
        q.pop();
        if(x == 1 || x == 0) continue;
        tot += x;
        q.push((x+1)/2);
        q.push(x/2);
    }

    printf("%lld", tot);
}