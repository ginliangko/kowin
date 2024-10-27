/*
219. Contains Duplicate II

Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
*/

typedef struct {
    int val;
    int idx;
} e_t;

int cmpFunc(const void *a, const void *b) {
    return ((e_t *)a)->val -((e_t *)b)->val;
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    e_t *p;
    int i, ret=0;

    p = malloc(numsSize * sizeof(e_t));

    for (i = 0; i < numsSize; i ++) {
        p[i].val = nums[i];
        p[i].idx = i;
    }

    qsort(p, numsSize, sizeof(e_t), cmpFunc);

    for (i = 1; !f && i < numsSize; i ++) {
        if (p[i].val == p[i-1].val && p[i].idx - p[i-1].idx <= k) {
             ret = 1;
             break;
        }
    }

    free(p);

    return ret;
}

/*
Difficulty:Easy
Total Accepted:116.5K
Total Submissions:360K


Companies Palantir Airbnb
Related Topics Array Hash Table
Similar Questions 
                
                  
                    Contains Duplicate
                  
                    Contains Duplicate III
*/
