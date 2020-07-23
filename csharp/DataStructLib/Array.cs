using System;
using System.Text;

namespace Chester.DataStructLib
{
    /// <summary>
    /// 数组实现基类
    /// </summary>
    /// <typeparam name="T"></typeparam>
    public interface IArray<T>
    {
        /// <summary>
        /// 插入元素
        /// </summary>
        /// <param name="index"></param>
        /// <param name="t"></param>
        bool Insert(int index, T t);
        /// <summary>
        /// 追加元素
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
        /// 清空数组
        /// </summary>
        void Clear();
        /// <summary>
        /// 获取数组长度
        /// </summary>
        int Length { get; }
        /// <summary>
        /// 尝试获取数组元素
        /// </summary>
        /// <param name="index">索引位置从0开始</param>
        /// <param name="t"></param>
        /// <returns></returns>
        bool TryGetItem(int index, out T t);
        /// <summary>
        /// 获取索引位置 
        /// 第一个元素的索引值为0
        /// </summary>
        /// <param name="t"></param>
        /// <returns></returns>
        int IndexOf(T t);
        /// <summary>
        /// 是否为满
        /// </summary>
        /// <returns></returns>
        bool IsFull();
        /// <summary>
        /// 是否为空
        /// </summary>
        /// <returns></returns>
        bool IsEmpty();
    }

    public class Array<T> : IArray<T>
    {
        private T[] mData;
        private readonly int mCapacity;
        private int mLength;

        public Array(int capacity)
        {
            mData = new T[capacity];
            mCapacity = capacity;
            mLength = 0;
        }

        public int Length
        {
            get
            {
                return mLength;
            }
        }
        public bool IsFull()
        {
            if (mLength >= mCapacity)
                return true;
            return false;
        }
        public bool IsEmpty()
        {
            if (mLength <= 0)
                return true;
            return false;

        }

        public void Clear()
        {
            mLength = 0;
        }

        public bool Delete(int index, out T t)
        {
            t = default(T);

            if (IsEmpty())
                return false;

            if (index < 0 || index >= mLength)
                return false;
            
            t = mData[index];

            for (int i = index; i < mLength-1; i++)
            {
                mData[i] = mData[i + 1];    
            }

            mLength --;
            return true;
        }

        public bool Delete(T t)
        {
            int index = IndexOf(t);
            return Delete(index, out _);
        }

        public int IndexOf(T t)
        {
            for (int i = 0; i < mLength; i++)
            {
                if(mData[i].Equals(t))
                {
                    return i;
                }
            }
            return -1;
        }

        public bool Insert(int index, T t)
        {
            if (IsFull())
                return false;
            if (index < 0 || index > mLength)
                return false;
            
            //移位
            for (int i = mLength; i > index; i--)
            {
                mData[i] = mData[i-1]; 
            }
            mData[index] = t;
            mLength++;
            return true;
        }

        public bool Append(T t)
        {
            if (IsFull())
                return false;
            mData[mLength] = t;
            mLength++;
            return true;
        }

        public bool TryGetItem(int index, out T t)
        {
            t = default(T);
            if (index < 0 || index >= mLength)
                return false;
            t = mData[index];
            return true;
        }

        public override string ToString()
        {
            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.Append("[");
            for (int i = 0; i < mLength; i++)
            {
                stringBuilder.Append(mData[i]);
                if (i != mLength - 1)
                {
                    stringBuilder.Append(",");
                }
            }
            stringBuilder.Append("]");
            return stringBuilder.ToString();
        }
    }
}
