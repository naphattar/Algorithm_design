#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n,m,k;
    cin >> n >> m >> k;
    int arr[n+1] = {0};
    long long qs[n+1] = {0};
    for(int i = 1;i<=n;i++){
        cin >> arr[i];
        qs[i] = qs[i-1]+arr[i];
    }
    while(m--){
        int a;
        long long b,ans = 0;
        cin >> a >> b;
        // find max sum that <= b
        int l = a+1 , r = n,mid;
        while(l < r){
            mid = (l+r)/2;
            long long check =  qs[mid]-qs[a-1] + (mid-a+1)*k;
            if(check  == b){
                ans = qs[mid]-qs[a-1];
                break;
            }else if(check < b){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        if(ans){
            cout << ans << "\n";
        }else{
            cout << qs[l]-qs[a-1] << "\n";
        }

    }
    return 0;
}