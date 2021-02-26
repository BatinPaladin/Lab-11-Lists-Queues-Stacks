#include <iostream>
using namespace std;
struct List {
	char data;
	List* next;
	List* prev;
};
List* FillList(int N)
{
	List* first, * p = new List;
	cout << "\n������� 1 �������: ";
	cin >> p->data;
	first = p;
	p->next = nullptr;
	for (int i = 2; i <= N; i++) {
		List* k = new List;
		List* l = p;
		p->next = k;
		p = p->next;
		cout << "������� " << i << " �������: ";
		cin >> p->data;
		p->next = nullptr;
		p->prev = l;
	}
	return first;
};
void PrintList(List*& first)
{
	List* p = first;
	while (p != nullptr) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
};
void AddElement(List*& first,  int size) {
	int pos;
	cout << "\n������� ����� ��������: ";
	do {
		cin >> pos;
		if ((pos > size) || (pos < 1)) {
			cout << "������� ����� ��������: ";
		}
	} while (pos > size || pos < 1); cout << "������� �������: ";
	char el;
	cin >> el;
	List* p = new List; 
	p->data = el; 
	List* h = first;
	for (int i = pos; i > 1; i--) {
		h = h->next;
	}
	h->prev->next = p;
	p->prev = h->prev;
	p->next = h;
	h->prev = p;
};
int main()
{
	system("chcp 1251");
	int size = -1;
	cout << "������� ������ ������: ";
	while (size < 0) {
		cin >> size;
		if (size < 0) {
			cout << "������� ������ ������: ";
		}
	}
	if (size == 0) {
		cout << "������ ����!\n";
	}
	else {
		List* list = FillList(size);
		cout << "\n������: \n";
		PrintList(list);
		AddElement(list,size);
		cout << "\n������ ����� ����������: \n";
		PrintList(list);
	}
	system("pause");
	return 0;
}