#include<bits/stdc++.h>
using namespace std;

class LFUCache {
public:
    class node{
        public:
        int key;
        int val;
        int cnt;
        node * next;
        node * prev;
        node(int Key,int Val){
            key = Key;
            val = Val;
            cnt = 1;
        }
    };
    int cap = 0;
    // node * head = new node(-1,-1);
    // node * tail = new node(-1,-1);
    map<int,pair<node*,node*>> freqMap;
    map<int,node*> hshMap;

    void init(int freq){
        node * head = new node(-1,-1);
        node * tail = new node(-1,-1);
        head->next = tail;
        tail->prev = head;
        freqMap[freq] = make_pair(head,tail);
    }

    void deleteNode(node * curr){
        node * prevNode = curr->prev;
        node * nextNode = curr->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        int freq = curr->cnt;
        node * head = freqMap[freq].first;
        node * tail = freqMap[freq].second;
        if(head->next == tail){
            delete(head);
            delete(tail);
            freqMap.erase(freq);
        }
    }

    void insertNode(node * curr,int freq){
        if(freqMap.find(freq) == freqMap.end()){
            init(freq);
        }
        node * head = freqMap[freq].first;
        node * nextNode = head->next;
        curr->next = nextNode;
        curr->prev = head;
        head->next = curr;
        nextNode->prev = curr;
    }


    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(hshMap.find(key) != hshMap.end()){
            node * currNode = hshMap[key];
            int res = currNode->val;

            deleteNode(currNode);
            insertNode(currNode,currNode->cnt + 1);

            currNode->cnt = currNode->cnt + 1;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(hshMap.find(key) != hshMap.end()){
            node * currNode = hshMap[key];
            
            deleteNode(currNode);
            insertNode(currNode, currNode->cnt + 1);
            currNode->val = value;
            currNode->cnt = currNode->cnt + 1;
        }
        else if(cap == 0){
            int minFreq = freqMap.begin()->first;
            node * deletionTail = freqMap[minFreq].second;
            node * toDelete = deletionTail->prev;
            hshMap.erase(toDelete->key);
            deleteNode(deletionTail->prev);
            delete(toDelete);

            node * newNode = new node(key,value);
            insertNode(newNode,1);
            hshMap[key] = newNode;
        }
        else{
            node * newNode = new node(key,value);
            insertNode(newNode,1);
            hshMap[key] = newNode;
            cap--;
        }
    }
};


int main(){

}