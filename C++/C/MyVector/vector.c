#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

#define DEFAULT_CAPACITY 5 // 设置动态数组的默认最小容量
#define THRESHOLD 1024

Vector* vector_create(){
	Vector* v = (Vector*)calloc(1, sizeof(Vector));
	if(v == NULL){
		printf("calloc failed in vector_create.\n");
		return NULL;   // 创建失败返回空指针
	}
	v->data = (ElementType*)calloc(DEFAULT_CAPACITY, sizeof(ElementType));
	if (v->data == NULL) {
		printf("malloc failed in vector_create.\n");
		// 不要忘记free结构体Vector，否则会导致内存泄漏
		free(v);
		return NULL;   // 创建失败返回空指针
	}
	// size已自动初始化为0值，所以不需要再次赋值了。
	v->capacity = DEFAULT_CAPACITY;
	
	return v;
}

void vector_destroy(Vector* v){
	free(v->data);
	free(v);
}

// 在C语言中, static修饰函数表示此函数仅在当前文件内部生效
static void vector_resize(Vector* v){
	int old_capacity = v->capacity;
	int new_capacity = v->capacity < THRESHOLD ? (old_capacity * 2) : (old_capacity + old_capacity / 2);
	// 利用realloc重新分配动态数组
	ElementType* tmp = realloc(v->data, new_capacity * (sizeof(ElementType)));
	if (tmp == NULL){
		printf("realloc failed in resize_vector.\n");
		exit(1);    // 扩容失败，退出整个程序。或者也可以做别的处理
	}
	v->data = tmp;
	v->capacity = new_capacity;
}
// 向动态数组末尾添加一个元素
void vector_push_back(Vector* v, ElementType element){
	if (v->size == v->capacity) {
		vector_resize(v);
	}
	v->data[v->size++] = element;
}