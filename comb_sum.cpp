#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> all_ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        solve(0, candidates, target, v);
        return all_ans;
    }

    void solve(int index, vector<int> &c, int t, vector<int> &v) {
        if (t == 0) {
            all_ans.push_back(v);
            return;
        }
        if(t < 0) return;
        for (int i = index; i < c.size(); i++) {
                v.push_back(c[i]);
                solve(i, c, t - c[i], v);
                v.pop_back();
        }
    }
};


int main(){
    Solution sol;
    int n;
    cin >> n;
    vector<int> input(n);
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }
    int target;
    cin >> target;
    vector<vector<int>> ans = sol.combinationSum(input, target);
    for(auto vec: ans){
        for(auto ele: vec){
            cout << ele <<"  ";
        }
        cout << endl;
    }
}
