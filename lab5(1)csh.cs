using System;
using System.Collections.Generic;
using System.Text;

namespace lab5SH1
{
    
    class Figures
    {
        protected int[] x = new int[4];
        protected int[] y = new int[4];

        public Figures(int[] x1, int[] y1)
        {
            for (int i = 0; i < 4; i++)
            {
                x[i] = x1[i];
                y[i] = y1[i];
            }
        }
        Figures() { }
        
        virtual int Perimeter() { return 0; }
        virtual int Square() { return 0; }
        public int length_of_side(int index1, int index2)
        {
            index1--;
            index2--;
            if (x[index1] == x[index2]) return Math.Abs(y[index1] - y[index2]);
            else if (y[index1] == y[index2]) return Math.Abs(x[index1] - x[index2]);
            else return 0;
        }
    }

    class Rectangles : Figures
    {
        public Rectangles(int[] x1, int[] y1) : base(x1, y1) { }

        public int Square()
        {
            return this.length_of_side(1, 2) * this.length_of_side(2, 3);
        }
        public int Perimeter()
        {
            return (this.length_of_side(1, 2) + this.length_of_side(2, 3)) * 2;
        }
        public (int[] x, int[] y) Get_Info()
        {
            return (x, y);
        }
    }

        class Program
        {
            static void Main(string[] args)
            {
                int[] x = new[] { 0, 0, 2, 2 };
                int[] y = new[] { 0, 1, 1, 0 };
                Figures f1 = new Figures(x, y);
                int l = f1.length_of_side(1, 2);
                Rectangles r1 = new Rectangles(x, y);
                int s = r1.Square();
                int p = r1.Perimeter();
                int[] x1 = new int[4];
                int[] y1 = new int[4];
                (x1, y1) = r1.Get_Info();
            }
        }
    
}