#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

pair<vector<vector<int>>, vector<pair<int,int>>> get_input(string file_name) {
    string file_path = "_2022/"+file_name+".in";
    ifstream file(file_path);

    vector<vector<int>>arr;
    vector<pair<int,int>>moves;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return {arr, moves};
    }

    string line;

    while(getline(file, line)) {
        stringstream ss(line);
        int x;
        vector<int>t;
        while(ss>>x) t.push_back(x);
        if(t.size()!=2) arr.push_back(t);
        else moves.push_back({t[0], t[1]});
    }
    file.close();
    return {arr, moves};
}

void restructure_grid(vector<vector<int>>&grid, int r, int c) {
    for(int i=0;i<r/2;i++) swap(grid[i], grid[r-i-1]);
    for(int i=0;i<r;i++)
        if(i%2==1)
            for(int j=0;j<c/2;j++)
                swap(grid[i][j], grid[i][c-j-1]);
}

pair<int,int> move_player(vector<vector<int>>&grid, pair<int,int>pos, int steps) {
    int r = grid.size(), c = grid[0].size();
    pair<int,int>me = pos;
    do {
        int index = me.first * c + me.second;
        index += steps;
        index = max(0, min(index, r * c - 1));
        me = {index / c, index % c};
        steps = grid[me.first][me.second];
    } while (steps!=0);
    return me;
}

void solve(vector<vector<int>>grid, vector<pair<int,int>>moves) {
    int r = grid.size(), c = grid[0].size(), n = moves.size(), cnt = 0, res;
    restructure_grid(grid, r, c);
    pair<int,int>p1 = {0, 0}, p2 = {0, 0};
    for(int i=0;i<moves.size();i++) {
        cnt++;
        
        p1 = move_player(grid, p1, moves[i].first);
        if(p1 == make_pair(r-1, c-1)) {res = cnt; break;}
        
        p2 = move_player(grid, p2, moves[i].second);
        if(p2 == make_pair(r-1, c-1)) {res = cnt*2; break;}
    }
    cout<<"\nRES:: "<<res<<"\n";
}

int main() {
    pair<vector<vector<int>>, vector<pair<int,int>>> ip = get_input("01");
    solve(ip.first, ip.second);
    return 0;
}
