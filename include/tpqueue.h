// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
 private:
    struct Node {
        T x;
        Node* next;
    };
    Node* head;

 public:
    TPQueue() : head(nullptr) {}
    bool isEmpty() const {
        return head == nullptr;
    }
    void push(const T& x) {
        if (isEmpty()) {
            Node* temp = new Node;
            temp->x = x;
            temp->next = nullptr;
            return temp;
        } else {
            Node* current = head;
            while (x.prior <= current->next->x.prior && current != nullptr)
                current = current->next;
            Node* temp = new Node;
            temp->next = current->next;
            current->next = temp;
            temp->x = x;
            return;
        }
    }
    T& pop() {
        if (isEmpty()) {
            throw std::string("Empty!");
        } else {
            Node* temp = head->next;
            T x = head->x;
            delete(head);
            head = temp;
            return x;
        }
        return;
    }
    struct SYM {
        char ch;
        int prior;
    };
};

#endif  // INCLUDE_TPQUEUE_H_
