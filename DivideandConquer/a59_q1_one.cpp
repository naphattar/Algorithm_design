#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long a[11] = {0,1,2,3,4,5,6,6,5,4,3};
vector<long> q = {1,11,111,1111,11111,111111,1111111,11111111,111111111};
long solve(long x){
    x = x > 0 ? x : -1*x;
    if( x < 11){
        return a[x];
    }
    int idx = upper_bound(q.begin(),q.end(),x) - q.begin();
    int k1 = x/q[idx-1];
    if(x == q[idx-1]){
        return idx;
    }
    long solve1 =  min(k1*idx+solve(x-q[idx-1]*k1),k1*idx+idx+solve(q[idx-1]*(k1+1)-x));
    if(q[idx]-x < x){
        return min(idx+1+solve(q[idx]-x),solve1);
    }
    return solve1;
}
int main(){
    long n;
    cin >> n;
    cout << solve(n) << "\n";
}
