using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Interferente_ECO
{
    public partial class DirectieRobotForm : Form
    {
        

        public Directie directie;
        public DirectieRobotForm()
        {
            InitializeComponent();
            lblChooseDirecrtion.BackColor = Color.Transparent;
        }

        
        private void btnSus_Click(object sender, EventArgs e)
        {
            directie = Directie.Sus;
            Close();
        }

        private void btnDreapta_Click(object sender, EventArgs e)
        {
            directie = Directie.Dreapta;
            Close();
        }

        private void btnJos_Click(object sender, EventArgs e)
        {
            directie = Directie.Jos;
            Close();
        }

        private void btnStanga_Click(object sender, EventArgs e)
        {
            directie = Directie.Stanga;
            Close();
        }
    }
}
