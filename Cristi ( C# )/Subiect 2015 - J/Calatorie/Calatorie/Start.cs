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
    public partial class Start : Form
    {
        public Start()
        {
            InitializeComponent();
        }

        private void btnAdmin_Click(object sender, EventArgs e)
        {
            if(txtParola.Text == "agentie2015")
            {
                var frm = new Meniu(1);
                this.Visible = false;
                frm.ShowDialog();
                this.Visible = true;
            }
        }

        private void btnTurist_Click(object sender, EventArgs e)
        {
            if(txtParola.Text == "oti2015")
            {
                var frm = new Meniu(0);
                this.Visible = false;
                frm.ShowDialog();
                this.Visible = true;
            }
        }
    }
}
