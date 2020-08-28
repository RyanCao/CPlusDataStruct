using System;
using System.Collections.Generic;
using Chester.DataStructLib;
using DataStructLib;

namespace DataStruct
{
    class Program
    {
        static void Main(string[] args)
        {
            //TestArray();
            TesthashTable();
        }

        static void TesthashTable()
        {
            HashTable<string, int> hashTable = new HashTable<string, int>();
            hashTable["a"] = 1;
            hashTable["b"] = 2;
            hashTable["c"] = 3;
            hashTable["d"] = 4;
            hashTable["e"] = 5;
            hashTable["f"] = 6;
            hashTable["g"] = 7;
            hashTable["g"] = 8;
            hashTable["g"] = 9;
            hashTable["g"] = 10;

            Console.WriteLine(hashTable);
        }
        static void TestArray()
        {
            Comparison<int> comparison = delegate (int a, int b)
            {
                if (a > b)
                    return 1;
                else if (a == b)
                    return 0;
                else
                    return -1;
            };

            SortArray<int> sortArray = new SortArray<int>(2);
            sortArray.Comparer = comparison;

            //IArray<int> array = new VariableArray<int>(2);
            IArray<int> array = sortArray;

            array.Append(10);
            Console.WriteLine(array);
            array.Append(22);
            Console.WriteLine(array);
            array.Append(32);
            Console.WriteLine(array);
            array.Append(4);
            Console.WriteLine(array);
            array.Append(51);
            Console.WriteLine(array);
            array.Append(6);
            Console.WriteLine(array);

            Console.WriteLine(array.IndexOf(4));

            SortArray<int> sortArray2 = new SortArray<int>(2);
            sortArray2.Comparer = comparison;

            sortArray2.Append(100);
            sortArray2.Append(200);
            sortArray2.Append(102);
            sortArray2.Append(300);
            sortArray2.Append(160);
            sortArray2.Append(150);

            Console.WriteLine(sortArray2);

            sortArray2.Merge(array as SortArray<int>);

            Console.WriteLine(sortArray2);

        }
    }
}
