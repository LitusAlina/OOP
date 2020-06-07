<<<<<<< HEAD
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab4cs
{
    class Section
    {
        private int begX;
        private int endX;
        private int begY;
        private int endY;
        int x, y;
        public Section()
        {
            begX = 0;
            endX = 0;
            x = 0;
            begY = 0;
            endY = 0;
            y = 0;
        }
        public Section(int valuebegX, int valueendX, int valuebegY, int valueendY)
        {
            begX = valuebegX;
            endX = valueendX;
            begY = valuebegY;
            endY = valueendY;
            x = endX - begX;
            y = endY - begY;
        }
        public int GetbegX()
        {
            return begX;
        }
        public int GetendX()
        {
            return endX;
        }
        public int GetbegY()
        {
            return begY;
        }
        public int GetendY()
        {
            return endY;
        }
        public int Getx()
        {
            return x;
        }
        public int Gety()
        {
            return y;
        }

        public Section(Section other)
        {
            //конструктор копирования
            this.x = other.x;
            this.y = other.y;
        }
        public static Section operator -(Section obj, Section other)
        {
            Section temp1 = new Section();
            temp1.x = obj.endX - other.begX;
            temp1.y = obj.endY - other.begY;
            return temp1;
        }
        public static Section operator +(Section obj, Section other)
        {
            Section temp2 = new Section();
            temp2.x = obj.x + other.x;
            temp2.y = obj.y + other.y;
            return temp2;
        }
        public static Section operator *(Section obj, int a)
        {
            Section temp3 = new Section();
            temp3.x = obj.x * a;
            temp3.y = obj.y * a;
            return temp3;
        }
        public double Length()
        {
            double result;
            result = Math.Sqrt(this.x * this.x + this.y * this.y);
            Console.WriteLine(result);
            return result;
        }
        public void Print()
        {
            Console.WriteLine("L\t" + x + "\t" + y);
            Console.WriteLine("\n");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Section L2 = new Section(3, 8, 4, 16);
            Section L3 = new Section(1, 4, 5, 9);
            Section L1 = L2 + L3;
            L1.Print();
            L2.Print();
            L3.Print();
            L1.Length();
            L2.Length();
            L3.Length();

            Section L4 = L3 * 2;
            L4.Print();
            L4.Length();
        }
    }
}
=======
﻿using System;

namespace Labor1
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = 128; // rand () % 10 + 1
            Func1(ref num);

            Console.WriteLine("num " + num);
            int y = -25;
            int z = -20;
            Console.WriteLine("y = " + y);
            Console.WriteLine("z = " + z);

            Console.WriteLine(Func2( y, z));
        }
        public static void Func1(ref int num)
        {

            int num1 = num;
            Console.WriteLine(num);

            for (int i = 0; i < sizeof(int) * 8; i++)
            {
                num = num ^ (1 << i);
                if ((num1 & (1 << i)) != 0) break;
            }
        }

        public static int Func2(int y, int z)
        {
            int a = sizeof(int) * 4;
            if ((y ^ z) == 0)
            {
                return 0;
            }

            for (int i = a; i >= 0; i--)
            {
                int Ay = y & (1 << i);
                int Az = z & (1 << i);

                if (i == a && (y ^ z) < 0)
                {
                    if ((Ay != 0) && (Az == 0))
                    {
                        return 1;
                    }
                    if ((Az != 0) && (Ay == 0))
                    {
                        return -1;
                    }
                }
                else if ((y ^ z) > 0)
                {
                    if ((Ay != 0) && (Az == 0))
                    {
                        return -1;
                    }
                    if ((Az != 0) && (Ay == 0))
                    {
                        return 1;
                    }
                }
            }
            return 1;
        }
    }
}

