#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<map>

using namespace std;

vector<string> get_input(string file_name) {
    string file_path = "2023/"+file_name+".in";
    ifstream file(file_path);

    vector<string>arr;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }

    string line;

    while (getline(file, line))
        arr.push_back(line);
    
    file.close();
    return arr;
}

struct TreeNode {
    long long id;
    TreeNode *left, *right;

    TreeNode(long long id) {
        left = NULL;
        right = NULL;
    }

    TreeNode(TreeNode *node) {
        id = node->id;
        left = node->left;
        right = node->right;
    }
};

long long hex_to_dec(string hex) {
    int mul = 0;
    long long res = 0;
    for(int i=hex.length()-1;i>=0;i--) {
        int x;
        if(hex[i]>='a' && hex[i]<='f') x = hex[i]-'a'+10;
        else x = hex[i]-'0';
        res += pow(16, mul)*x;
        mul++;
    }
    return res;
}

void solve(vector<string>&arr) {
    for(string hex: arr) {
        long long x = hex_to_dec(hex);
        cout<<hex<<" "<<x<<"\n";
    }
    cout<<"RES:: "<<""<<"\n";
}

int main() {
    vector<string>arr = get_input("09");
    solve(arr);
    return 0;
}
