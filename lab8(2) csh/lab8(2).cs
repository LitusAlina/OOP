using System;

namespace lab8_2CSH
{
    class Mass_obj
    {
        public int Summa(int [,] arr)
        {
            const int a = 3;
            int [] summ = new int [a] ;
            for (int i = 0; i < a;)
            {
                for (int q = 0; q < 3; q++)
                {
                    for (int w = 0; w < 4; w++)
                    {
                        summ[i] += arr[q, w];
                    }
                    Console.WriteLine(summ[i]);
                    i++;
                }
            }
            return 0;
        }
    }
    static class Mass_static
    {
        static public int Summa(int[,] arr)
        {
            const int a = 3;
            int[] summ = new int[a] ;
            for (int i = 0; i < a;)
            {
                for (int q = 0; q < 3; q++)
                {
                    for (int w = 0; w < 4; w++)
                    {
                        summ[i] += arr[q, w];
                    }
                    Console.WriteLine(summ[i]);

                    i++;
                }
            }
            return 0;
            
        }
    
    }
    class Program
    {
        delegate int Count(int[,] arr);
    static void Main(string[] args)
    {
        int[,] massive = new int [3, 4] { {10, 9, 98, 65}, {8, -9, -4, 6}, {15, 6, 78, -8} };

        Count count = new Count(Mass_static.Summa);
        Console.WriteLine(count.Invoke(massive));

        Mass_obj obj = new Mass_obj();
        Console.WriteLine(obj.Summa(massive));
    }

    }
}
