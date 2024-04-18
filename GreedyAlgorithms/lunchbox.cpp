#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, m;
    scanf("%d %d", &N, &m);
    vector<int> arr(m);
    for(int i = 0; i<m; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr.begin(), arr.end());
    int c = 0;
    int out = 0;
    for(int e : arr) {
        c += e;
        if (c > N) break;
        out += 1;
    }
    printf("%d", out);
    return 0;
}
