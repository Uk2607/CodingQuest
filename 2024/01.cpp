#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<map>

using namespace std;

vector<tuple<string, string, int>> get_input(string file_name) {
    string file_path = "2024/"+file_name+".in";
    ifstream file(file_path);

    vector<tuple<string, string, int>> arr;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }

    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string airline, type;
        int cost;
        ss>>airline>>type>>cost;
        arr.push_back(make_tuple(airline.substr(0, airline.length()-1), type, cost));
    }
    
    file.close();
    return arr;
}

void solve(vector<tuple<string, string, int>>&arr) {
    map<string, int>total_cost;
    for(tuple<string, string, int>t: arr) {
        string airline = get<0>(t);
        string type = get<1>(t);
        int cost = get<2>(t);
        if(type=="Discount" || type=="Rebate") cost = -cost;
        if(total_cost.find(airline)==total_cost.end()) total_cost[airline] = cost;
        else total_cost[airline]+=cost;
    }
    int min_cost = INT_MAX;;
    for(auto [_, cost]: total_cost) min_cost = min(min_cost, cost);
    cout<<"\nRES:: "<<min_cost<<"\n\n";
    return;
}

int main() {
    vector<tuple<string, string, int>> arr = get_input("01");
    solve(arr);
    return 0;
}
