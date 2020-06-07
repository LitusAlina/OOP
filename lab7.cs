namespace lab7
{
    class Program
    {
        static void Main(string[] args)
        {
            CharList<char> charList = new CharList<char>();
            charList.Add('m');
            charList.Add('g');
            charList.Add('s');
            charList.Add('@');
            charList.Add('$');
            charList.Add('3');
            charList.DeleteMoreThanA();
        }
    }
}