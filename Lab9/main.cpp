//
//  main.cpp
//  DS_Lab9
//
//  Created by Tuğba Özkal on 7.12.2016.
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
};

struct tree{
    node * root;
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

tree directory;

int main() {
    directory.createTree();
    
    cout << endl << "preorder: " << endl;
    directory.printPreorder(directory.root);
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
                    if (findNumLeaf(traverse->left) > findNumLeaf(traverse->right)){
                        traverse = traverse->right;
                    }
                    else{
                        traverse = traverse-left;
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
    if (r->left != NULL && r->left->number > max){
        max = r->left->number;
    }
    if (r->right != NULL && r->right->number > max){
        max = r->right->number;
    }
    
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

