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
    uint64 n;
    SCLLU(n);
    uint64 l = 0; uint64 r = n;
    uint64 pred = n / 2;
    cout << "? " << pred << endl;
    int rep;
    SCD(rep);
    pred = 1;
    while(l != r) {
        cout << "? " << pred << endl;
        SCD(rep);
        if(rep == 0) {
            l = (r+l)/2 + 1;
        }
        else {
            r = (r+l)/2;
        }
        if(pred > (r + l)/2) pred = pred - (r + l)/2;
        else pred = pred + (r + l)/2;
        
        
    }
    cout << "= " << l << endl;
    
    
    
    
    return 0;
}
