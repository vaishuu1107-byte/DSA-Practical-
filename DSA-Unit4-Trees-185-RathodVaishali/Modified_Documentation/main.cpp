#include <iostream>
#include <queue>
#include <limits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    explicit Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Insert a value. Duplicate values are ignored.
Node* insertNode(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);

    return root;
}

bool searchNode(Node* root, int value) {
    if (root == nullptr)
        return false;
    if (root->data == value)
        return true;
    if (value < root->data)
        return searchNode(root->left, value);
    return searchNode(root->right, value);
}

Node* findMin(Node* root) {
    if (root == nullptr)
        return nullptr;
    while (root->left != nullptr)
        root = root->left;
    return root;
}

Node* findMax(Node* root) {
    if (root == nullptr)
        return nullptr;
    while (root->right != nullptr)
        root = root->right;
    return root;
}

// Delete a value while preserving the BST property.
Node* deleteNode(Node* root, int value) {
    if (root == nullptr)
        return nullptr;

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == nullptr) {
            Node* replacement = root->right;
            delete root;
            return replacement;
        }
        if (root->right == nullptr) {
            Node* replacement = root->left;
            delete root;
            return replacement;
        }

        // Two children: replace with the inorder successor.
        Node* successor = findMin(root->right);
        root->data = successor->data;
        root->right = deleteNode(root->right, successor->data);
    }
    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Improvement: breadth-first (level-order) traversal.
void levelOrder(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty.";
        return;
    }

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
}

// Improvement: display each node with its children.
void displayStructure(Node* root, int depth = 0, const char* side = "Root") {
    if (root == nullptr) return;
    for (int i = 0; i < depth; ++i) cout << "    ";
    cout << side << ": " << root->data << "\n";
    displayStructure(root->left, depth + 1, "L");
    displayStructure(root->right, depth + 1, "R");
}

// Improvement: free all dynamically allocated nodes on exit.
void destroyTree(Node* root) {
    if (root == nullptr) return;
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

void showMenu() {
    cout << "\n\n--- Binary Search Tree Menu ---\n"
         << "1. Insert\n"
         << "2. Search\n"
         << "3. Delete\n"
         << "4. Inorder Traversal\n"
         << "5. Preorder Traversal\n"
         << "6. Postorder Traversal\n"
         << "7. Level-order Traversal (NEW)\n"
         << "8. Find Minimum (NEW)\n"
         << "9. Find Maximum (NEW)\n"
         << "10. Display Tree Structure (NEW)\n"
         << "11. Exit\n"
         << "Enter your choice: ";
}

int readInt(const char* prompt, int& value) {
    cout << prompt;
    if (cin >> value) return 1;

    cout << "Invalid input. Please enter an integer.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return 0;
}

int main() {
    Node* root = nullptr;
    int choice = 0;
    int value = 0;

    do {
        showMenu();
        if (!(cin >> choice)) {
            cout << "Invalid menu input. Please enter a number from 1 to 11.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                if (readInt("Enter value to insert: ", value)) {
                    bool alreadyExists = searchNode(root, value);
                    root = insertNode(root, value);
                    if (alreadyExists)
                        cout << "Duplicate value ignored; BST unchanged.\n";
                    else
                        cout << "Insertion completed.\n";
                }
                break;

            case 2:
                if (readInt("Enter value to search: ", value)) {
                    if (searchNode(root, value))
                        cout << value << " found in the BST.\n";
                    else
                        cout << value << " not found in the BST.\n";
                }
                break;

            case 3:
                if (readInt("Enter value to delete: ", value)) {
                    if (searchNode(root, value)) {
                        root = deleteNode(root, value);
                        cout << "Deletion completed.\n";
                    } else {
                        cout << value << " not found in the BST.\n";
                    }
                }
                break;

            case 4:
                cout << "Inorder Traversal: ";
                if (root == nullptr) cout << "Tree is empty.";
                else inorder(root);
                cout << "\n";
                break;

            case 5:
                cout << "Preorder Traversal: ";
                if (root == nullptr) cout << "Tree is empty.";
                else preorder(root);
                cout << "\n";
                break;

            case 6:
                cout << "Postorder Traversal: ";
                if (root == nullptr) cout << "Tree is empty.";
                else postorder(root);
                cout << "\n";
                break;

            case 7:
                cout << "Level-order Traversal: ";
                levelOrder(root);
                cout << "\n";
                break;

            case 8: {
                Node* minimum = findMin(root);
                if (minimum == nullptr) cout << "Tree is empty.\n";
                else cout << "Minimum value: " << minimum->data << "\n";
                break;
            }

            case 9: {
                Node* maximum = findMax(root);
                if (maximum == nullptr) cout << "Tree is empty.\n";
                else cout << "Maximum value: " << maximum->data << "\n";
                break;
            }

            case 10:
                if (root == nullptr) cout << "Tree is empty.\n";
                else {
                    cout << "Tree Structure (L = left child, R = right child):\n";
                    displayStructure(root);
                }
                break;

            case 11:
                cout << "Freeing tree memory and exiting.\n";
                destroyTree(root);
                root = nullptr;
                break;

            default:
                cout << "Invalid choice. Please select 1 to 11.\n";
        }
    } while (choice != 11);

    return 0;
}
