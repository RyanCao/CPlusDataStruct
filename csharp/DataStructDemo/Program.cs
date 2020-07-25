using System;
using System.Collections.Generic;
using Chester.DataStructLib;

namespace DataStruct
{
    class Program
    {
        static void Main(string[] args)
        {
            TestArray();
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
