using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tablouri
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] a;  // declar o referinta la un viitor tablou
            Console.Write("n = ");
            int n = int.Parse(Console.ReadLine());

            a = new int[n]; // aici se creaza tabloul

            for (int i = 0; i < a.Length; i++)
                a[i] = i + 1;
            
            for (int i = 0; i < a.Length; i++)
                Console.Write(a[i] + " ");

            Console.WriteLine(); // scrie NewLine

            foreach(int x in a)
                Console.Write(x + " "); 

            Console.ReadKey();
        }
    }
}
