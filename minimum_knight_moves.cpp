#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9+10;
bool vis[8][8];
int level[8][8];


int getX(string s){
	return s[0] - 'a';
}

int getY(string s){
	return s[1] - '1';
}

vector<pair<int,int>> movements = {{1, 2}, {2, 1},{1, -2}, {2, -1},
								   {-1, 2}, {-2, 1},{-1, -2}, {-2, -1}};

bool isValid(int x, int y){
	return x >= 0 && y >= 0 && x < 8 && y < 8 && !vis[x][y];
}

int bfs(string source, string dest){
	int sourceX = getX(source);
	int sourceY = getY(source);
	int destX = getX(dest);
	int destY = getY(dest);
	
	queue<pair<int,int>> q;
	q.push({sourceX, sourceY});
	vis[sourceX][sourceY] = true;
	level[sourceX][sourceY] = 0;
	level[destX][destY] = INF;
	
	while(!q.empty()){
		pair<int,int> v = q.front();
		q.pop();
		int x = v.first;
		int y = v.second;
		
		for(auto movement : movements) {
			int childX = x + movement.first;
			int childY = y + movement.second;
			
			if(isValid(childX, childY)){
				q.push({childX, childY});
				vis[childX][childY] = true;
				level[childX][childY] = level[x][y]+1;
			}
		}
		
		if(level[destX][destY] != INF) break;
	}
	
	return level[destX][destY];
	
}

void reset() {
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			vis[i][j] = false;
		}
	}
}

int main(){
	int T;
	cin >> T;
	for(int i = 0; i < T; i++){
		string s1, s2;
		cin >> s1 >> s2;
		cout << bfs(s1, s2) << endl;
		reset();
	}
}
