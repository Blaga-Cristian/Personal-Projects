using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FirstApp
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void btnInfo_Click(object sender, EventArgs e)
        {
            DialogResult dr;
            dr = MessageBox.Show("De ce tot faci clic?", "Intrebare",
                MessageBoxButtons.YesNoCancel, MessageBoxIcon.Question);
            
            if (dr == DialogResult.Yes)
            {
                lblMessage.Text = "Ai ales butonul Yes";
            }

            if (dr == DialogResult.No)
            {
                lblMessage.Text = "Ai ales butonul No";
            }

            if (dr == DialogResult.Cancel)
            {
                lblMessage.Text = "Ai ales butonul Cancel";
            }
        }
    }
}
