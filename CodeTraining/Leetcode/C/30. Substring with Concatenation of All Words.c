/*
30. Substring with Concatenation of All Words

You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.



For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]



You should return the indices: [0,9].
(order does not matter).
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

// Solution the fastest
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int nwords = 0, trieLen = 1, wordLen = strlen(words[0]), sLen = strlen(s);
    int counts[wordsSize + 1], countMap[wordLen * wordsSize + 1], trie[wordLen * wordsSize][26];
    memset(counts, 0, sizeof counts);
    memset(countMap, 0, sizeof countMap);
    memset(trie, 0, sizeof trie);
    for (int i = 0; i < wordsSize; i++) {
        int node = 0;
        for (int j = 0; j < wordLen; j++) {
            char next = words[i][j] - 'a';
            if (trie[node][next] == 0) {
                trie[node][next] = trieLen++;
                //printf("trie[%d][%d]=%d\n", node, next, trieLen-1);
            }
            node = trie[node][next];
        }
        if (countMap[node] == 0){
             countMap[node] = ++nwords;
             //printf("countMap[%d]=%d\n", node, nwords);
        }
        counts[countMap[node]]++;
        //printf("counts[%d]=%d\n", countMap[node], counts[countMap[node]]);
    }
    int* res = (int*) malloc(sLen * sizeof(int));
    int resLen = 0;
    int matches[sLen / wordLen + 1], windowCounts[nwords + 1];
    for (int i = 0; i < wordLen; i++) {
        if (i + wordLen * wordsSize > sLen) continue;

        memset(windowCounts, 0, sizeof windowCounts);
        int hits = 0, misses = 0;
        for (int j = i, k = 0, l = 0; j <= sLen-wordLen; j += wordLen, k++) {
            int node = 0;
            for (int m = j; m < j + wordLen; m++) {
                node = trie[node][s[m] - 'a'];
                printf("%d, %d, %d, node=%d\n", i, j, m, node);
                if (node == 0) { 
                    misses++;
                    matches[k] = -1; 
                    break; 
                }
            }
            printf("  node=%d\n", node);
            if (node != 0) {
                int countIdx = countMap[node];
                matches[k] = countIdx;
                windowCounts[countIdx]++;
                printf("  matches[%d]=%d, windowCounts[%d]++=%d\n", k, matches[k], countIdx, windowCounts[countIdx]);
                if (windowCounts[countIdx] == counts[countIdx]) {
                    hits++;
                    printf("  hits++=%d\n", hits);
                } else {
                    while (windowCounts[countIdx] > counts[countIdx]) {
                        int leftIdx = matches[l++];
                        printf("  l=%d, matches[%d]=%d, leftIdx=%d\n", l, l-1, leftIdx, leftIdx);
                        if (leftIdx == -1) {
                            misses--;
                            printf("  misses=%d\n", misses);
                        } else {
                            if (windowCounts[leftIdx] == counts[leftIdx]) {
                                hits--;
                                printf("  hits--=%d\n", hits);
                            }
                            windowCounts[leftIdx]--;
                            printf("  windowCounts[%d]--=%d\n", leftIdx, windowCounts[leftIdx]);
                        }
                    }
                }
            }

            while (l <= k && matches[l] == -1) { 
                l++;
                misses--;
            }
            if (hits == nwords && misses == 0) {
                res[resLen++] = i + l * wordLen;
            }
        }
    }
    *returnSize = resLen;
    return res;
}
/* Solution Jerry
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int *flag=malloc(wordsSize*sizeof(int));
    int sLen=strlen(s);
    int wLen=strlen(words[0]);
    int i=0;
    int *retS = (int*) malloc(sLen * sizeof(int));

    *returnSize=0;

    // Go throuth all the characters in the string
    while(i<sLen) {
        int cnt=0;
        int f=0;
        memset(flag, 0, wordsSize*sizeof(int));

        // go through all the words and compare to the substring start with index i
        for(int k=0; k<wordsSize; k++) {
            for(int j=0; j<wordsSize; j++) {
                f%=wordsSize;
                // if the string is the same, then set the flag to 1, else continue next
                if(flag[f]==0 && !strncmp(&s[i+(k*wLen)], words[f], wLen)) {
                    flag[f++]=1;
                    cnt++;
                    break;
                } else f++;
            }
            if(cnt<(k+1))    break;
        }

        if(cnt==wordsSize)  {
            *returnSize+=1;
            retS[*returnSize-1]=i;
        }
        i++;
    }

    return retS;
}
*/

/* Solution original
typedef struct item_s {
    char *word;
    int idx;
    struct item_s *next;
} item_t;

typedef struct {
    item_t *p;
    int n;
} buff_t;

#define HF 1021

unsigned int hash_code(const char *s, int len) {
    unsigned int hc = 5381;
    char c;
    while (len -- > 0) {
        hc = hc * 33 + s[len];
    }
    return hc % HF;
}

item_t *lookup(item_t **ht, unsigned int hc, const char *w, int len) {
    item_t *p = ht[hc];
    while (p) {
        if (!strncmp(p->word, w, len)) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    // 1. sort all words
    // 2. caculate each uniq words appears how many times
    // for (i = 0; i < length of string; i ++) {
    //    substr = s[i ... length of one word]
    //    if (substr is not one of the words or it appears more than what we have) continue;
    //    increase the count of this word
    //    if all words are found, add i into result
    //} 
    
    item_t *ht[HF] = { 0 }, **sp, *p;
    int *counts, *counts2, total, i;
    char *w;
    unsigned int hc;
    
    int total_len, word_len;
    int left, mid, right;
    
    int *results;
    
    if (wordsSize == 0) return NULL;
    
    buff_t buff = { 0 };
    buff.p = malloc(wordsSize * sizeof(item_t));
    //assert(buff->p);
    counts = calloc(wordsSize * 2, sizeof(int));
    //assert(counts);
    counts2 = &counts[wordsSize];
    total = 0;
    
    word_len = strlen(words[0]);
    total_len = strlen(s);
    
    sp = malloc(total_len * sizeof(item_t *));
    //assert(sp);
    
    results = malloc(total_len * sizeof(int));
    //assert(results);
    *returnSize = 0;
    
    for (i = 0; i < wordsSize; i ++) {
        w = words[i];
        hc = hash_code(w, word_len);
        p = lookup(ht, hc, w, word_len);
        if (p) {
            counts[p->idx] ++;
        } else {
            p = &buff.p[buff.n];
            
            p->idx = buff.n ++;
            p->word = w;
            
            p->next = ht[hc];
            ht[hc] = p;
            
            counts[p->idx] = 1;
        }
    }
        
    left = mid = right = 0;
    while (right <= total_len - word_len) {
        w = &s[right];
        hc = hash_code(w, word_len);
        p = lookup(ht, hc, w, word_len);
        if (!p) {
            total = 0;
            memset(counts2, 0, buff.n * sizeof(int));   // reset all counts
            left ++;           // shift one character from left
            mid = left;
            right = left;      // reset right
        } else {
            sp[right] = p;
            i = p->idx;
            counts2[i] ++;
            total ++;
            while (counts2[i] > counts[i]) {
                p = sp[mid];
                mid += word_len;   // push out a word
                counts2[p->idx] --;
                total --;
            }
            if (total == wordsSize) {   // all are found
                results[*returnSize] = mid;
                (*returnSize) ++;
                total = 0;
                memset(counts2, 0, buff.n * sizeof(int));   // reset all counts
                left = mid + 1;
                mid = left;
                right = left;
            } else {
                right += word_len;
            }
        }
    }
    
    free(buff.p);
    free(counts);
    free(sp);
    
    return results;
}
*/

/*
Difficulty:Hard
Total Accepted:82.6K
Total Submissions:376.3K


Related Topics Hash Table Two Pointers String
Similar Questions Minimum Window Substring

*/
