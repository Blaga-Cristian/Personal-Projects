using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Turismul_de_pretutindeni
{
    public partial class FrmAdminNou : Form
    {
        static TurismDSTableAdapters.VacanteTableAdapter vtb = new TurismDSTableAdapters.VacanteTableAdapter();
        static TurismDSTableAdapters.UtilizatoriTableAdapter utb = new TurismDSTableAdapters.UtilizatoriTableAdapter();

        public FrmAdminNou()
        {
            InitializeComponent();
            IncarcaCmb();            
        }

        private void IncarcaCmb()
        {
            cmb.DataSource = null;
            cmb.Items.Clear();
            var dt = utb.GetData();
            cmb.DataSource = dt;
            cmb.DisplayMember = "Email";
            cmb.ValueMember = "IdUser";
        }

        private void btnRenunta_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnInregistreaza_Click(object sender, EventArgs e)
        {
            var frm = new FrmInregistrare();
            frm.ShowDialog();
            IncarcaCmb();
        }

        private void btnAdmin_Click(object sender, EventArgs e)
        {
            int id = (int)cmb.SelectedValue;
            utb.FaAdmin(0, id);
        }
    }
}
