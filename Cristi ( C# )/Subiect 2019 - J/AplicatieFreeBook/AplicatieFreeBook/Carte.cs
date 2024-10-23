using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AplicatieFreeBook
{
    class Carte
    {
        public Carte()
        {
        }

        public Carte(int id, string titlu, string autor, string gen)
        {
            Titlu = titlu;
            Autor = autor;
            Gen = gen;
            Id = id;
        }

        public int Id { get; set; }
        public string Titlu { get; set; }
        public string Autor { get; set; }
        public string Gen { get; set; }

    }
}
