#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

long long getlen(long long x){
    int exp = log2(x);
    long long sz = 2*pow(2,exp)-1;
    return sz;
}

long long solve(long long x,long long l,long long r){
    if(r < l){
        return 0;
    }
    if(x <= 1){
        return x;
    }
    long long sz = getlen(x);
    long long mid = (sz-1)/2;
    long long nr = min(mid-1,r);
    long long nl = (l-mid-1 > 0) ? l-mid-1 : 0;
    long long ans = solve(x/2,l,nr)+solve(x/2,nl,r-mid-1);
    if(l <= mid && r >= mid) ans += (x%2); 
    return ans;
}

int main(){
    long long  x,l,r;
    cin >> x >> l >> r;
    cout << solve(x,l-1,r-1);
    return 0;
}