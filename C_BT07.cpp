#include <bits/stdc++.h>
using namespace std;
char maze[55][55];
int n, dx, dy;

void dfs(int x, int y){
    dx = x;
    dy = y;
    maze[x][y] = '0';
    if(y-1 >= 0 && maze[x][y-1] == '1'){
        dfs(x, y-1);
    }
    if(y+1 < n && maze[x][y+1] == '1'){
        dfs(x, y+1);
    }
    if(x+1 < n && maze[x+1][y] == '1'){
        dfs(x+1, y);
    }
    if(x-1 >= 0 && maze[x-1][y] == '1'){
        dfs(x-1, y);
    }
    maze[x][y] = '1';
}

int main(){
    while(cin >> n){
        int x, y;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin >> maze[i][j];
                if(maze[i][j] == 'S'){
                    x = i;
                    y = j;
                }
            }
        }

        dfs(x, y);
        
        maze[x][y] = 'S';
        maze[dx][dy] = '#';
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cout << maze[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}