#include <bits/stdc++.h> 
using namespace std; 
  
/* A linked list node */
class node { 
public: 
    int data; 
    node* next; 
}; 
  
node* pairWiseSwap(node* head) 
{ 
    // Base Case: The list is empty or has only one node 
    if (head == NULL || head->next == NULL) 
        return head; 
  
    // Store head of list after two nodes 
    node* remaing = head->next->next; 
  
    // Change head 
    node* newhead = head->next; 
  
    // Change next of second node 
    head->next->next = head; 
  
    // Recur for remaining list and change next of head 
    head->next = pairWiseSwap(remaing); 
  
    // Return new head of modified list 
    return newhead; 
} 
  

void push(node** head_ref, int new_data) 
{ 
    node* new_node = new node(); 

    new_node->data = new_data; 
  
    new_node->next = (*head_ref); 
  
    (*head_ref) = new_node; 
} 
  
void printList(node* node) 
{ 
    while (node != NULL) { 
        cout << node->data << " "; 
        node = node->next; 
    } 
} 

int main() 
{ 
    node* start = NULL; 
  
    /* The constructed linked list is:  
    1->2->3->4->5->6->7 */
    push(&start, 7); 
    push(&start, 6); 
    push(&start, 5); 
    push(&start, 4); 
    push(&start, 3); 
    push(&start, 2); 
    push(&start, 1); 
  
    cout << "Linked list before calling pairWiseSwap() "; 
    printList(start); 
  
    start = pairWiseSwap(start); 
  
    cout << "\nLinked list after calling pairWiseSwap() "; 
    printList(start); 
  
    return 0; 
} 
