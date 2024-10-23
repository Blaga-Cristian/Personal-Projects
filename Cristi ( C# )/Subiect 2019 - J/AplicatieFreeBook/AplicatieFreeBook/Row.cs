using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AplicatieFreeBook
{
    class Row
    {
        public Row()
        {
        }

        public Row(int id, string titlu, string nume_Autor, DateTime dataimprumut, DateTime datadisponibil)
        {
            Id = id;
            Titlu = titlu;
            Nume_Autor = nume_Autor;
            Dataimprumut = dataimprumut;
            Datadisponibil = datadisponibil;
        }

        public int Id { get; set; }
        public string Titlu { get; set; }
        public string Nume_Autor { get; set; }
        public DateTime Dataimprumut { get; set; }
        public DateTime Datadisponibil { get; set; }
    }
}
