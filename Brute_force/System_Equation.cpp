#include<iostream>
#include<math.h>
using namespace std;
int n,m,ans;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    cin >> n >> m;
    for(int b = 0;b<=n;b++){
        int a = pow(n-b,0.5);
        if(a *a == n-b && a + b*b == m){
            ans++;
        }
    }
    cout << ans;
    return 0;
}