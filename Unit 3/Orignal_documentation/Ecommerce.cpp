#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    int productId;
    string productName;
    double price;
    int quantity;
    Node* next;

    Node(int id, string name, double p, int q) {
        productId = id;
        productName = name;
        price = p;
        quantity = q;
        next = nullptr;
    }
};

class ShoppingCart {
private:
    Node* head;

public:
    ShoppingCart() {
        head = nullptr;
    }

    // 1. Add item to the cart
    void addItem(int id, string name, double price, int quantity) {
        Node* newNode = new Node(id, name, price, quantity);
        
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Item added to cart.\n";
    }

    // 2. Update quantity
    void updateQuantity(int id, int newQuantity) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->productId == id) {
                temp->quantity = newQuantity;
                cout << "Quantity updated.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Product not found in cart.\n";
    }

    // 3. Remove item
    void removeItem(int id) {
        if (head == nullptr) {
            cout << "Cart is empty.\n";
            return;
        }

        // If the item to remove is the first node
        if (head->productId == id) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Item removed.\n";
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr && current->productId != id) {
            previous = current;
            current = current->next;
        }

        if (current != nullptr) {
            previous->next = current->next;
            delete current;
            cout << "Item removed.\n";
        } else {
            cout << "Product not found.\n";
        }
    }

    // 4. Simple display function
    void displayCart() {
        if (head == nullptr) {
            cout << "Cart is empty.\n";
            return;
        }

        Node* temp = head;
        double totalCost = 0.0;
        
        cout << "\n--- Cart Details ---\n";
        while (temp != nullptr) {
            cout << "ID: " << temp->productId 
                 << " | Name: " << temp->productName 
                 << " | Price: Rs" << temp->price 
                 << " | Qty: " << temp->quantity << "\n";
                 
            totalCost += (temp->price * temp->quantity);
            temp = temp->next;
        }
        cout << "Total Cost: Rs" << totalCost << "\n\n";
    }
};

int main() {
    ShoppingCart cart;
    int choice, id, qty;
    double price;
    string name;

    do {
        cout<<"1. Add Item"<<endl;
        cout<<"2. Update Qty"<<endl; 
        cout<<"3. Remove Item"<<endl;
        cout<<"4. Display Cart"<<endl;
        cout<<"5. Exit\n"<<endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "ID: "; cin >> id;
                cout << "Name: "; cin >> name;
                cout << "Price: "; cin >> price;
                cout << "Qty: "; cin >> qty;
                cart.addItem(id, name, price, qty);
                break;
            case 2:
                cout << "ID: "; 
                cin >> id;
                cout << "New Qty: "; 
                cin >> qty;
                cart.updateQuantity(id, qty);
                break;
            case 3:
                cout << "ID: "; 
                cin >> id;
                cart.removeItem(id);
                break;
            case 4:
                cart.displayCart();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
        cout << "\n";
    } while (choice != 5);

    return 0;
}