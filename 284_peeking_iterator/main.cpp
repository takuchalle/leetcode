class PeekingIterator : public Iterator {
private:
    int m_next{0};
    
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    m_next = Iterator::next();
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return m_next;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        int tmp = m_next;
        if(Iterator::hasNext()) {
            m_next = Iterator::next();
        } else {
            m_next = -1;
        }
	    return tmp;
	}
	
	bool hasNext() const {
	    return m_next != -1;
	}
};
