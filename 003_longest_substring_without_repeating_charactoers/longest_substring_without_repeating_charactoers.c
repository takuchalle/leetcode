int lengthOfLongestSubstring(char * s){
    char* head = s;
    char* tail = s;
    int max = 0;

    while(*tail != '\0') {
		tail++;
		for(char* t = head; t != tail; t++) {
			int count = tail - head;
			if(max < count) max = count;
			if(*t == *tail) {
				head = ++t;
				break;
			}
		}
	}
	return max;
}
