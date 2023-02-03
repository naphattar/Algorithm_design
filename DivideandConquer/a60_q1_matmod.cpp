#include<iostream>
#include<vector>
using namespace std;
long long n,k;
vector<vector<long long>> arr(2,vector<long long>(2,0));

vector<vector<long long>> mul(vector<vector<long long>>a,vector<vector<long long>>b){
    vector<vector<long long>> ans(2,vector<long long>(2,0));
    ans[0][0] =  (a[0][0]*b[0][0]+a[0][1]*b[1][0])%k;
    ans[0][1] =  (a[0][0]*b[0][1]+a[0][1]*b[1][1])%k;
    ans[1][0] =  (a[1][0]*b[0][0]+a[1][1]*b[1][0])%k;
    ans[1][1] =  (a[1][0]*b[0][1]+a[1][1]*b[1][1])%k;
    return ans;
}
vector<vector<long long>> solve(int x){
    if(x == 1){
        return arr;
    }
    vector<vector<long long>> newarr = solve(x/2);
    if(x%2 == 0){
        return mul(newarr,newarr);
    }
    return mul(arr,mul(newarr,newarr));
}
int main(){
    cin >> n >> k;
    cin >> arr[0][0] >> arr[0][1] >> arr[1][0] >> arr[1][1];
    vector<vector<long long>> ans = solve(n);
    cout << ans[0][0] <<" " << ans[0][1] << " " << ans[1][0] << " " << ans[1][1];
    return 0;
}