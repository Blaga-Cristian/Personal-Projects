using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Program
    {
        private static string path = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\";
        static void Main(string[] args)
        {
            string str1;
            string str2;
            str1 = Console.ReadLine();
            str2 = Console.ReadLine();

            bool b = str1.Equals(str2, StringComparison.OrdinalIgnoreCase);
            Console.WriteLine(b);

            Console.ReadKey();
        }
    }
}
