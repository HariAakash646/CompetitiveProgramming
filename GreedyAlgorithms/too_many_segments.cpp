#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define for_range(i, j) FOR(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define PB push_back
 
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
 
int main()
{
    int n, k;
    SCD(n); SCD(k);
    VII line;
    int m = 0;
    int r, l;
    for_range(i, n) {
        SCD(l); SCD(r);
        line.PB(PII(r, l));
        m = max({m, l, r});
    }
    VII unsort_line = line;
    sort(line.begin(), line.end());
    VI points(m, 0);
    int rem = 0;
    VI rem_vec;
    for(PII p : line) {
        
        // for_each(points.begin() + p.second, points.begin() + p.first, [](int x){++x;});
        FOR(i, p.second-1, p.first, 1) {
            points[i]++;
        }
        // for(int e : points) printf("%d ", e);
        // printf("\n");
        if(find(points.begin(), points.end(), k+1) != points.end()) {
            
            // for(int e : points) printf("%d ", e);
            // printf("\n");
            rem += 1;
            rem_vec.push_back(find(unsort_line.begin(), unsort_line.end(), p) - unsort_line.begin());
            unsort_line[find(unsort_line.begin(), unsort_line.end(), p) - unsort_line.begin()] = PII(0, 0);
            FOR(i, p.second-1, p.first, 1) {
                points[i]--;
            }
        }
    }
    printf("%d\n", rem);
    for(int e : rem_vec) printf("%d ", e+1);
    
    
    return 0;
}
