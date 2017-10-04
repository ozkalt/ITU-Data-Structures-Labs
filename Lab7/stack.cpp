//
//  stack.cpp
//  DS_Lab7
//
//  Created by Tuğba Özkal on 22.11.2016.
//  Copyright © 2016 Tuğba Özkal. All rights reserved.
//

#include <stdio.h>
#include "stack.h"

void Stack::create() {
    num = 0;
}

void Stack::close() {
}

bool Stack::push(StackDataType new_element) {
    if (num<STACKSIZE) {
        element[num++] = new_element;
        return true;
    }
    return false;
}

StackDataType Stack::pop() {
    return element[--num];
}

bool Stack::isEmpty() {
    return (num == 0);
}

StackDataType Stack::top() {
    return element[num - 1];
}
