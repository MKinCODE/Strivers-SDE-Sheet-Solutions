
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* temp = &dummy;
        int sum=0;
        int carry=0;
        while(l1!=nullptr || l2!=nullptr || carry){
            int v1 = (l1 != nullptr)? l1->val : 0;
            int v2 = (l2 != nullptr)? l2->val : 0;
            sum=v1+v2+carry;
            carry=sum/10;
            sum=sum%10;

            temp->next = new ListNode(sum);
            temp=temp->next;
            if(l1 != nullptr) l1=l1->next;
            if(l2 != nullptr) l2=l2->next;
        }
        return dummy.next;
    }
};