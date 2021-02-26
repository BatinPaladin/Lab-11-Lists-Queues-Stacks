#include <iostream>
using namespace std;
struct List {
	double data;
	List* next;
};
List* FillList(int N)
{
	List* first, * p = new List;
	cout << "\n������� 1 �������: ";
	cin >> p->data;
	first = p;
	for (int i = 2; i <= N; i++) {
		List* k = new List;
		p->next = k;
		p = p->next;
		cout << "������� " << i << " �������: ";
		cin >> p->data;
		p->next = nullptr;
	}
	return first;
};
void PrintList(List* first)
{
	List* p = first;
	while (p != nullptr) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
};
void DeleteElement(List* first)
{
	List* p = first;
	int count = 1;
	while (p->next!=nullptr) {
		count++;
		if ((count%2) == 0) {
			List* q = p->next;
			p->next = p->next->next;
			delete q;
		}
		else {
			p = p->next;
		}
	}
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
	List* list = FillList(size);
	cout << "\n������: \n";
	PrintList(list);
	DeleteElement(list);
	cout << "\n������ ����� ��������: \n";
	PrintList(list);
	system("pause");
	return 0;
}