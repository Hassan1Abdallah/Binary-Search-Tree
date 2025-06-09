#include <iostream>
#include <cassert>

using namespace std;

struct Node {
    int item;
    Node *left;
    Node *right;
};


class binarySearchTreeType {
private:
    Node *root;

    void clear(Node *&p) {
      if (p != NULL) {
        clear(p->left);
        clear(p->right);
        delete p;
        p = NULL;
      }
    }

    void inorder(Node *p) {
      if (p != NULL) {
        inorder(p->left);
        cout << p->item << " ";
        inorder(p->right);
      }
    }

    void preorder(Node *p) {
      if (p != NULL) {
        cout << p->item << " ";
        preorder(p->left);
        preorder(p->right);
      }
    }

    void postorder(Node *p) {
      if (p != NULL) {
        postorder(p->left);
        postorder(p->right);
        cout << p->item << " ";
      }
    }

    int height(Node *p) {
      if (p == NULL)
        return 0;
      else
        return 1 + max(height(p->left), height(p->right));
    }

    int max(int x, int y) {
      if (x >= y)
        return x;
      else
        return y;
    }

    int nodeCount(Node *p) {
      if (p == NULL)
        return 0;
      else
        return 1 + nodeCount(p->left) + nodeCount(p->right);
    }

    int leavesCount(Node *p) {
      if (p == NULL)
        return 0;
      else if ((p->left == NULL) && (p->right == NULL))
        return 1;
      else
        return leavesCount(p->left) + leavesCount(p->right);
    }

    void deleteFromTree(Node *&p) {
      Node *current;
      Node *trailCurrent;
      Node *temp;

      if (p->left == NULL && p->right == NULL) {
        delete p;
        p = NULL;
      } else if (p->left == NULL) {
        temp = p;
        p = p->right;
        delete temp;
      } else if (p->right == NULL) {
        temp = p;
        p = p->left;
        delete temp;
      } else {
        current = p->left;
        trailCurrent = NULL;

        while (current->right != NULL) {
          trailCurrent = current;
          current = current->right;
        }

        p->item = current->item;

        if (trailCurrent == NULL)
          p->left = current->left;
        else
          trailCurrent->right = current->left;

        delete current;
      }
    }

    bool searchRecPriv(Node *p, int item) {
      if (p == NULL)
        return false;
      else if (p->item == item)
        return true;
      else if (p->item > item)
        return searchRecPriv(p->left, item);
      else
        return searchRecPriv(p->right, item);
    }

public:
    bool isEmpty() {
      return (root == NULL);
    }

    bool search(int item) {
      Node *current = root;

      while (current != NULL) {
        if (current->item == item)
          return true;
        else if (current->item > item)
          current = current->left;
        else
          current = current->right;
      }

      return false;
    }

    bool searchRec(int item) {
      return searchRecPriv(root, item);
    }

    void insert(int item) {
      Node *current;
      Node *trailCurrent;
      Node *newNode;

      newNode = new Node;
      assert(newNode != NULL);
      newNode->item = item;
      newNode->left = NULL;
      newNode->right = NULL;

      if (root == NULL)
        root = newNode;
      else {
        current = root;

        while (current != NULL) {
          trailCurrent = current;

          if (current->item == item) {
            cout << "The insert item is already in the list -- ";
            cout << "duplicates are not allowed." << endl;
            return;
          } else if (current->item > item)
            current = current->left;
          else
            current = current->right;
        }

        if (trailCurrent->item > item)
          trailCurrent->left = newNode;
        else
          trailCurrent->right = newNode;
      }
    }

/// this function only determines the node to be deleted
    void remove(int item) {
      Node *current;
      Node *trailCurrent;

      if (root == NULL) {
        cout << "Cannot delete from the empty tree." << endl;
        return;
      }
      if (root->item == item) {
        deleteFromTree(root);
        return;
      }

      trailCurrent = root;

      if (root->item > item)
        current = root->left;
      else
        current = root->right;

      while (current != NULL) {
        if (current->item == item)
          break;
        else {
          trailCurrent = current;
          if (current->item > item)
            current = current->left;
          else
            current = current->right;
        }
      }
      if (current == NULL)
        cout << "The delete item is not in the tree." << endl;
      else if (trailCurrent->item > item)
        deleteFromTree(trailCurrent->left);
      else
        deleteFromTree(trailCurrent->right);
    }

    void inorderTraversal() {
      inorder(root);
    }

    void preorderTraversal() {
      preorder(root);
    }

    void postorderTraversal() {
      postorder(root);
    }

    int treeHeight() {
      return height(root);
    }

    int treeNodeCount() {
      return nodeCount(root);
    }

    int treeLeavesCount() {
      return leavesCount(root);
    }

    void clearTree() {
      clear(root);
    }

    binarySearchTreeType() {
      root = NULL;
    }

    ~binarySearchTreeType() {
      clear(root);
    }

};


int main() {
  binarySearchTreeType b;
  b.insert(10);
  b.insert(20);
  b.insert(5);
  b.remove(10);
  b.inorderTraversal();
  b.postorderTraversal();
  b.preorderTraversal();
  return 0;
}