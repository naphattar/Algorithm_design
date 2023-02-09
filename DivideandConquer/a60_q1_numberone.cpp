#include<iostream>
#include<vector>
using namespace std;

long long  getlen(int n){
    if(n <= 1){
        return 1;
    }
    return 2*getlen(n/2)+1;
}

long long solve(long long x,long long l,long long r){

    long long n = getlen(x);
    if(r - l < 0){
        return 0;
    }
    long long mid = n/2;
    return x%2 + solve(x/2,l,min(r,mid-1))+solve(x/2,0,r-mid-1);

}

int main(){
    long long  x,l,r;
    cin >> x >> l >> r;
    cout << solve(x,l-1,r-1);
    return 0;
}