# Binary-Search-Tree---BST

# Binary Search Tree with C++

This is a simple C++ project that implements a **Binary Search Tree (BST)** and provides basic operations such as insertion, deletion, search, and different types of tree traversals (Inorder, Preorder, Postorder).

## 💡 Features

- `insert(int item)`: Adds a new node to the tree.
- `remove(int item)`: Deletes a node from the tree.
- `search(int item)`: Searches for an item using an iterative approach.
- `searchRec(int item)`: Searches for an item using a recursive approach.
- `inorderTraversal()`: Prints the elements in Inorder (Left, Root, Right).
- `preorderTraversal()`: Prints the elements in Preorder (Root, Left, Right).
- `postorderTraversal()`: Prints the elements in Postorder (Left, Right, Root).
- `treeHeight()`: Returns the height of the tree.
- `treeNodeCount()`: Returns the total number of nodes in the tree.
- `treeLeavesCount()`: Returns the number of leaf nodes (nodes with no children).
- `clearTree()`: Clears the entire tree.

## 📁 Code Structure

- `Node`: A struct that contains the value (`item`) and pointers to left and right children.
- `binarySearchTreeType`: The main class that encapsulates all BST operations.
- `main()`: A demo function to test insertion, deletion, and traversals.

## ⚠️ Notes

- Duplicate values are not allowed — the tree ignores any duplicates during insertion.
- If you try to remove a value that doesn't exist, the code will notify you.
- When deleting a node with one or two children, the logic handles all the edge cases correctly using `deleteFromTree`.

## ✅ Example Usage

```cpp
int main() {
  binarySearchTreeType b;
  b.insert(10);
  b.insert(20);
  b.insert(5);
  b.remove(10);
  b.inorderTraversal();     // Output: 5 20
  b.postorderTraversal();   // Output: 5 20
  b.preorderTraversal();    // Output: 20 5
  return 0;
}
