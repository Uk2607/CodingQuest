#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<map>

using namespace std;

vector<int> get_input(string file_name) {
    string file_path = "2024/"+file_name+".in";
    ifstream file(file_path);

    vector<int> arr;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }

    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        int x;
        while(ss>>x) arr.push_back(x);
    }
    
    file.close();
    return arr;
}

void solve(vector<int>arr) {
    int R = 80, C = 100, idx = 0;
    bool dot = true;
    vector<string>grid(R, string(C, '.'));
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            if(arr[idx]<=0) {
                idx++;
                dot =! dot;
            }
            if(idx==arr.size()) break;
            if(dot) grid[i][j] = '.';
            else grid[i][j] = '#';
            arr[idx]--;
        }
        if(idx==arr.size()) break;
    }
    cout<<"\nRES::\n";
    for(string str: grid) cout<<str<<"\n";
    return;
}

int main() {
    vector<int> arr = get_input("03");
    solve(arr);
    return 0;
}
