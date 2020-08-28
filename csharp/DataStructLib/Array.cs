using System;
using System.Text;

namespace Chester.DataStructLib
{
    /// <summary>
    /// 数组接口
    /// </summary>
    /// <typeparam name="T">泛型类表示数据类型</typeparam>
    public interface IArray<T>
    {
        /// <summary>
        /// 插入元素
        /// </summary>
        /// <param name="index">索引 从0开始</param>
        /// <param name="t">插入元素</param>
        /// <returns>插入成功与否</returns>
        bool Insert(int index, T t);
        /// <summary>
        /// 追加元素
        /// </summary>
        /// <param name="t">元素</param>
        /// <returns>元素追加是否成功，空间不够会失败</returns>
        bool Append(T t);
        /// <summary>
        /// 删除元素
        /// </summary>
        /// <param name="index">要删除的元素位置</param>
        /// <param name="t">删除元素的值</param>
        /// <returns>是否删除成功</returns>
        bool Delete(int index, out T t);
        /// <summary>
        /// 删除元素
        /// </summary>
        /// <param name="t">待删除的元素</param>
        /// <returns>是否删除成功</returns>
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
        /// <param name="t">元素</param>
        /// <returns>是否存在数据</returns>
        bool TryGetItem(int index, out T t);
        /// <summary>
        /// 获取索引位置 
        /// 第一个元素的索引值为0
        /// </summary>
        /// <param name="t">元素</param>
        /// <returns>返回元素在Array中的索引[索引起始位置0]，不存在返回-1</returns>
        int IndexOf(T t);
        /// <summary>
        /// 访问器
        /// </summary>
        /// <param name="index">索引</param>
        /// <returns>返回访问到的数据</returns>
        T this[int index] { get; set; }
        /// <summary>
        /// 判断数组是否满了
        /// </summary>
        /// <returns>是否为满</returns>
        bool IsFull();
        /// <summary>
        /// 判断数组是否为空
        /// </summary>
        /// <returns>是否为空</returns>
        bool IsEmpty();
    }

    /// <summary>
    /// 数组实现类
    /// </summary>
    /// <typeparam name="T"></typeparam>
    public class Array<T> : IArray<T>
    {
        /// <summary>
        /// 数组数据
        /// </summary>
        protected T[] mData;
        /// <summary>
        /// 数组长度
        /// </summary>
        protected int mLength;

        /// <summary>
        /// 数组初始化
        /// </summary>
        /// <param name="_capacity">数组容许最大长度</param>
        public Array(int _capacity)
        {
            mData = new T[_capacity];
            mLength = 0;
        }
        /// <summary>
        /// 获取数组长度
        /// </summary>
        public int Length
        {
            get
            {
                return mLength;
            }
        }
        /// <summary>
        /// 访问器
        /// </summary>
        /// <param name="index">索引</param>
        /// <returns>返回访问到的数据</returns>
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
        /// <summary>
        /// 判断数组是否满了
        /// </summary>
        /// <returns>是否为满</returns>
        public bool IsFull()
        {
            if (mLength >= mData.Length)
                return true;
            return false;
        }
        /// <summary>
        /// 判断数组是否为空
        /// </summary>
        /// <returns>是否为空</returns>
        public bool IsEmpty()
        {
            if (mLength <= 0)
                return true;
            return false;

        }
        /// <summary>
        /// 清空数组
        /// </summary>
        public void Clear()
        {
            mLength = 0;
        }
        /// <summary>
        /// 删除元素
        /// </summary>
        /// <param name="index">要删除的元素位置</param>
        /// <param name="t">删除元素的值</param>
        /// <returns>是否删除成功</returns>
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
        /// <summary>
        /// 删除元素
        /// </summary>
        /// <param name="t">待删除的元素</param>
        /// <returns>是否删除成功</returns>
        public bool Delete(T t)
        {
            int index = IndexOf(t);
            return Delete(index, out _);
        }
        /// <summary>
        /// 获取索引位置 
        /// 第一个元素的索引值为0
        /// </summary>
        /// <param name="t">元素</param>
        /// <returns>返回元素在Array中的索引[索引起始位置0]，不存在返回-1</returns>
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
        /// <summary>
        /// 插入元素
        /// </summary>
        /// <param name="index">索引 从0开始</param>
        /// <param name="t">插入元素</param>
        /// <returns>插入成功与否</returns>
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
        /// <returns>是否成功</returns>
        protected virtual bool MallocMoreSize()
        {
            return false;
        }
        /// <summary>
        /// 追加元素
        /// </summary>
        /// <param name="t">元素</param>
        /// <returns>元素追加是否成功，空间不够会失败</returns>
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
        /// <summary>
        /// 尝试获取数组元素
        /// </summary>
        /// <param name="index">索引位置从0开始</param>
        /// <param name="t">元素</param>
        /// <returns>是否存在数据</returns>
        public bool TryGetItem(int index, out T t)
        {
            t = default(T);
            if (index < 0 || index >= mLength)
                return false;
            t = mData[index];
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
        /// <summary>
        /// 初始化
        /// </summary>
        /// <param name="_capacity">默认数组长度</param>
        public VariableArray(int _capacity) : base(_capacity)
        {
        }

        /// <summary>
        /// 内存申请
        /// </summary>
        /// <returns>是否成功</returns>
        protected override bool MallocMoreSize()
        {
            return SetSize(mData.Length + INCREMENT);
        }

        /// <summary>
        /// 扩充数组大小 实现数组自动扩容
        /// </summary>
        /// <param name="size">扩充后的内存大小</param>
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
        /// <summary>
        /// 初始化
        /// </summary>
        /// <param name="_capacity">初始数组大小</param>

        public SortArray(int _capacity) : base(_capacity)
        {
        }
        /// <summary>
        /// 插入数据 和 append 操作相同
        /// 数据插入以后自动排序
        /// </summary>
        /// <param name="index">索引[无用]</param>
        /// <param name="t">元素</param>
        /// <returns>是否插入数据成功</returns>
        public override bool Insert(int index, T t)
        {
            return base.Append(t);
        }

        /// <summary>
        /// 追加数据的时候 判断数据
        /// </summary>
        /// <param name="t">元素</param>
        /// <returns>是否插入或追加数据成功</returns>
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
        /// <param name="t">待插入元素</param>
        /// <returns>返回待插入位置</returns>
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
        /// <param name="t">另外一个数组</param>
        public void Merge(SortArray<T> array)
        {
            for (int i = 0, length = array.Length; i < length; i++)
            {
                Append(array[i]);
            }
        }
    }
}
