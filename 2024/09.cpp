#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<map>

using namespace std;

vector<vector<string>> get_input(string file_name) {
    string file_path = "2024/"+file_name+".in";
    ifstream file(file_path);

    vector<vector<string>>arr(2);

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }

    bool flag = true;
    string line;

    while (getline(file, line)) {
        if(line.length()==0) {
            flag=!flag;
            continue;
        }
        if(flag) arr[0].push_back(line);
        else arr[1].push_back(line);
    }
    
    file.close();
    return arr;
}

vector<pair<int,int>>dirs = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

int bfs(vector<vector<string>>&grid, tuple<int,int,int>&start, tuple<int,int,int>&end) {
    int F = 2;
    int R = grid[0].size();
    int C = grid[0][0].size();
    vector<vector<vector<bool>>> visited(F, vector<vector<bool>>(R, vector<bool>(C, false)));
    queue<tuple<int, int, int, int>> q; // floor, row, col, steps

    q.push({get<0>(start), get<1>(start), get<2>(start), 0});
    visited[get<0>(start)][get<1>(start)][get<2>(start)] = true;

    while(!q.empty()) {
        auto [f, x, y, steps] = q.front();
        q.pop();

        if(make_tuple(f, x, y)==end) {
            return steps;
        }

        for(auto [dx, dy]: dirs) {

            if(grid[f][x][y]=='$') {
                int nf = (f+1)%2;
                if(!visited[nf][x][y]) {
                    visited[nf][x][y] = true;
                    q.push({nf, x, y, steps});
                }
            }

            int nx = x+dx;
            int ny = y+dy;

            if(nx>=0 && nx<R && ny>=0 && ny<C && !visited[f][nx][ny] && grid[f][nx][ny]!='#') {
                visited[f][nx][ny] = true;
                q.push({f, nx, ny, steps + 1});
            }
        }
    }
    return -1;
}

void solve(vector<vector<string>>&grid) {
    // for(vector<string>floor: grid) {
    //     for(string row: floor) cout<<row<<"\n";
    //     cout<<"\n";
    // }
    int R = grid[0].size();
    int C = grid[0][0].length();
    tuple<int,int,int>start = {0, 1, 0}, end = {0, R-2, C-1};
    int min_len = bfs(grid, start, end);
    cout<<"\nRES:: "<<min_len<<"\n\n";
    return;
}

int main() {
    vector<vector<string>> arr = get_input("09");
    solve(arr);
    return 0;
}
