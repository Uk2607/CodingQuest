#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<sstream>
#include<map>

using namespace std;

vector<vector<double>> get_input(string file_name) {
    string file_path = "2024/"+file_name+".in";
    ifstream file(file_path);

    vector<vector<double>> arr;

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
        arr.push_back({stod(t[t.size()-3]), stod(t[t.size()-2]), stod(t[t.size()-1])});
    }
    
    file.close();
    return arr;
}

void solve(vector<vector<double>>&arr) {
    double min_dist = INT_MAX;
    for(int i=0;i<arr.size();i++) {
        for(int j=i+1;j<arr.size();j++) {
            double dist = sqrt(pow(arr[i][0]-arr[j][0], 2)+pow(arr[i][1]-arr[j][1], 2)+pow(arr[i][2]-arr[j][2], 2));
            min_dist = min(min_dist, dist);
        }
    }
    cout<<"\nRES:: "<<fixed<<setprecision(3)<<min_dist<<"\n\n"; 
    return;
}

int main() {
    vector<vector<double>> arr = get_input("04");
    solve(arr);
    return 0;
}
