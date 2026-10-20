# Problem Statement: Improved E-Commerce Shopping Cart Using a Singly Linked List

## Title
Improved E-Commerce Shopping Cart Using a Singly Linked List in C++

## Problem Statement
Develop a menu-driven C++ application that manages products in an e-commerce shopping cart using a singly linked list. Users should be able to add products, update the quantity of an existing product, remove a product by ID, and view all cart items with the total bill.

The modified implementation should improve reliability over the original version by rejecting duplicate product IDs, validating product details, accepting product names containing spaces, handling invalid menu input, and releasing dynamically allocated nodes when the cart object is destroyed.

## Objectives
1. Store each cart item in a dynamically allocated linked-list node.
2. Add a product only when its ID is not already present and its details are valid.
3. Update the quantity of an existing product.
4. Remove a product while correctly handling deletion of the first, middle, or last node.
5. Display product details and calculate the total cost.
6. Handle invalid menu and data input with clear messages.
7. Free all remaining nodes to avoid memory leaks.

## Functional Requirements
- **Add item:** Accept ID, product name, price, and quantity. Reject duplicate IDs, non-positive IDs, empty names, negative prices, and non-positive quantities.
- **Update quantity:** Find a product by ID and update its quantity only when the new quantity is greater than zero.
- **Remove item:** Delete the matching product, if present.
- **Display cart:** Print each product's ID, name, unit price, and quantity; calculate the total as the sum of `price × quantity`.
- **Exit:** End the menu loop and release any remaining nodes through the destructor.
- **Input handling:** Recover from invalid numeric input and display an error message.

## Input
The user enters a menu option from 1 to 5. Depending on the selected operation, the program also reads a product ID, product name, unit price, and/or quantity.

## Output
The program displays success or error messages, cart item details, and the total bill formatted to two decimal places.

## Data Structure Used
A **singly linked list**. Each node stores a product's ID, name, price, quantity, and a pointer to the next node. The `head` pointer references the first node, or `nullptr` when the cart is empty.

## Improvements Over the Original Version
- Checks for duplicate product IDs before adding.
- Accepts product names containing spaces by using `getline`.
- Validates IDs, prices, and quantities.
- Handles invalid menu and numeric input.
- Uses a destructor to delete all remaining nodes.
- Formats money values to two decimal places.

## Scope and Limitations
This is a console-based educational project. It does not store cart contents permanently between program runs, connect to an actual online store, or implement taxes, discounts, payment processing, or inventory management. The price uses `double`, which is adequate for a basic demonstration but is not ideal for precise financial calculations in production systems.
