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
    vector<string>grid(N, string(N, '.'));
    int T = 3600, t=3600;
    bool flag;
    while(t<=T+60) {
        flag = false;
        for(vector<float>&v: arr) {
            float y=v[0], x=v[1], dy=v[2], dx=v[3];
            int nx = x+(t*dx), ny = y+(t*dy);
            if(nx>=0 && nx<N && ny>=0 && ny<N && grid[nx][y]=='.') {
                grid[nx][ny] = '#';
                flag = true;
            }
        }
        if(flag) {
            cout<<"|"<<t<<"|\n";
            for(string str: grid) cout<<str<<"\n";
            cout<<"\n";
        }
        t++;
    }
    cout<<"\nLast State\n";
    cout<<"|"<<t-1<<"|\n";
    for(string str: grid) cout<<str<<"\n";
    cout<<"\n";
    cout<<"\nRES::\n"<<""<<"\n";
}

int main() {
    vector<vector<float>> arr = get_input("06");
    solve(arr);
    return 0;
}
