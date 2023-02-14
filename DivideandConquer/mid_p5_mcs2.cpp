#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n,summ = 0;
    cin >> n ;
    vector<int> v(n,0);
    for(int i = 0;i<n;i++){
        cin >> v[i];
        summ += v[i];
    }
    int maxans = v[0],bestans = v[0];
    int minans = 0,bestminans = 0;
    for(int i = 1;i<n;i++){
        if(maxans + v[i] > v[i]){
            maxans += v[i];
        }else{
            maxans = v[i];   
        }
        if(maxans > bestans) bestans = maxans;

        if(minans + v[i] < v[i]){
            minans += v[i];
        }else{
            minans = v[i];
        }
        bestminans = min(bestminans,minans);
    }
    if(bestminans == summ){
        cout << bestans;
        return 0;
    }
    cout << max(bestans,summ-bestminans);
    return 0;
}