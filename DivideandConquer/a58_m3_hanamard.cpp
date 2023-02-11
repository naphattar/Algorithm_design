#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

void solve(int n,vector<int> &v,int mfront){
    if(n == 1) return; // just multiply by 1
    int mid = n/2;
    solve(mid,v,0);
    solve(mid,v,mid);
    for(int i = 0;i<mid;i++){
        v[mfront+i] = v[mfront+i] + v[mfront+mid+i]; 
        v[mfront+mid+i] = v[mfront+i] - 2*v[mfront+mid+i]; 
    }
}
int main(){
    ios_base::sync_with_stdio(false),cout.tie(nullptr);
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
    ofstream out("output.txt");
    cout.rdbuf(out.rdbuf());
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0;i<n;i++) cin >> v[i];
    solve(n,v,0);
    for(int i = 0;i<n;i++) cout << v[i] << " ";
    return 0;
}