# Improved Binary Search Tree (BST)

A menu-driven C++ implementation of a Binary Search Tree with the original operations preserved and several improvements.

## Files
- `main.cpp` — source code.
- `Algorithm.md` — algorithms and complexity.
- `Problem_Statement.md` — requirements and scope.
- `Flowchart.png` — program flowchart.
- `Report.pdf.pdf` — detailed project report.
- `Output.pdf.pdf` — illustrative sample output.
- `README.md` — project guide.
- `CONTENTS.txt` — file list.

## Features
### Original features retained
- Insert, search, and delete values.
- Inorder, preorder, and postorder traversals.
- Menu-driven interface.
- Correct deletion for nodes with zero, one, or two children.

### Improvements
- Level-order traversal using a queue.
- Find minimum and maximum values.
- Display parent-child structure with indentation.
- Validate non-integer menu and value input.
- Explicitly report empty-tree cases.
- Release all remaining nodes on exit.
- Clear duplicate-value message.

## Compile and run

Linux/macOS:
```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o bst
./bst
```

Windows with MinGW:
```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o bst.exe
bst.exe
```

## Complexity
Let `h` be tree height and `n` the number of nodes. Insert/search/delete take O(h), worst-case O(n). Traversals take O(n). This is not a self-balancing BST.

## Example
Insert: `50, 30, 70, 20, 40, 60, 80`

- Inorder: `20 30 40 50 60 70 80`
- Preorder: `50 30 20 40 70 60 80`
- Postorder: `20 40 30 60 80 70 50`
- Level-order: `50 30 70 20 40 60 80`

Tree display:
```text
Root: 50
    L: 30
        L: 20
        R: 40
    R: 70
        L: 60
        R: 80
```
