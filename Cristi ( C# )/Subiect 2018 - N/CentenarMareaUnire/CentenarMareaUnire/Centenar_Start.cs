using CentenarMareaUnire.CentenarDBSTableAdapters;
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
using System.Globalization;
using System.Diagnostics.Eventing.Reader;

namespace CentenarMareaUnire
{
    public partial class Centenar_Start : Form
    {
        string conStr = $@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\CentenarDB.mdf;Integrated Security=True";
        string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\Resurse_C#\";
        UtilizatoriTableAdapter utilizatoriTableAdapter = new UtilizatoriTableAdapter();
        LectiiTableAdapter lectiiTableAdapter = new LectiiTableAdapter();
        int idUtilizator = 0;
        public Centenar_Start()
        {
            InitializeComponent();
            IncarcaUtilizatori();
            IncarcaLectii();
            var frm = new CreareLectie();
            frm.ShowDialog();
            var frm1 = new GhicesteRegiunea();
            frm1.ShowDialog();
        }

        private void IncarcaLectii()
        {
            var sr = new StreamReader(respath + "lectii.txt");
            string line;
            string[] s;
            char[] sep = { '*' };

            while ((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                if (s.Length != 5)
                {
                    int idUtilizator = int.Parse(s[0]);
                    string regiune = s[1];
                    string numeImagine = s[2];
                    DateTime dataCreare = DateTime.ParseExact(s[3], "M/d/yyyy h:mm:ss tt", CultureInfo.InvariantCulture);
                    lectiiTableAdapter.InsertLectie(idUtilizator, null, regiune, dataCreare, numeImagine);
                }
                else
                {
                    int idUtilizator = int.Parse(s[0]);
                    string titluLectie = s[1];
                    string reginune = s[2];
                    string numeImagine = s[3];
                    DateTime dataCreare = DateTime.ParseExact(s[4], $@"M/d/yyyy h:mm:ss tt", CultureInfo.InvariantCulture);
                    lectiiTableAdapter.InsertLectie(idUtilizator, titluLectie, reginune, dataCreare, numeImagine);
                }                
            }
        }

        private void IncarcaUtilizatori()
        {
            var sr = new StreamReader(respath + "utilizatori.txt");
            string line;
            string[] s;
            char[] sep = { '*' };

            while((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                string nume = s[0];
                string parola = s[1];
                string email = s[2];

                utilizatoriTableAdapter.InsertUtilizator(nume, parola, email);
            }
        }

        private void btnLectie_Click(object sender, EventArgs e)
        {
            if(idUtilizator == 0)
            {
                MessageBox.Show("Logati-va in aplicatie", "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            var frm = new VizualizareLectii(idUtilizator);
            this.Visible = false;
            frm.ShowDialog();
            this.Visible = true;

        }

        private void btnLogare_Click(object sender, EventArgs e)
        {
            var frm = new Centenar_Logare();
            this.Visible = false;
            if (frm.ShowDialog() == DialogResult.OK)
                idUtilizator = frm.Id;
            this.Visible = true;            
        }
    }
}
