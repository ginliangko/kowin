#define HASHSIZE 1000

typedef struct hashNode {
    int val;
    int idx;
    struct hashNode *next;
} xHashNode_t;

xHashNode_t *dict[HASHSIZE] = {NULL};

xHashNode_t *get(int val) {
    unsigned hashVal = (unsigned) val % HASHSIZE;
    
    for(xHashNode_t *np = dict[hashVal]; np; np = np->next)
        if(np->val == val)
            return np;
    return NULL;
}

void insert(int val, int idx) {
    unsigned hashVal = (unsigned) val % HASHSIZE;
    xHashNode_t *np = malloc(sizeof(xHashNode_t));
    
    np->val = val;
    np->idx = idx;
    np->next = dict[hashVal];
    dict[hashVal] = np;
}

void freeList(xHashNode_t *np) {
    if(np != NULL) {
        freeList(np -> next);
        free(np);
    }
}

void freeDict() {
    for(int i = 0; i < HASHSIZE; i++) {
        freeList(dict[i]);
        dict[i] = NULL;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *out = (int *) malloc(sizeof(int)*2);
    for(int i = 0;i < numsSize;i++) {
        xHashNode_t *np = get(target-nums[i]);
        if(np != NULL) {
            out[0] = np->idx;
            out[1] = i;
            freeDict();
            *returnSize = 2;
            return out;
        }
        insert(nums[i],i);
    }
    freeDict();
    free(out);
    *returnSize = 0;
    return NULL;
}