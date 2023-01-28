#include<iostream>
int n,m,q;
int arr[100001];
using namespace std;

int binary_search(int target){
    // need smallest arr[] such that arr[] <= target
    int l = 0;
    int r = n-1;
    int mid;
    while(l<=r){
        mid = (l+r)/2;
        if(arr[mid] == target){
            return arr[mid];
        }
        if(arr[mid] > target){
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return r == -1 ? -1 : arr[r]; 
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    while(m--){
        cin >> q;
        cout << binary_search(q) << "\n";
    }
    return 0;
}