#include <iostream>

struct MapElem {
	std::string key;
	int value;
	MapElem* left;
	MapElem* right;
	MapElem(std::string k, int v) {
		key = k;
		value = v;
		left = nullptr;
		right = nullptr;
	}
};
struct Map {
	MapElem* root;
	Map() {
		root = nullptr;
	}
	void add(std::string k, int v) {
		if (root == nullptr)
		{
			root = new MapElem(k, v);
		}
		else
		{
			MapElem* cur = root;
			while (true)
			{
				if (k < cur->key)
				{
					if (cur->left == nullptr)
					{
						cur->left = new MapElem(k, v);
						break;
					}
					else
					{
						cur = cur->left;
					}
				}
				else if (k > cur->key) {
					if (cur->right == nullptr)
					{
						cur->right = new MapElem(k, v);
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
	bool contains(std::string v) {
		MapElem* cur = root;
		while (true) {
			if (v == cur->key)
			{
				return true;
			}
			else if (cur->right == nullptr && cur->left == nullptr)
			{
				return false;
			}
			else
			{
				cur = (v < cur->key ? cur->left : cur->right);
			}
		}
	}
	int at(std::string k) {
		MapElem* cur = root;
		while (true) {
			if (k == cur->key)
			{
				return cur->value;
			}
			else if (cur->right == nullptr && cur->left == nullptr)
			{
				return 404;
			}
			else
			{
				cur = (k < cur->key ? cur->left : cur->right);
			}
		}
	}
	void content(std::string k) {
		std::cout << k << '|' << contains(k) << '|' << at(k) << '\n';
	}

	void print(std::string k, int v) {
		std::cout << k << '|' << v << ' ';
	}
	void print() {
		MapElem* cur = root;
		print(root);
	}
	void print(MapElem* cur)
	{
		if (cur->left != nullptr)
		{
			print(cur->left);
			print(cur->key, cur->value);

		}
		else {
			print(cur->key, cur->value);
		}
		if (cur->right != nullptr)
		{
			print(cur->right);
		}
	}
	//~Map() {
	//	//while (true) {
	//	for (int i = 0; i < 1; i++) {
	//		if (loop(root) != nullptr) {
	//			//std::cout << loop(root) << ' ';
	//			//delete loop(root);
	//		}
	//	}
	//	/*else {
	//		break;
	//	}*/
	//	//}
	//	//root = nullptr;
	//	print();
	//}

	//MapElem* loop(MapElem* cur) {
	//	if (cur->left != nullptr) {
	//		loop(cur->left);
	//		cur = nullptr;
	//	}
	//	else {
	//		return cur;
	//	}
	//	if (cur->right != nullptr)
	//	{
	//		loop(cur->right);
	//		cur = nullptr;
	//	}
	//	else {
	//		return cur;
	//	}
	//}
};

int main() {
	Map set;
	set.add("UwU", 228);
	set.add("69", 777);
	set.add("i'm cool", 1984);
	set.add("eeeeeeeee", 0);
	set.add(":3", 1337);
	set.add(":O", 5553535);

	set.content("UwU");
	set.content("NO");
	set.content("i'm cool");
	set.content("69");
	set.content(":3");
	set.content(":O");
	set.content("eeeeeeeee");
	std::cout << '\n';

	set.print();
	std::cout << '\n';
	return 0;
}