#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,mn,mx,ans = 0,score;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> score;
        if(i == 0){
            mn = score;
            mx = score;
        }else{
            if(score > mx){
                ans++;
                mx = score;
            }else if(score < mn){
                ans++;
                mn = score;
            }
        }
    }
    cout << ans;
    return 0;
}