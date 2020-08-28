using System;
using System.Text;

namespace Chester.DataStructLib
{
    /// <summary>
    /// 链表接口
    /// </summary>
    /// <typeparam name="T">泛型数据</typeparam>
    public interface ILinkedList<T>
    {
        /// <summary>
        /// 插入
        /// </summary>
        /// <param name="index"></param>
        /// <param name="newElem"></param>
        /// <returns></returns>
        bool Insert(int index, T newElem);
        /// <summary>
        /// 追加
        /// </summary>
        /// <param name="t"></param>
        /// <returns></returns>
        bool Append(T t);
        /// <summary>
        /// 删除元素
        /// </summary>
        /// <param name="index"></param>
        /// <param name="t"></param>
        /// <returns></returns>
        bool Delete(int index, out T t);
        /// <summary>
        /// 删除元素
        /// </summary>
        /// <param name="t"></param>
        /// <returns></returns>
        bool Delete(T t);
        /// <summary>
        /// 清空单链表
        /// </summary>
        void Clear();
        /// <summary>
        /// 求链表长度
        /// </summary>
        int Length { get; }
        /// <summary>
        /// 获取元素
        /// </summary>
        /// <param name="index"></param>
        /// <param name="t"></param>
        /// <returns></returns>
        bool TryGetItem(int index, out T t);
        /// <summary>
        /// 求元素索引
        /// </summary>
        /// <param name="t"></param>
        /// <returns></returns>
        int IndexOf(T t);
        /// <summary>
        /// 访问器
        /// </summary>
        /// <param name="index"></param>
        /// <returns></returns>
        T this[int index] { get; set; }
        /// <summary>
        /// 链表判空
        /// </summary>
        /// <returns></returns>
        bool IsEmpty();

    }
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
    public class SingleLinkedList<T> : ILinkedList<T>
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
