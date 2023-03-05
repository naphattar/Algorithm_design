#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n,q,a,b;
    long long c;
    cin >> n >> q;
    vector<long long> dp(n,0);
    vector<pair<int,int>> arr(n+1,make_pair(0,0));
    for(int i = 0;i<n;i++){
        cin >> a >> b;
        arr[i].first = a;
        arr[i].second = b;
    }
    sort(arr.begin(),arr.end());
    for(int i = 1;i<n;i++){
        dp[i] = dp[i-1]+arr[i].second;
    }
    while(q--){
        cin >> c;
        int pos = lower_bound(dp.begin(),dp.begin()+n,c) - dp.begin();
        cout << arr[pos].first << "\n";
    }
    return 0;
}