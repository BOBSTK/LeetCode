
//双向链表结点
class Node{
   public:
      int key;
      int val;
      Node* next;
      Node* prev;  
      Node():key(),val(),next(nullptr),prev(nullptr){}
      Node(int k,int v):key(k),val(v),next(nullptr),prev(nullptr){}
};

class LRUCache {
public:
    LRUCache(int capacity) {
      this->capacity = capacity;
      size = 0;
      //虚头部结点和尾部结点
      head = new Node();
      tail = new Node();
      head->next = tail;
      tail->prev = head;
    }
    
     int get(int key) {
      if(cache.find(key) == cache.end()) //key不存在
        return -1;
      //key存在,先通过哈希表定位，再移到头部
      Node* node = cache[key];
      moveToHead(node);
      return node->val;   
    }
    
    // void put(int key, int value) {
    //     if (!cache.count(key)) {
    //         // 如果 key 不存在，创建一个新的节点
    //         Node* node = new Node(key, value);
    //         // 添加进哈希表
    //         cache[key] = node;
    //         // 添加至双向链表的头部
    //         addToHead(node);
    //         ++size;
    //         if (size > capacity) {
    //             // 如果超出容量，删除双向链表的尾部节点
    //             Node* removed = removeTail();
    //             // 删除哈希表中对应的项
    //             cache.erase(removed->key);
    //             // 防止内存泄漏
    //             delete removed;
    //             --size;
    //         }
    //     }
    //     else {
    //         // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
    //         Node* node = cache[key];
    //         node->val = value;
    //         moveToHead(node);
    //     }
    // }


    
    void put(int key, int value) {
      if(cache.find(key)!=cache.end()){
          //更新值
          Node* node = cache[key];
          node->val = value;
          //移到头部
          moveToHead(node);
      }else{ //不存在
          //创建新节点
          Node* node = new Node(key,value);
          cache[key] = node;
          if(size<capacity){ //容量够
             cache[key] = node;
             addToHead(node);
             ++size;
          }else{  //容量不够
             Node* deleteNode = removeTail(); //删除尾部结点
             cache.erase(deleteNode->key); //删除键
             delete deleteNode;  //防止内存泄漏
             addToHead(node);
          }
      }
    }


    
    void addToHead(Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    
    void removeNode(Node* node) {
       node->prev->next = node->next;
       node->next->prev = node->prev;
    }

    //移动到头部
    void moveToHead(Node* node) {
       removeNode(node); //删除该结点
       addToHead(node); //在头结点添加该结点
    }

    Node* removeTail() {
       Node* node = tail->prev; //找到尾部结点
       removeNode(node); //删除该结点
       return node;
    }


private:
   unordered_map<int,Node*> cache; //key -> node(key,val)
   Node* head;
   Node* tail;
   int size;  //大小
   int capacity; //容量
};



/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */