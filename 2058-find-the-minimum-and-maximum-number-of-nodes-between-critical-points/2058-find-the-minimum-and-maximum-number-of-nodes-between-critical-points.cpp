class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first=-1,last=-1,mn=INT_MAX,pos=1;
        ListNode* a=head;
        ListNode* b=head->next;

        while(b->next){
            ListNode* c=b->next;
            if((b->val>a->val&&b->val>c->val)||(b->val<a->val&&b->val<c->val)){
                if(first==-1) first=pos;
                else mn=min(mn,pos-last);
                last=pos;
            }
            a=b;
            b=c;
            pos++;
        }

        if(first==-1||first==last) return {-1,-1};
        return {mn,last-first};
    }
};