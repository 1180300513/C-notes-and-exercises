#include <stdio.h>
#include "vector.h"
#define N 26

int main(void) {
    // ��ջ�ϴ���һ��Vectorָ�룬ָ����ϵĽṹ�����
    Vector* v = vector_create();

    // ��Vector�����Ԫ��
    for (int i = 0; i < N; i++) {
        vector_push_back(v, 65+i);
    }

    // ��������Vector�е�Ԫ��
    for (int i = 0; i < N; i++) {
        printf("%c\n", v->data[i]);
    }

    // ����������Vector
    vector_destroy(v);

    return 0;
}