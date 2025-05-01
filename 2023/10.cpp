#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<map>
#include<set>

using namespace std;

map<string, vector<pair<int, string>>> get_input(string file_name) {
    string file_path = "2023/"+file_name+".in";
    ifstream file(file_path);

    map<string, vector<pair<int, string>>>mp;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return mp;
    }

    string line;

    while (getline(file, line)){
        string src = line.substr(0, 3);
        string dest_list = line.substr(7);
        stringstream ss(dest_list);

        vector<pair<int, string>>dest;
        string pr;
        while(ss>>pr) {
            string st = pr.substr(0, 3);
            int cost = stoi(pr.substr(4));
            dest.push_back({cost, st});
        }
        mp[src] = dest;
    }
    
    file.close();
    return mp;
}

void solve(map<string, vector<pair<int, string>>>&graph) {
    string src = "TYC", dest = "EAR";
    int stop_time = 600;
    set<pair<int,string>>pq;
    map<string,int>distance;
    for(auto node: graph) distance[node.first] = INT_MAX;
    distance[src] = 0;
    pq.insert({0, src});
    while(!pq.empty()) {
        auto [curr_dist, curr_node] = *pq.begin();
        pq.erase(pq.begin());
        for(auto [weight, next_node]: graph[curr_node]) {
            int dist = curr_dist+weight+stop_time;
            if(dist<distance[next_node]) {
                pq.erase({distance[next_node], next_node});
                distance[next_node] = dist;
                pq.insert({dist, next_node});
            }
        }
    }
    for (const auto& pair : distance)
        cout << "Distance from " << src << " to " << pair.first << " is " << pair.second-600 << endl;
    cout<<"RES:: "<<distance[dest]-600<<"\n";
}

int main() {
    map<string, vector<pair<int, string>>>mp = get_input("10");
    solve(mp);
    return 0;
}
