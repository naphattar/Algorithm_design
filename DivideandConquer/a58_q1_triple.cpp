#include<iostream>
using namespace std;
long long v[1001];
int n,m;

void solve(long long q){
    bool found = false;
    if(q < v[0]+v[1]+v[2] || q > v[n-3]+v[n-2]+v[n-1]){
        cout << "NO" << "\n";
        return;
    }
    for(int m = 1;m<n-1 && !found;m++){
        int l = 0,r = n-1;
        // two pointer
        while(l < m && m < r && !found){
            if(v[l]+v[m]+v[r] == q){
                found = true;
                break;
            }else if(v[l]+v[m]+v[r] > q){
                r--;
            }else{
                l++;
            }
        }

    }
    if(found){
        cout << "YES" << "\n";
    }else{
        cout << "NO" << "\n";
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    while(m--){
        long long q;
        cin >> q;
        solve(q);
    }
    return 0;
}