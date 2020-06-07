using System;

namespace lab7
{
    public class CharList<T>
    {
        DoubleNode<T> head;
        DoubleNode<T> tail;
        private decimal count;

        public void Add(T data)
        {
            DoubleNode<T> node = new DoubleNode<T>(data);

            if (head == null)
                head = node;
            else
            {
                tail.Next = node;
                node.Previous = tail;
            }
            tail = node;
            count++;
        }

        public int CountEven()
        {
            return (int)Math.Floor(count / 2);
        }

        public void Remove(T data)
        {
            DoubleNode<T> current = head;

            while (current != null)
            {
                if (current.Data.Equals(data))
                {
                    break;
                }
                current = current.Next;
            }
            if (current != null)
            {
                if (current.Next != null)
                {
                    current.Next.Previous = current.Previous;
                }
                else
                {
                    tail = current.Previous;
                }
                if (current.Previous != null)
                {
                    current.Previous.Next = current.Next;
                }
                else
                {
                    head = current.Next;
                }
                count--;
            }
        }

        public void DeleteMoreThanA()
        {
            DoubleNode<T> current = head;
            while (current != null)
            {
                if ((int)'№' < (int)current.ToChar(current.Data.ToString()))
                {
                    Console.WriteLine(current.Data);
                    Console.WriteLine((int) '№');
                    Remove(current.Data);
                }
                current = current.Next;
            }
        }

    }
}

