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

namespace Turismul_de_pretutindeni
{
    public partial class FrmStart : Form
    {
        string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\clasa_c#_oti_2017_resurse\Resurse\";
        TurismDSTableAdapters.VacanteTableAdapter vtb = new TurismDSTableAdapters.VacanteTableAdapter();
        TurismDSTableAdapters.UtilizatoriTableAdapter utb = new TurismDSTableAdapters.UtilizatoriTableAdapter();
        public FrmStart()
        {
            InitializeComponent();
            IncarcaDate();
            IncarcaDefault();
        }

        private void IncarcaDefault()
        {
            if (Properties.Settings.Default.email != null)
                txtEmail.Text = Properties.Settings.Default.email;
        }

        private void IncarcaDate()
        {
            var sr = new StreamReader(respath + "Vacante.txt");
            string line;
            string[] s;
            char[] sep = { '|' };

            while ((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                string numeVacanta = s[0];
                string descriere = s[1];
                string caleFisier;

                try
                {
                    caleFisier = Directory.GetFiles(respath + $@"Imagini\", $@"{numeVacanta}.*")[0];
                }
                catch
                {
                    caleFisier = respath + $@"Imagini\" + "implicit.jpg";
                }

                float pret = float.Parse(s[2]);
                int nrLocuri = int.Parse(s[3]);

                vtb.InsertVacanta(numeVacanta, descriere, caleFisier, pret, nrLocuri);
            }
        }

        private void btnAutentificare_Click(object sender, EventArgs e)
        {
            string email = txtEmail.Text;
            string parola = txtParola.Text;
            if (!Valid(email, parola))
            {
                MessageBox.Show("Eroare de autetificare!");
                txtEmail.Text = "";
                txtParola.Text = "";
                return;
            }

            if (chk.Checked == true)
            {
                Properties.Settings.Default.email = email;
                Properties.Settings.Default.Save();
            }

            var frm = new FrmVacanta(email);
            this.Visible = false;
            frm.ShowDialog();
            if (frm.Exited) return;
            this.Visible = true;

        }

        private bool Valid(string email, string parola)
        {
            return utb.Count(email, parola) != 0;
        }

        private void btnInregistrare_Click(object sender, EventArgs e)
        {
            var frm = new FrmInregistrare();
            this.Visible = false;
            frm.ShowDialog();
            this.Visible = true;
        }
    }
}
