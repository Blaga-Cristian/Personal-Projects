using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interferente_ECO
{
    internal class Utilizatori
    {
        public Utilizatori()
        {
        }

        public Utilizatori(string nume, string parola)
        {
            Nume = nume;
            Parola = parola;
        }

        public string Nume { get; set; }
        public string Parola { get; set; }
    }
}
