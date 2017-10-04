//
//  stack.h
//  DS_Lab7
//
//  Created by Tuğba Özkal on 22.11.2016.
//  Copyright © 2016 Tuğba Özkal. All rights reserved.
//

#ifndef stack_h
#define stack_h

#define STACKSIZE 100
typedef struct d {
    int x;
    int y;
    int right;
    int left;
    int down;
    int up;
    int camefrom;
}StackDataType, position;

struct Stack {
    StackDataType element[STACKSIZE];
    int num;
    StackDataType top();
    void create();
    void close();
    bool push(StackDataType);
    StackDataType pop();
    bool isEmpty();
};

#endif /* stack_h */
