using AplicatieBiblioteca.BibliotecaDBTableAdapters;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AplicatieBiblioteca
{
    public partial class LogareBiblioteca : Form
    {
        UtilizatoriTableAdapter utilizatoriTableAdapter = new UtilizatoriTableAdapter();

        public LogareBiblioteca()
        {
            InitializeComponent();
        }

        private void btnLogare_Click(object sender, EventArgs e)
        {
            if (txtEmail.Text == "" || txtParola.Text == "" || !Valid(txtEmail.Text, txtParola.Text))
            {
                MessageBox.Show("Email si/sau parila invalida!", "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            //txtEmail.Text = "tutor@gmail.com";
            var frm = new BibliotecarBiblioteca(txtEmail.Text);
            this.Visible = false;
            frm.ShowDialog();
            this.Close();
        }

        private bool Valid(string email, string parola)
        {
            char[] p = parola.ToCharArray();
            for(int i = 0; i < p.Length; ++i)
            {
                if (p[i] >= 'a' && p[i] <= 'z')
                {
                    p[i]++;
                    if (p[i] > 'z') p[i] = 'a';
                }
                if (p[i] >= 'A' && p[i] <= 'Z')
                {
                    p[i]--;
                    if (p[i] < 'A') p[i] = 'Z';
                }
                if (p[i] >= '0' && p[i] <= '9')
                {
                    int x = p[i] - '0';
                    x = 9 - x;
                    p[i] = (char)('0' + x);
                }
            }

            parola = new string(p);


            return utilizatoriTableAdapter.CountValid(email, parola) == 1;
        }

        private void btnRenunta_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
