#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int p,k,a,b;
vector<long long> avenger(100001,0); 
long long solve(long long l,long long r){
   int totalavenger = upper_bound(avenger.begin(),avenger.begin()+k,r) - lower_bound(avenger.begin(),avenger.begin()+k,l);
   if(totalavenger <= 0){
        return a;
   }
   if(l == r){
        return b*totalavenger; 
   }
   long long notdivided = b*totalavenger*(r-l+1);
   long long mid = (l+r)/2;
   long long divided = solve(l,mid)+solve(mid+1,r);
   return min(notdivided,divided);
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
    ofstream out("output.txt");
    cout.rdbuf(out.rdbuf());
    
    cin >> p >> k >> a >> b;
    for(int i = 0;i<k;i++){
        cin >>avenger[i];
        avenger[i] -= 1;
    }
    sort(avenger.begin(),avenger.begin()+k);
    cout << solve(0, (1<< p)-1);
    return 0;
}