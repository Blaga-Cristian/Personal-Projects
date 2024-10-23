using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Constructori2
{
    class User 
    {
        // constructorii clasei
        
        // campuri
        string userName;
        string password;
        string email;

        // Properties
        public string UserName 
        { 
            get { return userName; }
            set { userName = value; }
        }

        public string Password
        {
            get { return password; }
            set { password = value; }
        }

        public string Email
        {
            get { return email; }
            set { email = value; }
        }
        public int Age
        { get; set; }


        public User(string userName)
        {
            this.userName = userName;
        }

        
        // constructori
        public User(string userName, string password)
        {
            this.userName = userName;
            this.password = password;
        }

        public User(string userName, string password, string email)
        {
            this.userName = userName;
            this.password = password;
            this.email = email;
        }

        public string GetUserName()
        { 
            return this.userName; 
        }

        public void SetUserName(string userName)
        {
            this.userName = userName;
        }

        override public string ToString()
        {
            return $"{UserName}, {Password}, {Email}, {Age}";
        }
    }
}
