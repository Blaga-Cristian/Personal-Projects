using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AplicatieBiblioteca
{
    internal class Item
    {
        public Item()
        {
        }

        public Item(int idCarte, string titlu, string autor, int nrPag)
        {
            IdCarte = idCarte;
            Titlu = titlu;
            Autor = autor;
            NrPag = nrPag;
        }

        public int IdCarte { get; set; }
        public string Titlu { get; set; }
        public string Autor { get; set; }
        public int NrPag { get; set; }
    }
}
