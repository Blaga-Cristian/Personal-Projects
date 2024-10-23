using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PollutionMap
{
    public partial class AdaugaMasurareForm : Form
    {
        public int Poluare { get; set; }

        public AdaugaMasurareForm()
        {
            InitializeComponent();
           
        }

        private void btnAdMas_Click(object sender, EventArgs e)
        {
            Poluare = int.Parse(txtAdMas.Text);
            Close();
        }
    }
}
