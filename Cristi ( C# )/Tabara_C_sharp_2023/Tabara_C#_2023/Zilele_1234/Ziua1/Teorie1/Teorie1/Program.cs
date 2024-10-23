using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Teorie1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int a, b;
            Console.WriteLine("Introduceti doua numere intregi: ");
            string s1, s2;
            s1 = Console.ReadLine();
            s2 = Console.ReadLine();

            a = int.Parse(s1);  // transforma sirul de carcatere in numar intreg
            b = int.Parse(s2);  // transforma sirul de carcatere in numar intreg
            
            Console.WriteLine(a + " + " + b + " = " + (a + b));
            Console.WriteLine("{0} + {1} = {2}", a, b, a + b);
            Console.WriteLine($"{a} + {b} = {a + b}");
            Console.ReadKey();
        }
    }
}
