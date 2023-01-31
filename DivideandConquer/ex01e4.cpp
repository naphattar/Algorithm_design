#include<iostream>
using namespace std;
int x,n,k;
long long solve(int x,int n){
    if(n == 1){
        return x%k;
    }
    if(n%2 == 1){
        long long md = solve(x,n/2);
        return (x*md*md)%k;
    }
    long long md = solve(x,n/2);
    return (md*md)%k;
}

int main(){
    cin >> x >> n >> k;
    cout << solve(x,n);
    return 0;
}