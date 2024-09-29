#include <stdlib.h>

#define HASHSIZE	10
typedef struct hashNode {
	int val;
	int idx;
	struct hashNode *next;
} xHN_t;

xHN_t dict[HASHSIZE];

xHN_t *get(int val) {
	int hashVal = val% HASHSIZE;
	for(xHN_t *n=dict[hashVal]; n; n=n->next) {
		if(n->value == val)
			return n;
	}
	return NULL;
}


int sum(int num) {
	if(num<=0)
		return 0;
	else
		return sum(num-1) + num;
}

int main() {
    get(dict[3]);
	
	sum(5);
    return 0;
}