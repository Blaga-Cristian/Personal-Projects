using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Turismul_Durabil
{
    class Excursie
    {
        public Excursie()
        {
        }

        public Excursie(string nume, DateTime dataStart, DateTime dataStop, string frecventa, int ziua)
        {
            Nume = nume;
            DataStart = dataStart;
            DataStop = dataStop;
            Frecventa = frecventa;
            Ziua = ziua;
        }

        public string Nume { get; set; }
        public DateTime DataStart { get; set; }
        public DateTime DataStop { get; set; }
        public string Frecventa { get; set; }
        public int Ziua { get; set; }
    }
}
