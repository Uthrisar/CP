#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int ans = 0;
    int three = (a+b+c);
    ans = 3*(n/three);
    int rem = n%three;
    if(rem > 0 && rem <= a){
        ans += 1;
    } else if(rem > a && rem <= a+b){
        ans += 2;
    } else if(rem > a+b){
        ans += 3;
    }
    cout << ans << endl;
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        solve();
    }
}