using CentenarMareaUnire.CentenarDBSTableAdapters;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CentenarMareaUnire
{
    

    public partial class Centenar_Logare : Form
    {
        UtilizatoriTableAdapter utilizatoriTableAdapter = new UtilizatoriTableAdapter();
        LectiiTableAdapter lectiiTableAdapter = new LectiiTableAdapter();
        public int Id { get; set; }
        public Centenar_Logare()
        {
            InitializeComponent();
        }

        private void btnLogare_Click(object sender, EventArgs e)
        {
            string email = txtEmail.Text;
            string parola = txtParola.Text;
            if (!Valid(email, parola))
            {
                MessageBox.Show("Parola sau emai incorecte");
                txtEmail.Text = "";
                txtParola.Text = "";
                return;
            }

            var dt = utilizatoriTableAdapter.GetUtilizatorByLog(email, parola);
            Id = (int)dt.Rows[0]["IdUtilizator"];
            this.DialogResult = DialogResult.OK;
            this.Close();
        }

        private bool Valid(string email, string parola)
        {
            return (int)utilizatoriTableAdapter.Count(email, parola) == 1;
        }

        private void label3_MouseClick(object sender, MouseEventArgs e)
        {
            string email = txtEmail.Text;
            int cnt = (int)utilizatoriTableAdapter.CountByEmail(email);
            if ((int)utilizatoriTableAdapter.CountByEmail(email) == 0) return;

            var frm = new Captcha(email);
            this.Visible = false;
            frm.ShowDialog();
            this.Visible = true;
        }
    }
}
