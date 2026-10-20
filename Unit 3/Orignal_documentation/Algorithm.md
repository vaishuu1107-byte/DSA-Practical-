# Algorithm: E-Commerce Shopping Cart Using a Singly Linked List

## Objective
Implement a menu-driven shopping cart in C++ using a singly linked list. Each node stores a product ID, product name, price, quantity, and a pointer to the next node.

## Data Structure
Each `Node` contains:
- `productId`: unique identifier used to find or remove a product.
- `productName`: product name.
- `price`: price of one unit.
- `quantity`: number of units in the cart.
- `next`: pointer to the next node.

The `ShoppingCart` class maintains a pointer named `head` to the first node.

## Algorithm

### 1. Initialize the Shopping Cart
1. Start.
2. Create a `ShoppingCart` object.
3. Set `head = nullptr`, representing an empty cart.

### 2. Add an Item — `addItem(id, name, price, quantity)`
1. Create a new node containing the supplied product details.
2. If `head == nullptr`, set `head` to the new node.
3. Otherwise, start at `head` and follow `next` pointers until the last node is reached.
4. Link the last node to the new node.
5. Display `Item added to cart.`

### 3. Update Quantity — `updateQuantity(id, newQuantity)`
1. Set a temporary pointer to `head`.
2. Traverse the list while the pointer is not `nullptr`.
3. If the current node's product ID matches `id`, assign `newQuantity` to its quantity, display `Quantity updated.`, and return.
4. Otherwise, move to the next node.
5. If the end is reached without a match, display `Product not found in cart.`

### 4. Remove an Item — `removeItem(id)`
1. If `head == nullptr`, display `Cart is empty.` and return.
2. If the first node contains the requested ID:
   - Store `head` in a temporary pointer.
   - Move `head` to `head->next`.
   - Delete the old first node.
   - Display `Item removed.` and return.
3. Otherwise, initialize `current = head` and `previous = nullptr`.
4. Traverse until `current == nullptr` or the matching product ID is found, updating `previous` and `current`.
5. If a match is found, link `previous->next` to `current->next`, delete `current`, and display `Item removed.`
6. If no match is found, display `Product not found.`

### 5. Display Cart and Calculate Total — `displayCart()`
1. If `head == nullptr`, display `Cart is empty.` and return.
2. Set a temporary pointer to `head` and `totalCost = 0`.
3. Print the cart heading.
4. For each node:
   - Display its ID, name, unit price, and quantity.
   - Add `price * quantity` to `totalCost`.
   - Move to the next node.
5. Display the total cost.

### 6. Main Menu
1. Start the program and create a `ShoppingCart` object.
2. Repeatedly display the menu:
   - 1. Add Item
   - 2. Update Qty
   - 3. Remove Item
   - 4. Display Cart
   - 5. Exit
3. Read the user's choice.
4. Execute the corresponding operation.
5. If the choice is invalid, display `Invalid choice.`
6. Continue until the user chooses option 5.
7. Display `Exiting...` and stop.

## Complexity Analysis

Let `n` be the number of items in the cart.

| Operation | Time Complexity | Explanation |
|---|---:|---|
| Add item | O(n) | Traverses to the last node (O(1) when empty). |
| Update quantity | O(n) | May search every node. |
| Remove item | O(n) | May search every node. |
| Display cart and total | O(n) | Visits each node once. |
| Initialize cart | O(1) | Sets `head` to `nullptr`. |

The linked list uses **O(n)** space for `n` product nodes.

## Notes
- The supplied program appends a new node for every add operation; it does not check for duplicate product IDs.
- Input uses `cin >> name`, so product names cannot contain spaces.
- The program does not validate negative prices or quantities.
- Nodes removed from the list are deleted, but the class does not currently define a destructor to free all nodes left in the cart when the object is destroyed.
