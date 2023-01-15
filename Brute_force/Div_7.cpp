#include<iostream>
using namespace std;
int n,t;
void solve(int n){
    int md = n%7;
    int c = n%10;
    if( c >= md){
        cout << n - md << "\n";
        return;
    }
    if(c -md + 7 >= 0){
        cout << n - md +7 << "\n";
        return;
    }
    cout << n - md + 14 << "\n";
    return;
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    cin >> t;
    while(t--){
        cin >> n;
        solve(n);
    }
    
    return 0;
}