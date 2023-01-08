#include <iostream>
#include "myexceptions.h"
#include <exception>

template <class T>
class myDList{
    struct Node{
        int index;
        T data;
        Node* prev;
        Node* next;

        Node()
        : data{NULL},
        prev{nullptr},
        next{nullptr}
        {}

        Node(int val)
        : data{val},
        prev{nullptr},
        next{nullptr}
        {}
    };

    size_t listsize;
    Node *root;
    Node *tail;

    public:

    myDList()
    :listsize{0},
    root{nullptr},
    tail{nullptr}
    {}

    ~myDList(){
        
    }

    T& operator[] (int index){
        Node* iter = root;
        try
        {
            if(index >= listsize) throw MyExceptions("Out of range");
            while (iter != nullptr){
                if(iter->index != index) iter=iter->next;
                else return iter->data;
            }

        }
        catch(std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    void AddToHead(T val){
        Node *node = new Node(val);
        if (root == nullptr&&tail==nullptr){
            root=tail=node;
        }
        else{
            node->next = root;
            root->prev = node;
            root = node;    
        }
        Node* iter = root->next;
        while (iter != nullptr) {
            iter->index++;
            iter=iter->next;
        }
        listsize++;
    }

        void AddToTail(T val){
        Node *node = new Node(val);
        if (root == nullptr&&tail==nullptr){
            root=tail=node;
        }
        else{
            node->prev = tail;
            tail->next = node;
            tail = node;    
        }
        tail->index = tail->prev+1;
        listsize++;
    }


    size_t size() {return listsize;}
};


int main(){
    
    myDList<int> list;
    list.AddToHead(5);
    list.AddToTail(10);
    for (int i{0};i<list.size();i++) std::cout<<list[i]<<", "<<std::endl;
    return 0;
}