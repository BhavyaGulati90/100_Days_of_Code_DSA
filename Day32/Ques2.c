// Min Stack


#include <stdlib.h>

typedef struct {
    int *st;        
    int *mn;        
    int top;        
    int cap;        
} MinStack;

static void ensureCapacity(MinStack *obj) {
    if (obj->top + 1 < obj->cap) return;

    int newCap = (obj->cap == 0) ? 4 : obj->cap * 2;
    obj->st = (int *)realloc(obj->st, newCap * sizeof(int));
    obj->mn = (int *)realloc(obj->mn, newCap * sizeof(int));
    obj->cap = newCap;
}

MinStack* minStackCreate() {
    MinStack *obj = (MinStack *)malloc(sizeof(MinStack));
    obj->st = NULL;
    obj->mn = NULL;
    obj->top = -1;
    obj->cap = 0;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    ensureCapacity(obj);
    obj->top++;
    obj->st[obj->top] = val;

    if (obj->top == 0) obj->mn[obj->top] = val;
    else {
        int prevMin = obj->mn[obj->top - 1];
        obj->mn[obj->top] = (val < prevMin) ? val : prevMin;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top >= 0) obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->st[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->mn[obj->top];
}

void minStackFree(MinStack* obj) {
    if (!obj) return;
    free(obj->st);
    free(obj->mn);
    free(obj);
}