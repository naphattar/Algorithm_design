#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    vector<int> price(n,0);
    vector<pair<int,int>> dp(n,make_pair(2e9,1)); // dp[i] = {min price to cover [1,i+1],the maximum distance its cover}
    for(int i = 0;i<n;i++){
        cin >> price[i];
        if(i <= k){ // its can cover to [1,i+1]
            dp[i] = make_pair(price[i],min(n,i+1+k));
        }
        dp[i].second = min(n,i+1+k);
    }
    for(int i = 1;i<n;i++){
        int start = max(1,i+1-k) , stop = min(n,i+1+k);
        int j =  max(0,i-1-2*k);
        while(j < i){
            if(j+1+k < i+1 || dp[j].second < i+1){
                // need price[i]
                if(dp[j].second >= start-1 && dp[j].first+price[i] <= dp[i].first){
                    dp[i] = make_pair(dp[j].first + price[i],stop);
                    dp[i].second = stop;
                }
            }else {
                // do not need price[i] but need to check if the maximum distance really cover position i+1 ?? 
                if(dp[j].second >= start-1){
                    dp[i] = min(dp[i],dp[j]);
                }
            }
            /*
            cout << "i = " << i << " j = " << j;
            for(auto t : dp){
                cout << " (" << t.first << " " << t.second << ") ";
            }
            cout << endl;
            */
            j++;
        }
    }
    cout << dp[n-1].first;
    return 0;
}