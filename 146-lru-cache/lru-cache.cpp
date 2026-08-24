class Node{
public:
    int k;
    int val;
    Node* left;
    Node* right;

    Node(int key, int value){
        this->k = key;
        this->val = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class LRUCache {
private:
    unordered_map<int, Node*> mp;
    Node* head = new Node(-1,-1);
    Node* end = new Node(-1,-1); 
    int c;

    void remove(Node* temp){
        temp->left->right = temp->right;
        temp->right->left = temp->left;
    }

    void insertAtEnd(Node* node){
        node->right = end;
        node->left = end->left;

        end->left->right = node;
        end->left = node;
    }

public:
    LRUCache(int capacity) {
        c = capacity;
        head->right = end;
        end->left = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        
        Node* temp = mp[key];
        remove(temp);
        insertAtEnd(temp);

        return temp->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) == mp.end()){
            Node* node = new Node(key, value);
            mp[key] = node;

            insertAtEnd(node);

            if (mp.size() > c) {
                Node* lru = head->right;

                remove(lru);
                mp.erase(lru->k);

                delete lru;
            }
        }
        else{
            Node* temp = mp[key];
            temp->val = value;
            remove(temp);
            insertAtEnd(temp);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */