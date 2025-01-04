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

	void push_back(int val) {
		//head = new Elements(val);
		Elements* newElem = new Elements(val);
		//tail = new Elements(val);
		tail->next = newElem;
		tail = newElem;
		/*for (Elements* cur = head; cur->next != nullptr; cur = cur->next) {
			cur = newElem;
		}
		tail->next = newElem;*/
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
	int pop_front() {
		Elements* oldhead = head;
		head = head->next;
		return oldhead->value;
	}
	int pop_back() {
		Elements* oldtail = tail;
		tail = tail->next;
		return oldtail->value;
	}
	void print() {
		for (Elements* cur = head; cur != nullptr; cur = cur->next) {
			std::cout << cur->value << '\n';
		}
	}
	int at(int idx) {
		Elements* cur = head;
		for (int i = 0; i < idx; cur = cur->next, i++) {}
		//std::cout << cur->value << '\n';
		return cur->value;
	}
	void insert(int val, int idx) {
		int i = 0;
		for (Elements* cur = head; cur != nullptr; cur = cur->next, i++) {
			if (i == idx) {
				Elements* curold = cur;
				cur->value = val;
				for (; curold != nullptr; curold = curold->next) {
					curold->value;
				}
				break;
			}
		}
		Elements* newElem = new Elements(val);
		tail->next = newElem;
		tail = newElem;
		Elements* curcur = head;
		return ;
	}
};

int main() {
	List a;
	a.push_front(10);
	a.push_front(20);
	a.push_front(30);
	a.push_back(777);
	a.print();
	std::cout << '\t' << a.at(0) << '\n';
	a.insert(69, 2);
	a.print();
	std::cout << '\n' << a.pop_front() << "\n\n";
	a.print();
	std::cout << '\n' << a.pop_back() << "\n\n";
	a.print();

	return 0;
}