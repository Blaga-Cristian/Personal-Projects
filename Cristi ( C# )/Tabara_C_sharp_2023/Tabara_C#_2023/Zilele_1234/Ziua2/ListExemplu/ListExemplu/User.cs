using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ListExemplu
{
    class User
    {
        public string UserName { get; set; }
        public string Password { get; set; }
        public string Email { get; set; }
        public int Age { get; set; }

        public User(string userName, string password, string email, int age)
        {
            UserName = userName;
            Password = password;
            Email = email;
            Age = age;
        }

        public User()
        {
        }

        public override string ToString()
        {
            return $"{UserName}, {Password}, {Email}, {Age}";
        }
    }
}
