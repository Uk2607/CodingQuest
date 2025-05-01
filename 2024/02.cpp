#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<map>

using namespace std;

vector<string> get_input(string file_name) {
    string file_path = "2024/"+file_name+".in";
    ifstream file(file_path);

    vector<string> arr;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }

    string line;

    while (getline(file, line)) arr.push_back(line);
    
    file.close();
    return arr;
}

void solve(vector<string>&arr) {
    cout<<"\nRES:: "<<""<<"\n\n";
    return;
}

int main() {
    vector<string> arr = get_input("02");
    solve(arr);
    return 0;
}
