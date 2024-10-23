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
            // Cream o matrice triunghiulara
            int[][] a;  // declar o referinta la un viitoare matrice dreptunghiulara
            int n;
            Console.Write("n = ");
            n = int.Parse(Console.ReadLine());
            a = new int[n][]; // am creat n linii vide!

            for (int i = 0; i < n; i++)  // cream liniile
                a[i] = new int[i + 1];   // una cate una

            // acum avem matricea triunghiulara
            for (int i = 0; i < n ; i++)
                for (int j = 0; j <= i; ++j)
                    a[i][j] = i + 1;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j <= i; ++j)
                    Console.Write(a[i][j] + " ");
                Console.WriteLine();
            }
            
            Console.ReadKey();
        }
    }
}
