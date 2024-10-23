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
    public partial class Actiunile_mele : Form
    {
        DSBursaTableAdapters.ActiuniTableAdapter ata = new DSBursaTableAdapters.ActiuniTableAdapter();

        List<Actiune> actiuni;
        List<Actiune> actiuniInitiale;
        int profit;

        public Actiunile_mele(List<Actiune> actiuni)
        {
            this.actiuni = actiuni;
            InitializeComponent();
            GetData();
            FillDgw();
        }

        public void Incarca(List<Actiune> actiuni)
        {
            this.actiuni = actiuni;
            FillDgw();
        }

        private void FillDgw()
        {
            dgw.Rows.Clear();

            profit = 0;

            for (int i = 0; i < actiuni.Count; ++i)
            {
                dgw.Rows.Add(actiuniInitiale[i].Denumire, actiuniInitiale[i].NrActiuni,
                    actiuniInitiale[i].Valoare, actiuni[i].Valoare, actiuni[i].Valoare - actiuniInitiale[i].Valoare,
                    actiuniInitiale[i].Valoare * actiuniInitiale[i].NrActiuni,
                    actiuni[i].Valoare * actiuni[i].NrActiuni,
                    actiuni[i].NrActiuni * (actiuni[i].Valoare - actiuniInitiale[i].Valoare),
                    actiuni[i].Valoare * actiuni[i].NrActiuni - actiuniInitiale[i].Valoare * actiuniInitiale[i].NrActiuni);

                profit += actiuni[i].Valoare * actiuni[i].NrActiuni - actiuniInitiale[i].Valoare * actiuniInitiale[i].NrActiuni;
            }

            txtProfit.Text = "" + profit;
        }

        private void GetData()
        {
            actiuniInitiale = new List<Actiune>();

            DataTable dt = ata.GetData();
            foreach (DataRow dr in dt.Rows)
                actiuniInitiale.Add(new Actiune((string)dr["Denumire"],
                    (int)dr["NrActiuni"], (int)dr["Valoare"]));
        }
    }
}
