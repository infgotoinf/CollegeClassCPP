#include <iostream>

struct Elements {
	int value;
	Elements* next;
	Elements* prev;

	Elements(int val) {
		value = val;
		next = nullptr;
		prev = nullptr;
	}
};

struct List {
	Elements* head;
	Elements* tail;

	List() {
		head = nullptr;
		tail = nullptr;
	}

	~List() {
		while (head != nullptr) {
			Elements* v = head;
			head = head->next;
			delete v;
		}
	}
	void push_front(int val) {
		if (head == nullptr) {
			head = new Elements(val);
			tail = head;
		}
		else {
			Elements* newElem = new Elements(val);
			newElem->next = head;
			head = newElem;
		}
	}
	/*void push_back(int val) {
		Elements* newElem = new Elements(val);
		tail->next = newElem;
		tail = newElem;
	}*/
	void insert(int val, int idx) {
		int i = 0;
		for (Elements* cur = head; cur != nullptr; cur = cur->next, i++) {}
		Elements* cur = head;
		for (int i2 = 0; i2 != idx; cur = cur->next, i2++) {}
		cur = new Elements(val);
		for (Elements* cur2 = tail; i < idx; cur2 = cur2->next, i--) {
			cur2->next = cur2;
		}
	}

	void print() {
		for (Elements* cur = head; cur != nullptr; cur = cur->next) {
			std::cout << cur->value << '\n';
		}
	}
};

int main() {
	List a;
	a.push_front(10);
	a.push_front(20);
	a.push_front(30);
	a.insert(15, 1);
	a.print();

	return 0;
}