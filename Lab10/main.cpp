//
//  main.cpp
//  DS_Lab10
//
//  Created by Tuğba Özkal on 14.12.2016.
//  Copyright © 2016 Tuğba Özkal. All rights reserved.
//

#include <iostream>
#include <time.h>

#define N 7

using namespace std;

struct node{
    int number;
    node * left;
    node * right;
    node * next;
};

struct tree{
    node * root;
    int nodecount;
    void createTree();
    void removeTree(node *);
    void printPreorder(node *);
    void printInorder(node *);
    void printPostorder(node *);
    int findMax(node *);
    int findMin(node *);
    int findNumNode(node *);
    int findNumLeaf(node *);
    int calculateDepth(node *);
    int calculateSum(node *);
    float calculateAverage(node *);
};

struct Queue {
    node * front;
    node * back;
    void create();
    void close();
    bool isEmpty();
    void enqueue(node *);
    node * dequeue();
};

struct Stack{
    node * head;
    void create();
    void close();
    void push(node *);
    node * pop();
    bool isEmpty();
};


tree directory;
int BFS_counter = 0;
int DFS_counter = 0;
int ios_counter = 0;

void inorderSearch(node * f, int num){
    bool found = false;
    if(f){
        inorderSearch(f->left, num);
        ios_counter++;
        if (num == f->number){
            found = true;
            cout << ios_counter << ". node: " << f->number << endl;
            return;
        }
        inorderSearch(f->right, num);
    }
    /*
    if (!found){
        cout << "No matching numbers." << endl;
    }*/
}

void BFS(node * root, int num){
    Queue Q;
    Q.create();
    Q.enqueue(root);
    node * u;
    bool found = false;
    while(!Q.isEmpty()){
        u = Q.dequeue();
        if(u->left)
            Q.enqueue(u->left);
        if(u->right)
            Q.enqueue(u->right);
        //cout << u->number << " ";
        BFS_counter++;
        if (num == u->number){
            found = true;
            cout << BFS_counter << ". node: " << u->number << endl;
            break;
        }
    }
    if (!found){
        cout << "No matching numbers." << endl;
    }
}

void DFS(node * root, int num){
    Stack S;
    S.create();
    S.push(root);
    node * u;
    bool found = false;
    while (!S.isEmpty()){
        u = S.pop();
        if(u->right)
            S.push(u->right);
        if(u->left)
            S.push(u->left);
        //cout << u->number << " ";
        DFS_counter++;
        if (num == u->number){
            found = true;
            cout << DFS_counter << ". node: " << u->number << endl;
            break;
        }
    }
    if (!found){
        cout << "No matching numbers." << endl;
    }
}

int main() {
    int input;
    
    directory.createTree();
    
    cout << endl << "preorder: " << endl;
    directory.printPreorder(directory.root);
    
    cout << endl << "Enter number to find a node in Tree: ";
    cin >> input;
    
    cout << "Inorder Search: " << endl;
    inorderSearch(directory.root, input);
    //cout << "Step size is: " << ios_counter << endl;
    
    cout << "BFS: " << endl;
    BFS(directory.root, input) ;
    //cout << "Step size is: " << BFS_counter << endl;
    
    cout << "DFS: " << endl;
    DFS(directory.root, input);
    //cout << "Step size is: " << DFS_counter << endl;
    
    
    
    /*
    cout << endl << "inorder: " << endl;
    directory.printInorder(directory.root);
    cout << endl << "postorder: " << endl;
    directory.printPostorder(directory.root);
    
    cout << endl << endl << "The max number is " << directory.findMax(directory.root) << endl;
    
    cout << "The min number is " << directory.findMin(directory.root) << endl;
    
    cout << "There are " << directory.findNumNode(directory.root) << " nodes." << endl;
    
    cout << "There are " << directory.findNumLeaf(directory.root) << " leaves." << endl;
    
    cout << "Sum of all numbers is " << directory.calculateSum(directory.root) << endl;
    
    cout << "Average is " << directory.calculateAverage(directory.root) << endl;
    
    cout << "Depth is " << directory.calculateDepth(directory.root) << endl;
     
    */
    
    directory.removeTree(directory.root);
    
    return EXIT_SUCCESS;
}

void tree::createTree(){
    root = NULL;
    srand(time(NULL));
    for (int i = 0; i < N; i++){
        int t;
        t = rand() % N + 1;
        //cout << "Enter a number: ";
        //cin >> t;
        
        node * p = new node;
        p->number = t;
        p->left = NULL;
        p->right = NULL;
        
        if(!root){
            root = p;
        }
        else{
            node * traverse;
            traverse = root;
            while(traverse){
                if(traverse->left == NULL){
                    traverse->left = p;
                    break;
                }
                else if(traverse->right == NULL){
                    traverse->right = p;
                    break;
                }
                else{
                    int r = rand() % 2;
                    if(r == 1){
                        traverse = traverse->left;
                    }
                    else if(r == 0){
                        traverse = traverse->right;
                    }
                }
            }
        }
    }
}

void tree::removeTree(node * r){
    node * deleted = r;
    if(r->left)
        removeTree(r->left);
    if(r->right)
        removeTree(r->right);
    delete deleted;
}

void tree::printPreorder(node * nptr){
    if(nptr){
        cout << nptr->number << "   ";
        printPreorder(nptr->left);
        printPreorder(nptr->right);
    }
}

void tree::printInorder(node * nptr){
    if(nptr){
        printInorder(nptr->left);
        cout << nptr->number << "   ";
        printInorder(nptr->right);
    }
}

void tree::printPostorder(node * nptr){
    if(nptr){
        printPostorder(nptr->left);
        printPostorder(nptr->right);
        cout << nptr->number << "   ";
    }
}

int tree::findMax(node * r){
    int max, temp;
    max = r->number;
    
    if(r->left != NULL){
        temp = findMax(r->left);
        if (temp > max)
            max = temp;
    }
    if(r->right != NULL){
        temp = findMax(r->right);
        if (temp > max)
            max = temp;
    }
    
    return max;
}

int tree::findMin(node * r){
    int min, temp;
    min = r->number;
    
    if (r->left != NULL && r->left->number < min){
        min = r->left->number;
    }
    if (r->right != NULL && r->right->number < min){
        min = r->right->number;
    }
    
    if(r->left != NULL){
        temp = findMin(r->left);
        if (temp < min)
            min = temp;
    }
    if(r->right != NULL){
        temp = findMin(r->right);
        if (temp < min)
            min = temp;
    }
    
    return min;
}

int tree::findNumNode(node * r){
    int counter = 0;
    counter++;
    
    if(r->left != NULL){
        counter += findNumNode(r->left);
    }
    if(r->right != NULL){
        counter += findNumNode(r->right);
    }
    
    return counter;
}

int tree::findNumLeaf(node * r){
    int counter = 0;
    if (r->left == NULL && r->right == NULL){
        counter++;
    }
    
    if(r->left != NULL){
        counter += findNumLeaf(r->left);
    }
    if(r->right != NULL){
        counter += findNumLeaf(r->right);
    }
    
    return counter;
}

float tree::calculateAverage(node * r){
    return (float)calculateSum(r)/(float)findNumNode(r);
}

int tree::calculateSum(node * r){
    int result = 0;
    
    result += r->number;
    
    if(r->left != NULL){
        result += calculateSum(r->left);
    }
    if(r->right != NULL){
        result += calculateSum(r->right);
    }
    
    return result;
}

int tree::calculateDepth(node * r){
    int dl = 0, dr = 0;
    
    if(r->left == NULL && r->right == NULL)
        return 1;
    else{
        if(r->left){
            dl = calculateDepth(r->left);
        }
        if(r->right){
            dr = calculateDepth(r->right);
        }
        
        if(dl > dr)
            return dl + 1;
        else
            return dr + 1;
    }
}

void Queue::create(){
    front = NULL;
    back = NULL;
}

void Queue::close(){
    node * p;
    while (front) {
        p = front;
        front = front->next;
        delete p;
    }
}

bool Queue::isEmpty() {
    return front == NULL;
}

void Queue::enqueue(node * newdata){
    node * newnode = new node;
    newnode = newdata;
    newnode->left = newdata->left;
    newnode->right = newdata->right;
    newnode->number = newdata->number;
    newnode->next = NULL;
    if ( isEmpty() ) {
        back = newnode;
        front = back;
    }
    else {
        back->next = newnode;
        back = newnode;
    }
}

node *Queue::dequeue() {
    node * topnode;
    topnode = front;
    front = front->next;
    //delete topnode;
    return topnode;
}

void Stack::create(){
    head = NULL;
}

void Stack::close(){
    node * p;
    while (head){
        p = head;
        head = head->next;
        delete p;
    }
}

void Stack::push(node * newdata){
    node * newnode = new node;
    newnode = newdata;
    newnode->left = newdata->left;
    newnode->right = newdata->right;
    newnode->number = newdata->number;
    newnode->next = head;
    head = newnode;
}

node * Stack::pop(){
    if (isEmpty())
        return NULL;
    
    node *topnode = head;
    head = head->next;
    //delete topnode;
    return topnode;
}

bool Stack::isEmpty(){
    return (head == NULL);
}
