#include <bits/stdc++.h>
using namespace std;

void ml(vector<vector<int>>& board){
    int n = board.size();
    for(int i = 0; i < n; ++i){
        vector<int> dr(n, 0);
        int pos = 0;
        for(int j = 0; j < n; ++j){
            if(board[i][j] != 0){
                if(pos > 0 && dr[pos - 1] == board[i][j] && (pos == 1 || dr[pos - 2] != board[i][j])){
                    dr[pos - 1] *= 2;
                }else{
                    dr[pos++] = board[i][j];
                }
            }
        }
        board[i] = dr;
    }
}

void mr(vector<vector<int>>& board){
    int n = board.size();
    for(int i = 0; i < n; ++i){
        vector<int> dr(n, 0);
        int pos = n - 1;
        for(int j = n - 1; j >= 0; --j){
            if(board[i][j] != 0){
                if(pos < n - 1 && dr[pos + 1] == board[i][j] && (pos == n - 2 || dr[pos + 2] != board[i][j])){
                    dr[pos + 1] *= 2;
                }else{
                    dr[pos--] = board[i][j];
                }
            }
        }
        board[i] = dr;
    }
}

void mu(vector<vector<int>>& board){
    int n = board.size();
    for(int j = 0; j < n; ++j){
        vector<int> dc(n, 0);
        int pos = 0;
        for(int i = 0; i < n; ++i){
            if(board[i][j] != 0){
                if(pos > 0 && dc[pos - 1] == board[i][j] && (pos == 1 || dc[pos - 2] != board[i][j])){
                    dc[pos - 1] *= 2;
                }else{
                    dc[pos++] = board[i][j];
                }
            }
        }
        for(int i = 0; i < n; ++i){
            board[i][j] = dc[i];
        }
    }
}

void md(vector<vector<int>>& board){
    int n = board.size();
    for(int j = 0; j < n; ++j){
        vector<int> dc(n, 0);
        int pos = n - 1;
        for(int i = n - 1; i >= 0; --i){
            if(board[i][j] != 0){
                if(pos < n - 1 && dc[pos + 1] == board[i][j] && (pos == n - 2 || dc[pos + 2] != board[i][j])){
                    dc[pos + 1] *= 2;
                }else{
                    dc[pos--] = board[i][j];
                }
            }
        }
        for(int i = 0; i < n; ++i){
            board[i][j] = dc[i];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 4;
    char dir;
    vector<vector<int>> board(n, vector<int>(n));
    
    while(cin >> dir){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin >> board[i][j];
            }
        }
        if(dir == 'L') ml(board);
        else if(dir == 'R') mr(board);
        else if(dir == 'U') mu(board);
        else if(dir == 'D') md(board);
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cout << board[i][j];
                if(j < n - 1) cout << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
