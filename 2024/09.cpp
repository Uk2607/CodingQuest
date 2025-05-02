#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<map>

using namespace std;

pair<vector<string>,vector<string>> get_input(string file_name) {
    string file_path = "2024/"+file_name+".in";
    ifstream file(file_path);

    vector<string>arr1, arr2;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return {arr1, arr2};
    }

    bool flag = true;
    string line;

    while (getline(file, line)) {
        if(line.length()==0) {
            flag=!flag;
            continue;
        }
        if(flag) arr1.push_back(line);
        else arr2.push_back(line);
    }
    
    file.close();
    return {arr1, arr2};
}

void solve(vector<string>grid1, vector<string>grid2) {
    cout<<"\nRES:: "<<""<<"\n\n";
    return;
}

int main() {
    pair<vector<string>,vector<string>> p = get_input("09");
    solve(p.first, p.second);
    return 0;
}
