using AplicatieBiblioteca.BibliotecaDBTableAdapters;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AplicatieBiblioteca
{
    public partial class StartBiblioteca : Form
    {
        public static string conStr = $@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\Biblioteca.mdf;Integrated Security=True";
        string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\ONTI_C#_2019_resurse\";
        UtilizatoriTableAdapter utilizatoriTableAdapter = new UtilizatoriTableAdapter();
        RezervariTableAdapter rezervariTableAdapter = new RezervariTableAdapter();
        Imprumuturi1TableAdapter imprumuturiTableAdapter = new Imprumuturi1TableAdapter();
        CartiTableAdapter cartiTableAdapter = new CartiTableAdapter();
        public StartBiblioteca()
        {
            InitializeComponent();
            IncarcaUtilizatori();
            IncarcaRezervari();
            IncarcaCarti();
            IncarcaImpurmuturi();
        }

        private void IncarcaCarti()
        {
            var sr = new StreamReader(respath + "carti.txt");
            string line;
            string[] s;
            char[] sep = { ';' };

            while ((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                string titlu = s[0];
                string autor = s[1];
                int nrpag = int.Parse(s[2]);

                cartiTableAdapter.InsertCarte(titlu, autor, nrpag);
            }
        }

        private void IncarcaImpurmuturi()
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
                DateTime dataImprumut = DateTime.ParseExact(s[2], "MM/dd/yyyy hh/mm/ss tt", CultureInfo.InvariantCulture);
                if (s[3] != "NULL")
                {
                    DateTime dataRestituire = DateTime.ParseExact(s[3], "MM/dd/yyyy hh/mm/ss tt", CultureInfo.InvariantCulture);
                    imprumuturiTableAdapter.InsertImprumut(idCititor, idCarte, dataImprumut, dataRestituire);
                }
                else 
                    imprumuturiTableAdapter.InsertImprumut(idCititor, idCarte, dataImprumut, null);
            }
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
                DateTime dataRezervare = DateTime.ParseExact(s[2], "MM/dd/yyyy hh/mm/ss tt", CultureInfo.InvariantCulture);
                int statusRezervare = int.Parse(s[3]);

                rezervariTableAdapter.InsertRezervare(idCititor, idCarte, dataRezervare, statusRezervare);
            }
        }

        private void IncarcaUtilizatori()
        {
            var sr = new StreamReader(respath + "utilizatori.txt");
            string line;
            string[] s;
            char[] sep = { ';' };

            while((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep);
                int tipUtlizator = int.Parse(s[0]);
                string numePrenume = s[1];
                string email = s[2];
                string parola = s[3];

                utilizatoriTableAdapter.InsertUtilizator(tipUtlizator, numePrenume, email, parola);
            }
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            var frm = new LoginLibrary();
            this.Visible = false;
            frm.ShowDialog();
            this.Close();
        }
    }
}
