using System;
using System.Collections.Generic;
using System.Linq;
using System.Security;
using System.Text;
using System.Threading.Tasks;

namespace Teorie2
{
    

    internal class Program
    {
        static void Main(string[] args)
        {
            Person p = new Person("Liliana", 16);

            p.Walk();
            p.Talk();
            Console.ReadKey();
        }
    }
}
