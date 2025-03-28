#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

vector<vector<int>> get_input(string file_name) {
    string file_path = "_2022/"+file_name+".in";
    ifstream file(file_path);

    vector<vector<int>>arr;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }

    string line;

    while(getline(file, line)) {
        stringstream ss(line);
        int x;
        vector<int>t;
        while(ss>>x) t.push_back(x);
        arr.push_back(t);
    }
    file.close();
    return arr;
}

vector<pair<int,int>>dir = {{0,1}, {-1, 0}, {0, -1}, {1, 0}};

int dfs(vector<vector<int>>&grid, int x, int y, int R, int C) {
    if(x<0 || x>=R || y<0 || y>=C) return 0;
    if(grid[x][y]==0) return 0;
    int sum = grid[x][y];
    grid[x][y] = 0;
    for(auto [dx, dy]: dir) {
        sum+=dfs(grid, x+dx, y+dy, R, C);
    }
    return sum;
}

void solve(vector<vector<int>>&grid) {
    int r = grid.size(), c = grid[0].size();
    int cnt = 0, sum = 0;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(grid[i][j]!=0) {
                cnt++;
                sum+=dfs(grid, i, j, r, c);
            }
        }
    }
    cout<<"\nRES:: "<<sum/cnt<<"\n\n";
}

int main() {
    vector<vector<int>>arr = get_input("03");
    solve(arr);
    return 0;
}