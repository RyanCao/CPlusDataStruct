using System;
using System.Text;

namespace Chester.DataStructLib
{
    /// <summary>
    /// 单链表Node节点
    /// </summary>
    /// <typeparam name="T">泛型数据</typeparam>
    internal class SingleListNode<T>
    {
        /// <summary>
        /// 初始化
        /// </summary>
        /// <param name="value">数据</param>
        public SingleListNode(T value)
        {
            Value = value;
        }
        /// <summary>
        /// 数据域
        /// </summary>
        public T Value { get; internal set; }
        /// <summary>
        /// 指针域 下一个元素 
        /// </summary>
        public SingleListNode<T> Next { get; set; }
    }

    /// <summary>
    /// 单链表实现
    /// </summary>
    /// <typeparam name="T">泛型数据</typeparam>
    public class SingleLinkedList<T> : IArray<T>
    {
        /// <summary>
        /// 头节点
        /// </summary>
        private SingleListNode<T> HeadNode;

        public SingleLinkedList()
        {
            HeadNode = new SingleListNode<T>(default(T));
            HeadNode.Next = null;
        }

        public T this[int index]
        {
            get
            {
                SingleListNode<T> CurrNode = HeadNode;
                int i = 0;
                while (CurrNode != null && i < index)
                {
                    CurrNode = CurrNode.Next;
                    i++;
                }

                if (i != index || CurrNode == null)
                {
                    throw new Exception("Index Error");
                }

                if (CurrNode.Next == null)
                    throw new Exception("Index Error");

                return CurrNode.Next.Value;
            }
            set
            {
                SingleListNode<T> CurrNode = HeadNode;
                int i = 0;
                while (CurrNode != null && i < index)
                {
                    CurrNode = CurrNode.Next;
                    i++;
                }

                if (i != index || CurrNode == null)
                {
                    throw new Exception("Index Error");
                }

                if (CurrNode.Next == null)
                    throw new Exception("Index Error");

                CurrNode.Next.Value = value;
            }
        }

        public int Length
        {
            get
            {
                SingleListNode<T> CurrNode = HeadNode;
                int count = 0;
                while (CurrNode.Next != null)
                {
                    CurrNode = CurrNode.Next;
                    count++;
                }
                return count;
            }
        }

        public bool Append(T t)
        {
            SingleListNode<T> CurrNode = HeadNode;
            while (CurrNode.Next != null)
            {
                CurrNode = CurrNode.Next;
            }
            CurrNode.Next = new SingleListNode<T>(t) { Next = null };
            return true;
        }

        public void Clear()
        {
            HeadNode.Next = null;
        }

        public bool Delete(int index, out T t)
        {
            SingleListNode<T> CurrNode = HeadNode;
            int i = 0;

            t = default(T);

            while (CurrNode != null && i < index)
            {
                CurrNode = CurrNode.Next;
                i++;
            }

            if (i != index || CurrNode == null)
            {
                Console.WriteLine("Pos Error!");
                return false;
            }

            if (CurrNode.Next == null)
                return false;

            t = CurrNode.Next.Value;
            CurrNode.Next = CurrNode.Next.Next;
            return true;
        }

        public bool Delete(T t)
        {
            int index = IndexOf(t);
            return Delete(index, out _);
        }

        public int IndexOf(T t)
        {
            SingleListNode<T> CurrNode = HeadNode.Next;
            int i = 0;
            while (CurrNode != null)
            {
                if (CurrNode.Value.Equals(t))
                {
                    break;
                }
                CurrNode = CurrNode.Next;
                i++;
            }
            if (CurrNode == null)
                return -1;
            return i;
        }

        public bool Insert(int index, T newElem)
        {
            SingleListNode<T> CurrNode = HeadNode;
            int i = 0;
            while (CurrNode != null && i < index)
            {
                CurrNode = CurrNode.Next;
                i++;
            }

            Console.WriteLine(string.Format("Insert pos({0}) Value:{1} ", index, newElem));

            if (i != index || CurrNode == null)
            {
                Console.WriteLine("Pos Error!");
                return false;
            }

            CurrNode.Next = new SingleListNode<T>(newElem) { Next = CurrNode.Next };
            Console.WriteLine("Succeed!");
            return true;
        }
        /// <summary>
        /// 永远不会满
        /// </summary>
        /// <returns>永远false</returns>
        public bool IsFull()
        {
            return false;
        }
        public bool IsEmpty()
        {
            return HeadNode.Next == null;
        }

        public bool TryGetItem(int index, out T t)
        {
            t = default(T);

            SingleListNode<T> CurrNode = HeadNode;
            int i = 0;
            while (CurrNode != null && i < index)
            {
                CurrNode = CurrNode.Next;
                i++;
            }

            if (i != index || CurrNode == null)
            {
                return false;
            }

            if (CurrNode.Next == null)
                return false;

            t = CurrNode.Next.Value;
            return true;
        }

        /// <summary>
        /// 格式化
        /// </summary>
        /// <returns>格式化字符</returns>
        public override string ToString()
        {
            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.Append("[");

            SingleListNode<T> CurrNode = HeadNode.Next;
            while (CurrNode != null)
            {
                stringBuilder.Append(CurrNode.Value);
                if (CurrNode.Next != null)
                {
                    stringBuilder.Append(",");
                }

                CurrNode = CurrNode.Next;
            }

            stringBuilder.Append("]");
            return stringBuilder.ToString();
        }

    }
}
