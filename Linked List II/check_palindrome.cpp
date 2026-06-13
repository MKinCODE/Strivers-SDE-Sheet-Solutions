struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//reversing second half
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* next=nullptr;
        ListNode* prev=nullptr;
        while(slow!=nullptr){
            next=slow->next;
            slow->next=prev;
            prev=slow;
            slow=next;
        }
        while(prev!=nullptr){
            if(head->val!=prev->val) return false;
            head=head->next;
            prev=prev->next;
        }
        return true;
    }
};
//converting into string
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        string s="";
        while(head!=nullptr){
            s+=head->val;
            head=head->next;
        }
        string s1=s;
        reverse(s.begin(),s.end());
        if(s==s1) return true;
        return false;
    }
};