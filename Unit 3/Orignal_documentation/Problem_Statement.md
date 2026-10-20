# Problem Statement: E-Commerce Shopping Cart Using a Singly Linked List

## Title
E-Commerce Shopping Cart Using a Singly Linked List in C++

## Problem Statement
Design and implement a menu-driven E-Commerce Shopping Cart in C++ using a singly linked list. The system should allow a user to add products to a cart, update the quantity of an existing product, remove a product by its ID, and display all cart items along with the total bill.

Each linked-list node stores the product ID, product name, unit price, quantity, and a pointer to the next node. The list should grow and shrink dynamically as products are added or removed.

## Objectives
1. Implement a node structure for storing product details.
2. Add products to the end of the linked list.
3. Search for a product by ID and update its quantity.
4. Remove a product by ID, including handling removal of the first node.
5. Display all products and calculate the total cost.
6. Provide a menu-driven interface so the user can choose an operation.

## Functional Requirements
- **Add item:** Read the product ID, name, price, and quantity, then append a new node.
- **Update quantity:** Search for the specified product ID and update its quantity if found.
- **Remove item:** Delete the node with the specified product ID if it exists.
- **Display cart:** Show each item's details and calculate the total using `price × quantity`.
- **Exit:** End the program when the user selects option 5.

## Input
The program accepts a menu choice and, depending on the operation, product ID, product name, price, and/or quantity.

## Output
The program displays operation status messages, cart item details, and the total cost of all items currently in the cart.

## Data Structure Used
A **singly linked list** is used. Each node points to the next node, and the `head` pointer refers to the first node.

## Scope and Limitations
- The current implementation does not prevent duplicate product IDs.
- Product names are read using `cin >> name`, so names containing spaces are not accepted as a single name.
- Input validation for negative prices and quantities is not included.
- The program is a console-based demonstration and does not store cart data permanently.
