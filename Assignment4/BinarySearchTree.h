#pragma once

#include <memory>
#include <vector>

namespace assignment4
{
	template<typename T>
	class TreeNode;

	template<typename T>
	class BinarySearchTree final
	{
	public:
		void Insert(std::unique_ptr<T> data);
		bool Search(const T& data);
		bool Delete(const T& data);
		const std::weak_ptr<TreeNode<T>> GetRootNode() const;

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);
	private:
		std::shared_ptr<TreeNode<T>> mRoot;
		static void inOrder(std::shared_ptr<TreeNode<T>> node, std::vector<T>& result);

		std::shared_ptr<TreeNode<T>> getMinNode(std::shared_ptr<TreeNode<T>> node);

	};

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		if (mRoot == nullptr)
		{
			mRoot = std::make_shared<TreeNode<T>>(std::move(data));
		}
		else
		{
			std::shared_ptr<TreeNode<T>> curNode = mRoot;

			while (true)
			{
				if (*(curNode->Data) >= *data)
				{
					if (curNode->Left == nullptr)
					{
						curNode->Left = std::make_shared<TreeNode<T>>(curNode, std::move(data));
						break;
					}
					else
					{
						curNode = curNode->Left;
					}
				}
				else
				{
					if (curNode->Right == nullptr)
					{
						curNode->Right = std::make_shared<TreeNode<T>>(curNode, std::move(data));
						break;
					}
					else
					{
						curNode = curNode->Right;
					}
				}
			}
		}
	}

	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		return mRoot;
	}

	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		if (mRoot == nullptr)
		{
			return false;
		} 
		else
		{
			std::shared_ptr<TreeNode<T>> curNode = mRoot;

			while (true)
			{
				if (*(curNode->Data) == data)
				{
					return true;
				}
				else
				{
					if (*(curNode->Data) >= data)
					{
						if (curNode->Left == nullptr)
						{
							return false;
						} 
						else
						{
							curNode = curNode->Left;
						}
					} 
					else
					{
						if (curNode->Right == nullptr)
						{
							return false;
						} else
						{
							curNode = curNode->Right;
						}
					}
				}
			}
		}
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		if (mRoot == nullptr)
		{
			return false;
		} 
		else
		{
			std::shared_ptr<TreeNode<T>> curNode = mRoot;
			
			// 지울 노드 찾기
			while (true)
			{
				if (*(curNode->Data) == data)
				{
					break;
				} 
				else
				{
					if (*(curNode->Data) >= data)
					{
						if (curNode->Left == nullptr)
						{
							return false;
						} 
						else
						{
							curNode = curNode->Left;
						}
					} else
					{
						if (curNode->Right == nullptr)
						{
							return false;
						} 
						else
						{
							curNode = curNode->Right;
						}
					}
				}
			}

			// 지우기
			if (curNode->Left == nullptr && curNode->Right == nullptr)
			{
				auto parent = (curNode->Parent).lock();

				if (parent->Left == curNode)
				{
					parent->Left = nullptr;
				}
				else if (parent->Right == curNode)
				{
					parent->Right = nullptr;
				}
				return true;
			}
			else if (curNode->Left == nullptr || curNode->Right == nullptr)
			{
				auto parent = (curNode->Parent).lock();

				std::shared_ptr<TreeNode<T>> temp;

				if (curNode->Left != nullptr)
				{
					temp = curNode->Left;
				}
				else
				{
					temp = curNode->Right;
				}

				if (parent->Left == curNode)
				{
					parent->Left = temp;
					temp->Parent = parent;
				}
				else
				{
					parent->Right = temp;
					temp->Parent = parent;
				}
			}
			else if (curNode->Left != nullptr && curNode->Right != nullptr)
			{
				auto parent = (curNode->Parent).lock();
			}
		}
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> v;
		inOrder(startNode, v);
		return v;
	}
	template<typename T>
	inline void BinarySearchTree<T>::inOrder(std::shared_ptr<TreeNode<T>> node, std::vector<T>& result)
	{
		if (node != nullptr)
		{
			inOrder(node->Left, result);
			result.push_back(*(node->Data));
			inOrder(node->Right, result);
		}
	}
	template<typename T>
	inline std::shared_ptr<TreeNode<T>> BinarySearchTree<T>::getMinNode(std::shared_ptr<TreeNode<T>> node)
	{
		return std::shared_ptr<TreeNode<T>>();
	}
}