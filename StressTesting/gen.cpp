#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
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

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int n = rand(1, 10000);
    int q = rand(1, 10);
    printf("%d %d\n", n, q);
    int d = rand(1, (int)1e6);
    int a = 1;
    int b = d;
    printf("%d %d %d\n", d, a, b);
    int r = -1;
    for(int i = 0; i < n; ++i) {
        int a = rand(r+2, max(10000, r+2));
        int b = rand(a, max(100000, a));
        printf("%d %d\n", a, b);
        r = b;
    }
    
    frange(i, q) {
        int x;
        x = rand(1, 1e6);
        printf("%d\n", x);
    }
    puts("");
}
    