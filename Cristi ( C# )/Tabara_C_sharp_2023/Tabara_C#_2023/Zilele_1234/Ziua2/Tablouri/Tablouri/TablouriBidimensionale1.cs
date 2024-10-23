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
            int[,] a;  // declar o referinta la un viitoare matrice dreptunghiulara
            int n, m;
            Console.Write("n = ");
            n = int.Parse(Console.ReadLine());
            Console.Write("m = ");
            m = int.Parse(Console.ReadLine());
            a = new int[n + 1, m + 1]; // aici cream o matrice 

            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    a[i, j] = i + j;

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                    Console.Write(a[i, j] + " ");
                Console.WriteLine();
            }
            

            
            Console.ReadKey();
        }
    }
}
