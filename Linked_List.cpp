#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node * next;
    Node(int val){
        this->val= val;
        next = nullptr;
    }
};

void InsertAtEnd(Node * &head,int val){
    Node * newnode = new Node(val);
    if (head == nullptr)
    {
        head = newnode;
        return;
    }
    Node * temp_pointer = head;
    while (temp_pointer->next != nullptr)
    {
        temp_pointer = temp_pointer->next;
    }
    temp_pointer->next = newnode;
}

void display (Node * head){
    while (head != nullptr)
    {
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

void InsertAtHead(Node * &head, int val){
    Node * newnode = new Node(val);
    newnode->next = head;
    head = newnode;
}

bool search(Node * head,int key){
    while (head!= nullptr){
       if (head->val== key){
           return true;
       }
       head = head->next;
    }
    return false;
}

void delete_at_head(Node * &head){
    Node* todelete = head;
    head = head->next;
    delete todelete;
}

void deletion(Node * &head, int key){

    if (head == nullptr){
        return;
    }

    if(head->val == key){
        delete_at_head(head);
        return;
    }

    Node * temp_pointer = head;
    while (temp_pointer->next->val != key){
        temp_pointer = temp_pointer->next;
    }

    if(temp_pointer->next == nullptr){
        cout<<"Element not found"<<endl;
        return;
    }
    
    Node * todelete = temp_pointer->next;
    temp_pointer->next  = temp_pointer->next->next;
    delete todelete;
}

Node * reverse(Node * &head){
    Node * prevptr = nullptr;
    Node * currptr = head;
    Node * nextptr;

    while(currptr != nullptr){
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}

Node * reverse_recursive(Node * &head){

    if (head==nullptr || head->next == nullptr){
       return head;
    }

    Node * newhead = reverse_recursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newhead;
}

Node *reversek(Node * &head, int k){

    Node * prevptr = nullptr;
    Node * currptr = head;
    Node * nextptr;
    int count = 0;
    while (currptr != nullptr && count < k){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    if(nextptr != nullptr){
        head->next = reversek(currptr,k);
    }
    return prevptr;
}

bool DetectCycle(Node * head){
    Node * slow = head;
    Node * fast = head;
    while(fast!= nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

void MakeCycle(Node * &head,int pos){
    Node * temp = head;
    Node * startnode = nullptr;
    int count = 1;
    while(temp->next != nullptr){
        if(count == pos){
            startnode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startnode;
}

void RemoveCylce(Node * &head){
    if(DetectCycle(head)){
        Node * slow = head;
        Node * fast = head;

        do{
            fast = fast->next->next;
            slow = slow->next;
        } while (fast!=slow);

        slow = head;
        while(slow->next != fast->next){
            fast = fast->next;
            slow = slow->next;
        }

        fast->next = nullptr;
        return;
    }
    cout<<"There is no cyle present"<<endl;
}

int length_list(Node * &head){
    Node * temp_pointer = head;
    int len = 0;
    while(temp_pointer != nullptr){
        len +=1;
        temp_pointer = temp_pointer->next;
    }
    return len;
}

//lecture 22.7 append k nodes from the end to the start, code below
Node * append_lastk_tostart(Node * &head, int k){
    if (k==0 || k==length_list(head)){
        return head;
    }
    int l = length_list(head);
    int count = 1;
    Node * newhead, *newtail, *tail = head;

    while (tail->next != nullptr){
        if(count == l - k){
            newtail = tail;
        }
        if(count == l - k+1){
            newhead = tail;
        }
        tail = tail->next;
        count++;
    }
    newtail->next = nullptr;
    tail->next = head;
    return newhead;   
}

//lecture 22.8 find intersection of 2 linked lists, code below
void intersect(Node * head1, Node * head2, int pos){

    Node * temp_pointer1 = head1;
    while (pos!=0){
        temp_pointer1 = temp_pointer1->next;
        pos--;
    }
    Node * temp_pointer2 = head2;
    while (temp_pointer2->next != nullptr){
        temp_pointer2 = temp_pointer2->next;
    }
    temp_pointer2->next = temp_pointer1;
}

int intersectionPoint(Node * &head1, Node * &head2){
    int l1 = length_list(head1);
    int l2 = length_list(head2);
    Node * temp_pointer1,* temp_pointer2;
    int sublen;

    if (l1>l2){
        sublen = l1-l2;
        temp_pointer1 = head1;
        temp_pointer2 = head2;
    }
    else{
        sublen = l2-l1;
        temp_pointer1= head2;
        temp_pointer2 = head1;
    }

    int count = 0;
    while (count!=sublen){
        if(temp_pointer1->next == nullptr){
            return -1;
        }
        temp_pointer1 = temp_pointer1->next;
        count ++;
    }

    while (temp_pointer1->next != nullptr && temp_pointer2 != nullptr){
        if (temp_pointer1 == temp_pointer2){
            return temp_pointer1->val;
        }
        temp_pointer1 = temp_pointer1->next;
        temp_pointer2 = temp_pointer2->next;
    }
    return -1;
}

// lecture 22.9 merge 2 sorted linked lists, code below
// iterative way
Node * merge(Node * head1, Node * head2){
    Node * dummy = new Node(-1);
    Node * ptr1 = head1;
    Node * ptr2 = head2;
    Node * ptr3 = dummy;

    while ((ptr1->next != nullptr) && (ptr2->next != nullptr)){
        if ((ptr1->val) > (ptr2->val)){
            ptr3->next = ptr2;
            ptr3 = ptr3->next;
            ptr2 = ptr2->next;
        }
        else{
            ptr3->next = ptr1;
            ptr3 = ptr3->next;
            ptr1 = ptr1->next;
        }
    }
    if(ptr1!=nullptr){
        while(ptr1!= nullptr){
            ptr2->next = ptr1;
            ptr1 = ptr1->next;
            ptr3 = ptr3->next;
        }
    }
    if(ptr1!=nullptr){
        while(ptr2 != nullptr){
            ptr1->next = ptr2;
            ptr2 = ptr2->next;
            ptr3 = ptr3->next;
        }
    }
    Node * newhead = dummy->next;
    deletion(dummy,-1);
    return newhead;
}

// recursive way
Node * merge_recursive(Node * head1 , Node * head2){
    if (head1 == nullptr){
        return head2;
    }
    if (head2 == nullptr){
        return head1;
    }

    Node * result;
    if (head1->val > head2->val)
    {
        result = head2;
        result->next = merge_recursive(head1, head2->next);
    }
    else{
        result = head1;
        result->next = merge_recursive(head1->next, head2);
    }
    return result;
}

//lecture 22.11 even index elements after odd index elements, code below
void evenafterodd(Node * &head){

    Node * oddhead = head;
    Node * evenhead = head->next;
    Node * evenstart = head->next;
    int count= 1;
    while (evenhead->next!=nullptr && oddhead->next != nullptr){
        if (count %2 == 1){
            oddhead->next = evenhead->next;
            oddhead = oddhead->next;
            count++;
        }
        else{
            evenhead->next = oddhead->next;
            evenhead = evenhead->next;
            count++;
        }
    }
    if (evenhead->next == nullptr){
        oddhead->next = evenstart;
        return;
    }
    if (oddhead->next == nullptr){
        oddhead->next = evenstart;
        evenhead->next = nullptr;
        return;
    }
}

//leet code question palindrome check
bool isPalindrome(Node * head){
    if(head == nullptr){
        return false;
    }
    if (head->next == nullptr){
        return true;
    }
    Node * temp = head;
    int len = 1;
    while(temp->next != nullptr){
        len ++;
        temp = temp->next;
    }
    temp = head;
    int arr[len];

    for (int i = 0; i < len; i++){
        arr[i] = temp->val;
        temp = temp->next;
    }

    int st1,st2;
    if (len %2 == 0){
        st1 = len/2 -1;
        st2 = len/2;
    }

    if(len %2!=0){
        st1 = len/2 -1;
        st2 = len/2 + 1;
    }

    while(st1!= 0 && st2!= len){
        if(arr[st1]!= arr[st2]){
            return false;
        }
        st1--;
        st2++;
    }
    return true;
}

// mergo sort for linked list
Node * midele(Node * head){
    Node * slow = head;
    Node * fast = head->next;

    while(slow->next != nullptr && (fast != nullptr && fast->next != nullptr)){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node * merge_combine_sort(Node * head1, Node * head2){
    
    Node * temp = new Node(-1);
    Node * newhead = temp;

    while(head1 != nullptr && head2 != nullptr){
        if(head1->val >= head2->val){
            temp->next = head2;
            head2 = head2->next;
        }
        else{
            temp->next = head1;
            head1 = head1->next;
        }
        temp = temp->next;
    }

    while(head1 != nullptr){
        temp->next = head1;
        temp = temp->next;
        head1 = head1->next;
    }

    while(head2 != nullptr){
        temp->next = head2;
        temp = temp->next;
        head2 = head2->next;
    }

    return newhead->next;
}

Node * merge_sort_main(Node * &head){
    if(head->next == nullptr){
        return head;
    }

    Node * mid = midele(head);
    Node * head2 = mid->next;
    mid->next = nullptr;
    Node * newhead = merge_combine_sort(merge_sort_main(head), merge_sort_main(head2));
    return newhead;
}

int main(){
    Node * head = nullptr;
    InsertAtHead(head,5);
    InsertAtHead(head,2);
    InsertAtHead(head,7);
    InsertAtHead(head,3);
    InsertAtHead(head,3);
    display(head);
    head = reversek(head,2);
    display(head);

    // // cout<<search(head,2)<<endl;
    // // delete_at_head(head);
    // // display(head);

    // // deletion(head,2);
    // // display(head);

    // head = reverse_recursive(head);
    // display(head);

    // Node * head2 = nullptr;
    // InsertAtHead(head2,1);
    // InsertAtEnd(head2,2);
    // InsertAtEnd(head2,3);
    // InsertAtEnd(head2,4);
    // InsertAtEnd(head2,5);
    // InsertAtEnd(head2,6);
    // InsertAtEnd(head2,7);
    // InsertAtEnd(head2,8);
    // // InsertAtEnd(head2,9);
    // display(head2);
    // Node * newhead = reversek(head2,3);
    // display(newhead);
    // MakeCycle(newhead, 5);
    // cout<<DetectCycle(newhead)<<endl;
    // RemoveCylce(newhead);
    // display(newhead);
    // // cout<<length_list(newhead);
    // newhead = append_lastk_tostart(newhead,5);
    // display(newhead);
    
                                            // int main for lecture 22.9 start
    // Node * head1 = nullptr;
    // Node * head2 = nullptr;
    // InsertAtEnd(head1,2);
    // InsertAtEnd(head1,4);
    // InsertAtEnd(head1,6);
    // InsertAtEnd(head1,8);
    // InsertAtEnd(head1,10);
    // InsertAtEnd(head1,12);
    // InsertAtEnd(head2,1);
    // InsertAtEnd(head2,4);
    // InsertAtEnd(head2,6);
    // InsertAtEnd(head2,7);
    // display(head1);
    // display(head2);
    // Node * newhead = merge_recursive(head1,head2); //there is an iterative and recursive way to merge check out both ways
    // display(newhead);
                                            // int main for lecture 22.9 end
    
                                            // int main for lecture 22.8 start
    // Node * head1= nullptr;
    // Node * head2 = nullptr;

    // InsertAtEnd(head1,1);
    // InsertAtEnd(head1,5);
    // InsertAtEnd(head1,4);
    // InsertAtEnd(head1,3);
    // InsertAtEnd(head1,9);
    // InsertAtEnd(head1,2);
    // InsertAtEnd(head2,2);
    // InsertAtEnd(head2,3);
    // InsertAtEnd(head2,4);
    // InsertAtEnd(head2,5);
    // display(head1);
    // display(head2);

    // intersect(head1,head2,3);
    // display(head2);
    // cout<<intersectionPoint(head1,head2)<<endl;
    // cout<<search(head,2)<<endl;
                                            // int main for lecture 22.8 end

                                            //int main for lecture 22.11 start
    // Node * head = nullptr;
    // InsertAtEnd(head,1);
    // InsertAtEnd(head,2);
    // InsertAtEnd(head,3);
    // InsertAtEnd(head,4);
    // InsertAtEnd(head,5);
    // InsertAtEnd(head,6);
    // InsertAtEnd(head,7);
    // display(head);
    // evenafterodd(head);
    // display(head);
                                            //int main for lecture 22.11 end
}