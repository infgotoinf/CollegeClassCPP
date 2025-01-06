#include <iostream>

struct SetElem {
	int value;
	SetElem* left;
	SetElem* right;
	SetElem(int v) {
		value = v;
		left = nullptr;
		right = nullptr;
	}
};
struct IntSet {
	SetElem* root;
	IntSet() {
		root = nullptr;
	}
	void add(int key) {
		if (root == nullptr)
		{
			root = new SetElem(key);
		}
		else
		{
			SetElem* cur = root;
			while (true)
			{
				if (key < cur->value)
				{
					if (cur->left == nullptr)
					{
						cur->left = new SetElem(key);
						break;
					}
					else
					{
						cur = cur->left;
					}
				}
				else if (key > cur->value) {
					if (cur->right == nullptr)
					{
						cur->right = new SetElem(key);
						break;
					}
					else
					{
						cur = cur->right;
					}
				}
				else {
					break;
				}
			}
		}
	}
	bool contains(int key) {
		SetElem* cur = root;
		while (true) {
			if (key == cur->value)
			{
				return true;
			}
			else if (cur->right == nullptr && cur->left == nullptr)
			{
				return false;
			}
			else
			{
				cur = (key < cur->value ? cur->left : cur->right);
			}
		}
	}
	void print(int cur) {
		std::cout << cur << ' ';
	}
	void print() {
		SetElem* cur = root;
		print(root);
	}
	void print(SetElem* cur)
	{
		if (cur->left != nullptr)
		{
			print(cur->left);
			print(cur->value);

		}
		else {
			print(cur->value);
		}
		if (cur->right != nullptr)
		{
			print(cur->right);
		}
	}
	~IntSet() {
		//while (true) {
		for (int i = 0; i < 1; i++) {
			if (loop(root) != nullptr) {
				//std::cout << loop(root) << ' ';
				//delete loop(root);
			}
		}
			/*else {
				break;
			}*/
		//}
		//root = nullptr;
		print();
	}

	SetElem* loop(SetElem* cur) {
		if (cur->left != nullptr) {
			loop(cur->left);
			cur = nullptr;
		}
		else {
			return cur;
		}
		if (cur->right != nullptr)
		{
			loop(cur->right);
			cur = nullptr;
		}
		else {
			return cur;
		}
	}
};

int main() {
	IntSet set;
	set.add(5);
	set.add(10);
	set.add(2);
	set.add(-3);
	set.add(4);
	set.add(0);

	std::cout << set.contains(0) << '\n';
	std::cout << set.contains(4) << '\n';
	std::cout << set.contains(2) << '\n';
	std::cout << set.contains(10) << '\n';
	std::cout << set.contains(5) << '\n';
	std::cout << set.contains(7) << '\n';
	std::cout << set.contains(13) << "\n\n";

	set.print();
	std::cout << '\n';
	return 0;
}