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
    multiset<pair<uint32, uint64>> ms;
    int n;
    SCD(n);
    uint32 L; uint64 C;
    for_range(i, n) {
        SCLD(L); SCLLD(C);
        ms.insert(pair<uint32, uint64>{ L, C });
    }
    auto itr = ms.begin();
    uint64 t = 0;
    while(true) {
        if((*next(itr)).first==(*itr).first) {
            uint64 v = (*next(itr)).second+(*itr).second;
            ms.insert(pair<uint32, uint64>{ (*itr).first+1,  v });
            t += v;
            ms.erase(itr, next(next(itr)));
            itr = ms.begin();
        }
        else {
            itr++;
            ms.erase(ms.begin(), itr);
        }
        if(itr == ms.end()) break;
    }
    cout << t;
    return 0;
}
