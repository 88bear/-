#include <bits/stdc++.h>
#define int long long
#define ipair pair<int, int>
using namespace std;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool issafe(int x, int y, vector<vector<int>>& maze, vector<vector<bool>>& vis){
    return(x >= 0 && x < maze.size() && y >= 0 && y < maze.size() && maze[x][y] == 0 && !vis[x][y]);
}

bool findP(int x, int y, vector<vector<int>>& maze, vector<vector<bool>>& vis, vector<ipair>& path){
    int n = maze.size();
    
    if(x == n-2 && y == n-2){
        path.push_back({x, y});
        return true;
    }

    vis[x][y] = true;
    path.push_back({x, y});

    for(int i = 0; i < 4; i++){
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];

        if(issafe(dx, dy, maze, vis)){
            if(findP(dx, dy, maze, vis, path)){
                return true;
            }
        }
    }

    path.pop_back();
    vis[x][y] = false;
    return false;
}

signed main(){
    string line;
    vector<vector<int>> maze;

    while(getline(cin, line)){
        vector<int> row;
        stringstream ss(line);
        int num;
        while(ss >> num){
            row.push_back(num);
        }
        maze.push_back(row);
    }

    int n = maze.size();
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    vector<ipair> path;

    int stx = 1, sty = 1;

    findP(stx, sty, maze, vis, path);
    
    for(auto p : path){
        maze[p.first][p.second] = -1;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(maze[i][j] == -1){
                cout << '#';
            } else {
                cout << maze[i][j];
            }
            if(j != n-1){
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
