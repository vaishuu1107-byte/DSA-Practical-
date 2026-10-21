# Problem Statement: Improved Binary Search Tree

## Title
Enhanced Menu-Driven Binary Search Tree Implementation in C++

## Problem definition
Develop a C++ program that implements a Binary Search Tree (BST) for integer values. It must preserve standard insertion, search, deletion, inorder traversal, preorder traversal, and postorder traversal functionality, while adding level-order traversal, minimum and maximum lookup, a readable tree-structure display, safer input handling, and memory cleanup on exit.

## Functional requirements
1. Insert integer values while ignoring duplicates.
2. Search for a value and report whether it exists.
3. Delete a value correctly for leaf nodes, nodes with one child, and nodes with two children.
4. Display inorder, preorder, and postorder traversals.
5. Display level-order traversal using a queue.
6. Find the minimum and maximum stored values.
7. Print the parent-child tree structure with indentation.
8. Handle non-integer menu/value input without crashing.
9. Show clear messages when the tree is empty or a value is not found.
10. Free all dynamically allocated nodes before the program exits.

## Expected outcome
The program offers an interactive menu. Inorder traversal prints values in ascending order. New operations help users inspect the tree and retrieve boundary values. Invalid text input is rejected with a helpful message, and allocated nodes are released on exit.

## Scope
This is a conventional, non-self-balancing BST. Its performance depends on tree height; it can become skewed if values are inserted in sorted order.
