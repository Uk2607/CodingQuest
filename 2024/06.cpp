#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<map>

using namespace std;

void solve(string key, string msg) {
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
    for(string str: grid) cout<<str<<"\n";
    cout<<"\nRES:: "<<""<<"\n\n";
    return;
}

int main() {
    // Get the input from the file 06.in
    string key = "codingquest";
    string msg = "rmqfgs yegv em qnpu pdml dc atuy olzy anpu";
    solve(key, msg);
    return 0;
}
