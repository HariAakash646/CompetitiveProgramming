#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int median(vector<int> vec) {
    sort(vec.begin(), vec.end());
    int s = vec.size();
    if(s % 2 == 0) {
        return (vec[s/2] + vec[s/2 - 1]) / 2;
    }
    else {
        return vec[s/2];
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> X_vec(n), Y_vec(n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &X_vec[i], &Y_vec[i]);
    }
    printf("%d %d", median(X_vec), median(Y_vec));

    return 0;
}
