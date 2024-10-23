using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Good_Food
{
    public class Element
    {
        public Element()
        {
        }

        public Element(string nume, int kcal, int pret, int cantitate)
        {
            this.nume = nume;
            this.kcal = kcal;
            this.pret = pret;
            this.cantitate = cantitate;
        }

        public string nume { get; set; }
        public int kcal { get; set; }
        public int pret { get; set; }
        public int cantitate { get; set; } 
    }
}
