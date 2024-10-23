using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.Versioning;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Good_Food
{
    public partial class Start : Form
    {
        public Start()
        {
            InitializeComponent();
        }

        private void btnInreg_Click(object sender, EventArgs e)
        {
            var frm = new Creare_cont_client();
            this.Visible = false;
            frm.ShowDialog();
            this.Visible = true;
        }

        private void btnAuten_Click(object sender, EventArgs e)
        {
            var frm = new Autentificare_client();
            this.Visible = false;
            frm.ShowDialog();
            this.Visible = true;
        }
    }
}
