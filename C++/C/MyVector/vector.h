#ifndef VECTOR_H
#define VECTOR_H

typedef char ElementType;

typedef struct
{
	ElementType* data;
	int size;
	int capacity;
}Vector;

// ��ʼ��һ��Vector��̬����.��ʵ������ģ����C++��Ĭ�Ϲ��캯��
Vector* vector_create();

// ����һ��Vector��̬���飬�ͷ��ڴ档��ʵ����ģ����C++����������
void vector_destroy(Vector* v);

// ��̬����ĩβ���һ��Ԫ��
void vector_push_back(Vector* v, ElementType element);


#endif