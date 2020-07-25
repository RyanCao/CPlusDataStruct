﻿using System;
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
        /// 访问器
        /// </summary>
        /// <param name="index"></param>
        /// <returns></returns>
        T this[int index] { get; set; }
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
        protected T[] mData;
        protected int mLength;

        public Array(int _capacity)
        {
            mData = new T[_capacity];
            mLength = 0;
        }

        public int Length
        {
            get
            {
                return mLength;
            }
        }

        public T this[int index]
        {
            get {
                if (index < 0 || index >= mLength)
                    throw new Exception("index out !");
                return mData[index];
            }
            set
            {
                if (index < 0 || index >= mLength)
                    throw new Exception("index out !");
                mData[index] = value;
            }
        }

        public bool IsFull()
        {
            if (mLength >= mData.Length)
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

            for (int i = index; i < mLength - 1; i++)
            {
                mData[i] = mData[i + 1];
            }

            mLength--;
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
                if (mData[i].Equals(t))
                {
                    return i;
                }
            }
            return -1;
        }

        public virtual bool Insert(int index, T t)
        {
            if (IsFull())
            {
                bool isSuccuss = MallocMoreSize();
                if (!isSuccuss)
                    return false;
            }

            if (index < 0 || index > mLength)
                return false;

            //移位
            for (int i = mLength; i > index; i--)
            {
                mData[i] = mData[i - 1];
            }
            mData[index] = t;
            mLength++;
            return true;
        }

        /// <summary>
        /// 申请更多的内存空间，成功则返回True,失败返回False
        /// </summary>
        /// <returns></returns>
        protected virtual bool MallocMoreSize()
        {
            return false;
        }

        public virtual bool Append(T t)
        {
            if (IsFull())
            {
                bool isSuccuss = MallocMoreSize();
                if (!isSuccuss)
                    return false;
            }

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

    /// <summary>
    /// 数组长度自动扩充的
    /// </summary>
    /// <typeparam name="T"></typeparam>
    public class VariableArray<T> : Array<T>
    {
        /// <summary>
        /// 自动增加因子
        /// </summary>
        private const int INCREMENT = 64;

        public VariableArray(int _capacity) : base(_capacity)
        {
        }

        protected override bool MallocMoreSize()
        {
            return SetSize(mData.Length + INCREMENT);
        }

        /// <summary>
        /// 扩充数组大小 实现数组自动扩容
        /// </summary>
        /// <param name="size"></param>
        private bool SetSize(int size)
        {
            if (size < mData.Length)
            {
                throw new Exception("扩容后的数组不能小于之前的数组大小");
            }

            if (size == mData.Length)
                return false;

            T[] array = new T[size];
            for (int i = 0, length = mData.Length; i < length; i++)
            {
                array[i] = mData[i];
            }
            mData = array;

            return true;
        }
    }

    /// <summary>
    /// 自动排序的数组
    /// 自动排序的数组 是不能实现插入函数的
    /// </summary>
    /// <typeparam name="T"></typeparam>
    public class SortArray<T> : VariableArray<T>
    {
        /// <summary>
        /// 比较方法
        /// </summary>
        public Comparison<T> Comparer { get; set; }

        public SortArray(int _capacity) : base(_capacity)
        {
        }
        /// <summary>
        /// 插入数据 和 append 操作相同
        /// </summary>
        /// <param name="index"></param>
        /// <param name="t"></param>
        /// <returns></returns>
        public override bool Insert(int index, T t)
        {
            return base.Append(t);
        }

        /// <summary>
        /// 追加数据的时候 判断数据
        /// </summary>
        /// <param name="t"></param>
        /// <returns></returns>
        public override bool Append(T t)
        {
            if (IsFull())
            {
                bool isSuccuss = MallocMoreSize();
                if (!isSuccuss)
                    return false;
            }
            int mPos = GetInsertPos(t);
            return base.Insert(mPos, t);
        }

        /// <summary>
        /// 获取待插入的位置
        /// </summary>
        /// <param name="t"></param>
        /// <returns></returns>
        private int GetInsertPos(T t)
        {
            if (Comparer == null)
                return mLength;

            for (int i = 0; i < mLength; i++)
            {
                if (Comparer(mData[i], t) > 0)
                {
                    return i;
                }
            }
            return mLength;
        }

        /// <summary>
        /// 合并数组
        /// </summary>
        /// <param name="t"></param>
        public void Merge(SortArray<T> array)
        {
            for (int i = 0, length = array.Length; i < length; i++)
            {
                Append(array[i]);
            }
        }
    }
}
