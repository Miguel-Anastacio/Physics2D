#pragma once
#include "../Vector2.h"
#include "SimpleCollisionDetection.h"
#include <list>
#include <functional>
namespace Physics2D
{

	template<typename T>
	struct QuadTreeEntry
	{
		Vector2 Pos;
		Vector2 Size;
		T Object;

		QuadTreeEntry(T obj, Vector2 pos, Vector2 size)
		{
			Object = obj;
			Pos = pos;
			Size = size;
		}
	};

	template<typename T>
	class QuadTreeNode
	{
	public:
		QuadTreeNode() {};
		QuadTreeNode(Vector2 pos, Vector2 size) 
		{
			//m_Children = nullptr;
			m_Position = pos;
			m_Size = size;
		}
		~QuadTreeNode() { m_Children.clear(); };

	protected:
		std::list<QuadTreeEntry<T>> m_Contents;
		Vector2 m_Position;
		Vector2 m_Size;

		std::vector<QuadTreeNode<T>> m_Children;

	public:
		typedef std::function<void(std::list<QuadTreeEntry<T>>&)> QuadTreeFunc;

		void OperateOnContents(QuadTreeFunc& func)
		{
			if (m_Children)
			{
				for (int i = 0; i < 4; i++)
				{
					m_Children[i].OperateOnContents(func);
				}
			}
			else
			{
				if (!m_Contents.empty())
					func(m_Contents);
			}
		}

		void Split()
		{
			Vector2 halfSize = m_Size * 0.5;
		/*	m_Children = new QuadTreeNode<T>[4];
			m_Children[0] = QuadTreeNode<T>(m_Position + Vector2(-halfSize.X, -halfSize.Y), halfSize);
			m_Children[1] = QuadTreeNode<T>(m_Position + Vector2(halfSize.X, -halfSize.Y), halfSize);
			m_Children[2] = QuadTreeNode<T>(m_Position + Vector2(-halfSize.X, halfSize.Y), halfSize);
			m_Children[3] = QuadTreeNode<T>(m_Position + Vector2(halfSize.X, halfSize.Y), halfSize);*/

			m_Children.push_back(QuadTreeNode<T>(m_Position + Vector2(-halfSize.X, -halfSize.Y), halfSize));
			m_Children.push_back(QuadTreeNode<T>(m_Position + Vector2(halfSize.X, -halfSize.Y), halfSize));
			m_Children.push_back(QuadTreeNode<T>(m_Position + Vector2(-halfSize.X, halfSize.Y), halfSize));
			m_Children.push_back(QuadTreeNode<T>(m_Position + Vector2(halfSize.X, halfSize.Y), halfSize));
		}

		void Insert(const T& object, const Vector2& objectPos, const Vector2& objectSize, int depthLeft, int maxSize)
		{
			// check if AABB of object overlaps with the root node
			if (!TestAABB(objectPos, objectSize, m_Position, m_Size))
				return;
			// if not a leaf node descend the tree
			if (!m_Children.empty())
			{
				for (int i = 0; i < 4; i++)
				{
					m_Children[i].Insert(object, objectPos, objectSize, depthLeft - 1, maxSize);
				}
			}
			else
			{
				// it is a leaf node so add 
				m_Contents.push_back(QuadTreeEntry<T>(object, objectPos, objectSize));
				// if the node has reached the max number of objects and the tree can be split further
				// split the node
				// reinsert contents in children and clear contents
				if ((int)m_Contents.size() > maxSize && depthLeft > 0)
				{
					if (m_Children.empty())
					{
						Split();
						for (const auto& entry : m_Contents)
						{
							for (int j = 0; j < 4; j++)
							{
								m_Children[j].Insert(entry.Object, entry.Pos, entry.Size, depthLeft - 1, maxSize);
							}
						}
						// no longer a leaf node
						// so clear contents
						m_Contents.clear();
					}
				}
			}
		}


	};
	template<typename T>
	class QuadTree
	{
	protected:
		QuadTreeNode<T> m_Root;
		int m_MaxDepth;
		int m_MaxSize;
	public:
		QuadTree(const Vector2& size, int maxDepth = 6, int maxSize = 5)
		{
			m_Root = QuadTreeNode<T>(Vector2(512, 512), size);
			m_MaxDepth = maxDepth;
			m_MaxSize = maxSize;
		}
		~QuadTree() {};
		void Insert(const T& object, const Vector2& objectPos, const Vector2& objectSize)
		{
			m_Root.Insert(object, objectPos, objectSize, m_MaxDepth, m_MaxSize);
		}
		void OperateOnCOntents(typename QuadTreeNode<T>::QuadTreeFunc func)
		{
			m_Root.OperateOnContents(func);
		}

	};

}
