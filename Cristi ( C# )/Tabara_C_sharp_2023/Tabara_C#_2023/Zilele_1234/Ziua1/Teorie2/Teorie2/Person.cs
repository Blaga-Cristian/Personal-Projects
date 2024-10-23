using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Teorie2
{
    class Person
    {

        public Person()
        {
            name = "";
            age = 0;
        }

        public Person(string name)
        {
            this.name = name;
        }

        public Person(string name, int age) 
        {
            this.name = name;
            this.age = age;
        }

        public Person(int age)
        {
            this.name = "";
            this.age = age;
        }
        public void Walk()
        {
            Console.WriteLine($"{name} is walking...");
        }

        public void Talk()
        {
            Console.WriteLine($"{name} is talking...");
        }

        private string name;
        private int age;
    }
}
