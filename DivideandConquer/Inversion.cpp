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
void merge(vector<int> &v,int l,int mid,int r,vector<int> &tmp){
    int bi = l;
    int ci = mid+1; 
    for(int i = l;i<=r;i++){
        if(ci > r){
            tmp[i] = v[bi++];
            continue;
        }
        if(bi > mid){
            tmp[i] = v[ci++];
            continue;
        }
        tmp[i] = (v[bi] < v[ci]) ? v[bi++] : v[ci++];
    }
    for(int i = l;i<=r;i++){
        v[i] = tmp[i];
    }
    for(auto elm : v){
        cout << elm << " ";
    }
    
    cout << cnt << "\n";
}
void merge_sort(vector<int> &v,int l,int r,vector<int> &tmp){
    if(l < r){
        int mid = (l+r)/2;
        merge_sort(v,l,mid,tmp);
        merge_sort(v,mid+1,r,tmp);
        merge(v,l,mid,r,tmp);
    }
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    cin >> n;
    vector<int> v(n,0),tmp(n,0);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    merge_sort(v,0,v.size()-1,tmp);
    /*
    for(auto t : v){
        cout << t << " ";
    }
    */
    cout << cnt;
    return 0;

}