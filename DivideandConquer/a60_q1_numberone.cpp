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
    if(r == l){
        return x%2 ? 1 : 0;
    }
    long long sz = getlen(x);
    long long mid = (sz-1)/2;
    long long ans = solve(x/2,l,min(mid-1,r))+solve(x/2,0,r-mid-1);
    ans = x%2 ? ans+1 : ans;
    return ans;
}

int main(){
    long long  x,l,r;
    cin >> x >> l >> r;
    cout << solve(x,l-1,r-1);
    return 0;
}