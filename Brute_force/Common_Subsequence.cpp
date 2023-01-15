#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int t,n,m,elm;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    cin >> t;
    while(t--){
        int ans = 0,idx;
        set<int> a;
        cin >> n >> m;
        for(int i = 0;i<n;i++){
            cin >> elm;
            a.insert(elm);
        }
        for(int i = 0;i<m;i++){
            cin >> elm;
            if( ans == 0 && a.find(elm) != a.end()){
                idx = elm;
                ans++;
            }
        }
        if(ans > 0 ){
            cout << "YES" << "\n";
            cout << ans << " " << idx << "\n";
        }else{
            cout << "NO" << "\n";
        }
    }
    return 0;
}