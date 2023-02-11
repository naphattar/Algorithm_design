#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n;
    cin >> n ;
    vector<int> v(2*n,0);
    for(int i = 0;i<n;i++){
        cin >> v[i];
        v[n+i] = v[i];
    }
    int maxans = v[0],bestans = v[0],cnt = 1;
    for(int i = 1;i<2*n;i++){
        if(maxans + v[i] > v[i]){
            if(cnt < n){
                maxans += v[i];
            }else{
                maxans += v[i] - v[i-cnt];
            }
            cnt++;
        }else{
            maxans = v[i];   
            cnt = 1;
        }
        if(maxans > bestans) bestans = maxans;
    }
    cout << bestans;
    return 0;
}