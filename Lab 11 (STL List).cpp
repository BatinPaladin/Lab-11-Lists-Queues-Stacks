#include <iostream>
#include <list>
#include <iterator>
using namespace std;
list <char> List;
void FillList(int N) {
	char el;
	for (int i = 0; i < N; i++) {
		cout << "������� " << i + 1 << " �������: ";
		cin >> el;
		List.push_back(el);
	}
};
void AddElement(int size){
	char key;
	int N = -1;
	while ((N < 1) || (N > size)) {
		if ((N < 1) || (N > size)) {
			cout << "\n������� ����� ��������: ";
		}
		cin >> N;
	}
	list<char> :: iterator p;
	p = List.begin();
	advance(p, N-1);
	list <char> AddList;
	cout << "������� �������: ";
	cin >> key;
	AddList.push_back(key);
	List.insert(p, AddList.begin(), AddList.end());
}
int main() 
{
	system("chcp 1251");
	int size = -1;
	while (size < 0) {
		if (size < 0) {
			cout << "������� ������ ������: ";
		}
		cin >> size;
	}
	cout << endl;
	if (size == 0) {
		cout << "������ ����!\n";
	}
	else {
		FillList(size);
		cout << endl << "������:\n";
		copy(List.begin(), List.end(), ostream_iterator<char>(cout, " "));
		cout << endl;
		AddElement(size);
		cout << endl << "������:\n";
		copy(List.begin(), List.end(), ostream_iterator<char>(cout, " "));
		cout << endl;
	}
	system("pause");
	return 0;
}