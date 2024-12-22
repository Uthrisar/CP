#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        func(0, v, ans, candidates, target);
        return ans;
    }

    void func(int index, vector<int> &v, vector<vector<int>> &ans, vector<int> &nums, int t){
        if(t == 0){
            ans.push_back(v);
            return;
        }
        for(int i = index; i < nums.size(); i++){
            if(i > index && nums[i] == nums[i-1]) continue;
            if(nums[i] > t) break; 
            v.push_back(nums[i]);
            func(i+1, v, ans, nums, t-nums[i]);
            v.pop_back();
        }
    }
};


int main(){
    cout << "Enter vector size = ";
    int size;
    cin >> size;
    vector<int> v(size);
    cout << "Enter the elements of vector = ";
    for(int i = 0; i < size; i++){
        cin >> v[i];
    }
    cout << "Enter the target value = ";
    int target;
    cin >> target;
    cout << "Ans :-"<< endl;
    Solution sol;
    auto ans = sol.combinationSum2(v, target);
    int s = 1;
    for(auto an : ans){
        cout << s <<"st array is: ";
        for(auto ele: an){
            cout << ele << "  ";
        }
        s++;
        cout << endl;
    }
}