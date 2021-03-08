#include <iostream>
using namespace std;
struct Queue {
	char data;
	Queue* next;
};
Queue* FillQueue(int N, Queue *&first) {
	Queue* p = new Queue;
	char el;
	cout << "Введите 1 элемент: ";
	cin >> el;
	p->data = el;
	first = p;
	for (int i = 2; i <= N; i++) {
		Queue* q = new Queue;
		cout << "Введите " << i << " элемент: ";
		cin >> el;
		q->data = el;
		p->next = q;
		p = p->next;		
	}
	p->next = nullptr;
	return first;
};
void PrintQueue(Queue* first) {
	Queue* p = first;
	while (p != nullptr) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl <<endl;
};
void AddElement(int size, Queue *&first) {
	int N = -1,count=0;
	char key;
	Queue* p = first;
	while ((N > size) || (N < 1)) {
		if ((N > size) || (N < 1)) {
			cout << "Введите номер элемента: ";
		}
		cin >> N;
	}
	cout << "Введите элемента который хотите добавить: ";
	cin >> key;
	for (int i = 2; i < N; i++) {
		p = p->next;
	}
	if (N != 1) {
		Queue* q = new Queue;
		q->data = key;
		q->next = p->next;
		p->next = q;
		q = q->next;
	}
	else {
		Queue* q = new Queue;
		q->data = key;
		q->next = first;
		first = q;
	}
};
int main() 
{
	system("chcp 1251");
	int size = -1;
	Queue* first;
	while (size < 0) {
		if (size < 0) {
			cout << "Введите размер очереди: ";
		}
		cin >> size;
	}
	cout << endl;
	if (size == 0) {
		cout << "Очередь пуста!\n";
	}
	else {
		FillQueue(size, first);
		cout << "\nОчередь:\n";
		PrintQueue(first);
		AddElement(size, first);
		cout << "\nОчередь:\n";
		PrintQueue(first);		
	}
	system("pause");
	return 0;
}
