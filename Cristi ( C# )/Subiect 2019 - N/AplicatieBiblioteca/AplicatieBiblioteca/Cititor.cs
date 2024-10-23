using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AplicatieBiblioteca
{
    public class Cititor
    {
        public Cititor()
        {
        }

        public Cititor(int idCititor, string numePrenume, string email)
        {
            IdCititor = idCititor;
            NumePrenume = numePrenume;
            Email = email;
        }

        public int IdCititor { get; set; }
        public string NumePrenume { get; set; }
        public string Email { get; set; }
    }
}
