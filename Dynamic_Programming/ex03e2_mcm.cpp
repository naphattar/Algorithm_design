#include<iostream>
#include<vector>
int ans = INT32_MAX;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> s(n+1,0);
    for(int i = 0;i<=n;i++){
        cin >> s[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
    return 0;
}