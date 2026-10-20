#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

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
    while (root != nullptr && root->left != nullptr)
        root = root->left;

    return root;
}

Node* deleteNode(Node* root, int value) {
    if (root == nullptr)
        return root;

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    int choice, value;

    do {
        cout << "\n\n--- Binary Search Tree Menu ---\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Preorder Traversal\n";
        cout << "6. Postorder Traversal\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insertNode(root, value);
                cout << "Insertion operation completed.\n";
                break;

            case 2:
                cout << "Enter value to search: ";
                cin >> value;

                if (searchNode(root, value))
                    cout << value << " found in the BST.\n";
                else
                    cout << value << " not found in the BST.\n";
                break;

            case 3:
                cout << "Enter value to delete: ";
                cin >> value;

                if (searchNode(root, value)) {
                    root = deleteNode(root, value);
                    cout << "Deletion operation completed.\n";
                } else {
                    cout << value << " not found in the BST.\n";
                }
                break;

            case 4:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 5:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;

            case 6:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;

            case 7:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}
