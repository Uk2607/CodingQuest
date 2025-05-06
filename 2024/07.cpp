#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>
#include <vector>
#include <regex>

using namespace std;

struct Node {
    string name; // Name of the file or folder
    bool isFile; // true if it's a file, false if it's a folder
    long long size; // Size of the file (0 if it's a folder)
    vector<Node*> children; // Children nodes

    Node(const string& name, bool isFile, long long size = 0) 
        : name(name), isFile(isFile), size(size) {}
};

Node* get_input(const std::string& file_name) {
    string file_path = "2024/"+file_name+".in";
    ifstream infile(file_path);
    if (!infile.is_open()) {
        cerr << "Unable to open file: " << file_name << endl;
        return nullptr;
    }

    unordered_map<int, Node*> folderMap; // Folder number -> Node
    string line;
    int currentFolder = -1;

    // First pass: create folder nodes
    while (getline(infile, line)) {
        if (line.rfind("Folder: ", 0) == 0) {
            currentFolder = stoi(line.substr(8));
            string folderName = "Folder_" + to_string(currentFolder); // Temporary name
            folderMap[currentFolder] = new Node(folderName, false);
        }
    }

    infile.clear();
    infile.seekg(0);
    currentFolder = -1;

    // Regex to match folder references: "name [FOLDER X]"
    regex folderRefRegex(R"((.+)\s+\[FOLDER (\d+)\])");

    while (getline(infile, line)) {
        if (line.empty()) continue;

        if (line.rfind("Folder: ", 0) == 0) {
            currentFolder = stoi(line.substr(8));
        } else if (line[0] == ' ') {
            size_t dash = line.find('-');
            if (dash == string::npos) continue;

            string trimmed = line.substr(dash + 1);
            while (!trimmed.empty() && trimmed[0] == ' ') trimmed = trimmed.substr(1);

            smatch match;
            if (regex_match(trimmed, match, folderRefRegex)) {
                // It's a folder reference
                string name = match[1];
                int folderIndex = stoi(match[2]);
                if (folderMap.count(folderIndex)) {
                    Node* folderNode = folderMap[folderIndex];
                    folderNode->name = name; // Update with actual name
                    folderMap[currentFolder]->children.push_back(folderNode);
                }
            } else {
                // It's a file
                size_t lastSpace = trimmed.find_last_of(' ');
                if (lastSpace == string::npos) continue;

                string name = trimmed.substr(0, lastSpace);
                string sizeStr = trimmed.substr(lastSpace + 1);
                long long size = stoll(sizeStr);

                Node* fileNode = new Node(name, true, size);
                folderMap[currentFolder]->children.push_back(fileNode);
            }
        }
    }

    infile.close();
    return folderMap.count(0) ? folderMap[0] : nullptr;
}

// Function to delete the tree and free memory
void delete_tree(Node* node) {
    if (node) {
        for (Node* child : node->children) delete_tree(child); // Recursively delete children
        delete node; // Delete the current node
    }
}


void print_tree(Node* node, int depth = 0) {
    if (!node) return;
    cout << string(depth * 2, ' ') << (node->isFile ? "File: " : "Folder: ") << node->name;
    if (node->isFile) cout << " (" << node->size << ")";
    cout << endl;
    for (Node* child : node->children) {
        print_tree(child, depth + 1);
    }
}

void solve(Node* root) {

    print_tree(root);

    cout<<"\nRES:: "<<""<<"\n\n";
    return;
}

int main() {
    // Node *root = get_input("07");
    Node *root = get_input("07.0");
    solve(root);
    delete_tree(root);
    return 0;
}
