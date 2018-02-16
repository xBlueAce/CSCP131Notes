//
//  main.cpp
//  Feb15Thu
//
//  Created by Carlos Agustin on 2/15/18.
//  Copyright © 2018 Carlos Agustin. All rights reserved.
//
#include <string>
#include <iostream>
using namespace std;

//continuing form last class on student nodes..
//

//Purpose of Data Structure is to Organize data and input data

//using a predefined student class
class Student{
public:
    string name;
    int nSem;
    Student(){nSem = 1;}
    
};


//SNode class
template <typename ELT>
class SNode{
    ELT element_;
    SNode* next_;
};/* SNode */



template <typename ELT>
class SLinkedList{
public:
    SLinkedList(){}
    
    //destructor
    ~SLinkedList(){
        // if we dont destruct/ remove nodes
        // this can cause a memory leak
        while(head_ != nullptr)
        {
            removeFront();
        }
    }
    
    void addFront(const ELT &x){// set the new head
        SNode<ELT> tempptr = head_; //create new temp ptr that connects
        head_ = new SNode<ELT>; //create new node
        head_->next_ = tempptr; //points the next ptr of the new head to the tempptr
        head_->element_ = x; // inputs value of ptr
    }
    
    //returns the front element
    ELT front() const{
        if(head_ == nullptr)
            throw std::length_error("list Empty");
        else
        return head_->element_;
    }
    
    //will return true is it is empty
    bool isEmpty() const;
    
    //Will remove front node
    void removeFront(){
        if(head_ == nullptr)
            throw std::length_error("list Empty");
        else
        {
            //to remove a node in a list
            SNode<ELT> * tempPtr = head_->next_; //create a pointer that points to the next element in line
            delete head_; // delete the current head
            head_ = tempPtr; // make new head point to the temp ptr
    
        }
        
        
    }
    
    //Will print list
    void print(){
        SNode<ELT> tempPtr = head_;
        while(tempPtr != nullptr){
            std::cout << tempPtr->element_ << std::endl; // *Note: to print out element must 
                                                         // be define in the element_ in order to print
            tempPtr = tempPtr->next_;
        }
    }
private:
    SNode<ELT> * head_;
    
}; /* SLinkedList */

int main(){
    SLinkedList<Student> studnetList; //Creaes a list of student (LINKED LIST)
    Student st; // Create a student
    st.name = "Alex"; st.nSem = 2; // Name the studnet and add number of semester
    studnetList.addFront(st); // add it to the list
    st.name = "Luis"; st.nSem = 1; //repeat
    studnetList.addFront(st);
    studnetList.print();
    
    
    
    
    
    return 0;
}
