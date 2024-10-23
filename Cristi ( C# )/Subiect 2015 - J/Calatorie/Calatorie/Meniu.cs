using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calatorie
{
    public partial class Meniu : Form
    {
        int tip;
        public Meniu(int tip)
        {
            this.tip = tip;
            InitializeComponent();
            if(tip == 1)btnTuristi.Enabled = false;
            else btnAdministrare.Enabled = false;
        }

        private void btnIesire_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnAdministrare_Click(object sender, EventArgs e)
        {
            var frm = new ListaCroaziere();
            this.Visible = false;
            frm.ShowDialog();
            this.Close();
        }

        private void btnTuristi_Click(object sender, EventArgs e)
        {
            var frm = new Turist();
            this.Visible = false;
            frm.ShowDialog();
            this.Close();
        }
    }
}
