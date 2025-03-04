/*
 * A cache is a component that stores data so future requests for that data can be served faster. 
 * The data stored in a cache might be the results of an earlier computation, or the duplicates of data stored elsewhere. 
 * A cache hit occurs when the requested data can be found in a cache, while a cache miss occurs when it cannot. 
 * Cache hits are served by reading data from the cache which is faster than recomputing a result or reading from a slower data store. 
 * Thus, the more requests that can be served from the cache, the faster the system performs.
 * One of the popular cache replacement policies is: "least recently used" (LRU). It discards the least recently used items first.
*/

#include <iostream>
#include <map>
#include <string>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache: public Cache {
    private:
    void rmNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void AddToHead(Node* p) {
        p->prev = nullptr;
        p->next = head;
        head = p;
        if (p->next) {
            p->next->prev = p;
        }
        if (!tail) {
            tail = p;
        }
    }
    void moveToHead(Node* p) {
        if (p == head) return; 
        if (p == tail) { 
            tail = p->prev; 
            tail->next = nullptr; 
        } else {
            rmNode(p); 
        }
        AddToHead(p);
    }
    void rmLRU() {
        Node* lru = tail->prev;
        rmNode(lru);
        mp.erase(lru->key);
        delete lru;
    }
    public:
    LRUCache(int capacity): Cache() {
        this->head = nullptr;
        this->tail = nullptr;
        cp = capacity;
    }
    // overloading methods
    void set(int key, int value) override {
        auto itr = mp.find(key);
        if (itr != mp.end()) {
            Node* p = itr->second;
            p->value = value;
            moveToHead(p);
        } else {
            Node* p = new Node(key, value);
            AddToHead(p);
            mp[key] = p;
            if (mp.size() > cp ) {
                mp.erase(tail->key);
                rmLRU();
            }
        }
    }
    int get(int key) override {
        auto itr = mp.find(key);
        if (itr == mp.end()) {
            return -1;
        } else {
            Node* temp = mp[key];
            moveToHead(temp);
            return temp->value;
        }
    }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}

