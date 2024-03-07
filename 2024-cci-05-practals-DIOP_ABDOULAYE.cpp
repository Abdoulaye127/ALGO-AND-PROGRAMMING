#include <iostream>
#include <cstdlib>
#include <vector>
#include <cctype>
#include <ctime>
#include <algorithm>
#include <queue>

#define MAX_DATA_SIZE 10000

using namespace std;

int sum_of_numbers(int n) {
    return (n * (n + 1)) / 2;
}

void sum() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "The sum of the first " << n << " numbers is : " << sum_of_numbers(n) << endl;
}

class ListType {
public:
    ListType(int n) : MAX_ITEMS(n), nbItems(0) {}

    void MakeEmpty() {
        nbItems = 0;
    }

    bool IsEmpty() const {
        return (nbItems == 0);
    }

    bool IsFull() const {
        return (nbItems == MAX_ITEMS);
    }

    void FindNode(int searchItem) {
        int i = 0;
        while (i < nbItems && items[i] != searchItem)
            i++;
        if (i == nbItems)
            cout << "\n the Item :" << searchItem << " is not found  !\n";
        else
            cout << "\n the item : " << searchItem << " is found !";
    }

    void InsertNode(int position, int newItem) {
        if (!(nbItems == MAX_ITEMS)) {
            for (int i = nbItems; i > position; i--)
                items[i] = items[i - 1];
            items[position] = newItem;
            nbItems++;
        }
    }

    void DeleteNode(int position) {
        if (!(nbItems == 0)) {
            for (int i = position; i < nbItems - 1; i++)
                items[i] = items[i + 1];
            nbItems--;
        }
    }

    void Display() {
        cout << "\n Content of the List : \n";
        for (int i = 0; i < nbItems; i++)
            cout << "\n " << i << "\t" << items[i];
        cout << "\n";
    }

    void RandomNodes() {
        for (int i = 0; i < MAX_ITEMS; i++)
            items[i] = rand() % 100 + 1;
        nbItems = MAX_ITEMS;
    }

private:
    const int MAX_ITEMS;
    int nbItems;
    int items[MAX_DATA_SIZE];
};

class StackType {
public:
    StackType(int n) : MAX_ITEMS(n), top(-1) {}

    void MakeEmpty() {
        top = -1;
    }

    bool IsEmpty() const {
        return (top == -1);
    }

    bool IsFull() const {
        return (top == MAX_ITEMS - 1);
    }

    void Push(int newItem) {
        if (!IsFull()) {
            top++;
            items[top] = newItem;
        } else {
            cout << "\n Stack overflow \n";
        }
    }

    void Pop(int& item) {
        if (!IsEmpty()) {
            item = items[top];
            top--;
        } else
            cout << "\n Stack underflow \n";
    }

    void Display() {
        cout << "\n content of the stack \n";
        for (int i = 0; i <= top; i++)
            cout << "\n" << i << " \t" << items[i];
        cout << "\n";
    }

    void RandomNodes() {
        for (int i = 0; i < MAX_ITEMS; i++)
            items[i] = rand() % 100 + 1;
        top = MAX_ITEMS - 1; // Update top to point to the last index
    }

private:
    const int MAX_ITEMS;
    int top;
    int items[MAX_DATA_SIZE];
};

class QueueType {
public:
    QueueType(int n) : MAX_ITEMS(n), front(-1), rear(-1) {}

    void MakeEmpty() {
        front = rear = -1;
    }

    bool IsEmpty() const {
        return (front == -1);
    }

    bool IsFull() const {
        return ((rear + 1) % MAX_ITEMS == front);
    }

    void Enqueue(int newItem) {
        if (!IsFull()) {
            rear = (rear + 1) % MAX_ITEMS;
            items[rear] = newItem;
            if (front == -1) {
                front = rear;
            }
        } else {
            cout << "\n Queue overflow \n";
        }
    }

    void Dequeue(int& item) {
        if (!IsEmpty()) {
            item = items[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % MAX_ITEMS;
            }
        } else {
            cout << "\n Queue underflow \n";
        }
    }

    void Display() {
        if (!IsEmpty()) {
            cout << "\n content of the queue \n";
            int i = front;
            do {
                cout << "\n" << i << " \t" << items[i];
                i = (i + 1) % MAX_ITEMS;
            } while (i != (rear + 1) % MAX_ITEMS);
            cout << "\n";
        } else {
            cout << "\n The queue is empty \n";
        }
    }

    void RandomNodes() {
        for (int i = 0; i < MAX_ITEMS; i++)
            items[i] = rand() % 100 + 1;
        front = 0;
        rear = MAX_ITEMS - 1;
    }

private:
    const int MAX_ITEMS;
    int front, rear;
    int items[MAX_DATA_SIZE];
};

/////////////////////// START HEAP SORT ///////////////////////

/////////////////////// START HEAP SORT ///////////////////////

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void displayHeap(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void manuallyEnterElements(vector<int>& arr) {
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < arr.size(); ++i) {
        cout << "Element " << i+1 << ": ";
        cin >> arr[i];
    }
}

void generateRandomElements(vector<int>& arr) {
    srand(time(0)); // Seed for random number generator
    for (int i = 0; i < arr.size(); ++i)
        arr[i] = rand() % 100; // Generates random numbers between 0 and 99
}

///////////////// END HEAP SORT ///////////////////////


///////////////// END HEAP SORT /////////////////////////

////////////////////  BINARY SEARCH ///////////////////////


// Binary search function
int binarySearch(vector<int>& arr, int key) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // If the element is present at the middle
        if (arr[mid] == key)
            return mid;

        // If the element is greater than mid, ignore left half
        if (arr[mid] < key)
            left = mid + 1;

        // If the element is smaller than mid, ignore right half
        else
            right = mid - 1;
    }

    // If the element is not present in the array
    return -1;
}
//////////////// END BINARY SEARCH ///////////////////////////

///////////////// start TREE TRAVERSAL ///////////////////////


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTree {
public:
    // Function to perform preorder traversal
    void preorderTraversal(TreeNode* root) {
        if (root == NULL)
            return;
        
        cout << root->val << " "; // Process current node
        preorderTraversal(root->left); // Traverse left subtree
        preorderTraversal(root->right); // Traverse right subtree
    }

    // Function to perform inorder traversal
    void inorderTraversal(TreeNode* root) {
        if (root == NULL)
            return;
        
        inorderTraversal(root->left); // Traverse left subtree
        cout << root->val << " "; // Process current node
        inorderTraversal(root->right); // Traverse right subtree
    }

    // Function to perform postorder traversal
    void postorderTraversal(TreeNode* root) {
        if (root == NULL)
            return;
        
        postorderTraversal(root->left); // Traverse left subtree
        postorderTraversal(root->right); // Traverse right subtree
        cout << root->val << " "; // Process current node
    }

    // Function to display the binary tree
    void displayTree(TreeNode* root) {
        if (root == NULL)
            return;
        
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr != NULL) {
                    cout << curr->val << " ";
                    q.push(curr->left);
                    q.push(curr->right);
                } else {
                    cout << "null ";
                }
            }
            cout << endl;
        }
    }

    // Function to fill the binary tree with random values
    void fillRandom(TreeNode*& root, int size) {
        srand(time(NULL)); // Seed the random number generator with current time
        root = createRandomTree(size);
    }

    // Function to fill the binary tree manually
    void fillManually(TreeNode*& root) {
        cout << "Enter the value of root: ";
        int val;
        cin >> val;
        root = new TreeNode(val);
        fillManuallyUtil(root);
    }

private:
    // Utility function to fill the binary tree manually
    void fillManuallyUtil(TreeNode* root) {
        if (root == NULL)
            return;

        cout << "Enter the value of left child of " << root->val << " (Enter -1 if null): ";
        int leftVal;
        cin >> leftVal;
        if (leftVal != -1) {
            root->left = new TreeNode(leftVal);
            fillManuallyUtil(root->left);
        }

        cout << "Enter the value of right child of " << root->val << " (Enter -1 if null): ";
        int rightVal;
        cin >> rightVal;
        if (rightVal != -1) {
            root->right = new TreeNode(rightVal);
            fillManuallyUtil(root->right);
        }
    }

    // Utility function to create a binary tree with random values
    TreeNode* createRandomTree(int size) {
        if (size <= 0)
            return NULL;

        TreeNode* root = new TreeNode(rand() % 100); // Generate a random value between 0 and 99
        --size;

        if (size > 0) {
            int leftSize = rand() % size;
            root->left = createRandomTree(leftSize);
            root->right = createRandomTree(size - leftSize);
        }

        return root;
    }
};

////////////// END Binary Tree Traversal ///////////////////////


/////////////////////// Start Graph ///////////////////


class GraphN {
    int n_v;
    int** adj;

public:
    GraphN(int n_v);
    void InsertEdge(int start, int e);
    void Bfs(int start);
    void Dfs(int start, vector<bool>& visited);
};

GraphN::GraphN(int n_v) {
    this->n_v = n_v;
    adj = new int*[n_v];
    for (int i = 0; i < n_v; i++) {
        adj[i] = new int[n_v];
        for (int j = 0; j < n_v; j++) {
            adj[i][j] = 0;
        }
    }
}

void GraphN::InsertEdge(int start, int e) {
    adj[start][e] = 1;
    adj[e][start] = 1;
}

void GraphN::Bfs(int start) {
    vector<bool> visited(n_v, false);
    vector<int> q;
    q.push_back(start);
    visited[start] = true;
    int vis;
    while (!q.empty()) {
        vis = q[0];
        cout << "(" << vis << ") ";
        q.erase(q.begin());
        for (int i = 0; i < n_v; i++) {
            if (adj[vis][i] == 1 && (!visited[i])) {
                q.push_back(i);
                visited[i] = true;
            }
        }
    }
}

void GraphN::Dfs(int start, vector<bool>& visited) {
    cout << "(" << start << ") ";
    visited[start] = true;
    for (int i = 0; i < n_v; i++) {
        if (adj[start][i] == 1 && (!visited[i])) {
            Dfs(i, visited);
        }
    }
}


/////////////////////// End Graph /////////////////
int main() {
    char choice = '+';
    vector<int> arr; // Declare arr here

    while (choice != 'E' && choice != 'e') {
        cout << "\t\n\n \t***********  Select an option **********";
        cout << "\t\n\n            N: \tSum of number";
        cout << "\t\n\n            L: \tList";
        cout << "\t\n\n            S: \tStack";
        cout << "\t\n\n            Q: \tQueue";
        cout << "\t\n\n            H: \tHeap Sort";
        cout << "\t\n\n            B: \tBinary search";
        cout << "\t\n\n            T: \tBinary Tree Traversals(inorder,preorder,PostOrder)";
        cout << "\t\n\n            G: \tGraphs";
        cout << "\t\n\n            E: \tExit";
        cout << "\t\n\n \t *******  please Enter your choice: ******* ";
        cin >> choice;
        choice = toupper(choice);
        if (choice == 'N') {
            sum();
        } else if (choice == 'L') {
            int size = 0;
            cout << "\n Enter the size of the list: ";
            cin >> size;

            ListType list(size);
            char option = '+';

            while (option != '0') {
                cout << "\n Select a list operation";
                cout << "\n1 : Insert a new item";
                cout << "\n2 : Delete an item";
                cout << "\n3 : Find an item";
                cout << "\n4 : Empty the list";
                cout << "\n5 : Check if the list is empty";
                cout << "\n6 : Check if the list is full";
                cout << "\n7 : Fill the list randomly";
                cout << "\n8 : Display the content of the list";
                cout << "\n0 : Stop";

                cout << "\n Enter Option: ";
                cin >> option;

                switch (option) {
                    case '1': {
                        int position, item;
                        cout << "\n Enter the position to insert: ";
                        cin >> position;
                        cout << "\n Enter the item to insert: ";
                        cin >> item;
                        list.InsertNode(position, item);
                        break;
                    }
                    case '2': {
                        int position;
                        cout << "\n Enter the position to delete: ";
                        cin >> position;
                        list.DeleteNode(position);
                        break;
                    }
                    case '3': {
                        int searchItem;
                        cout << "\n Enter the item to find: ";
                        cin >> searchItem;
                        list.FindNode(searchItem);
                        break;
                    }
                    case '4': {
                        list.MakeEmpty();
                        cout << "\n The list is emptied \n";
                        break;
                    }
                    case '5': {
                        if (list.IsEmpty())
                            cout << "\n The list is empty \n";
                        else
                            cout << "\n The list is not empty \n";
                        break;
                    }
                    case '6': {
                        if (list.IsFull())
                            cout << "\n The list is full \n";
                        else
                            cout << "\n The list is not full \n";
                        break;
                    }
                    case '7': {
                        list.RandomNodes();
                        cout << "\n The list is filled randomly \n";
                        break;
                    }
                    case '8': {
                        list.Display();
                        break;
                    }
                    case '0': {
                        break;
                    }
                    default: {
                        cout << "\n Invalid option, please choose again!" << endl;
                        break;
                    }
                }
            }
        } else if (choice == 'S') {
            int size = 0;
            cout << "\n Enter the size of the stack: ";
            cin >> size;

            StackType stack(size);
            char option = '+';

            while (option != '0') {
                cout << "\n Select a stack operation";
                cout << "\n1 : Push an element";
                cout << "\n2 : Pop an element";
                cout << "\n3 : Display the stack";
                cout << "\n4 : Empty the stack";
                cout << "\n5 : Check if the stack is empty";
                cout << "\n6 : Check if the stack is full";
                cout << "\n7 : Fill the stack randomly";
                cout << "\n0 : Stop";

                cout << "\n Enter Option: ";
                cin >> option;

                switch (option) {
                    case '1': {
                        int item;
                        cout << "\n Enter the item to push: ";
                        cin >> item;
                        stack.Push(item);
                        break;
                    }
                    case '2': {
                        int poppedItem;
                        stack.Pop(poppedItem);
                        cout << "\n Popped item: " << poppedItem << endl;
                        break;
                    }
                    case '3': {
                        stack.Display();
                        break;
                    }
                    case '4': {
                        stack.MakeEmpty();
                        cout << "\n The stack is emptied \n";
                        break;
                    }
                    case '5': {
                        if (stack.IsEmpty())
                            cout << "\n The stack is empty \n";
                        else
                            cout << "\n The stack is not empty \n";
                        break;
                    }
                    case '6': {
                        if (stack.IsFull())
                            cout << "\n The stack is full \n";
                        else
                            cout << "\n The stack is not full \n";
                        break;
                    }
                    case '7': {
                        stack.RandomNodes();
                        cout << "\n The stack is filled randomly \n";
                        break;
                    }
                    case '0': {
                        break;
                    }
                    default: {
                        cout << "\n Invalid option, please choose again!" << endl;
                        break;
                    }
                }
            }
        } else if (choice == 'Q') {
            int size = 0;
            cout << "\n Enter the size of the queue: ";
            cin >> size;

            QueueType queue(size);
            char option = '+';

            while (option != '0') {
                cout << "\n Select a queue operation";
                cout << "\n1 : Enqueue an element";
                cout << "\n2 : Dequeue an element";
                cout << "\n3 : Display the queue";
                cout << "\n4 : Empty the queue";
                cout << "\n5 : Check if the queue is empty";
                cout << "\n6 : Check if the queue is full";
                cout << "\n7 : Fill the queue randomly";
                cout << "\n0 : Stop";

                cout << "\n Enter Option: ";
                cin >> option;

                switch (option) {
                    case '1': {
                        int item;
                        cout << "\n Enter the item to enqueue: ";
                        cin >> item;
                        queue.Enqueue(item);
                        cout << "\n Item enqueued successfully\n";
                        break;
                    }
                    case '2': {
                        int dequeuedItem;
                        queue.Dequeue(dequeuedItem);
                        cout << "\n Dequeued item: " << dequeuedItem << endl;
                        break;
                    }
                    case '3': {
                        queue.Display();
                        break;
                    }
                    case '4': {
                        queue.MakeEmpty();
                        cout << "\n The queue is emptied \n";
                        break;
                    }
                    case '5': {
                        if (queue.IsEmpty())
                            cout << "\n The queue is empty \n";
                        else
                            cout << "\n The queue is not empty \n";
                        break;
                    }
                    case '6': {
                        if (queue.IsFull())
                            cout << "\n The queue is full \n";
                        else
                            cout << "\n The queue is not full \n";
                        break;
                    }
                    case '7': {
                        queue.RandomNodes();
                        cout << "\n The queue is filled randomly \n";
                        break;
                    }
                    case '0': {
                        break;
                    }
                    default: {
                        cout << "\n Invalid option, please choose again!" << endl;
                        break;
                    }
                }
            }
        } else if (choice == 'H') {
                           int size, choice;
            cout << "Enter the size of the array: ";
            cin >> size;
            arr.resize(size); // Resize the vector to match the input size

            cout << "Enter 1 to manually enter elements or 2 to generate random elements: ";
            cin >> choice;

            if (choice == 1)
                manuallyEnterElements(arr);
            else if (choice == 2)
                generateRandomElements(arr);
            else {
                cerr << "Invalid choice. Exiting program.\n";
                return 1;
            }

            cout << "Original heap: ";
            displayHeap(arr);

            heapSort(arr);

            cout << "Heap after heap sort: ";
            displayHeap(arr);

        } else if (choice == 'B') {

                if (arr.empty()) {
                cerr << "Array is empty. Please perform heap sort first.\n";
                continue;
            }
             displayHeap(arr);
            int key;
            cout << "Enter the element to search: ";
            cin >> key;

            int index = binarySearch(arr, key);
            if (index != -1)
                cout << "Element " << key << " found at index " << index << endl;
            else
                cout << "Element " << key << " not found in the heap." << endl;

        } else if (choice == 'T') {
             BinaryTree bt;
    TreeNode* root = NULL;

    cout << "Enter the size of the binary tree: ";
    int size;
    cin >> size;

    int choice;
    cout << "Choose an option to fill the tree:" << endl;
    cout << "1. Manually" << endl;
    cout << "2. Randomly" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            bt.fillManually(root);
            break;
        case 2:
            bt.fillRandom(root, size);
            break;
        default:
            cout << "Invalid choice. Exiting..." << endl;
            return 1;
    }

    cout << "Preorder traversal: ";
    bt.preorderTraversal(root);
    cout << endl;

    cout << "Inorder traversal: ";
    bt.inorderTraversal(root);
    cout << endl;

    cout << "Postorder traversal: ";
    bt.postorderTraversal(root);
    cout << endl;

    cout << "Displaying tree structure:" << endl;
    bt.displayTree(root);
        } 
        
        else if (choice == 'G'){
             int numbOFVertex = 8; // Corrected initialization
    int startVertex, toVertex;
    string wantToInsert = "N";
    int choice;
    cout << "The graph is : \n";
    cout << "\n";
    cout << "0 -> 1, 0 -> 2,0 -> 3,0 -> 4, 2-> 5,2 -> 6, 3 -> 7\n";
    int v = 8;
    GraphN G(v);
    G.InsertEdge(0, 1);
    G.InsertEdge(0, 2);
    G.InsertEdge(0, 3);
    G.InsertEdge(0, 4);
    G.InsertEdge(2, 5);
    G.InsertEdge(2, 6);
    G.InsertEdge(3, 7);
    vector<bool> visited(numbOFVertex, false);
    do {
        cout << ("\n1 : Depth-First Search ");
        cout << ("\n2 : Breadth-First Search ");
        cout << ("\n0 : Exit the program ");

        cout << "\n\n\t Choose to continue... " << endl;
        cin >> choice;

        switch (choice) {
            case 1:

                cout << "\tDepth-First Search: \n";
                cout << "From which vertex \n" << endl;
                cin >> choice;

                G.Dfs(choice, visited);
                cout << "  " << endl;

                break;
            case 2:
                cout << "\tBreadth-First Search: ";
                cout << "\tFrom which vertex \n" << endl;
                cin >> choice ;
                G.Bfs(choice)  ;
                cout << "  " << endl;
                break;

        }

    } while (choice != 0);
        }
        
        else if (choice == 'E') {
            cout << "Exiting program..." << endl;
            break;
        } else {
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
