#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<map>

using namespace std;

pair<vector<pair<int,int>>, string> get_input(string file_name) {
    string file_path = "2023/"+file_name+".in";
    ifstream file(file_path);

    vector<pair<int,int>> arr;
    string moves;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return {arr, moves};
    }

    string line;
    int idx = 0;

    while (getline(file, line)) {
        idx++;
        if(idx%2==1) continue;
        if(idx==2) {
            stringstream ss(line);
            string coords;
            while(ss>>coords) {
                stringstream pairs(coords);
                int x, y;
                string t;
                bool flag = false;
                while(getline(pairs, t, ',')) {
                    if(!flag) x = stoi(t);
                    if(flag) y = stoi(t);
                    flag = !flag;
                }
                arr.push_back({y, x});
            }
        } else {
            moves = line;
        }
    }
    
    file.close();
    return {arr, moves};
}

void solve(vector<pair<int,int>>&fruits, string &moves) {
    int idx = 0, N = 20, score, k = 0;
    vector<pair<int,int>>snake = {{0, 0}};
    pair<int,int>f = fruits[idx];;
    vector<string>grid(N, string(N, '.'));
    grid[0][0] = 'S';
    grid[f.first][f.second] = 'F';
    for(char m: moves) {
        int snake_len = snake.size(), nx, ny;

        if(m == 'R') nx = snake[0].first, ny = snake[0].second+1;
        else if(m == 'L') nx = snake[0].first, ny = snake[0].second-1;
        else if(m == 'U') nx = snake[0].first-1, ny = snake[0].second;
        else nx = snake[0].first+1, ny = snake[0].second;

        if(nx<0 || nx>=N || ny<0 || ny>=N) break;
        if(make_pair(nx, ny) != f) {
            grid[snake[snake_len-1].first][snake[snake_len-1].second] = '.';
        }
        else {
            score+=100;
            snake.push_back({-1,-1});
            idx++;
            f = fruits[idx];
            grid[f.first][f.second] = 'F';
        }
        for(int i=snake.size()-1;i>0;i--) snake[i] = snake[i-1];
        for(pair<int,int>p: snake) if(p==make_pair(nx, ny)) break;
        snake[0] = {nx, ny};
        for(pair<int,int>p: snake) grid[p.first][p.second] = 'o';
        grid[snake[0].first][snake[0].second] = 'O';
        score++;

        cout<<m<<"\n";
        for(string r: grid) {
            cout<<r<<"\n";
            cout<<"\n";
        } cout<<"\n";

        cout<<++k<<" : "<<nx<<", "<<ny<<" == "<<score<<"\n";

    }
    cout<<"\nRES::\n"<<score<<"\n";
}

int main() {
    auto[fruits, moves]= get_input("07");
    solve(fruits, moves);
    return 0;
}
