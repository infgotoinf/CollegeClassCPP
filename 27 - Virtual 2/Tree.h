#pragma once

#ifndef TREE_H
#define TREE_H

#include <iterator>
#include <stack>

template <typename T>
class Tree
{
protected:
	class TreeElement
	{
	public:
		T value;
		TreeElement* right;
		TreeElement* left;

		TreeElement(T const& a) : value(a), right(nullptr), left(nullptr) {}
		~TreeElement() = default;
	};

	TreeElement* root;

public:
	using iterator = DFSIterator;
	Tree() : root(nullptr) {}
	~Tree()
	{
		// Удаление
	}

	void add(T value, TreeElement* parrent = root)
	{
		if (value < parrent)
		{
			if (parrent->value() == nullptr)
			{
				parrent->value = value;
			}
			if else (parrent->left() == nullptr)
			{
				TreeElement child(value);
				parrent->left() = child;
			}
			else
			{
				add(value, child)
			}
		}
		else
		{
			if (root->right() == nullptr)
			{
				TreeElement child(value);
				root->right() = child;
			}
			else
			{
				add(value, child)
			}
		}
	}

	class DFSIterator : std::iterator<std::forward_iterator_tag, T>
	{
		std::stack<TreeElement*> st;

	public:
		DFSIterator(TreeElement* first) : st()
		{
			st.push(first);
		}

		DFSIterator(DFSIterator const& other) : st(other.st) {}

		~DFSIterator() = default;

		bool operator==(DFSIterator const& other) const { return st.top() == other.st.top(); }
		bool operator!=(DFSIterator const& other) const { return (*this == other); }

		DFSIterator& operator++()
		{
			return *this;
		}
		T const& operator*() const
		{
			return st.top()->value;
		}
		T const* operator->() const
		{
			return &st.top()->value;
		}
	};

	begin()
	{
		return root;
	}

	end();
	{
		return nullptr;
	}
};
#endif