using System;
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
        /// <summary>
        /// 当前节点的K值
        /// </summary>
        public K key;
        /// <summary>
        /// 当前节点的V值
        /// </summary>
        public V value;
        /// <summary>
        /// 链表指向的下一个对象
        /// </summary>
        public Entry<K, V> next;
        public Entry(K k, V v, Entry<K, V> next = null)
        {
            this.key = k;
            this.value = v;
            this.next = next;
        }

        public override string ToString()
        {
            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.Append("(");
            stringBuilder.Append(key);
            stringBuilder.Append(",");
            stringBuilder.Append(value);
            stringBuilder.Append(")");
            return stringBuilder.ToString();
        }
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
        /// 装载因子 
        /// </summary>
        private const float LOAD_FACTOR = 0.75f;

        /// <summary>
        /// 实际元素数量 
        /// </summary>
        private int size = 0;

        /// <summary>
        /// 散列表索引数量
        /// </summary>
        private int use = 0;

        /// <summary>
        /// 数据存放位置
        /// </summary>
        private Entry<K, V>[] mTable;

        public HashTable()
        {
            mTable = new Entry<K, V>[DEFAULT_INITAL_CAPACITY];
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
                return (h ^ (h >> 16)) % mTable.Length;
            }
        }


        public V this[K index]
        {
            get
            {
                return Get(index);
            }
            set
            {
                Add(index, value);
            }
        }

        /// <summary>
        /// 添加元素 如果键值重复了，如何解决
        /// </summary>
        /// <param name="key"></param>
        /// <param name="value"></param>
        public void Add(K key, V value)
        {
            int index = hash(key);

            // 位置未被引用，创建哨兵节点
            if (mTable[index] == null)
            {
                mTable[index] = new Entry<K, V>(default(K), default(V));
            }

            Entry<K, V> entry = mTable[index];
            if (entry.next == null)
            {
                //新增节点
                entry.next = new Entry<K, V>(key, value);
                size++;
                use++;

                //动态扩容
                if (use > mTable.Length * LOAD_FACTOR)
                {
                    //大小重新设置
                    resize();
                }
            }
            else
            {
                while (entry.next != null && !entry.key.Equals(key))
                {
                    entry = entry.next;
                }
                if (entry.key.Equals(key))
                {
                    entry.value = value;
                }
                else
                {
                    entry.next = new Entry<K, V>(key, value);
                    size++;
                }
            }
        }

        /// <summary>
        /// 扩容
        /// </summary>
        private void resize()
        {
            Entry<K, V>[] oldTable = mTable;
            mTable = (Entry<K, V>[])new Entry<K,V>[mTable.Length * 2];
            use = 0;
            for (int i = 0; i < oldTable.Length; i++)
            {
                if (oldTable[i] == null || oldTable[i].next == null)
                {
                    continue;
                }
                Entry<K, V> e = oldTable[i];
                while (e.next != null)
                {
                    e = e.next;
                    int index = hash(e.key);
                    if (mTable[index] == null)
                    {
                        use++;
                        // 创建哨兵节点
                        mTable[index] = new Entry<K,V>(default(K), default(V), null);
                    }
                    mTable[index].next = new Entry<K,V>(e.key, e.value, mTable[index].next);
                }
            }
        }

        public V Get(K key)
        {
            V value;
            bool isGet = TryGetValue(key, out value);
            if (isGet)
            {
                return value;
            }
            else
            {
                throw new Exception("key not found!");
            }
        }

        public void Remove(K key)
        {
            int index = hash(key);
            Entry<K, V> entry = mTable[index];

            if (entry == null || entry.next == null)
            {
                return;
            }

            Entry<K, V> pre;
            Entry<K, V> headNode = entry;

            do
            {
                pre = entry;
                entry = entry.next;
                if (key.Equals(entry.key))
                {
                    pre.next = entry.next;
                    size--;
                    if (headNode.next == null) use--;
                    return;
                }
            } while (entry.next != null);

        }

        public bool TryGetValue(K key, out V value)
        {
            int index = hash(key);
            Entry<K, V> entry = mTable[index];

            if (entry == null || entry.next == null)
            {
                value = default(V);
                return false;
            }

            while (entry != null && !entry.key.Equals(key))
            {
                entry = entry.next;
            }

            if (entry != null)
            {
                value = entry.value;
                return true;
            }
            else
            {
                value = default(V);
                return false;
            }
        }

        public override string ToString()
        {
            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.Append("[");

            for (int i = 0, mLength = mTable.Length; i < mLength; i++)
            {
                Entry<K, V> entry = mTable[i];
                while (entry != null)
                {
                    stringBuilder.Append(entry);
                    entry = entry.next;
                }
                stringBuilder.Append(",");
            }
            stringBuilder.Append("]");
            return stringBuilder.ToString();
        }
    }
}
