#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int j=0; j<n; j++){
        cin>>b[j];
    }
    int ans = 0;
    for(int i=0; i<n-1; i++){
        if(a[i]>b[i+1]){
            ans += (a[i]-b[i+1]);
        }
    }
    ans += a[n-1];
    cout << ans << endl;
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        solve();
    }
}