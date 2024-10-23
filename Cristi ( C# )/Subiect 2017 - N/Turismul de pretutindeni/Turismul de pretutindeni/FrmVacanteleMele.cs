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
    public partial class FrmVacanteleMele : Form
    {
        TurismDSTableAdapters.RezervariTableAdapter rtb = new TurismDSTableAdapters.RezervariTableAdapter();
        TurismDSTableAdapters.VacanteTableAdapter vtb = new TurismDSTableAdapters.VacanteTableAdapter();
        TurismDSTableAdapters.UtilizatoriTableAdapter utb = new TurismDSTableAdapters.UtilizatoriTableAdapter();

        string email;
        public FrmVacanteleMele(string email)
        {
            this.email = email;
            InitializeComponent();
            IncarcaDgw();
        }

        private void IncarcaDgw()
        {
            dgw.Rows.Clear();
            dgw.Columns.Clear();

            var col1 = new DataGridViewTextBoxColumn();
            col1.Name = "Vacanta";
            dgw.Columns.Add(col1);
            var col2 = new DataGridViewTextBoxColumn();
            col2.Name = "Data Inceput";
            dgw.Columns.Add(col2);
            var col3 = new DataGridViewTextBoxColumn();
            col3.Name = "Data Final";
            dgw.Columns.Add(col3);
            var col4 = new DataGridViewTextBoxColumn();
            col4.Name = "NrPersoane";
            dgw.Columns.Add(col4);
            var col5 = new DataGridViewTextBoxColumn();
            col5.Name = "Pret total";
            dgw.Columns.Add(col5);

            var btn = new DataGridViewButtonColumn();
            btn.Name = "Sterge";
            btn.Text = "Sterge";
            btn.UseColumnTextForButtonValue = true;
            dgw.Columns.Add(btn);

            dgw.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;

            int idUser = (int)utb.GetUtilizator(email).Rows[0]["IdUser"];
            var dt = rtb.GetRezervari(idUser);

            foreach(DataRow row in dt.Rows)
            {
                string vacanta = (string)vtb.GetVacanta((int)row["IdVacanta"]).Rows[0]["NumeVacanta"];
                DateTime dataInceput = (DateTime)row["DataInceput"];
                DateTime dataFinal = (DateTime)row["DataSfarsit"];
                int nrPersoane = (int)row["NrPersoane"];
                float pretTotal = (float)row["PretTotal"];

                dgw.Rows.Add(vacanta, dataInceput, dataFinal, nrPersoane, pretTotal);
            }
        }

        private void dgw_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex < 0 || e.ColumnIndex < 5) return;

            int idVacanta = (int)vtb.GetVacantaNume((string)dgw.Rows[e.RowIndex].Cells["Vacanta"].Value).Rows[0]["IdVacanta"];
            int idUser = (int)utb.GetUtilizator(email).Rows[0]["IdUser"];
            DateTime dataInceput = (DateTime)dgw.Rows[e.RowIndex].Cells["Data Inceput"].Value;
            DateTime dataSfarsit = (DateTime)dgw.Rows[e.RowIndex].Cells["Data Final"].Value;
            int nrPersoane = (int)dgw.Rows[e.RowIndex].Cells["NrPersoane"].Value;
            float pret = (float)dgw.Rows[e.RowIndex].Cells["Pret total"].Value;

            rtb.DeleteRezervare(idVacanta, idUser, dataInceput, dataSfarsit, nrPersoane, pret);

            IncarcaDgw();
        }
    }
}
