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

namespace PollutionMap
{
    public partial class Form1 : Form
    {
        DSPoluareTableAdapters.HartiTableAdapter hta = new DSPoluareTableAdapters.HartiTableAdapter();
        DSPoluareTableAdapters.MasurareTableAdapter mta = new DSPoluareTableAdapters.MasurareTableAdapter();
        DSPoluareTableAdapters.UtilizatoriTableAdapter uta = new DSPoluareTableAdapters.UtilizatoriTableAdapter();
        string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\OJTI_2022_C#_Resurse\";

        public Form1()
        {
            InitializeComponent();
            IncarcaHarti();
            IncarcaMasurari();
        }

        private void IncarcaMasurari()
        {
            {
                var sr = new StreamReader(respath + "masurari.txt");
                string line;
                string[] s;
                char[] sep = { '#' };

                while ((line = sr.ReadLine()) != null)
                {
                    s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);

                    int idHarta = (int)hta.GetDataByNume(s[0]).Rows[0]["IdHarta"];
                    int pozitieX = int.Parse(s[1]);
                    int pozitieY = int.Parse(s[2]);
                    int valoareMasurare = int.Parse(s[3]);
                    DateTime dataMasurare = DateTime.ParseExact(s[4], "dd/MM/yyyy HH:mm", System.Globalization.CultureInfo.CurrentCulture);

                    mta.Insert(idHarta, pozitieX, pozitieY, valoareMasurare, dataMasurare);
                }
            }
        }

        private void IncarcaHarti()
        {
            var sr = new StreamReader(respath + "harti.txt");
            string line;
            string[] s;
            char[] sep = { '#' };

            while((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);

                string numeHarta = s[0];
                string fisierHarta = s[1];

                hta.Insert(numeHarta, fisierHarta);
            }
        }

        private void btnLogare_Click(object sender, EventArgs e)
        {
            string nume = txtNume.Text;
            string parola = txtParola.Text;
            if(uta.GetDataByNumeParola(nume, parola).Rows.Count != 1)
            {
                MessageBox.Show(" Nume de utilizator si/ sau parola invalida! ");
                txtNume.Text = txtParola.Text = "";
                return;
            }

            uta.UpdateData(DateTime.Now, nume);

            var frm = new Vizualizare(nume);
            this.Visible = false;
            frm.ShowDialog();
            this.Close();
        }

        private void btnContNou_Click(object sender, EventArgs e)
        {
            var frm = new Inregistrare();
            this.Visible = false;
            frm.ShowDialog();
            this.Visible = true;
        }
    }
}
