#include <iostream>
#include <queue>
using namespace std;
queue<char> Queue;
void FillQueue(int N) {
	char el;
	for (int i = 1; i <= N; i++) {
		cout << "������� " << i << " �������: ";
		cin >> el;
		Queue.push(el);
	}
}
void PrintQueue(queue<char> Queue) {
	int N = Queue.size();
	for (int i = 1; i <= N; i++) {
		cout << Queue.front() << " ";
		Queue.pop();
	}
	cout << endl;
}
void AddElement(char *& arr ,int size) {
	char key;
	int N = -1;
	while ((N < 1) || (N > size)) {
		if ((N < 1) || (N > size)) {
			cout << "\n������� ����� ��������: ";
		}
		cin >> N;
	}
	for (int i = 1; i <= size; i++) {
		arr[i] = Queue.front();
		Queue.pop();
	}
	for (int i = 1; i < N; i++) {
		Queue.push(arr[i]);
	}
	cout << "\n������� �������: ";
	cin >> key;
	Queue.push(key);
	for (int i = N; i <= size; i++) {
		Queue.push(arr[i]);
	}
}
int main() 
{
	system("chcp 1251");
	int size = -1;
	while (size < 0) {
		if (size < 0) {
			cout << "������� ������ �������: ";
			cin >> size;
		}
	}
	cout << endl;
	if (size == 0) {
		cout << "������� �����!\n";
	}
	else {
		char* array = new char[size];
		FillQueue(size);
		cout << "\n�������:\n";
		PrintQueue(Queue);
		AddElement(array, size);
		cout << "\n������� ����� ����������:\n";
		PrintQueue(Queue);
		delete [] array;
	}
	system("pause");
	return 0;
}