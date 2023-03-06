#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    int n,q;
    long long c;
    cin >> n >> q;
    long long dp[n] = {0};
    pair<int,int> arr[n+1];
    arr[0] = make_pair(0,0);
    for(int i = 0;i<n;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr,arr+n+1);
    for(int i = 1;i<n;i++){
        dp[i] = dp[i-1]+arr[i].second;
    }
    while(q--){
        cin >> c;
        int pos = lower_bound(dp,dp+n,c) - dp;
        cout << arr[pos].first << "\n";
    }
    return 0;
}