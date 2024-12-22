#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<string> ans;
    vector<string> findPath(vector<vector<int>> &m, int n) {
    	string s;
    	vector<vector<int>> visited(n, vector<int>(n, 0));
        solve(0 , 0, m, n, s, visited);
        return ans;
    }
    void solve(int i, int j, vector<vector<int>> &m, int n, string &s, vector<vector<int>> &visited){
    	if (i < 0 || i >= n || j < 0 || j >= n || m[i][j] == 0 || visited[i][j] == 1) {
            return;
        }
    	if(i == n-1 && j == n-1) {
    		ans.push_back(s);
    		return;
    	}
    	
    		visited[i][j] = 1;
    		
    		s += 'R';
    		solve(i, j+1, m, n, s, visited);
    		s.pop_back();
    	
    		s += 'D';
    		solve(i+1, j, m, n, s, visited);
    		s.pop_back();
    	
    		s += 'U';
    		solve(i-1, j, m, n, s, visited);
    		s.pop_back();
    	
    		s += 'L';
    		solve(i, j-1, m, n, s, visited);
    		s.pop_back();
    		
    		visited[i][j] = 0;
    	
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}

