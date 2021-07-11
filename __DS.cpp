#include <bits/stdc++.h>
using namespace std;

void DEBUG(int d)
{
    cout << "----------\t" << d << "\t--------------" << endl;
}

class singlyNode
{
    int data;
    singlyNode *next;

public:
    singlyNode() { }
    singlyNode(int val)
    {
        data = val;
        next = nullptr;
    }

    singlyNode *root = nullptr;

    // append to the last node
    void append(int val)
    {
        singlyNode *newNode = new singlyNode(val);
        if (root == nullptr)
        {
            root = newNode;
        }
        else
        {
            singlyNode *currNode = root;
            while(currNode->next != nullptr)  //reached last node
            {
                currNode = currNode->next;
            }
            currNode->next = newNode;
        }
    }
    void deleteNode(int val)
    {
        singlyNode *currNode = root;
        singlyNode *temp = nullptr, *prevNode = nullptr;

        while(currNode->next != nullptr && currNode->data != val)   // stop if nullptr is reached and val doesn't match
        {
            prevNode = currNode;    // prev node of deleted node
            currNode = currNode->next;  // deleted node
        }

        if (currNode->next == nullptr && currNode->data != val) // val doesn't exist in list
        {
            return;
        }

        if (currNode == root)  // delete root
        {
            temp = root;
            root = root->next;
            delete(temp);
        }
        else
        {
            prevNode->next = currNode->next;
            delete(currNode);
        }
    }
    void print()
    {
        singlyNode *currNode = root;
        while(currNode != nullptr)  //reached last node
        {
            cout << currNode->data << " ";
            currNode = currNode->next;
        }
        cout << endl;
    }
};

class stackOperation
{
    stack<int> _stack;

public:
    stackOperation(int arr[], int n)
    {
        for(int i=0; i<n; i++)
        {
            _stack.push(arr[i]);
        }
    }
    void print()
    {
        while(!_stack.empty())  // _stack.size() > 0
        {
            cout << _stack.top() << " ";
            _stack.pop();
        }
        cout << endl;
    }
    void sort()
    {
        stack<int> _tempStack;
        int topStack, topTempStack;

        while(!_stack.empty())
        {
            topStack = _stack.top();            
            _stack.pop();

            //If the stack container is empty, top() causes undefined behaviour
            while (!_tempStack.empty() && _tempStack.top() > topStack)   // while temptop has greater val, need pop & sort
            {
                topTempStack = _tempStack.top();
                _tempStack.pop();
                _stack.push(topTempStack);
            }

           _tempStack.push(topStack);
        }
        
        while(!_stack.empty())  // clear stack
            _stack.pop();

        while(!_tempStack.empty())  // reverse stack
        {
            int c = _tempStack.top();
            _tempStack.pop();
            _stack.push(c);
        }
    }
};

class queueOperation
{
    queue<int> _queue;
public:
    queueOperation(int arr[], int n)
    {
        for (int i=0; i<n; i++)
        {
            _queue.push(arr[i]);
        }
    }
    void print()
    {
        while (!_queue.empty())
        {
            cout << _queue.front() << " ";
            _queue.pop();
        }
        cout << endl;
    }
};

class dequeOperation
{
    deque<int> _dequeue;
    deque<int>::iterator _it1, _it2;

public:
    dequeOperation(int arr[], int n)
    {
        for (int i=0; i<n; i++)     // odd in front, even in back
        {
            if (arr[i] % 2 == 0)
                _dequeue.push_back(arr[i]);
            else
                _dequeue.push_front(arr[i]);
        }
    
    }
    void remove(int start, int end)
    {
        if (_dequeue.empty())
            return;

        _it1 = _dequeue.begin();
        _it2 = _dequeue.end();

        _it1 += start-1;
        _it2 -= _dequeue.size() - end;
        _dequeue.erase(_it1, _it2);
    }
    void remove(int pos)
    {
        if (_dequeue.empty())
            return;

        _it1 = _dequeue.begin();        
        _it1 += pos-1;
        _dequeue.erase(_it1);
    }
    void remove()
    {
        _dequeue.clear();
    }
    void print()
    {
        deque<int> temp = _dequeue;

        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop_front();
        }
        cout << endl;
    }
};

class priorityQueue
{
    priority_queue<int, vector<int>, greater<int> > _pqIncre;
    priority_queue<int> _pqDecre;

public:
    priorityQueue(int arr[], int n)
    {
        for (int i=0; i<n; i++)
        {
            _pqDecre.push(arr[i]);
        }
    }
    void incrementalSort()
    {
        priority_queue<int> temp = _pqDecre;
        while (!temp.empty())
        {
            _pqIncre.push(temp.top());
            temp.pop();
        }
    }
    void print()
    {
        DEBUG(321);
        while (!_pqDecre.empty())
        {
            cout << _pqDecre.top() << " ";
            _pqDecre.pop();
        }
        cout << endl;

        DEBUG(123);
        while (!_pqIncre.empty())
        {
            cout << _pqIncre.top() << " ";
            _pqIncre.pop();
        }
        cout << endl;
    }
};


class binaryTreeNode
{
    int val;
    binaryTreeNode *left;
    binaryTreeNode *right;

public:
    binaryTreeNode *root = nullptr;

    binaryTreeNode(int v)
    {
        val = v;
        left = nullptr;
        right = nullptr;
    }

    void insertNode(int data)
    {
        binaryTreeNode *newNode = new binaryTreeNode(data);
        if (root == nullptr)
        {
            root = newNode;
            return;
        }
        else
        {
            // do level order traversal until null
            queue<binaryTreeNode*> treeQ;
            treeQ.push(root);

            binaryTreeNode *temp = nullptr;
            while (!treeQ.empty())
            {
                temp = treeQ.front();
                treeQ.pop();

                if (temp->left)
                    treeQ.push(temp->left);
                else
                {
                    temp->left = newNode;
                    return;
                }
                if (temp->right)
                    treeQ.push(temp->right);
                else
                {
                    temp->right = newNode;
                    return;
                }
            }
        }
    }
    void deleteNode(int data)   // the deleted node is replaced by bottom most and rightmost node
    {
        binaryTreeNode *deleteNode = nullptr;

        if (root == nullptr)
            return;
        
        queue<binaryTreeNode*> treeQ;
        treeQ.push(root);
 
        binaryTreeNode *temp = nullptr;
        while (!treeQ.empty())
        {
            temp = treeQ.front();
            treeQ.pop();

            if (temp->val == data)
                deleteNode = temp;
        }

        
    }
    void preorderTraversal()
    {

    }
    void inorderTraversal()
    {

    }
    void postorderTraversal()
    {

    }
};


int main()
{
    // singly link list
    /*{
        singlyNode *n = new singlyNode();

        for(int i=1; i<=10; i++)
        {
            n->append(i*5);
        }
        n->deleteNode(1);
        n->deleteNode(30);
        n->print();
    }*/
    
    // stack
    /*{
        int arr[] = {34, 3, 31, 98, 92, 23};
        stackOperation *stackobj = new stackOperation(arr, sizeof(arr)/sizeof(arr[0]));
        stackobj->sort();
        stackobj->print();
    }*/
    
    // queue
    /*{
        int arr[] = {34, 3, 31, 98, 92, 23};
        queueOperation *queueobj = new queueOperation(arr, sizeof(arr)/sizeof(arr[0]));
        queueobj->print();
    }*/

    // dequeue - Double ended queues
    /*{
        int arr[] = {34, 3, 31, 98, 92, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        dequeOperation *dequeObj = new dequeOperation(arr, sizeof(arr)/sizeof(arr[0]));
        dequeObj->print();
        dequeObj->remove(5);
        dequeObj->remove(5, 14);
        dequeObj->remove();
        dequeObj->print();
    }*/

    // priority queue
    {
        int arr[] = {34, 3, 31, 98, 92, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        priorityQueue *pqObj = new priorityQueue(arr, sizeof(arr)/sizeof(arr[0]));
        pqObj->incrementalSort();
        pqObj->print();
    }

    // binary tree
    {
        sdsd
    }
}