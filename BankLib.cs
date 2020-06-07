using System;
using System.Collections.Generic;
using System.Text;

namespace BankLib
{
    public delegate void Overdraft();
    public class Bank
    {
        public event Overdraft Notify;
        private int Bill;

        public void CreateBankAccount()
        {
            Console.WriteLine("Bank Account is created");
        }

        public int IncreaseBill(int a)
        {

            Bill += a;
            if (Bill > 100) throw new Exception();
            Console.WriteLine("Bill is increased by " + a);
            Console.WriteLine("Bill: " + Bill);
            return Bill;
        }
        public int DecreaseBill(int a)
        {

            Bill -= a;
            Console.WriteLine("Bill is decreased by " + a);
            Console.WriteLine("Bill: " + Bill);
            if (Bill <= 0)
            {
                if (Notify != null)
                {
                    Notify();
                }
            }
            return Bill;
        }
        public void AccountСlosure()
        {
            Console.WriteLine("Bank Account is closed");
        }

    }
}
