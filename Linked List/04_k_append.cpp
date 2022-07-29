#include<iostream>
using namespace std;
class node
{
	public:
	int data;
	node *next;

	node(int data)
	: data(data), next(nullptr) {}
};
void inputNode(node* &head, node* &last, int arr[], int N)
{
	head = new node(arr[0]);
	last = head;

	for(int i=1; i<N; i++)
	{
		node *temp = new node(arr[i]);
		last->next = temp;
		last = temp;
	}
}

ostream& operator<<(ostream &os, node *head)
{
	while(head)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
	return os;
}

int length(node *head)
{
	if(head == nullptr)
	return 0;

	return length(head->next) + 1;
}
void kAppend(node* &head, int k, node* &last)
{
	if(head == nullptr || head->next == nullptr)
	return;

	k = k%length(head);
	if(k == 0)
	return;
	
	node *fast = head;
	node *slow = head;

	int jump = 1;
	while(jump <= k)
	{
		fast = fast->next;
		jump++;
	}
	node *pre = nullptr;
	while(fast)
	{
		fast = fast->next;
		pre = slow;
		slow = slow->next;
	}
	pre->next = nullptr;
	last->next = head;
	last = pre;
	head = slow;
}
int main() {
	int N;
	int arr[1000001];
	cin >> N;
	for(int i=0; i<N; i++)
	cin >> arr[i];

	node *head = nullptr;
	node *last = nullptr;
	inputNode(head, last, arr, N);
	int k;
	cin >> k;
	kAppend(head, k, last);
	cout << head;
	return 0;
}