using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.Design;

namespace Good_Food
{
    public partial class Vizualizare : Form
    {
        private List<Element> elements = new List<Element>();
        int kcalz, kcal, pret;

        public Vizualizare(List<Element> elements,int kcalz, int kcal, int pret)
        {
            this.elements = elements;
            this.kcal = kcal;
            this.kcalz = kcalz;
            this.pret = pret;
            InitializeComponent();
            txtKcalz.ReadOnly = true;
            txtKcal.ReadOnly = true;
            txtPret.ReadOnly = true;
            txtKcalz.Text = kcalz.ToString();
            txtKcal.Text = kcal.ToString();
            txtPret.Text = pret.ToString();
            IncarcaDgw();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Comanda a fost trimisa", "Vizualizare", MessageBoxButtons.OK, MessageBoxIcon.Information);
            this.Close();
        }

        private void IncarcaDgw()
        {
            for (int i = 0; i < 4; ++i)
                dgw.Columns.Add(new DataGridViewTextBoxColumn());

            dgw.Columns[0].HeaderText = "Nume";
            dgw.Columns[1].HeaderText = "Kcal";
            dgw.Columns[2].HeaderText = "Pret";
            dgw.Columns[3].HeaderText = "Cantitate";

            var c1 = new DataGridViewButtonColumn();
            c1.HeaderText = "Elimina";
            c1.Text = "Elimina";
            c1.UseColumnTextForButtonValue = true;

            dgw.Columns.Add(c1);
            dgw.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            dgw.AllowUserToAddRows = false;

            foreach(var x in elements)
                dgw.Rows.Add(x.nume, x.kcal, x.pret, x.cantitate);

            dgw.CellClick += CellClickHandler;
        }

        private void CellClickHandler(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex < 0 || e.ColumnIndex != 4) return;

            kcal -= int.Parse(dgw.Rows[e.RowIndex].Cells[1].Value.ToString()) * int.Parse(dgw.Rows[e.RowIndex].Cells[3].Value.ToString());
            pret -= int.Parse(dgw.Rows[e.RowIndex].Cells[2].Value.ToString()) * int.Parse(dgw.Rows[e.RowIndex].Cells[3].Value.ToString());

            dgw.Rows.RemoveAt(e.RowIndex);

            txtKcalz.Text = kcalz.ToString();
            txtKcal.Text = kcal.ToString();
            txtPret.Text = pret.ToString();
        }
    }
}
