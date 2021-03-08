#include <iostream>
#include <stack>
using namespace std;
stack <double> Stack;
stack <double> StackP;
void PrintStack(stack <double> Stack) {
	int N = Stack.size();
	for (int i = 1; i <= N; i++) {
		cout << Stack.top() << " ";
		Stack.pop();
	}
	cout << endl;
};
int main()
{
	system("chcp 1251");
	int size = -1;
	double el;
	while (size < 0) {
		if (size < 0) {
			cout << "Введите размер стека: ";
		}
		cin >> size;
	}
	cout << endl;
	if (size == 0) {
		cout << "Стек пуст!\n";
	}
	else {
		for (int i = 0; i < size; i++) {
			cout << "Введите " << i + 1 << " элемент: ";
			cin >> el;
			Stack.push(el);
		}
		cout << "\nСтек:\n";
		PrintStack(Stack);
		int N = Stack.size();
		for (int i = 1; i <= N; i++) {
			if ((i+1)% 2 != 0) {
				StackP.push(Stack.top());
			}
			Stack.pop();
		}
		N = StackP.size();
		for (int i = 1; i <= N; i++) {
			Stack.push(StackP.top());
			StackP.pop();
		}
		cout << "\nСтек:\n";
		PrintStack(Stack);
	}
	system("pause");
	return 0;
}
