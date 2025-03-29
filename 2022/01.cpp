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
    int L = 1500, R = 1600, sum = 0, i=0, cnt=0;
    while(i<60) sum+=arr[i++];
    if(sum/60<L || sum/60>R) cnt++;
    for(;i<arr.size();i++) {
        sum+=arr[i];
        sum-=arr[i-60];
        if(sum/60<L || sum/60>R) cnt++;
    }
    cout<<"\nRES:: "<<cnt<<"\n\n";
}

int main() {
    vector<int> arr = get_input("01");
    solve(arr);
    return 0;
}
