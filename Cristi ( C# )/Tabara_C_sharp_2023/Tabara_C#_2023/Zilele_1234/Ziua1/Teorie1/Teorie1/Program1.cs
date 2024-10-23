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
            int a;
            string s;
            s = Console.ReadLine();
            a = int.Parse(s);  // transforma sirul de carcatere in numar intreg
            Console.WriteLine(a);
            Console.ReadKey();
        }
    }
}
