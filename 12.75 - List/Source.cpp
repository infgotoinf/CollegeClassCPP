#include <iostream>

struct Elements {
	int value;
	Elements* next;

	Elements(int val) {
		value = val;
		next = nullptr;
	}
};

struct List {
	Elements* head;

	List() {
		head = nullptr;
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
		}
		else {
			Elements* newElem = new Elements(val);
			newElem->next = head;
			head = newElem;
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
	a.print();

	return 0;
}