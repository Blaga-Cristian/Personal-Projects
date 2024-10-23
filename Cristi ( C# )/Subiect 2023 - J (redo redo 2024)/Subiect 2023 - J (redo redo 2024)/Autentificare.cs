using Subiect_2023___J__redo_redo_2024_.DSJocEducativTableAdapters;
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

namespace Subiect_2023___J__redo_redo_2024_
{
    public partial class Autentificare : Form
    {
        UtilizatoriTableAdapter uta = new UtilizatoriTableAdapter();
        ItemiTableAdapter ita = new ItemiTableAdapter();
        RezulateTableAdapter rta = new RezulateTableAdapter();

        string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\csarp\csarp\";
        public Autentificare()
        {
            InitializeComponent();
            LoadData();
        }

        void LoadData()
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

                uta.InsertUtilizator(emailUtilizator, numeUtilizator, parola);
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

            sr = new StreamReader(respath + "Itemi.txt");

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
        }

        private void btnLogare_Click(object sender, EventArgs e)
        {
            string email = txtEmail.Text;
            string parola = txtParola.Text;

            DataTable dt = uta.GetUtilizator(email, parola);

            if (dt.Rows.Count > 0)
            {
                AlegeJoc frm = new AlegeJoc(email);
                this.Visible = false;
                frm.ShowDialog();
                this.Visible = true;
            }
            else
            {
                MessageBox.Show("Date de autentificare invalide!", "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);
                txtEmail.Clear();
                txtParola.Clear();
            }
        }
    }
}
