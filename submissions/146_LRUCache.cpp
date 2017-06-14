/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the
following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity,
it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache(2);

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/
/*
LRU 即最近最少使用算法。该算法需要维护一个双向链表，用来保存节点，链表的结构使得节点移动时间复杂度都为O(1)。
但是为了快速定位节点，我们需要使用额外的数据结构来存放节点在链表中的位置，这样存取的时间复杂度也是O(1)，
所以我们使用哈希表来存放键值和其对应的节点在链表中的位置。
get(int key)操作：在哈希表中寻找，如果找到key，返回该节点对应的value；如果没找到返回-1
put(int key,int value)：添加节点，如果该节点存在，更新节点值，并将节点放到链表头；
如果不存在，看是否有剩余空间：如果没有，去掉尾部节点，添加新节点；如果有，将新节点放到链表头。
*/

class LRUCache {
public:
  LRUCache(int capacity):cap(capacity) {}
  int get(int key) {
    auto it = mp.find(key);
    if(it!=map.end()) {
      int res = it->second->second;
      update(it->second);
      return res;
    }
    return -1;
  }

  void put(int key, int value) {
    auto it = mp.find(key);
    if(it!=mp.end()){
      it->second->second = value;
      update(it->second);
    }
    else{
      if(mylist.size()==cap){
        auto li_it = --mylist.end();
        mp.erase(li_it->first);
        li_it->first = key;
        li_it->second = value;
        update(li_it);
      }
      else{
        mylist.push_front(make_pair(key,value));
        mp[key] = mylist.begin();
      }
    }
  }
private:
  void update(LI::iterator &it){
    mylist.push_front(make_pair(it->first,it->second));
    mp[it->first] = mylist.begin();
    mylist.erase(it);
  }
  using LI = list<pair<int,int>>;
  using hashmap = unordered_map<int,LI::iterator>;

  LI mylist;
  hashmap mp;
  int cap;
};
