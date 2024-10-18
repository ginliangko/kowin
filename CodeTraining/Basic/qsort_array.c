 int cmp(const void *a, const void *b) {
    int **aa=a, **bb=b;
    return (*aa)[0] - (*bb)[0];
 }

int main(void) {
  int arr[5][2]={{7,10}, {4,6}, {0,4}, {2,6}, {5,6}}; 
  
  qsort(arr, 5, 2*sizeof(int), cmp);
}
