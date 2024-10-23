using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bursa_Nume_Prenume
{
    public class Actiune
    {
        public Actiune()
        {
        }

        public Actiune(string denumire, int nrActiuni, int valoare)
        {
            Denumire = denumire;
            NrActiuni = nrActiuni;
            Valoare = valoare;
        }

        public string Denumire { get; set; }
        public int NrActiuni { get; set; }
        public int Valoare { get; set; }
    }
}
