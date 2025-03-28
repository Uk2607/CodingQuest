#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<map>

using namespace std;

vector<int>  get_input(string file_name) {
    string file_path = "2022/"+file_name+".in";
    ifstream file(file_path);

    vector<int> arr;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }

    string line;

    while (getline(file, line)) {
        arr.push_back(stoi(line));
    }
    
    file.close();
    return arr;
}

void solve(vector<int>&arr) {
    cout<<"\nRES:: "<<""<<"\n\n";
}

int main() {
    vector<int> arr = get_input("01");
    solve(arr);
    return 0;
}