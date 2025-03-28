#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

string  get_input(string file_name) {
    string file_path = "_2022/"+file_name+".in";
    ifstream file(file_path);

    string str;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return str;
    }

    file>>str;
    file.close();
    return str;
}

void solve(string &str) {
    cout<<str<<"\n";
    cout<<"\nRES:: "<<""<<"\n\n";
}

int main() {
    string arr = get_input("05");
    solve(arr);
    return 0;
}