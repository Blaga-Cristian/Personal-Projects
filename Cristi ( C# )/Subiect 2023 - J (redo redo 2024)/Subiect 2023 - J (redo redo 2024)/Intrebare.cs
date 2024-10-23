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
    public partial class Intrebare : Form
    {
        static ItemiTableAdapter ita = new ItemiTableAdapter();
        static DataTable dt = ita.GetData();
        static Random rnd = new Random();
        int ind = rnd.Next(dt.Rows.Count);

        public Intrebare()
        {
            InitializeComponent();

            Puncte = 0;
            rtb.Text = dt.Rows[ind][1].ToString();
            rb1.Text = dt.Rows[ind][2].ToString();
            rb2.Text = dt.Rows[ind][3].ToString();
            rb3.Text = dt.Rows[ind][4].ToString();
        }

        public int Puncte { get; set; }

        private void btn_Click(object sender, EventArgs e)
        {
            if (rb1.Checked && (int)(dt.Rows[ind][5]) == 1) Puncte = (int)(dt.Rows[ind][6]);
            if (rb2.Checked && (int)(dt.Rows[ind][5]) == 2) Puncte = (int)(dt.Rows[ind][6]);
            if (rb3.Checked && (int)(dt.Rows[ind][5]) == 3) Puncte = (int)(dt.Rows[ind][6]);

            this.Close();
        }
    }
}
