﻿using System;
using Chester.DataStructLib;

namespace DataStruct
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            IArray<int> array = new Array<int>(5);
            
            array.Append(1);
            Console.WriteLine(array);
            array.Append(2);
            Console.WriteLine(array);
            array.Append(3);
            Console.WriteLine(array);
            array.Append(4);
            Console.WriteLine(array);
            array.Append(5);
            Console.WriteLine(array);
            array.Append(6);
            Console.WriteLine(array);

        }
    }
}