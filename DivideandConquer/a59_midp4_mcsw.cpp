#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n,w;
    cin >> n >> w;
    vector<int> v(n,0);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    int maxans = v[0],cnt = 1,bestans = v[0];
    for(int i = 1;i<n;i++){
        if(maxans + v[i] >= v[i]){
            maxans += v[i];
            cnt++;
            if(cnt > w){
                maxans -= v[i-cnt+1];
                cnt--;
            }
        }else{
            maxans = v[i];
            cnt = 1;
        }
        if(cnt <= w){
            bestans = max(bestans,maxans);
        }
    }
    cout << bestans;
    return 0;
}