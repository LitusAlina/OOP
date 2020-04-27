using System;
using System.Text;
using System.Collections.Generic;

namespace lab5SH2
{
    class String
    {
     public
         int str_len() { return 0; }
         string char_replace() { return ""; }
    }

    class Characters : String
    {
        private string s;

        public Characters(string s1)
        {
            s = s1;
        }

       public int str_len(string s) 
        {
            int len = s.Length;
           
            Console.WriteLine(len);
            return len;
        }
                 
        public string char_replace()
        {
            int counter = 0;
            for (int i = 0; i < s.Length; i++) { if (s[i] == '#') counter++; }
            char[] arr = new char[s.Length];
            Array.Resize(ref arr, s.Length + counter);
            for (int i = 0, j = 0; i < s.Length; i++, j++)
            {
                if (s[i] != '#') arr[j] = s[i];
                else
                {
                    arr[j] = '!';
                    arr[j + 1] = '!';
                    j++;
                }
            }
            s = new string(arr);
            return s;
        }
        public void Print()
        {
            Console.WriteLine(s, str_len(s));
        }
    }

        class Program
        {
            static void Main(string[] args)
            {
                Characters c = new Characters("gvh23#$%#");
                c.Print();
                c.str_len();
                c.char_replace();
                c.str_len();
                c.Print();
                
            }
        }
    
}
