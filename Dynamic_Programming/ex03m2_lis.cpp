#include<iostream>
#include<string>
#include<vector>
using namespace std;
int maxans = 0;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> s(n,0);
    for(int i = 0;i<n;i++){
        cin >> s[i];
    }
    vector<int> dp(n,1);
    for(int i = 1;i<n;i++){
        for(int j = 0;j<i;j++){
            if(s[i] > s[j] && dp[j]+1 > dp[i]){
                dp[i] = dp[j]+1;
            }
        }
        maxans = max(maxans,dp[i]);
    }
    cout << maxans;
    return 0;
}