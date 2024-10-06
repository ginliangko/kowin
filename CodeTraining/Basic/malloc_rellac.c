
int main(void)
{
	int index;
	int allocSize = 10;
	int **out = (int**)malloc(sizeof(int*) * allocSize);
	int *m = (int*)malloc(sizeof(int) * allocSize);

	for(int i=0; i<allocSize; i++) {
		out[i] = (int*)calloc(3, sizeof(int));
		(*m)[i] = 3;
	}
	
	if(true) {
		allocSize = allocSize * 2;
		out = (int**)realloc(out, allocSize * sizeof(int*));
		(*m) = (int*)realloc((*m), allocSize * sizeof(int));
	}
}
