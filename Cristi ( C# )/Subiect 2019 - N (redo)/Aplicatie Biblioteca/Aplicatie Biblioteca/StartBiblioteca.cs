using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Aplicatie_Biblioteca
{
    public partial class StartBiblioteca : Form
    {
        DSBibliotecaTableAdapters.CartiTableAdapter cta = new DSBibliotecaTableAdapters.CartiTableAdapter();
        DSBibliotecaTableAdapters.ImprumuturiTableAdapter ita = new DSBibliotecaTableAdapters.ImprumuturiTableAdapter();
        DSBibliotecaTableAdapters.RezervariTableAdapter rta = new DSBibliotecaTableAdapters.RezervariTableAdapter();
        DSBibliotecaTableAdapters.UtilizatoriTableAdapter uta = new DSBibliotecaTableAdapters.UtilizatoriTableAdapter();
        string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\ONTI_C#_2019_resurse\";

        public StartBiblioteca()
        {
            InitializeComponent();
            IncarcaCarti();
            IncarcaUtilizatori();
            IncarcaImprumuturi();
            IncarcaRezervari();
        }

        private void IncarcaRezervari()
        {
            var sr = new StreamReader(respath + "rezervari.txt");
            string line;
            string[] s;
            char[] sep = { ';' };

            while ((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                int idCititor = int.Parse(s[0]);
                int idCarte = int.Parse(s[1]);
                DateTime dataRezervare = DateTime.ParseExact(s[2], "M/d/yyyy h/mm/ss tt", System.Globalization.CultureInfo.InvariantCulture);
                int statusRezervare = int.Parse(s[3]);

                rta.Insert(idCititor, idCarte, dataRezervare, statusRezervare);
            }
        }

        private void IncarcaImprumuturi()
        {
            var sr = new StreamReader(respath + "imprumuturi.txt");
            string line;
            string[] s;
            char[] sep = { ';' };

            while ((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                int idCititor = int.Parse(s[0]);
                int idCarte = int.Parse(s[1]);
                DateTime dataImprumut = DateTime.ParseExact(s[2], "M/d/yyyy h/mm/ss tt", System.Globalization.CultureInfo.InvariantCulture);
                if (s[3] == "NULL")
                    ita.Insert(idCititor, idCarte, dataImprumut, null);
                else
                {
                    DateTime dataRestituire = DateTime.ParseExact(s[3], "M/d/yyyy h/mm/ss tt", System.Globalization.CultureInfo.InvariantCulture);
                    ita.Insert(idCititor, idCarte, dataImprumut, dataRestituire);
                }
            }
        }

        private void IncarcaUtilizatori()
        {
            var sr = new StreamReader(respath + "utilizatori.txt");
            string line;
            string[] s;
            char[] sep = { ';' };

            while ((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                int tipUtilizator = int.Parse(s[0]);
                string numePrenume = s[1];
                string email = s[2];
                string parola;
                if (tipUtilizator == 1)
                    parola = s[3];
                else
                    parola = null;

                uta.InsertUtilizator(tipUtilizator, numePrenume, email, parola);
            }
        }

        private void IncarcaCarti()
        {
            var sr = new StreamReader(respath + "carti.txt");
            string line; 
            string[] s;
            char[] sep = { ';' };

            while((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                string titlu = s[0];
                string autor = s[1];
                int nrPag = int.Parse(s[2]);

                cta.InsertCarte(titlu, autor, nrPag);
            }
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            var frm = new LogareBilblioteca();
            this.Visible = false;
            frm.ShowDialog();
            this.Close();
        }
    }
}
