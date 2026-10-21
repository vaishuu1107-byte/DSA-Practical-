# Algorithm: Improved Binary Search Tree

## Objective
Implement a menu-driven Binary Search Tree (BST) in C++ with the original operations plus level-order traversal, minimum/maximum lookup, tree-structure display, input validation, and cleanup of dynamically allocated nodes.

## BST rule
For each node, values smaller than its data are in the left subtree and larger values are in the right subtree. Duplicate values are ignored.

## 1. Insert
1. If the current node is null, create and return a new node.
2. If the value is smaller, recursively insert it into the left subtree.
3. If the value is larger, recursively insert it into the right subtree.
4. If equal, leave the tree unchanged.
5. Return the current root.

## 2. Search
1. If the current node is null, return false.
2. If its data matches the target, return true.
3. Search the left subtree if the target is smaller; otherwise search the right subtree.

## 3. Delete
1. Find the target using BST comparisons.
2. If it has no left child, replace it with its right child.
3. Otherwise, if it has no right child, replace it with its left child.
4. If it has two children, copy the minimum value from its right subtree (inorder successor) into it.
5. Delete the successor from the right subtree and return the updated root.

## 4. Find minimum / maximum
- Minimum: follow left pointers until there is no left child.
- Maximum: follow right pointers until there is no right child.
- If the root is null, report that the tree is empty.

## 5. Traversals
- Inorder: Left → Node → Right. In a BST, values appear in ascending order.
- Preorder: Node → Left → Right.
- Postorder: Left → Right → Node.
- Level-order: use a queue; enqueue the root, then repeatedly remove a node, visit it, and enqueue its left and right children if present.

## 6. Display tree structure
Recursively print each node with indentation. Label the root as `Root`, its left child as `L`, and its right child as `R`.

## 7. Input handling and termination
1. Validate menu input and integer values.
2. Display an error for invalid input and clear the input stream.
3. Repeat until the user selects option 11.
4. Before exiting, recursively delete all nodes to release dynamic memory.

## Complexity
Let `n` be the number of nodes and `h` be the tree height.

| Operation | Time | Auxiliary space |
|---|---:|---:|
| Insert, search, delete | O(h), worst O(n) | O(h) recursion |
| Minimum / maximum | O(h), worst O(n) | O(1) |
| Inorder / preorder / postorder | O(n) | O(h) recursion |
| Level-order traversal | O(n) | O(w), where w is maximum width |
| Display structure | O(n) | O(h) recursion |
| Destroy tree | O(n) | O(h) recursion |

A balanced BST has height O(log n), but this implementation is not self-balancing. In the worst case, height is O(n).
