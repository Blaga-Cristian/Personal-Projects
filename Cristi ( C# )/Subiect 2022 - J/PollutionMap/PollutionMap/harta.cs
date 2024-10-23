using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PollutionMap
{
    public class Harta
    {
        public Harta()
        {
        }

        public Harta(int idHarta, string numeHarta, string fisierHarta)
        {
            IdHarta = idHarta;
            NumeHarta = numeHarta;
            FisierHarta = fisierHarta;
        }

        public int IdHarta { get; set; }
        public string NumeHarta { get; set; }
        public string FisierHarta { get; set; }
    }
}
