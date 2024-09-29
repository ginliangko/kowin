int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int hIndex(int* citations, int citationsSize) {
    qsort(citations, citationsSize, sizeof(int), cmpfunc);

    int h = 0;
    for (int i=0; i< citationsSize; i++)
    {
        if (citations[i] > i)  h++;
    }

    return h;
}