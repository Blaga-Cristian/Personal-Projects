using Subiect_2023___J__redo_redo_2024_.DSJocEducativTableAdapters;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Subiect_2023___J__redo_redo_2024_
{
    public partial class AlegeJoc : Form
    {

        UtilizatoriTableAdapter uta = new UtilizatoriTableAdapter();
        ItemiTableAdapter ita = new ItemiTableAdapter();
        RezulateTableAdapter rta = new RezulateTableAdapter();

        string email;
        public AlegeJoc(string email)
        {
            InitializeComponent();
            this.email = email;
            LoadLabel();
            LoadGhiceste();
            LoadSarpeEducativ();
        }

        void LoadLabel()
        {
            DataTable dt = uta.GetUtilizatorByEmail(email);
            string numeUtilizator = dt.Rows[0][1].ToString();
            string emailUtilizator = dt.Rows[0][0].ToString();
            lbl.Text = $@"Bine ai venit, {numeUtilizator}!, ({emailUtilizator})";
        }

        void LoadGhiceste()
        {
            dgwGhiceste.Rows.Clear();

            DataTable dt = rta.GetBest(0);

            for(int i = 0; i < 3; ++i)
            {
                string numeUtilizator = uta.GetUtilizatorByEmail(dt.Rows[i][2].ToString()).Rows[0][1].ToString();
                string emailUtilizator = dt.Rows[i][2].ToString();
                int punctajJoc = (int)dt.Rows[i][3];

                dgwGhiceste.Rows.Add(numeUtilizator, emailUtilizator, punctajJoc);
            }
        }

        void LoadSarpeEducativ()
        {
            dgwSarpeEducativ.Rows.Clear();

            DataTable dt = rta.GetBest(1);

            for (int i = 0; i < 3; ++i)
            {
                string numeUtilizator = uta.GetUtilizatorByEmail(dt.Rows[i][2].ToString()).Rows[0][1].ToString();
                string emailUtilizator = dt.Rows[i][2].ToString();
                int punctajJoc = (int)dt.Rows[i][3];

                dgwSarpeEducativ.Rows.Add(numeUtilizator, emailUtilizator, punctajJoc);
            }
        }

        private void btnGhiceste_Click(object sender, EventArgs e)
        {
            Ghiceste frm = new Ghiceste(email);
            this.Visible = false;
            frm.ShowDialog();
            this.Visible = true;
            LoadGhiceste();
        }

        private void btnSarpeEducativ_Click(object sender, EventArgs e)
        {
            Sarpe frm = new Sarpe(email);
            this.Visible = false;
            frm.ShowDialog();
            this.Visible = true;
            LoadSarpeEducativ();
        }
    }
}
