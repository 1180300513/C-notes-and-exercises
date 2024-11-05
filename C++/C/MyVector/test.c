#include <stdio.h>
#include "vector.h"
#define N 26

int main(void) {
    // 在栈上创建一个Vector指针，指向堆上的结构体对象
    Vector* v = vector_create();

    // 向Vector中添加元素
    for (int i = 0; i < N; i++) {
        vector_push_back(v, 65+i);
    }

    // 遍历访问Vector中的元素
    for (int i = 0; i < N; i++) {
        printf("%c\n", v->data[i]);
    }

    // 用完了销毁Vector
    vector_destroy(v);

    return 0;
}