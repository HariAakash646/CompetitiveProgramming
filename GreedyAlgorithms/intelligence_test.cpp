#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCLLU(t) scanf("%llu",&t)
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
    int n; SCD(n);
    VI vec(n);
    
    for_range(i, n) {
        SCD(vec[i]);
    }
    int max = *max_element(vec.begin(), vec.end());
    VVI freq(max+1);
    for_range(i, n) {
        freq[vec[i]].push_back(i);
    }
    int t; SCD(t);
    for_range(i, t) {
        int l; SCD(l);
        VI seq(l);
        for_range(j, l) SCD(seq[j]);
        auto beg = vec.begin();
        int r = -1;
        
        bool brk = false;
        for(int e : seq) {
            VI &idxs = freq[e];
            auto pos = upper_bound(idxs.begin(), idxs.end(), r);
            if(pos == idxs.end()) {
                brk = true;
                break;
            }
            r = *pos;
            
        }
        if(brk) printf("NIE\n");
        else printf("TAK\n");
    }
    return 0;
}
