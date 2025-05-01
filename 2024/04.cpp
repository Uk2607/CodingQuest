#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<map>

using namespace std;

vector<vector<float>> get_input(string file_name) {
    string file_path = "2024/"+file_name+".in";
    ifstream file(file_path);

    vector<vector<float>> arr;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }

    string line;
    bool first = true;

    while (getline(file, line)) {
        if(first) {
            first = false;
            continue;
        }
        vector<string>t;
        stringstream ss(line);
        string x;
        while(ss>>x) t.push_back(x);
        arr.push_back({stof(t[t.size()-3]), stof(t[t.size()-2]), stof(t[t.size()-1])});
    }
    
    file.close();
    return arr;
}

void solve(vector<vector<float>>&arr) {
    for(vector<float> f: arr)
        cout<<f[0]<<", "<<f[1]<<", "<<f[2]<<"\n";
    cout<<"\nRES:: "<<""<<"\n\n";
    return;
}

int main() {
    vector<vector<float>> arr = get_input("04");
    solve(arr);
    return 0;
}
