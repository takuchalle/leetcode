#include <vector>
#include <stdio.h>

class MyHashMap {
private:
	struct ListNode {
		int key;
		int val;
		ListNode* next;
		ListNode() : key(-1), val(0), next(nullptr) {}
		ListNode(int key, int val) : key(key), val(val), next(nullptr) {}
		ListNode(int key, int val, ListNode* next) : key(key), val(val), next(next) {}
	};

public:
    MyHashMap() {
		heads = std::vector<ListNode>(num);
    }
    
    void put(int key, int value) {
      	auto& head = heads[key % num];
		ListNode *l = &head;
		for (; l->next != nullptr; l = l->next) {
			if(l->key == key) {
				l->val = value;
				return;
			}
		}
		if(l->key == key) {
            l->val = value;
            return;
        }
		/* printf("add key %d, value %d\n", key, value); */
		l->next = new ListNode(key, value);	
    }
    
    int get(int key) {
      	auto& head = heads[key % num];
		for (ListNode *l = &head; l != nullptr; l = l->next) {
			if(l->key == key) {
				return l->val;
			}
		}
		return -1;
    }
    
    void remove(int key) {
      	auto& head = heads[key % num];
		ListNode *l = head.next;	
		ListNode *prev = &head;
		for (; l != nullptr; prev = l, l = l->next) {
			if(l->key == key) {
				prev->next = l->next;	
				delete l;
				return;
			}
		}
    }
private:
	std::vector<ListNode> heads;
	const int num = 100;
};


int main (int argc, char *argv[])
{
	MyHashMap* myHashMap = new MyHashMap();
	printf("a\n");
	myHashMap->put(1, 1); // The map is now [[1,1]]
	printf("b\n");
	myHashMap->put(2, 2); // The map is now [[1,1], [2,2]]
	printf("c\n");
	printf("%d\n",myHashMap->get(1));    // return 1, The map is now [[1,1], [2,2]]
	myHashMap->get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
	myHashMap->put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
	myHashMap->get(2);    // return 1, The map is now [[1,1], [2,1]]
	myHashMap->remove(2); // remove the mapping for 2, The map is now [[1,1]]
	myHashMap->get(2);    // return -1 (i.e., not found), The map is now [[1,1]]	
	return 0;
}
