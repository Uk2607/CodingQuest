#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<map>

using namespace std;

vector<vector<int>> get_input(string file_name) {
    string file_path = "2023/"+file_name+".in";
    ifstream file(file_path);

    vector<vector<int>> arr;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }

    string line;

    while (getline(file, line)) {
        int x;
        vector<int>t;
        stringstream ss(line);
        while(ss>>x) t.push_back(x);
        arr.push_back(t);
    }
    
    file.close();
    return arr;
}

bool state(vector<vector<char>>&b) {
    for(int i=0;i<3;i++) {
        if(b[i][0]!=' ' && b[i][0]==b[i][1] && b[i][0]==b[i][2]) return true;
        if(b[0][i]!=' ' && b[0][i]==b[1][i] && b[0][i]==b[2][i]) return true;
    }
    if(b[1][1]!=' ' && ((b[1][1]==b[0][0] && b[1][1]==b[2][2]) || (b[1][1]==b[0][2] && b[1][1]==b[2][0]))) return true;
    return false;
}

int play(vector<int>&game) {
    vector<vector<char>>b(3, vector<char>(3, ' '));
    bool p1 = true;
    for(int x: game) {
        b[(x-1)/3][(x-1)%3] = (p1?'X':'O');
        if(state(b)) return p1?1:-1;
        p1 = !p1;
    }
    return 0;
}

void solve(vector<vector<int>>&arr) {
    int x = 0, o = 0, d = 0;
    for(vector<int>v: arr) {
        int res = play(v);
        if(res == -1) o++;
        else if(res == 1) x++;
        else d++;
    }
    cout<<"X:"<<x<<"\n";
    cout<<"O:"<<o<<"\n";
    cout<<"-:"<<d<<"\n";
    cout<<"\nRES:: "<<x*o*d<<"\n\n";
    return;
}

int main() {
    vector<vector<int>> arr = get_input("03");
    solve(arr);
    return 0;
}
