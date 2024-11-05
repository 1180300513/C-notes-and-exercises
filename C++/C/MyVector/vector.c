#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

#define DEFAULT_CAPACITY 5 // ���ö�̬�����Ĭ����С����
#define THRESHOLD 1024

Vector* vector_create(){
	Vector* v = (Vector*)calloc(1, sizeof(Vector));
	if(v == NULL){
		printf("calloc failed in vector_create.\n");
		return NULL;   // ����ʧ�ܷ��ؿ�ָ��
	}
	v->data = (ElementType*)calloc(DEFAULT_CAPACITY, sizeof(ElementType));
	if (v->data == NULL) {
		printf("malloc failed in vector_create.\n");
		// ��Ҫ����free�ṹ��Vector������ᵼ���ڴ�й©
		free(v);
		return NULL;   // ����ʧ�ܷ��ؿ�ָ��
	}
	// size���Զ���ʼ��Ϊ0ֵ�����Բ���Ҫ�ٴθ�ֵ�ˡ�
	v->capacity = DEFAULT_CAPACITY;
	
	return v;
}

void vector_destroy(Vector* v){
	free(v->data);
	free(v);
}

// ��C������, static���κ�����ʾ�˺������ڵ�ǰ�ļ��ڲ���Ч
static void vector_resize(Vector* v){
	int old_capacity = v->capacity;
	int new_capacity = v->capacity < THRESHOLD ? (old_capacity * 2) : (old_capacity + old_capacity / 2);
	// ����realloc���·��䶯̬����
	ElementType* tmp = realloc(v->data, new_capacity * (sizeof(ElementType)));
	if (tmp == NULL){
		printf("realloc failed in resize_vector.\n");
		exit(1);    // ����ʧ�ܣ��˳��������򡣻���Ҳ��������Ĵ���
	}
	v->data = tmp;
	v->capacity = new_capacity;
}
// ��̬����ĩβ���һ��Ԫ��
void vector_push_back(Vector* v, ElementType element){
	if (v->size == v->capacity) {
		vector_resize(v);
	}
	v->data[v->size++] = element;
}