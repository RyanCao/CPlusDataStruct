using System;
using System.Collections.Generic;
using System.Text;

namespace DataStructLib
{
    /// <summary>
    /// 散列表 接口
    /// </summary>
    /// <typeparam name="K"></typeparam>
    /// <typeparam name="V"></typeparam>
    public interface IHashTable<K, V>
    {
        /// <summary>
        /// 键值设置获取
        /// </summary>
        /// <param name="index"></param>
        /// <returns></returns>
        V this[K index] { get; set; }
        /// <summary>
        /// 添加键值数据
        /// </summary>
        /// <param name="key"></param>
        /// <param name="value"></param>
        void Add(K key, V value);
        /// <summary>
        /// 删除键值数据
        /// </summary>
        /// <param name="key"></param>
        void Remove(K key);
        /// <summary>
        /// 获取键值数据
        /// </summary>
        /// <param name="key"></param>
        /// <returns></returns>
        V Get(K key);
        /// <summary>
        /// 获取键值数据
        /// </summary>
        /// <param name="key"></param>
        /// <param name="value"></param>
        /// <returns></returns>
        bool TryGetValue(K key, out V value);
    }

    public class Entry<K, V>
    {
        public K key;
        public V value;

        public Entry(K k, V v)
        {
            this.key = k;
            this.value = v;
        }

        public Entry<K, V> next;
    }

    /// <summary>
    /// 散列表 实现
    /// </summary>
    public class HashTable<K, V> : IHashTable<K, V>
    {
        /// <summary>
        /// 默认实例化的值
        /// </summary>
        private const int DEFAULT_INITAL_CAPACITY = 8;
        /// <summary>
        /// 散列表大小 实际占内存大小
        /// </summary>
        private int size;
        /// <summary>
        /// 散列表的长度 , 实际由多少条数据
        /// </summary>
        private int length;

        /// <summary>
        /// 数据存放位置
        /// </summary>
        private Entry<K, V>[] mData;

        public HashTable()
        {
            mData = new Entry<K, V>[DEFAULT_INITAL_CAPACITY];
            size = DEFAULT_INITAL_CAPACITY;
            length = 0;
        }

        /// <summary>
        /// 求Hash值 对应的数据存放位置
        /// </summary>
        /// <param name="key"></param>
        /// <returns></returns>
        private int hash(K key)
        {
            if (key == null)
            {
                return 0;
            }
            else
            {
                int h = key.GetHashCode();
                return h ^ (h >> 16) % mData.Length;
            }
        }

        /// <summary>
        /// 自动扩容
        /// </summary>
        private void resize()
        {

        }


        public V this[K index]
        {
            get
            {
                throw new NotImplementedException();
            }
            set
            {
                throw new NotImplementedException();
            }
        }

        public void Add(K key, V value)
        {
            int index = hash(key);
            mData[index] = new Entry<K, V>(default(K), default(V));
            
            throw new NotImplementedException();
        }

        public V Get(K key)
        {
            throw new NotImplementedException();
        }

        public void Remove(K key)
        {
            throw new NotImplementedException();
        }

        public bool TryGetValue(K key, out V value)
        {
            throw new NotImplementedException();
        }
    }
}
