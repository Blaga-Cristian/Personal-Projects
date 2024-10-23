using System;
using System.Collections.Generic;
using System.Linq;
using System.Security;
using System.Text;
using System.Threading.Tasks;

namespace Teorie2
{
    class Person
    {
        public void Walk()
        {
            Console.WriteLine($"{name} is walking...");
        }

        public void Talk()
        {
            Console.WriteLine($"{name} is talking...");
        }

        private string name = "Maria";
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            Person p; // p - referinta la un viitor obiect de tip Persoana
            p = new Person();  // se creaza (se aloca dinamic)
                               // un nou obiect de tip Person
            p.Talk();
            p.Walk();
            Console.ReadKey();
        }
    }
}
