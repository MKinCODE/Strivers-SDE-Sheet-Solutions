#include<unordered_set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//space optimal approach
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp=headA;
        ListNode* temp2=headB;
        while(temp!=temp2){
            if(temp==NULL) temp=headB;
            else temp=temp->next;

            if(temp2==NULL) temp2=headA;
            else temp2=temp2->next; 
        }
        return temp;
    }
};

//less space optimal
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> us;
        while(headA!=NULL){
            us.insert(headA);
            headA=headA->next;
        }
        while(headB!=NULL){
            if(us.count(headB)){
                return headB;
            }
            headB=headB->next;
        }
        return NULL;
    }
};