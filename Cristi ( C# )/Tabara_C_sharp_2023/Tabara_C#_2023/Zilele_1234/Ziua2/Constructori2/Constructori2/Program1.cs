using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Constructori2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            User user = new User("Ana", "ana123", "ana@yahoo.com");
            Console.WriteLine(user);
            user.SetUserName("Radu");

            Console.WriteLine(user);
            Console.WriteLine(user.GetUserName());
            Console.ReadKey();
        }
    }
}
