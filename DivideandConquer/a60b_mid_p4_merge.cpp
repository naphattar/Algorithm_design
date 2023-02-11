#include<iostream>
using namespace std;

void solve(int n,int k,int l,int r){
    // solve the 

}
int main(){
    int n,k;
    cin >> n >> k;
    if(k%2 == 0 || k >= 2*n){
        cout << -1;
        return;
    }
    solve(n,k,0,n);
    return 0;
}