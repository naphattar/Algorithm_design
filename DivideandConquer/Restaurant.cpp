#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,a;
vector<long long> chef(1001,0);
/*
test case 1 
3 5
2 2 5
4 5 6 30 123456789012

0 0 0 2 2 4 4 5 6 6 8 8 10 10 10 
*/

int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    cin >> n >> a;
    for(int i = 0;i<n;i++){
        cin >> chef[i];
    }
    while(a--){
        long long customer;
        cin >> customer;
        // binary search on 0 and 1e18 to find a smallest time work
        long long l = 0,r = 1e18,mid;
        while(l<r){
            mid = (l+r)/2;
            long long served = n;
            for(int i = 0;i<n;i++){
                served += mid/chef[i];
            }
            if(served >= customer){
                // it's work
                r = mid;
            }else{
                l = mid+1;
            } 
        }
        cout << l << "\n";
    }
    
    return 0;
}