#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<set>

using namespace std;

#define ll long long
#define ull unsigned long long

vector<string>  get_input(string file_name) {
    string file_path = "2022/"+file_name+".in";
    ifstream file(file_path);

    vector<string> arr;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }

    string line;

    while (getline(file, line)) {
        arr.push_back(line);
    }
    
    file.close();
    return arr;
}

int gameStatus(vector<vector<int>>grid) {
    for(int i=0;i<7;i++) {
        for(int j=0;j<7;j++) {  // Forward, Downward & Main Diagonal
            int x = grid[i][j];
            if(x==-1) continue;
            if(i<4 && grid[i+1][j]==x && grid[i+2][j]==x && grid[i+3][j]==x) return x;  // Forward
            if(j<4 && grid[i][j+1]==x && grid[i][j+2]==x && grid[i][j+3]==x) return x;  // Downward
            if(i<4 && j<4 && grid[i+1][j+1]==x && grid[i+2][j+2]==x && grid[i+3][j+3]==x) return x;  // Diag
        }
        for(int j=6;j>=3;j--) {  // Anti Diagonal
            int x = grid[i][j];
            if(x==-1) continue;
            if(i<4 && grid[i+1][j-1]==x && grid[i+2][j-2]==x && grid[i+3][j-3]==x) return x;  // Anti Diag
        }
    }
    return -1;
}

void solve(vector<string>&arr) {
    vector<int>pFreq(3, 0);
    for(string game: arr) {
        vector<vector<int>>grid(7, vector<int>(7, -1));
        int player = 0;
        vector<int>pos(7, 0);
        for(int i=0;i<game.length();i++) {
            int j = pos[game[i]-'1'];
            grid[game[i]-'1'][j] = player;
            int won = gameStatus(grid);
            pos[game[i]-'1']++;
            player = (player+1)%3;
            if(won!=-1) {
                pFreq[won]++;
                break;
            }
        }
    }
    cout<<"\nRES:: "<<pFreq[0]*pFreq[1]*pFreq[2]<<"\n\n";
}

int main() {
    vector<string> arr = get_input("04");
    solve(arr);
    return 0;
}
