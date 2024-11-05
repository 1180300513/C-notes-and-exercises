#ifndef VECTOR_H
#define VECTOR_H

typedef char ElementType;

typedef struct
{
	ElementType* data;
	int size;
	int capacity;
}Vector;

// 初始化一个Vector动态数组.这实际上是模拟了C++的默认构造函数
Vector* vector_create();

// 销毁一个Vector动态数组，释放内存。这实际上模拟了C++的析构函数
void vector_destroy(Vector* v);

// 向动态数组末尾添加一个元素
void vector_push_back(Vector* v, ElementType element);


#endif