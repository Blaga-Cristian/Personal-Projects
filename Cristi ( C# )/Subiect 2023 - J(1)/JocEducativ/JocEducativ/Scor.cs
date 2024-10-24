using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace JocEducativ
{
    public class Scor
    {
        public Scor()
        {
        }

        public Scor(string numeUtilizator, string emailUtilizator, int punctajJoc)
        {
            NumeUtilizator = numeUtilizator;
            EmailUtilizator = emailUtilizator;
            PunctajJoc = punctajJoc;
        }

        public string NumeUtilizator { get; set; }
        public string EmailUtilizator { get; set; }
        public int PunctajJoc { get; set; }
    }
}
