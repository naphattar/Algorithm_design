#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,h,a,ans = 0;
int home[33],guest[33]; 
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> home[i] >> guest[i];
    }
    sort(guest,guest+n);
    for(int i = 0;i<n;i++){
        int start = lower_bound(guest,guest+n,home[i]) - guest;
        int stop = upper_bound(guest,guest+n,home[i]) - guest;
        ans += stop -start;
    }
    cout << ans;
    return 0;
}