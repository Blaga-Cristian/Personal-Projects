using JocEducativ.DSJocEducativTableAdapters;
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

namespace JocEducativ
{
    public partial class Autentificare : Form
    {
        ItemiTableAdapter ita = new ItemiTableAdapter();
        RezultateTableAdapter rta = new RezultateTableAdapter();
        UtilizatoriTableAdapter uta = new UtilizatoriTableAdapter();
        static string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\csarp\";

        public Autentificare()
        {
            InitializeComponent();
            IncarcaDate();
        }

        private void IncarcaDate()
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
                string raspun1 = s[2];
                string raspun2 = s[3];
                string raspun3 = s[4];
                int raspunsCorect = int.Parse(s[5]);
                int punctajItem = int.Parse(s[6]);

                ita.InsertItem(idItem, enuntItem, raspun1, raspun2, raspun3, raspunsCorect, punctajItem);
            }

            sr = new StreamReader(respath + "Utilizatori.txt");

            while((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);

                string emailUtilizator = s[0];
                string numeUtilizator = s[1];
                string parola = s[2];

                uta.Insert(emailUtilizator, numeUtilizator, parola);
            }

            sr = new StreamReader(respath + "Rezultate.txt");

            while((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);

                int idRezultat = int.Parse(s[0]);
                int tipJoc = int.Parse(s[1]);
                string emailUtilizator = s[2];
                int punctajJoc = int.Parse(s[3]);

                rta.InsertRezultat(idRezultat, tipJoc, emailUtilizator, punctajJoc);
            }
        }

        private void btnLogare_Click(object sender, EventArgs e)
        {
            string email = txtEmail.Text;
            string parola = txtParola.Text;

            DataTable dt = uta.GetDataByKey(email);

            if(dt.Rows.Count != 1 || (string)dt.Rows[0]["Parola"] != parola)
            {
                MessageBox.Show("Date de logare incorecte!", "Eroare", MessageBoxButtons.OK);
                txtEmail.Text = txtParola.Text = "";
                return;
            }

            var frm = new AlegeJoc(email);
            this.Visible = false;
            frm.ShowDialog();
            this.Visible = true;
        }
    }
}
