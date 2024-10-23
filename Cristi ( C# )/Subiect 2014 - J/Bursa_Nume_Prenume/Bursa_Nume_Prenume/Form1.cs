using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Bursa_Nume_Prenume
{
    public partial class Start : Form
    {
        DSBursaTableAdapters.ActiuniTableAdapter ata = new DSBursaTableAdapters.ActiuniTableAdapter();


        Random rand = new Random();
        public List<Actiune> actiuni;
        Timer tmr = new Timer();
        Actiunile_mele frm1;
        Grafic_Profit frm2;

        List<int> valori;

        public Start()
        {
            InitializeComponent();
            btnInchide.Enabled = false;
        }

        private void GetData()
        {
            valori = new List<int>();
            actiuni = new List<Actiune>();
            DataTable dt = ata.GetData();
            foreach(DataRow dr in dt.Rows)
            {
                string denumire = (string)dr["Denumire"];
                int nrActiuni = (int)dr["NrActiuni"];
                int valoare = (int)dr["Valoare"];

                actiuni.Add(new Actiune(denumire, nrActiuni, valoare));
            }

            int profit = 0;
            foreach (var x in actiuni)
                profit += x.NrActiuni * x.Valoare;
            valori.Add(profit);
        }

        private void btnDeschide_Click(object sender, EventArgs e)
        {
            GetData();

            btnDeschide.Enabled = false;
            btnInchide.Enabled = true;

            tmr.Interval = (int)numericUpDown1.Value;
            tmr.Tick += UpdateBursa;
            tmr.Start();
        }

        private void UpdateBursa(object sender, EventArgs e)
        {
            foreach(Actiune x in actiuni)
                x.Valoare += rand.Next(-5, 6);


            int profit = 0;
            foreach (var x in actiuni)
                profit += x.NrActiuni * x.Valoare;
            valori.Add(profit);


            if (frm1 != null)
                frm1.Incarca(actiuni);

            if (frm2 != null)
                frm2.Incarca(valori);
        }

        private void btnInchide_Click(object sender, EventArgs e)
        {
            btnInchide.Enabled = false;
            btnDeschide.Enabled = true;

            tmr.Stop();
            tmr.Tick -= UpdateBursa;
        }

        private void actiunileMeleToolStripMenuItem_Click(object sender, EventArgs e)
        {
            frm1 = new Actiunile_mele(actiuni);
            frm1.ShowDialog();
        }

        private void graficProfitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            frm2 = new Grafic_Profit(valori);
            frm2.ShowDialog();
        }
    }
}
