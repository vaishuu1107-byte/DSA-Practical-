#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

class Node {
public:
    int productId;
    string productName;
    double price;
    int quantity;
    Node* next;

    Node(int id, const string& name, double p, int q)
        : productId(id), productName(name), price(p), quantity(q), next(nullptr) {}
};

class ShoppingCart {
private:
    Node* head;

    Node* findItem(int id) const {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->productId == id) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

public:
    ShoppingCart() : head(nullptr) {}

    // Release every node still in the cart.
    ~ShoppingCart() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Prevent accidental shallow copies of a class owning raw pointers.
    ShoppingCart(const ShoppingCart&) = delete;
    ShoppingCart& operator=(const ShoppingCart&) = delete;

    void addItem(int id, const string& name, double price, int quantity) {
        if (findItem(id) != nullptr) {
            cout << "A product with this ID already exists.\n";
            return;
        }
        if (id <= 0 || name.empty() || price < 0 || quantity <= 0) {
            cout << "Invalid product details. ID must be positive, price cannot be negative, "
                    "and quantity must be greater than zero.\n";
            return;
        }

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

    void updateQuantity(int id, int newQuantity) {
        if (newQuantity <= 0) {
            cout << "Quantity must be greater than zero.\n";
            return;
        }

        Node* item = findItem(id);
        if (item != nullptr) {
            item->quantity = newQuantity;
            cout << "Quantity updated.\n";
        } else {
            cout << "Product not found in cart.\n";
        }
    }

    void removeItem(int id) {
        if (head == nullptr) {
            cout << "Cart is empty.\n";
            return;
        }

        if (head->productId == id) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Item removed.\n";
            return;
        }

        Node* previous = head;
        Node* current = head->next;

        while (current != nullptr && current->productId != id) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Product not found.\n";
            return;
        }

        previous->next = current->next;
        delete current;
        cout << "Item removed.\n";
    }

    void displayCart() const {
        if (head == nullptr) {
            cout << "Cart is empty.\n";
            return;
        }

        const Node* temp = head;
        double totalCost = 0.0;

        cout << "\n--- Cart Details ---\n";
        cout << fixed << setprecision(2);
        while (temp != nullptr) {
            cout << "ID: " << temp->productId
                 << " | Name: " << temp->productName
                 << " | Price: Rs " << temp->price
                 << " | Qty: " << temp->quantity << '\n';

            totalCost += temp->price * temp->quantity;
            temp = temp->next;
        }
        cout << "Total Cost: Rs " << totalCost << "\n\n";
    }
};

int main() {
    ShoppingCart cart;
    int choice = 0;

    do {
        cout << "===== E-Commerce Shopping Cart =====\n";
        cout << "1. Add Item\n";
        cout << "2. Update Quantity\n";
        cout << "3. Remove Item\n";
        cout << "4. Display Cart\n";
        cout << "5. Exit\n";
        cout << "Choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number from 1 to 5.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                int id, qty;
                double price;
                string name;

                cout << "ID: ";
                if (!(cin >> id)) {
                    cout << "Invalid ID.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Name: ";
                getline(cin, name);

                cout << "Price: ";
                if (!(cin >> price)) {
                    cout << "Invalid price.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                cout << "Qty: ";
                if (!(cin >> qty)) {
                    cout << "Invalid quantity.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                cart.addItem(id, name, price, qty);
                break;
            }
            case 2: {
                int id, qty;
                cout << "ID: ";
                if (!(cin >> id)) {
                    cout << "Invalid ID.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                cout << "New Qty: ";
                if (!(cin >> qty)) {
                    cout << "Invalid quantity.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                cart.updateQuantity(id, qty);
                break;
            }
            case 3: {
                int id;
                cout << "ID: ";
                if (!(cin >> id)) {
                    cout << "Invalid ID.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                cart.removeItem(id);
                break;
            }
            case 4:
                cart.displayCart();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please select 1 to 5.\n";
        }
        cout << '\n';
    } while (choice != 5);

    return 0;
}
