using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ListExemplu
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<User> users = new List<User>(); // lista vida

            ReadUsers(users);
            users.Sort((a, b) => a.Age.CompareTo(b.Age));
            WriteUsers(users);

            // filtram in noua lista numai userii cu varsta > 15
            var filteredList = users.FindAll(u => u.Age >= 16);
            WriteUsers(filteredList);
        }

        private static void WriteUsers(List<User> users)
        {
            StreamWriter sw = new StreamWriter("users.out");
            foreach (User user in users)
                sw.WriteLine(user);
            sw.Close();
        }

        private static void ReadUsers(List<User> names)
        {
            StreamReader sr = new StreamReader("users.txt");
            string line;
            string[] s; // sir de stringuri
            char[] sep = { ';', ' ' };

            while ((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                string userName = s[0];
                string password = s[1];
                string email = s[2];
                int age = int.Parse(s[3]);
                names.Add(new User(userName, password, email, age));
            }
            sr.Close();
        }
    }
}
