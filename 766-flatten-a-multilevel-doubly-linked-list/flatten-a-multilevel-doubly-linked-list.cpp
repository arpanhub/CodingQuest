/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* current = head;
        Node* tail = head;
        stack<Node*> st; 
        while(current){
            if(current->child != NULL){
                Node* child = current->child;
                if(current->next != NULL){
                    st.push(current->next);
                    current -> next->prev = NULL;
                }
                    current->next =child;
                    child->prev = current;
                    current->child=NULL;
            }
            tail = current;
            current = current->next;
        }
        while(!st.empty()){
            Node* Joint = st.top();
            st.pop();
            tail->next = Joint;
            Joint ->prev = tail;
            current = Joint;
            while(current){
                tail = current;
                current = current->next;
            }
        }
        return head;

    }
};







