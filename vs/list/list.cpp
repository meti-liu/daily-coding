#include<iostream>
using namespace std;
struct Node
{
	int val;
	Node* next;
	Node(int val)
	{
		this->next = NULL;
		this->val = val;
	}
};
int main()
{
	int n;
	Node* head = NULL;
	Node* cur = NULL;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		Node* s = new Node(temp);
		if (head == NULL)
		{
			head = s;
			cur = head;
		}

		else
		{
			cur->next = s;
			cur = cur->next;
		}
	}

	Node* cur1 = head;
	while (cur1->val!= NULL)
	{
		cout << cur1->val << endl;
		cur1 = cur1->next;
	}
	return 0;
}