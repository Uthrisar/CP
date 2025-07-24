#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x : a){
        cin>>x;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i=0; i<n; i++){
        if(a[i] > i+1){
            ans += (a[i]-i-1);
        }
    }
    cout<<ans;
}