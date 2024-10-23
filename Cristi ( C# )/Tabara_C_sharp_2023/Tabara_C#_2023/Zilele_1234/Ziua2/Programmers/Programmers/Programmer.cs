using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Programmers
{
    class Programmer
    {
        public Programmer() 
        {
            Name = "";
            Position = "";
            Salary = 0;
            HiringDate = DateTime.Now;
        }

        public Programmer(string name, string position, int salary, DateTime hiringDate)
        {
            Name = name;
            Position = position;
            Salary = salary;
            HiringDate = hiringDate;
        }

        public override string ToString()
        {
            return $"{Name}, {Position}, {Salary}, {HiringDate}";    
        }

        public string Name { get; set; }
        public string Position { get; set; }
        public int Salary { get; set; }
        public DateTime HiringDate { get; set; }


    }
}
