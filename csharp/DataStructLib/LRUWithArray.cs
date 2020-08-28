using System;

/// <summary>
/// 实现LRU缓存淘汰算法思路：
/// 维护一个有序单链表，越靠近链尾的数据是最早访问的。
/// 当有一个新的数据被访问时，
/// 1. 如果数据在缓存中，则将其从原位置删除，然后插入到表头；
/// 2. 如果数据不在缓存中，有两种情况：
///  1) 链表未满，则将数据插入到表头；
///  2) 链表已满，则删除尾结点，将新数据插入到表头。
/// </summary>
namespace Chester.DataStructLib
{
    /// <summary>
    /// 数组实现 LRU 缓存淘汰算法
    /// </summary>
    public class LRUWithArray<T>
    {
        private IArray<T> mData;
        public LRUWithArray(int _capacity = 0)
        {
            mData = new Array<T>(_capacity);
        }

        public void Set(T v)
        {
            int index = mData.IndexOf(v);
            if (index != -1)
            {
                //找到元素
                mData.Delete(index,out _);
                mData.Append(v);
            }
            else
            {
                //添加数据
                if (mData.IsFull())
                {
                    mData.Delete(0,out _);
                }
                mData.Append(v);
            }
        }

    }
}
