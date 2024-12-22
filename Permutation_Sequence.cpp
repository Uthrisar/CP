#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int fact[10];
    string ans;
    vector<int> v;

    string getPermutation(int n, int k) {
        fact[0] = 1;
        for (int i = 1; i <= 9; i++) {     //pre-computation of factorial.
            fact[i] = i * fact[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            v.push_back(i);
        }
        solve(ans, k-1, n);  // Subtract 1 from k because it's 0-based.
        return ans;
    }

    void solve(string &s, int k, int n) {
        if (n == 0) {
            return;
        }
        
        int num = k / fact[n - 1];
        char ch = v[num] + '0';   // convert to character by adding '0' or 48.
        v.erase(v.begin() + num);
        s += ch;
        solve(s, k % fact[n - 1], n - 1);
    }
};

int main() {
    Solution sol;
    int n, k;      // 1 <= n <= 9 , 1 <= k <= n!
    cin >> n >> k;
    string result = sol.getPermutation(n, k);
    cout << "The " << k << "th permutation of numbers from 1 to " << n << " is: " << result << endl;
    return 0;
}

