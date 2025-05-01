#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<map>

using namespace std;

vector<string> get_grid(string key) {
    vector<string>grid(5, string(5, '.'));
    vector<bool>flag(26, false);
    flag[9] = true; // j changed to i
    int idx = 0, idx2 = 0;
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            if(idx<key.length()) {
                while(idx<key.length() && flag[key[idx]-'a']) idx++;
                grid[i][j] = key[idx];
                flag[key[idx]-'a'] = true;
                idx++;
            } else {
                while(idx2<26 && flag[idx2]) idx2++;
                grid[i][j] = idx2+'a';
                flag[idx2] = true;
                idx2++;
            }
        }
    }
    return grid;
}

void solve(string key, string msg) {
    vector<string>grid = get_grid(key);

    vector<pair<int,int>>mp(26, {-1, -1});
    for(int i=0;i<grid.size();i++)
        for(int j=0;j<grid[0].length();j++)
            mp[grid[i][j]-'a'] = {i, j};
    
    string res = "";
    for(int i=0;i<msg.length();i++) {
        if(msg[i]==' ') {
            res+=' ';
            continue;
        }
        string str = msg.substr(i, 2);
        int x1 = mp[str[0]-'a'].first, y1 = mp[str[0]-'a'].second, x2 = mp[str[1]-'a'].first, y2 = mp[str[1]-'a'].second;
        if(x1!=x2 && y1!=y2) {
            res += grid[x1][y2];
            res += grid[x2][y1];
        } else if(x1==x2 && y1!=y2) {
            res += grid[x1][(y1+4)%5];
            res += grid[x2][(y2+4)%5];
        } else if(x1!=x2 && y1==y2) {
            res += grid[(x1+4)%5][y1];
            res += grid[(x2+4)%5][y2];
        }
        i++;
    }
    cout<<"\nRES:: "<<res<<"\n\n";
    return;
}

int main() {
    // Get the input from the file 06.in
    string key = "codingquest";
    string msg = "rmqfgs yegv em qnpu pdml dc atuy olzy anpu";
    solve(key, msg);
    return 0;
}
