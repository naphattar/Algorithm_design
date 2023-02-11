#include<iostream>
#include<vector>
using namespace std;
int n,cnt = 0;
/*
testcase 1:
4
10 30 40 20

testcase 2:
6
1 5 4 2 3 -1
*/
int solve(int l,int r,vector<int> &v, vector<int> &tmp){
    if(l == r){
        return 0;
    }
    int mid = (l+r)/2;
    int result = solve(l,mid,v,tmp);
    result = result + solve(mid+1,r,v,tmp);
    int pt1 = l,pt2 = mid+1,pt = 0;
    while(pt1 <= mid || pt2 <= r ){
        if(pt1 > mid){
            tmp[pt++] = v[pt2++];
        }else if(pt2 > r){
            tmp[pt++] = v[pt1++];
        }else{
            if(v[pt1] > v[pt2]){
                tmp[pt++] = v[pt2++];
                result += mid+1-pt1;
            }else{
                tmp[pt++] = v[pt1++];
            }
        }
    }
    for(int i = 0;i<pt;i++) v[l+i] = tmp[i];
    return result;
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    cin >> n;
    vector<int> v(n,0),tmp(n,0);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    cnt = solve(0,n-1,v,tmp);
    cout << cnt;
    return 0;

}