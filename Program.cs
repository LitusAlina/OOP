using System;

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
