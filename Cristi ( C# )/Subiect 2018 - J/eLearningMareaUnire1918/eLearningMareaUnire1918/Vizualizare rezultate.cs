using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace eLearningMareaUnire1918
{
    public partial class Vizualizare_rezultate : Form
    {
        private List<string> elevans = new List<string>();
        private List<string> corectans = new List<string>();
        public Vizualizare_rezultate(List<string> elevans, List<string> corectans)
        {
            InitializeComponent();
            cmbAns.SelectedIndex = 0;
            this.elevans = elevans;
            this.corectans = corectans;
            for (int i = 1; i <= 9; ++i)
                cmbAns.Items.Add("Intrebarea " + i);
        }

        private void cmbAns_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(cmbAns.SelectedIndex == 0)
            {
                txtElev.Text = "";
                txtCorect.Text = "";
                return;
            }
            txtElev.Text = elevans[cmbAns.SelectedIndex - 1];  
            txtCorect.Text = corectans[cmbAns.SelectedIndex - 1];  
        }

        private void btnIesire_Click(object sender, EventArgs e)
        {
            var dr = MessageBox.Show("Sunteti sigur ca doriti sa inchideti vizualizarea rezultatelor?", "Inchidere", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (dr == DialogResult.Yes)
                this.Close();
        }
    }
}
