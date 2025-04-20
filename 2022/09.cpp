#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<queue>

using namespace std;

#define ll long long
#define ull unsigned long long

vector<string> get_input(string file_name) {
    string file_path = "2022/"+file_name+".in";
    ifstream file(file_path);

    vector<string> arr;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }

    string line;

    while (getline(file, line))
        arr.push_back(line);
    
    file.close();
    return arr;
}

vector<pair<int,int>>dir = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

bool isInside(int x, int y, int R, int C) {
    return (x>=0 && x<R && y>=0 && y<C);
}

int bfs(vector<string>&arr, pair<int,int>start, pair<int,int>end, int R, int C) {
    set<pair<int,int>>vis;
    queue<pair<int,int>>q;
    int depth = 0;
    q.push(start);
    while(!q.empty()) {
        int n = q.size();
        while(n--) {
            pair<int,int>curr = q.front();
            q.pop();
            if(curr == end) return depth+1;
            vis.insert(curr);
            for(auto [dx, dy]: dir) {
                int nx = curr.first+dx, ny = curr.second+dy;
                if(arr[nx][ny]!='#' && vis.find({nx, ny})==vis.end() && isInside(nx, ny, R, C))
                    q.push({nx, ny});
            }
        }
        depth++;
    }
    return -1;
}

void solve(vector<string>&arr) {
    int R = arr.size(), C = arr[0].length();
    pair<int,int>start = {0, -1}, end = {R-1, -1};
    for(int j=0;j<C;j++) {
        if(arr[0][j] == ' ' && start.second==-1) start.second = j;
        if(arr[R-1][j] == ' ' && end.second==-1) end.second = j;
    }
    int min_len = bfs(arr, start, end, R, C);
    cout<<"\nRES:: "<<min_len<<"\n\n";
    return;
}

int main() {
    vector<string> arr = get_input("09");
    solve(arr);
    return 0;
}
