namespace lab7
{
    public class DoubleNode<T>
    {
        public T Data { get; set; }
        public DoubleNode(T data)
        {
            Data = data;
        }
        public DoubleNode<T> Previous { get; set; }
        public DoubleNode<T> Next { get; set; }
        public char ToChar(string str)
        {
            return str.ToCharArray()[0];
        }
    }
}
