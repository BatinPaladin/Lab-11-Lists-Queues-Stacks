#include<iostream>
using namespace std;
struct Stack {
	double data;
	Stack* prev;
};
void* FillStack(int N, Stack*& top)
{
	Stack* p = new Stack;
	double el=-1;
	top = nullptr;
	cout << "\nВведите 1 элемент: ";
	do {
		cin >> el;
		if (el==0) {
			cout << "Введите 1 элемент: ";
		}
	} while (el == 0);
	p->data = el;
	p->prev = nullptr;
	top = p;
	for (int i = 2; i <= N; i++) {
		Stack* k = new Stack;
		cout << "Введите " << i << " элемент: ";
		do {
			cin >> el;
			if (el == 0)
			{
				cout << "Введите " << i << " элемент: ";
			}
		} while (el == 0);
		k->data = el;
		k->prev = top;
		top = k;
	}
	return top;
};
void PrintStack(Stack* top)
{
	Stack* p = top;
	while (p != nullptr) {
		if (p->data != 0) {
			cout << p->data << " ";
			p = p->prev;
		}
		else {
			p = p->prev;
		}
	}
	cout << endl;
};
void ZeroElement(Stack* top,int N) {
	Stack* p = top;
	if (N % 2 != 0) {
		while (p->prev != nullptr) {
			p = p->prev;
			p->data = 0;
			if (p->prev != nullptr) {
				p = p->prev;
			}
		}
	}
	else {
		while (p->prev != nullptr) {
			p->data = 0;
			p = p->prev;
			if (p->prev != nullptr) {
				p = p->prev;
			}
		}
	}
};
void DeleteElement(Stack* top, int N)
{
	Stack* p = top;
	double key = 0;
	while (p->prev != nullptr) {
		if (p->prev->data == key) {
			Stack* q = p->prev;
			p->prev = p->prev->prev;
			delete q;
		}
		else {
			p = p->prev;
		}
	}
};
int main()
{
	system("chcp 1251");
	int size = -1;
	Stack* stack = new Stack;
	cout << "Введите размер стека: ";
	while (size < 0) {
		cin >> size;
		if (size < 0) {
			cout << "Введите размер стека: ";
		}
	}
	if (size == 0) {
		cout << "\nСтек пуст!\n";
	}
	else {
		FillStack(size,stack);
		cout << "\nСтек: \n";
		PrintStack(stack);
		ZeroElement(stack,size);
		DeleteElement(stack,size);
		cout << "\nСтек после удаления: \n";
		PrintStack(stack);
	}
	system("pause");
	return 0;
}
