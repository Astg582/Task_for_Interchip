#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
	int* arr;
	size_t size;
	size_t cap;
}Vint;


Vint construct_0(){
	Vint ob;
	ob.size = 0;
	ob.cap = 0;
	ob.arr = NULL;
	return ob;
}


Vint construct_s(size_t size){
	Vint ob;
	ob.size = size;
	ob.cap = size;
	ob.arr = (int*) malloc(ob.cap * (sizeof(int)));
	return ob;
}

Vint construct_v(size_t size, int val){
	Vint ob;
	ob.size = size;
	ob.cap = size;
	ob.arr = (int*) malloc(ob.cap * (sizeof(int)));
	for(int i = 0; i < size; ++i){
		ob.arr[i] = val;
	}
	return ob;
}

void Deletion(Vint* ob){
	ob->cap = 0;
	ob->size = 0;
	free(ob -> arr);
}

void resize(Vint* ob, size_t new_size){
	if(ob->size > new_size){
		ob->size = new_size;
	}else{
		if(new_size > ob -> size){
			ob->cap = new_size;
			int* ptr = (int*) malloc (sizeof(int)* ob->cap);
			if(ptr){
				return;
			}
			for(int i = 0; i < ob->size; ++i){
				ptr[i] = ob->arr[i];
			}
			for(int i = ob->size; i < ob->cap; ++i){
				ptr[i] = 0;
			}
			ob->size = new_size;
			free(ob->arr);
			ob->arr = ptr;
			ptr = NULL;
		}
		for(int i = ob->size; i < new_size; ++i){
			ob->arr[i] = 0;
		}
		ob->size = new_size;
	}
}


void recap(Vint* ob){
	if(ob->cap == 0){
		ob->cap = 4;
		ob->arr = (int*) malloc(sizeof(int) * 2);
	}else{
		ob->cap *= 2;
		int* ptr = (int*) malloc(sizeof(int) * (ob->cap * 2));
		for(int i = 0; i < ob->size; ++i){
			ptr[i] = ob->arr[i];
		}
		free(ob->arr);
		ob->arr = ptr;
		ptr = NULL;
	}
}

void push_back(Vint* ob, int val){
	if(ob->size == ob->cap){
		recap(ob);
	}
	ob->arr[ob->size] = val;
	ob->size += 1;
}

void Insert(Vint* ob, size_t index, int value){
	if(index >= ob->size){
		printf("\nError out of range\n");
		return;
	}
	if(ob->size == ob->cap){
		recap(ob);
	}
	size_t i = ob->size;
	while(i != index){
		ob->arr[i] = ob->arr[i-1];
		--i;
	}
	ob->arr[i] = value;
	ob->size += 1;
}

bool empty(Vint* ob){
	return ob->size == 0;
}

int Access(Vint* ob,  size_t index){
	if(index <= ob->size){
		return ob->arr[index];
	}else{
		printf("Error index out of bouns\n");
		return -1;
	}
}

void Sort(Vint* ob){
 	if(empty(ob)){
		 printf("\nObject is empty\n");
		return;
	}
	for(int i = 0; i < ob->size - 1; ++i){
		for(int j = 0; j < ob->size - i- 1; ++j){
			if(ob->arr[j] > ob->arr[j + 1]){
				int tmp = ob->arr[j];
				ob->arr[j] = ob->arr[j + 1];
				ob->arr[j + 1] = tmp;
			}
		}
	} 
}

int Search(Vint* ob, int key){
	int j = ob->size;
	int i = 0;
	while(i <= j){
		int mid = i + (j - i) / 2; 
		if(ob->arr[mid] == key){
				return mid;
		}else if(ob->arr[mid] > key){
				j = --mid;
		}
		i = ++mid;
	}
	printf(\n"The number is missing\n");
	return -1;
}

int main(){
	Vint ob = construct_v(10, 3);
	for(int i = 0; i < ob.size; ++i){
		printf("\n %d", ob.arr[i]);
	}
	
	Insert(&ob, 3, 2);
	Insert(&ob, 2, 23);
	Insert(&ob, 5, 18);
	Insert(&ob, 8, -1);
    Insert(&ob, 4, 7);		
	push_back(&ob, 14);
	Sort(&ob);
	printf("the new ob\n");
	
	for(int i = 0; i < ob.cap; ++i){
		printf("\n %d", ob.arr[i]);
	}
	




	Deletion(&ob);
}
