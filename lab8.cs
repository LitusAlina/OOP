using System;
using BankLib;

namespace lab8_1
{
    class Program
    {
        static void OnPoor()
        {
            Console.WriteLine("You are poor");
        }
        static void Main(string[] args)
        {
            Bank Account = new Bank();
            Account.Notify += new BankLib.Overdraft(OnPoor);
            Account.CreateBankAccount();
            try
            {
                Account.IncreaseBill(100);
            }
            catch (Exception) { Console.WriteLine("Too much money"); }

            Account.DecreaseBill(200);
            Account.AccountСlosure();
        
        }
    }
}
