using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ListExemplu
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<string> names;
            names = new List<string>(); // lista vida
            names.Add("Ionel");
            names.Add("Marcel");
            names.Add("Viorel");
            names.Add("Alunel");
            names.Add("Ghiocel");

            for (int i = 0; i < names.Count; i++)
            {
                Console.Write(names[i] + " ");
            }
            Console.WriteLine();

            foreach(var name in names)
            {
                Console.Write(name + " ");
            }
            Console.ReadKey();
        }
    }
}
