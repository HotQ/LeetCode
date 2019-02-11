struct Task {
	int key;
	int value;
	Task(int k, int v) :key(k), value(v) {};
};

class LRUCache {
private:
	int size, capacity;
	list<Task> cache;
	unordered_map<int, list<Task>::iterator> mp;
    
public:
	LRUCache(int capacity) : size(0), capacity(capacity) {}

	int get(int key) {
		if (mp.find(key) == mp.end()) return -1;
		int value = mp[key]->value;
		cache.erase(mp[key]);
		cache.emplace_front(key, value);
		mp[key] = cache.begin();
		return value;
	}

	void put(int key, int value) {
		if (mp.find(key) == mp.end()) {
			++size;
			cache.emplace_front(key, value);
			mp[key] = cache.begin();
			if (size > capacity) {
				mp.erase(cache.back().key);
				cache.pop_back();
			}
		}
		else {
			cache.erase(mp[key]);
			cache.emplace_front(key, value);
			mp[key] = cache.begin();
		}
	}
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
