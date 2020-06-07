using System;
using System.Collections.Generic;
using System.Text;

namespace LAB3CS
{
    public class Class1
    {
        public static int row, col;
        public int rows, cols;
        public int start;
        public bool error;
        private int[,] arr = new int[row, col];
        private int mid;

        public Class1(int s, int r, int c)
        {
            start = s;
            row = r;
            col = c;
            arr = new int[r, c];
            error = false;
            rows = r;
            cols = c;
        }
        public float this[int index]
        {
            get
            {
                index = index - start;
                if (index >= 0 && index < cols * rows)
                {
                    error = false;
                    float mult = 1;
                    for (int i = 0; i < rows; i++)
                    {
                        mult *= arr[i, index];
                    }
                    return mult;
                }
                else
                {
                    error = true;
                    return 0;
                }
            }
        }
        public int this[int index1, int index2]
        {
            set
            {
                if (index1 >= 0 && index1 < rows && index2 >= 0 && index2 < cols)
                {
                    error = false;
                    arr[index1, index2] = value;
                }
                else
                {
                    error = true;
                }
            }
            get
            {
                if (index1 >= 0 && index1 < rows && index2 >= 0 && index2 < cols)
                {
                    error = false;
                    return arr[index1, index2];
                }
                else
                {
                    error = true;
                    return 0;
                }
            }
        }
        public int Middle
        {
            get
            {
                mid = 0;
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < cols; j++)
                    {
                        mid += arr[i, j];
                    }
                }
                return mid/(rows*cols);
            }
        }
        public void Print()
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    Console.Write("{0} ", arr[i, j]);
                }
                Console.WriteLine("\n");
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            LAB3CS.Class1 array = new LAB3CS.Class1(1, 3, 3);
            for (int i = 0; i <= array.rows; i++)
            {
                for (int j = 0; j <= array.cols; j++)
                {
                    array[i, j] = i * array.cols + j + 1;
                }
            }
            array.Print();
            Console.WriteLine(array[1]);
            Console.WriteLine(array[2]);
            Console.WriteLine(array[3]);
            Console.WriteLine(array.Middle);
        }
    }
}
