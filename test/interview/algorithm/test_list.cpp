#include<stdio.h>
//评测题目: 编程题2： 请完成如下函数（函数功能：将单项列表的顺序倒过来），pNodeHead是个单项列表的头。返回值是新的列表头。并提供测试函数。（15~30分钟）
#define NULL 0

struct Node
{
	Node() : next(NULL), i(0){};
	struct Node *next;
	int i;
};

Node *Fun(Node *pNodeHead)
{
	if (NULL == pNodeHead)
	{
		return NULL;
	}

	Node *pTemp = pNodeHead;
	Node *pRetNode = NULL;
	Node *pHead = pNodeHead;
	while (pTemp->next)
	{
		pHead = pRetNode;
		pRetNode = pTemp->next;
		pTemp->next = pRetNode->next;
		pRetNode->next = pHead;
	}

	return pRetNode;
}


void test_print(Node* pNodeHead)
{
	if (pNodeHead->next)
	{
		test_print(pNodeHead->next);
		printf("%d  ", pNodeHead->i);
	}
}

int main()
{
	Node *pNodeFirst = new Node();
	Node *pTemp = pNodeFirst;
	for (int i = 0; i < 10; i++)
	{
		Node *temp = new Node();
		temp->i = i;
		pTemp->next = temp;
		pTemp = temp;
	}

	test_print(pNodeFirst);
	Node* pNode = Fun(pNodeFirst);

	printf("\r\n");
	test_print(pNode);

	return 0;
}