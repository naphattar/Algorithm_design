#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    cin >> n;
    vector<int> v(n,0);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int ans = 0;
    for(int i = 1;i<n;i = i+2){
        ans += v[i]-v[i-1];
    }
    cout << ans;
    return 0;
}