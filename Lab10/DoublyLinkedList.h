#pragma once

#include <memory>

namespace lab10
{
	template<typename T>
	class Node;

	template<typename T>
	class DoublyLinkedList
	{
	private:
		std::shared_ptr<Node<T>> mRoot = nullptr;

	public:
		DoublyLinkedList();
		void Insert(std::unique_ptr<T> data);
		void Insert(std::unique_ptr<T> data, unsigned int index);
		bool Delete(const T& data);
		bool Search(const T& data) const;

		std::shared_ptr<Node<T>> operator[](unsigned int index) const;
		unsigned int GetLength() const;
	};

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList()
	{
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		if (mRoot == nullptr)
		{
			mRoot = std::make_shared<Node<T>>(std::move(data));
		}
		else
		{
			std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(data));

			std::shared_ptr<Node<T>> node = mRoot;
			while (node->Next != nullptr)
			{
				node = node->Next;
			}

			node->Next = newNode;
			newNode->Previous = node;

		}
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(data));

		std::shared_ptr<Node<T>> node = mRoot;
		for (unsigned int i = 0; i < index; i++)
		{
			node = node->Next;

			if (node->Next == nullptr)
			{
				break;
			}
		}

		if (node->Next == nullptr)
		{
			node->Next = newNode;
			newNode->Previous = node;
		}
		else
		{
			std::shared_ptr<Node<T>> preNode = (node->Previous).lock();
			if (preNode == nullptr)
			{
				newNode->Next = node;
				node->Previous = newNode;
				mRoot = newNode;
			}
			else
			{
				newNode->Next = node;
				newNode->Previous = node->Previous;

				node->Previous = newNode;
				preNode->Next = newNode;
			}
		}


	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		bool mIsDeleted = false;
		std::shared_ptr<Node<T>> node = mRoot;
		if (node == nullptr)
		{
			return mIsDeleted;
		}
		
		while (true)
		{
			if (*(node->Data) == data)
			{
				if (node == mRoot)
				{
					mRoot = mRoot->Next;
				}
				else
				{
					std::shared_ptr<Node<T>> preNode = (node->Previous).lock();
					std::shared_ptr<Node<T>> nextNode = node->Next;
					if (nextNode == nullptr)
					{
						preNode->Next = nullptr;
					}
					else
					{
						preNode->Next = nextNode;
						nextNode->Previous = preNode;
					}
				}
				mIsDeleted = true;
				break;
			}

			node = node->Next;

			if (node == nullptr)
			{
				break;
			}
		}

		return mIsDeleted;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		std::shared_ptr<Node<T>> node = mRoot;
		if (node == nullptr)
		{
			return false;
		}

		while (true)
		{
			if (*(node->Data) == data)
			{
				return true;
			}

			node = node->Next;

			if (node == nullptr)
			{
				break;
			}
		}

		return false;
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		std::shared_ptr<Node<T>> node = mRoot;

		for (unsigned int i = 0; i < index; i++)
		{
			if (node == nullptr)
			{
				return nullptr;
			}

			node = node->Next;
		}

		return node;
		/*auto x = std::make_unique<T>();
		std::shared_ptr<Node<T>> temp = std::make_shared<Node<T>>(std::move(x));
		return temp;*/
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		std::shared_ptr<Node<T>> node = mRoot;

		unsigned int length = 0;

		while (true)
		{
			if (node == nullptr)
			{
				break;
			}

			length++;
			node = node->Next;
		}

		return length;
	}
}