//
//  main.cpp
//  homework1
//
//  Created by 雷昊 on 08/09/2017.
//  Copyright © 2017 Hao Lei. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 * Class node : 
        contains an int value & a node pointer to next node.
 */
class node {
    public :
        int value;              // an int value for storing an Integer
        node* next;             // a node pointer to the next node
    
        // default node constructor to construct a node without any value
        node() {
            next = nullptr;
        }
    
        // node constructor with a known int value.
        node(int insert_value) {
            value = insert_value;
            next  = nullptr;
        }
};

/**
 *  Class linked_list : 
        contains an int value meaning the total number of node in this linked list,
        and a node pointer to next node.
 */
class linked_list {
    public :
        int node_number;        // record the number of nodes in this linked list.
        node* head;             // a pointer to the next node.
    
        // default constructor for creating linked list object.
        linked_list() {
            node_number = 0;
            head = nullptr;
        }
    
        // function declaration for make a k sized random list
        void make_random_list(int size);
    
        // function declaration for another make function.
        void new_make_random_list(int k, int m);
    
        // function declaration for print the whole linked list.
        void print();
    
        // function declaration for reverse node order in the linked list.
        void reverse();
    
        // function declaration for sort the value in each node in ascending way.
        void sort();
    
        // function declaration for creating a new node and properly insert it to this sorted list.
        void insert(int k);
    
        // function declaration for removing all nodes in list in which their values are equal to
        // the function argument.
        void remove_all(int value);
};

void linked_list::make_random_list(int size) {
    node* temp;
    
    for(int i = 0; i < size; i++) {
        temp = new node(rand() % 100);
        temp->next = head;
        head = temp;
        node_number++;
    }
}

void linked_list::print() {
    node* temp = head;
    
    while(temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    
    cout << endl;
}

void linked_list::reverse() {
    node *previous, *current, *current_next;
    
    previous = nullptr;
    current = head;
    current_next = head->next;
    
    while(current_next != nullptr) {
        current->next = previous;
        previous = current;
        current = current_next;
        current_next = current_next->next;
    }
}

void linked_list::sort() {
    // selection sort of link list.
    node *mark = nullptr;
    
    int flag;
    node *temp = head;
    node *temp_next = temp->next;
    node *ahead_of_last = nullptr;
   
    while(temp->next->next != nullptr) {
        ahead_of_last = temp;
        temp = temp->next;
    }
    
    temp = head;
    
    while(temp != ahead_of_last) {
        flag = temp->value;
        mark->value = flag;
        
        while(temp_next != nullptr) {
            if(temp_next->value < flag) {
                mark = temp_next;
                flag = mark->value;
            }
            temp_next = temp_next->next;
        }
        
        if(flag != temp->value) {
            int temp1 = flag;
            mark->value = temp->value;
            temp->value = temp1;
        }
        
        temp = temp->next;
        temp_next = temp->next;
    }
    
    
}

void linked_list::insert(int k) {
    node *current, *next;
    node *new_node = new node(k);

    current = head;
    next = current->next;
    
    if(current->value < k) {
        node *temp = new node(k);
        temp->next = head;
        head = temp;
        current = head;
        next = current->next;
    }
    
    while(next != nullptr) {
        if(next->value >= k) {
            new_node->next = next;
            current->next = new_node;
            return;
        }
        current = next;
        next = current->next;
    }
}

void linked_list::remove_all(int value) {
    node *current, *next;
    
    current = head;
    next = current->next;
    
    while(next != nullptr) {
        if(next->value == value) {
            current->next = next->next;
        }
        current = next;
        delete next;
        next = current->next;
    }
}

void linked_list::new_make_random_list(int k, int m) {
    node *temp;
    
    for(int i = 0; i < k; i++) {
        temp = new node(rand() % m);
        temp->next = head;
        head = temp;
        node_number++;
    }
}

int main() {
    //Some examples of tests for your program are given below
    //During grading, other test cases will also be used
    linked_list L1;
    L1.new_make_random_list(50, 7);
    L1.print();
    L1.remove_all(1);
    L1.print();
    L1.remove_all(6);
    L1.print();
    
    linked_list L2;
    L2.new_make_random_list(60, 20);
    L2.sort();
    L2.print();
    
    L2.insert(-1);
    L2.print();
    L2.insert(20);
    L2.print();
    L2.insert(15);
    L2.print();
    L2.insert(10);
    L2.print();
    getchar();
    getchar();
    return 0;
}
