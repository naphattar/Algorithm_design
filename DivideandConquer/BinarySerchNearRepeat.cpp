#include<iostream>
int n,m,q;
int arr[100001];
using namespace std;

int binary_search(int target){
    // need smallest idx such that arr[idx] <= target
    int mid;
    int l = 0;
    int r = n;
    while( l < r){
        mid = (l+r)/2;
        if(target >= arr[mid]){
            l = mid+1;
        }else{
            r = mid;
        }
    }
    if(l < n && arr[l] <= target){
        l++;
    }
    return l-1;
   
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