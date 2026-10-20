# Algorithm: Improved E-Commerce Shopping Cart Using a Singly Linked List

## Objective
Improve the original C++ shopping-cart program while keeping the singly linked list as its main data structure. The modified version supports adding products, updating quantities, removing products, displaying the cart and calculating the total bill, while also checking duplicate IDs and invalid values.

## Data Structure
Each `Node` stores:
- `productId`: product identifier.
- `productName`: product name, including spaces.
- `price`: unit price.
- `quantity`: number of units.
- `next`: pointer to the next node.

The `ShoppingCart` class stores `head`, which points to the first node.

## Algorithm

### 1. Initialize the Cart
1. Start.
2. Set `head = nullptr`.
3. Use a destructor to delete all nodes remaining in the list when the cart object is destroyed.

### 2. Add an Item
1. Read the product ID, name, price, and quantity.
2. If the ID already exists, display a duplicate-ID message and do not add the item.
3. If the price is negative or quantity is not positive, display an invalid-input message and stop this operation.
4. Create a new node with the product details.
5. If `head == nullptr`, set `head` to the new node.
6. Otherwise, traverse to the last node and link its `next` pointer to the new node.
7. Display a success message.

### 3. Update Quantity
1. Read the product ID and new quantity.
2. If the new quantity is not positive, display an invalid-quantity message.
3. Start at `head` and traverse the list.
4. If a node with the matching ID is found, update its quantity and display a success message.
5. If no matching ID is found, display a product-not-found message.

### 4. Remove an Item
1. If the cart is empty, display an empty-cart message and stop.
2. If the first node contains the requested ID, move `head` to the next node, delete the old first node, and display a success message.
3. Otherwise, traverse the list while keeping track of the previous and current nodes.
4. If the ID is found, connect the previous node to the current node's next node, delete the current node, and display a success message.
5. If no matching ID is found, display a product-not-found message.

### 5. Display Cart and Calculate Total
1. If the cart is empty, display an empty-cart message and stop.
2. Set `totalCost = 0` and a temporary pointer to `head`.
3. Traverse the list.
4. For each node, display the product ID, name, unit price, and quantity.
5. Add `price × quantity` to `totalCost`.
6. Display the final total.

### 6. Main Menu
1. Create a `ShoppingCart` object.
2. Display the menu: Add Item, Update Quantity, Remove Item, Display Cart, and Exit.
3. Read the user's menu choice.
4. Validate that the menu choice is valid.
5. Run the selected operation.
6. Repeat until the user selects Exit.
7. When the object is destroyed, release all remaining nodes.
8. Stop.

## Complexity Analysis

Let `n` be the number of products in the cart.

| Operation | Time Complexity | Explanation |
|---|---:|---|
| Add item | O(n) | Checks for duplicate ID and traverses to append |
| Update quantity | O(n) | Searches for the product ID |
| Remove item | O(n) | Searches for the product ID |
| Display cart | O(n) | Visits each node once |
| Free all remaining nodes | O(n) | Destructor visits and deletes each node |

The list requires **O(n)** space for `n` product nodes.

## Improvements Compared with the Original
- Rejects duplicate product IDs.
- Supports product names containing spaces.
- Rejects negative prices and non-positive quantities.
- Checks menu input where practical.
- Uses a destructor to release nodes still in the cart.
