//  
// Leetcode Codential
//  
// Given a linked list, swap the kth node counted from the beginning with the
// kth node counted fronm the end of the list.
//
// 1->2->3->4->5->NULL, k = 2
// 1->4->3->2->5->NULL

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapNodes(ListNode* head, int k) {
        
    ListNode *first = nullptr;
    ListNode *sec = nullptr;
    ListNode *headCopy = head;
    ListNode *headCopy2 = head;
    
    int counter = 1;
    int counter2 = 1;
    
    ListNode *firstPrev = nullptr;
    ListNode *firstPrevFinal = nullptr;
    ListNode *secPrev = nullptr;

    //save the Kth node as well as get length of list
    while(headCopy){
            
        if(counter == k){
            first = headCopy;
            firstPrevFinal = firstPrev;
        }
        
        firstPrev = headCopy;
        headCopy = headCopy->next;
        counter++;
    }
    
    //get Kth node from the back
    while(headCopy2){
            
        if(counter2 == counter-k){
            sec = headCopy2;
            break;
        }
        
        secPrev = headCopy2;
        headCopy2 = headCopy2->next;
        counter2++;
    }
    
    if(first == sec) return head;
    
    firstPrevFinal -> next = sec;
    secPrev -> next = first;
    
    ListNode *tmp = first->next;
    first -> next = sec->next;
    sec->next = tmp;
    
    return firstPrevFinal;
}

int main(int argc, const char * argv[]) {
    ListNode *head  = new ListNode(1);
    ListNode *two   = new ListNode(2);
    ListNode *three = new ListNode(3);
    ListNode *four  = new ListNode(4);
    ListNode *five  = new ListNode(5);
    
    head->next = two;
    head->next->next = three;
    head->next->next->next = four;
    head->next->next->next->next = five;
    
    swapNodes(head, 2);
    return 0;
}
