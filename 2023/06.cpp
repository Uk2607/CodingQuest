#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<map>

using namespace std;

vector<vector<float>> get_input(string file_name) {
    string file_path = "2023/"+file_name+".in";
    ifstream file(file_path);

    vector<vector<float>> arr;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }

    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        vector<float>t;
        int x;
        while(ss>>x) t.push_back(x);
        arr.push_back(t);
    }
    
    file.close();
    return arr;
}

void solve(vector<vector<float>>&arr) {
    int N = 100;
    vector<vector<char>>grid(N, vector<char>(N, '.'));
    int T = 3600, t=0;
    while(t<=T) {
        for(vector<float>&v: arr) {
            float x=v[0], y=v[1], dx=v[2], dy=v[3];
            float nx = x+(t*dx), ny = y+(t*dy);
            if(nx>=0 && nx<N &&ny>=0 && ny<N) grid[int(nx)][int(ny)] = '#';
        }
        t++;
    }
    for(vector<char>v: grid) {
        for(char c: v) cout<<c;
        cout<<"\n";
    }
    cout<<"\nRES::\n"<<""<<"\n";
}

int main() {
    vector<vector<float>> arr = get_input("05");
    solve(arr);
    return 0;
}
