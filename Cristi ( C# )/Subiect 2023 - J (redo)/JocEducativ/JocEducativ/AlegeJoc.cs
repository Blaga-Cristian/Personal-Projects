using JocEducativ.DSJocEducativTableAdapters;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace JocEducativ
{
    public partial class AlegeJoc : Form
    {
        ItemiTableAdapter ita = new ItemiTableAdapter();
        RezultateTableAdapter rta = new RezultateTableAdapter();
        UtilizatoriTableAdapter uta = new UtilizatoriTableAdapter();
        static string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\csarp\";

        string email;
        public AlegeJoc(string email)
        {
            InitializeComponent();
            this.email = email;
            IncarcaDate();
        }

        private void IncarcaDate()
        {
            DataTable dt = uta.GetDataByKey(email);
            lbl.Text = $@"Bine ai venit, {dt.Rows[0]["NumeUtilizator"]}! ({dt.Rows[0]["EmailUtilizator"]})";

            IncarcaGhiceste();
            IncarcaSarpeEducativ();
        }

        private void IncarcaSarpeEducativ()
        {
            dgwSarpeEducativ.Rows.Clear();

            DataTable dt = rta.GetRezJoc(1);
            foreach(DataRow dr in dt.Rows)
            {
                string email = (string)dr["EmailUtilizator"];
                string nume = (string)uta.GetDataByKey(email).Rows[0]["NumeUtilizator"];
                int scor = (int)dr["PunctajJoc"];

                dgwSarpeEducativ.Rows.Add(nume, email, scor);
            }
        }

        private void IncarcaGhiceste()
        {
            dgwGhiceste.Rows.Clear();

            DataTable dt = rta.GetRezJoc(0);
            foreach (DataRow dr in dt.Rows)
            {
                string email = (string)dr["EmailUtilizator"];
                string nume = (string)uta.GetDataByKey(email).Rows[0]["NumeUtilizator"];
                int scor = (int)dr["PunctajJoc"];

                dgwGhiceste.Rows.Add(nume, email, scor);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            var frm = new Ghiceste(email);
            this.Visible = false;
            frm.ShowDialog();
            this.Visible = true;

            IncarcaGhiceste();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            var frm = new SarpeEducativ(email);
            this.Visible = false;
            frm.ShowDialog();
            this.Visible = true;

            IncarcaSarpeEducativ();
        }
    }
}
