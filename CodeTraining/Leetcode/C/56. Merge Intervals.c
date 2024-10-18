/*
56. Merge Intervals

Given a collection of intervals, merge all overlapping intervals.


For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

// Runtime 2ms Beats 100.00%, Memory 17.99MB Beats 55.36%


int cmp(const void *a, const void *b) {
    int **aa=a, **bb=b;
    return (*aa)[0] - (*bb)[0];
}
 
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    int **retS=malloc(intervalsSize*sizeof(int *));
    int idx=0;

    *returnSize=0;
    if(intervalsSize<1) return NULL;

    qsort(intervals, intervalsSize, 2*sizeof(int), cmp);

    *returnColumnSizes=malloc(intervalsSize*sizeof(int));

    int s=intervals[0][0];
    int e=intervals[0][1];

    for(int i=1; i<intervalsSize; i++) {
        if(e>=intervals[i][0]) {
            e=e>intervals[i][1]?e:intervals[i][1];
            s=s<intervals[i][0]?s:intervals[i][0];
        } else {
            retS[idx]=malloc(2*sizeof(int));
            retS[idx][0]=s;
            retS[idx][1]=e;
            s=intervals[i][0];
            e=intervals[i][1];

            (*returnColumnSizes)[idx]=2;
            idx++;
        }
    }

    retS[idx]=malloc(2*sizeof(int));
    retS[idx][0]=s;
    retS[idx][1]=e;

    (*returnColumnSizes)[idx]=2;
    idx++;

    *returnSize=idx;
    *intervalsColSize=2;

    return retS;
}

/* original solution
int cmp(const void *a, const void *b) {
    return (*(struct Interval *)a).start - (*(struct Interval *)b).start;
}
struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    int i, j;
​
    if (intervalsSize <= 0) return NULL;
    
    qsort(intervals, intervalsSize, sizeof(struct Interval), cmp);
    
    i = 0;
    for (j = 1; j < intervalsSize; j ++) {
        if (intervals[j].start > intervals[i].end) {
            // append
            intervals[++ i] = intervals[j];
        } else if (intervals[j].end > intervals[i].end) {
            // merge
            intervals[i].end = intervals[j].end;
        }   // ignore it
    }
    
    *returnSize = i + 1;
    
    return intervals;
}
*/

/*
Difficulty:Medium
Total Accepted:136.7K
Total Submissions:454.4K


Companies LinkedIn Google Facebook Twitter Microsoft Bloomberg Yelp
Related Topics Array Sort
Similar Questions 
                
                  
                    Insert Interval
                  
                    Meeting Rooms
                  
                    Meeting Rooms II
                  
                    Teemo Attacking
                  
                    Add Bold Tag in String
*/
