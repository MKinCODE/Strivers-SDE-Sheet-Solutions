struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=0;
        ListNode* temp = head;
        while(temp!=nullptr){
            n++;
            temp=temp->next;
        }
        ListNode* last=nullptr;
        ListNode* curr=nullptr;
        for(int i=0; i<n/k; i++){
            last=head;
            ListNode* next=nullptr;
            ListNode* prev=nullptr;
            for(int i=0; i<k; i++){
                next=head->next;
                head->next=prev;
                prev=head;
                head=next;
            }

            if(i!=0) last->next=prev;
            else curr=prev;
        }
        last->next=head;
        return curr;
    }
};