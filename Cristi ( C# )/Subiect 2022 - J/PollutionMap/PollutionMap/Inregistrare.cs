using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net.Mail;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PollutionMap
{
    public partial class Inregistrare : Form
    {
        DSPoluareTableAdapters.HartiTableAdapter hta = new DSPoluareTableAdapters.HartiTableAdapter();
        DSPoluareTableAdapters.MasurareTableAdapter mta = new DSPoluareTableAdapters.MasurareTableAdapter();
        DSPoluareTableAdapters.UtilizatoriTableAdapter uta = new DSPoluareTableAdapters.UtilizatoriTableAdapter();
        string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\OJTI_2022_C#_Resurse\";



        public Inregistrare()
        {
            InitializeComponent();
        }

        private void btnRenunta_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnSalveaza_Click(object sender, EventArgs e)
        {
            string numeUtilizator = txtNumeUtilizator.Text;
            string parola = txtParola.Text;
            string email = txtEmail.Text;

            if(uta.GetDataByNume(numeUtilizator).Rows.Count != 0 || numeUtilizator.Length <= 4)
            {
                MessageBox.Show("Nume Incorect");
                return;
            }
            if(parola != txtCOnfirmareParola.Text || parola.Length <= 6)
            {
                MessageBox.Show("Parola incorecta");
                return;
            }
            if(!Valid(email))
            {
                MessageBox.Show("Email incorect");
                return;
            }

            uta.Insert(numeUtilizator, parola, email, null);

            this.Close();
        }

        private bool Valid(string email)
        {
            try
            {
                new MailAddress(email);
                return true;
            }
            catch
            {
                return false;
            }
        }
    }
}
