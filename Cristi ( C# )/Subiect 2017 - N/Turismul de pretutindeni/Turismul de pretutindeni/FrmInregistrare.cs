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

namespace Turismul_de_pretutindeni
{
    public partial class FrmInregistrare : Form
    {
        string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\clasa_c#_oti_2017_resurse\Resurse\";

        TurismDSTableAdapters.VacanteTableAdapter vtb = new TurismDSTableAdapters.VacanteTableAdapter();
        TurismDSTableAdapters.UtilizatoriTableAdapter utb = new TurismDSTableAdapters.UtilizatoriTableAdapter();
        string rcaptcha;
        string[] files;
        Random rand = new Random();

        public FrmInregistrare()
        {
            InitializeComponent();
            files = Directory.GetFiles(respath + $@"Logare\");
            IncarcaCaptcha();
        }

        private void IncarcaCaptcha()
        {
            int ind = rand.Next(files.Length);
            string path = files[ind];
            string[] s = path.Split('\\', '.');
            rcaptcha = s[s.Length - 2];
            pbCaptcha.Image = Image.FromFile(path);
        }

        private void btnInregistrare_Click(object sender, EventArgs e)
        {
            string nume = txtNume.Text;
            string prenume = txtPrenume.Text;
            string email = txtEmail.Text;
            string parola = txtParola.Text;
            string captcha = txtCaptcha.Text;

            if(!Valid(email))
            {
                MessageBox.Show("Email invalid!");
                return;
            }
            if(parola.Length < 3)
            {
                MessageBox.Show("Parola este prea scurta");
                return;
            }
            if(parola != txtConfirmareParola.Text)
            {
                MessageBox.Show("Parolelel nu coincid");
                return;
            }
            if(rcaptcha != captcha)
            {
                MessageBox.Show("Captcha esuat");
                return;
            }

            utb.InsertUtilizatori(nume, prenume, email, parola, 1);
            this.Close();
        }

        private bool Valid(string email)
        {
            try
            {
                new MailAddress(email);
                return utb.CountByEmail(email) == 0;
            }
            catch { return false; }
        }

        private void btnRenunta_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
