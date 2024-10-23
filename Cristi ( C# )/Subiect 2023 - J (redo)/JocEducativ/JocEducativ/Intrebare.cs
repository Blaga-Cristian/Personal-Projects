using JocEducativ.DSJocEducativTableAdapters;
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

namespace JocEducativ
{
    public partial class Intrebare : Form
    {
        ItemiTableAdapter ita = new ItemiTableAdapter();
        RezultateTableAdapter rta = new RezultateTableAdapter();
        UtilizatoriTableAdapter uta = new UtilizatoriTableAdapter();
        static string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\csarp\";



        int puncte = 0;
        public int PuncteExtra { get { return puncte; } set { puncte = value; } }
        int raspuns;
        int posibilpunctaj;
        Random rand = new Random();

        public Intrebare()
        {
            InitializeComponent();
            IncarcaIntrebare();
        }

        private void IncarcaIntrebare()
        {
            int id = rand.Next(1, ita.GetData().Rows.Count + 1);
            DataTable dt = ita.GetDataById(id);

            rtb.Text = (string)dt.Rows[0]["EnuntItem"];
            rb1.Text = (string)dt.Rows[0]["Raspuns1"];
            rb2.Text = (string)dt.Rows[0]["Raspuns2"];
            rb3.Text = (string)dt.Rows[0]["Raspuns3"];
            raspuns = (int)dt.Rows[0]["RaspunsCorect"];
            posibilpunctaj = (int)dt.Rows[0]["PunctajItem"];
        }

        private void btnInregistreaza_Click(object sender, EventArgs e)
        {
            if (rb1.Checked && raspuns == 1)
                PuncteExtra = posibilpunctaj;
            else if (rb2.Checked && raspuns == 2)
                PuncteExtra = posibilpunctaj;
            else if (rb3.Checked && raspuns == 3)
                PuncteExtra = posibilpunctaj;

            this.Close();
        }
    }
}
