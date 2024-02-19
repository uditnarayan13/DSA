/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int lengthOfList(ListNode* l){
        int length = 0;
        while(l!=NULL){
           length++;
            l=l->next;
        }
        return length;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1= lengthOfList(l1);
        int len2 = lengthOfList(l2);
        
        ListNode* tempList1 = l1;
        ListNode* tempList2=l2;
        
        if(len1<len2){
            swap(tempList1,tempList2);
        }
        ListNode* res = new ListNode(0);
        ListNode* temp=res;
        int carry=0;
        while(tempList1!=NULL && tempList2!=NULL){
            int x = tempList1->val;
            int y=tempList2->val;
            
            int sum = x+y+carry;
            
             carry = sum/10;
            int digitForResult = sum%10;
            ListNode* sumOfNodes = new ListNode(digitForResult);
            temp->next = sumOfNodes;
            temp=temp->next;
            
            if(tempList1!=NULL){
                tempList1=tempList1->next;
            }
            
             
            if(tempList2!=NULL){
                tempList2=tempList2->next;
                
            }
            
        }
        
        while(tempList1!=NULL){
            int x = tempList1->val;
             int sum = x+carry;
              carry = sum/10;
            int digitForResult = sum%10;
            ListNode* sumOfNodes = new ListNode(digitForResult);
            temp->next = sumOfNodes;
            temp=temp->next;
             if(tempList1!=NULL){
                tempList1=tempList1->next;
            }
            
        }
        if(carry!=0){
            ListNode* sumOfNodes = new ListNode(carry);
             temp->next = sumOfNodes;
        }
        return res->next;
    }
};