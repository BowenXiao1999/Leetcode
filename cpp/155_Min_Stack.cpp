//
// Created by bowen on 2020/9/6.
//

// class MinStack {
// public:
//     /** initialize your data structure here. */
//     struct Node {
//         Node* next;
//         int m;
//         int val;

//         Node(int a, int m, Node* next = NULL) {
//             this->val = a;
//             this->m = m;
//             this->next = next;
//         }
//     };

//     Node *head;
//     MinStack() {

//     }

//     void push(int x) {
//         if (!head){
//             head = new Node(x, x);
//         }else{
//             head = new Node(x, min(x, head->m), head);
//         }
//     }

//     void pop() {
//         head = head->next;
//     }

//     int top() {
//         return head->val;
//     }

//     int getMin() {
//         return head->m;
//     }
// };

// /**
//  * Your MinStack object will be instantiated and called as such:
//  * MinStack* obj = new MinStack();
//  * obj->push(x);
//  * obj->pop();
//  * int param_3 = obj->top();
//  * int param_4 = obj->getMin();
//  */

class MinStack {
public:
    struct Node{
        int val;
        int min;
        Node* next;

        Node(int val, int min, Node*next = NULL){
            this->val = val;
            this->min = min;
            this->next = next;
        }
    };
    Node*head;
    void push(int x) {
        if(!head){
            head = new Node(x, x);
        }
        else{
            // put every new element in the front with updated min, make them head
            head = new Node(x, min(x, head->min), head);
        }
    }

    void pop() {
        head = head->next;
    }

    int top() {
        return head->val;
    }

    int getMin() {
        return head->min;
    }
};
