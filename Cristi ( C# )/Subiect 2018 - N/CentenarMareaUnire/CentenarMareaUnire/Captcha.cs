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

namespace CentenarMareaUnire
{
    public partial class Captcha : Form
    {
        string conStr = $@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\CentenarDB.mdf;Integrated Security=True";
        string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\Resurse_C#\";
        UtilizatoriTableAdapter utilizatoriTableAdapter = new UtilizatoriTableAdapter();
        LectiiTableAdapter lectiiTableAdapter = new LectiiTableAdapter();

        List<string> imagini;
        List<string> oameni;
        Random rand = new Random();
        int cntoameni = 0;
        int cnt = 0;
        string email;
        PictureBox last;

        public string Parola { get; set; }

        public Captcha(string email)
        {
            this.email = email;
            InitializeComponent();
            SetLabels();
            IncarcaImagini();
        }

        private void SetLabels()
        {
            lblTitlu.Text = "Am uitat parola pentru emailul: " + email;
            lblInstructiune.Text = "Selecteaza imaginile care au oameni";
        }

        private void IncarcaImagini()
        {
            last = null;
            cnt = cntoameni = 0;
            imagini = new List<string>();
            oameni = new List<string>();
            foreach (var x in this.Controls.OfType<PictureBox>())
            {
                x.BorderStyle = BorderStyle.None;
                x.BackColor = Color.Transparent;
            }

            List<string> aux;
            aux = Directory.GetFiles(respath + $@"Captcha\").ToList();
            foreach (string s in aux)
            {
                var t = s.Split(new char[] { '\\' });
                imagini.Add(t.Last());
            }

            var sr = new StreamReader(respath + "oameni.txt");
            string line;
            while ((line = sr.ReadLine()) != null)
                oameni.Add(line);

            int ind = rand.Next() % imagini.Count;
            pb1.Image = Image.FromFile(respath + $@"Captcha\" + imagini[ind]);
            pb1.Tag = imagini[ind];
            if (EsteOm(imagini[ind])) cntoameni++;
            imagini.RemoveAt(ind);

            ind = rand.Next() % imagini.Count;
            pb2.Image = Image.FromFile(respath + $@"Captcha\" + imagini[ind]);
            pb2.Tag = imagini[ind];
            if (EsteOm(imagini[ind])) cntoameni++;
            imagini.RemoveAt(ind);

            ind = rand.Next() % imagini.Count;
            pb3.Image = Image.FromFile(respath + $@"Captcha\" + imagini[ind]);
            pb3.Tag = imagini[ind];
            if (EsteOm(imagini[ind])) cntoameni++;
            imagini.RemoveAt(ind);

            ind = rand.Next() % imagini.Count;
            pb4.Image = Image.FromFile(respath + $@"Captcha\" + imagini[ind]);
            pb4.Tag = imagini[ind];
            if (EsteOm(imagini[ind])) cntoameni++;
            imagini.RemoveAt(ind);

            ind = rand.Next() % imagini.Count;
            pb5.Image = Image.FromFile(respath + $@"Captcha\" + imagini[ind]);
            pb5.Tag = imagini[ind];
            if (EsteOm(imagini[ind])) cntoameni++;
            imagini.RemoveAt(ind);

            ind = rand.Next() % imagini.Count;
            pb6.Image = Image.FromFile(respath + $@"Captcha\" + imagini[ind]);
            pb6.Tag = imagini[ind];
            if (EsteOm(imagini[ind])) cntoameni++;
            imagini.RemoveAt(ind);

            if (cntoameni == 0 || cntoameni == 6)
                IncarcaImagini();
        }

        private void PictureClick(object sender, MouseEventArgs e)
        {
            var pb = (PictureBox)sender;
            if(last != null && last.BackColor == Color.Transparent)
                last.BorderStyle = BorderStyle.None;
            pb.BorderStyle = BorderStyle.FixedSingle;
            last = pb;
        }

        private bool EsteOm(string file)
        {
            return oameni.Any(x => x == file);
        }

        private void btnSelecteaza_Click(object sender, EventArgs e)
        {
            if (last == null) return;

            if(last.BackColor != Color.Transparent)
            {
                last.BorderStyle = BorderStyle.None;
                last.BackColor = Color.Transparent;
                last.Padding = new Padding(0);
                if (EsteOm(last.Tag.ToString())) cnt--;
                return;
            }

            last.BorderStyle = BorderStyle.FixedSingle;
            last.BackColor = Color.Blue;
            last.Padding = new Padding(10);
            if (EsteOm(last.Tag.ToString())) cnt++;
        }

        private void btnSalvare_Click(object sender, EventArgs e)
        {
            if (txtParola.Text != txtConfirmareParola.Text || cnt != cntoameni ||
                this.Controls.OfType<PictureBox>().Any(x => x.BorderStyle != BorderStyle.None && !EsteOm(x.Tag.ToString())))
            {
                MessageBox.Show("Captcha esuat");
                return;
            }

            string parola = txtParola.Text;
            utilizatoriTableAdapter.UpdateUtilizator(parola, email);
            this.Close();
        }

        private void btnAnulare_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
