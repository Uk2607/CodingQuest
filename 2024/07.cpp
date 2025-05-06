#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<regex>
#include<queue>

using namespace std;

struct Node {
    string name; // Name of the file or folder
    bool isFile; // true if it's a file, false if it's a folder
    long long size; // Size of the file (0 if it's a folder)
    vector<Node*> children; // Children nodes

    Node(const string& name, bool isFile, long long size = 0) 
        : name(name), isFile(isFile), size(size) {}
};

Node* get_input(const string& file_name) {
    string file_path = "2024/" + file_name + ".in";
    ifstream file(file_path);

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return nullptr; // Return nullptr if the file cannot be opened
    }

    Node* root = new Node("Root", false); // Create a root node
    Node* currentFolder = root; // Start with the root folder
    vector<Node*> folderStack; // Stack to keep track of folders

    string line;
    while (getline(file, line)) {
        // Trim leading spaces
        line.erase(0, line.find_first_not_of(" \t"));

        // Check if the line indicates a folder
        if (line.find("Folder:") != string::npos) {
            string folderName = line.substr(line.find(":") + 2); // Extract folder name
            Node* newFolder = new Node(folderName, false); // Create a new folder node
            currentFolder->children.push_back(newFolder); // Add new folder to current folder
            folderStack.push_back(currentFolder); // Push current folder to stack
            currentFolder = newFolder; // Move to the new folder
        } else {
            // Process files
            regex fileRegex(R"((.+?)\s+(\d+)(?:\s+$$FOLDER\s+\d+$$)?)");
            smatch match;

            if (regex_match(line, match, fileRegex)) {
                string fileName = match[1].str(); // File name
                long long fileSize = stoll(match[2].str()); // File size
                Node* newFile = new Node(fileName, true, fileSize); // Create a new file node
                currentFolder->children.push_back(newFile); // Add file to current folder
            }
        }

        // Check for indentation or end of folder (you may need to adjust this logic)
        if (line.empty() || line.find("Folder:") != string::npos) {
            if (!folderStack.empty()) {
                currentFolder = folderStack.back(); // Pop back to the previous folder
                folderStack.pop_back();
            }
        }
    }

    file.close();
    return root;
}

// Function to delete the tree and free memory
void delete_tree(Node* node) {
    if (node) {
        for (Node* child : node->children) delete_tree(child); // Recursively delete children
        delete node; // Delete the current node
    }
}


void solve(Node* root) {

    queue<Node*>q;

    q.push(root);
    while(!q.empty()) {
        int n = q.size();
        while(n--) {
            Node *curr = q.front();
            q.pop();
            cout<<curr->name<<" ";
            for(Node *child: curr->children) {
                q.push(child);
            }
        }
        cout<<"\n";
    }

    cout<<"\nRES:: "<<""<<"\n\n";
    return;
}

int main() {
    Node *root = get_input("07");
    solve(root);
    delete_tree(root);
    return 0;
}
