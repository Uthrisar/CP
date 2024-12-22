#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string>> all_ans;

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(0, n, board);
        return all_ans;
    }

    bool isSafe(int row, int col, vector<string> &board){
        int n = board.size();
        for(int r = 0; r < n; r++){
            if(board[r][col] == 'Q')
                return false;
        }
        for(int c = 0; c < n; c++){
            if(board[row][c] == 'Q')
                return false;
        }
        for(int r = row, c = col; r >= 0 && c >= 0; r--, c--){
            if(board[r][c] == 'Q')
                return false;
        }
        for(int r = row, c = col; r < n && c < n; r++, c++){
            if(board[r][c] == 'Q')
                return false;
        }
        for(int r = row, c = col; r >= 0 && c < n; r--, c++){
            if(board[r][c] == 'Q')
                return false;
        }
        for(int r = row, c = col; r < n && c >= 0; r++, c--){
            if(board[r][c] == 'Q')
                return false;
        }
        return true;
    }

    void solve(int col, int &n, vector<string> &board){
        if(col == n){
            all_ans.push_back(board);
            return;
        }
        for(int row = 0; row < n; row++){
            if(isSafe(row, col, board)){
                board[row][col] = 'Q'; 
                solve(col + 1, n, board);
                board[row][col] = '.';
            }
        }
    }
};

int main(){
	int n;
	cin >> n;
	Solution sol;
	vector<vector<string>> answer = sol.solveNQueens(n);
	int sol_no = 0;
	for(auto a_v: answer){
		sol_no++;
		cout << sol_no<< "st sol --> ";
		for(auto a: a_v){
			cout << a << ", ";
		}	
		cout << endl;
	}
	return 0;
}
