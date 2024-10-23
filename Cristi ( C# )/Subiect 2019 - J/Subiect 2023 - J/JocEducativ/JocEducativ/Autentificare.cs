using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace JocEducativ
{
    public partial class Autentificare : Form
    {
        private string conStr = $@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\JocEducativ.mdf;Integrated Security=True";
        private string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\csarp\";
        private JocEducativDBTableAdapters.UtilizatoriTableAdapter utilizatoriTableAdapter = new JocEducativDBTableAdapters.UtilizatoriTableAdapter();
        private JocEducativDBTableAdapters.RezultateTableAdapter rezultateTableAdapter = new JocEducativDBTableAdapters.RezultateTableAdapter();
        private JocEducativDBTableAdapters.ItemiTableAdapter itemiTableAdapter = new JocEducativDBTableAdapters.ItemiTableAdapter();

        public Autentificare()
        {
            InitializeComponent();
            IncarcaUtilizatori();
            IncarcaRezultate();
            IncarcaItemi();
        }

        private void IncarcaItemi()
        {
            var sr = new StreamReader(respath + "Itemi.txt");
            string line;
            string[] s;
            char[] sep = { ';' };

            while((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);

                int idItem = int.Parse(s[0]);
                string enuntItem = s[1];
                string raspuns1 = s[2];
                string raspuns2 = s[3];
                string raspuns3 = s[4];
                int raspunsCorect = int.Parse(s[5]);
                int punctajItem = int.Parse(s[6]);

                itemiTableAdapter.InsertItemiIdInsertOn(idItem, enuntItem, raspuns1, raspuns2, raspuns3, raspunsCorect, punctajItem);
            }
        }

        private void IncarcaRezultate()
        {
            var sr = new StreamReader(respath + "Rezultate.txt");
            string line;
            string[] s;
            char[] sep = { ';' };

            while ((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                int idRezultat = int.Parse(s[0]);
                int tipJoc = int.Parse(s[1]);
                string emailUtilizator = s[2];
                int punctajJoc = int.Parse(s[3]);

                rezultateTableAdapter.InsertRezultatIdInsertON(idRezultat, tipJoc, emailUtilizator, punctajJoc);
            }
        }


        private void IncarcaUtilizatori()
        {
            var sr = new StreamReader(respath + "Utilizatori.txt");
            string line;
            string[] s;
            char[] sep = { ';' };

            while((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                string emailUtilizator = s[0];
                string numeUtilizator = s[1];
                string parola = s[2];

                utilizatoriTableAdapter.InsertUtilizator(emailUtilizator, numeUtilizator, parola);
            }
        }

        private void btnLogare_Click(object sender, EventArgs e)
        {
            string emailUtilizator = txtEmail.Text;
            string parola = txtParola.Text;

            if((int)utilizatoriTableAdapter.CheckValid(emailUtilizator, parola) == 1)
            {
                var frm = new AlegeJoc(emailUtilizator);
                this.Visible = false;
                frm.ShowDialog();
                this.Close();
            }
            else
            {
                MessageBox.Show("Date de autentificare incorecte!", "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);
                txtEmail.Clear();
                txtParola.Clear();
            }
        }
    }
}
