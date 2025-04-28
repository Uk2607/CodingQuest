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

    TreeNode() : id(0), left(NULL), right(NULL) {} // Default constructor

    TreeNode(long long val) : id(val), left(NULL), right(NULL) {} // Parameterized constructor

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

TreeNode* insertNode(long long val, TreeNode *root) {
    if (root == NULL) {
        TreeNode* newNode = new TreeNode(val);
        return newNode;
    }
    if(val<=root->id) root->left = insertNode(val, root->left);
    else root->right = insertNode(val, root->right);
    return root;
}

int tree_height(TreeNode *node) {
    if(node==NULL) return 0;
    return 1+max(tree_height(node->left), tree_height(node->right));
}

int tree_width(TreeNode *node) {  // The width of a binary tree is defined as the maximum number of nodes present at any level in the tree
    queue<TreeNode*>q;
    q.push(node);
    int max_width = 0;
    while(!q.empty()) {
        int n = q.size();
        max_width = max(max_width, n);
        while(n--) {
            TreeNode *node = q.front(); q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return max_width;
}

void solve(vector<string>&arr) {
    TreeNode *root = NULL;
    for(string hex: arr) {
        long long x = hex_to_dec(hex);
        root = insertNode(x, root);
    }
    int h = tree_height(root);
    int d = tree_width(root);
    cout<<"Height:: "<<h<<"\n";
    cout<<"Width:: "<<d<<"\n";
    cout<<"RES:: "<<(h*d)<<"\n";
}

int main() {
    vector<string>arr = get_input("09");
    solve(arr);
    return 0;
}
