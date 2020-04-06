#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef int Type;
typedef struct Node{
	Type _data;
	struct Node* _next;
}Node;

// ջ��ʵ��

// ������: pushFront popFront
// ˳���: pushBack popBack  ����ѡ�� ջ��ʵ�ֻ����϶���˳���ʵ��
//#pragma once
// ˳���ʵ��ջ
typedef struct Stack{
	Type* _array; 
	size_t _size;
	size_t _capacity;
}Stack;
void stackInit(Stack* st,size_t n){
	st->_capacity = n;
	st->_array = (Type*)malloc(sizeof(Type)*st->_capacity);
	st->_size = 0;
}

void stackPush(Stack* st, Type data){
	// �������
	if (st->_size == st->_capacity){
		st->_capacity *= 2;
		st->_array = (Type*)realloc(st->_array,sizeof(Type)*st->_capacity);
	}
	st->_array[st->_size++] = data;
}
void stackPop(Stack* st){
	// βɾ
	if (NULL == st){
		return;
	}
	if (st->_size){
		st->_size--;
	}
}

Type stackTop(Stack* st){
	return st->_array[st->_size-1];
}
size_t stackSize(Stack* st){
	return st->_size;
}
int stackEmpty(Stack* st){
	if (st->_size == 0){
		return 1;
	}
	return 0;
}


void stackDestory(Stack* st){
	free(st->_array);
	st->_array = NULL;
	st->_size = st->_capacity = 0;
}
void testStack(){
	Stack st;
	stackInit(&st,5);
	stackPush(&st, 1);
	stackPush(&st, 2);
	stackPush(&st, 3);
	stackPush(&st, 4);
	stackPush(&st, 5);
	stackPush(&st, 6);
	stackPush(&st, 7);
	stackPush(&st, 8);
	while ( stackEmpty(&st) != 1){
		printf("%d ",stackTop(&st));
		stackPop(&st);
	}
}
int main(){
	testStack();

	system("pause");
	return 0;
}