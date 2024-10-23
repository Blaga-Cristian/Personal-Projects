using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Good_Food
{

    public partial class Optiuni : Form
    {
        GOOD_FOODDataSetTableAdapters.MeniuTableAdapter mta = new GOOD_FOODDataSetTableAdapters.MeniuTableAdapter();
        GOOD_FOODDataSetTableAdapters.ComenziTableAdapter cta = new GOOD_FOODDataSetTableAdapters.ComenziTableAdapter();
        GOOD_FOODDataSetTableAdapters.SubcomenziTableAdapter sta = new GOOD_FOODDataSetTableAdapters.SubcomenziTableAdapter();
        GOOD_FOODDataSetTableAdapters.ClientiTableAdapter clientita = new GOOD_FOODDataSetTableAdapters.ClientiTableAdapter();

        private string conStr = $@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\GOOD_FOOD.mdf;Integrated Security=True";
        private string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\Resurse_C#\";
        private List<Element> elements = new List<Element> ();

        private string email;
        private int kcal = 0, pret = 0;
        List<List<Element>> meniuri;
        Element[] b;
        int buget;
        DataTable dt;

        public Optiuni(string email)
        {
            this.email = email;
            InitializeComponent();
            IncarcaMeniu();
            IncarcaDgw();
        }

        private void IncarcaDgw()
        {
            meniuTableAdapter.Fill(gOOD_FOODDataSet.Meniu);

            foreach (DataGridViewColumn x in dgw.Columns)
                x.ReadOnly = true;

            var c1 = new DataGridViewTextBoxColumn();
            c1.HeaderText = "Cantitate";
            c1.Name = "Cantitate";
            c1.DefaultCellStyle.NullValue = "1";
            var c2 = new DataGridViewButtonColumn();
            c2.HeaderText = "Adauga";
            c2.Name = "Adauga";
            c2.Text = "Adauga";
            c2.UseColumnTextForButtonValue = true;

            dgw.Columns.Add(c1);
            dgw.Columns.Add(c2);

            dgw.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            dgw.AllowUserToAddRows = false;
            dgw.CellClick += CellClickHandler;
        }

        private void CellClickHandler(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex < 0 || e.ColumnIndex < 7) return;

            int ridx = e.RowIndex;
            int cidx = e.ColumnIndex;

            if (dgw.Rows[ridx].Cells[cidx - 1].Value == null)
                dgw.Rows[ridx].Cells[cidx - 1].Value = "1";

            if (int.Parse(dgw.Rows[ridx].Cells[cidx-1].Value.ToString()) < 1)
            {
                MessageBox.Show("Valoare incorecta", "", MessageBoxButtons.OK);
                return;
            }

            this.kcal += int.Parse(dgw.Rows[ridx].Cells["Cantitate"].Value.ToString()) * int.Parse(dgw.Rows[ridx].Cells[4].Value.ToString());
            this.pret += int.Parse(dgw.Rows[ridx].Cells["Cantitate"].Value.ToString()) * int.Parse(dgw.Rows[ridx].Cells[3].Value.ToString());
            txtTotalk.Text = this.kcal.ToString();
            txtPret.Text = this.pret.ToString();

            string nume = dgw.Rows[ridx].Cells[1].Value.ToString();
            int kcal = int.Parse(dgw.Rows[ridx].Cells[4].Value.ToString());
            int pret = int.Parse(dgw.Rows[ridx].Cells[3].Value.ToString());
            int cantitate = int.Parse(dgw.Rows[ridx].Cells["Cantitate"].Value.ToString());

            elements.Add(new Element(nume, kcal, pret, cantitate));
        }

        private void IncarcaMeniu()
        {
            mta.TruncateTable(0, 0, "", 0, 0, 0, 0, 0, 0);

            var sr = new StreamReader(respath + "meniu.txt");
            string line;
            string[] s;
            char[] sep = { ';' };

            line = sr.ReadLine();

            while ((line = sr.ReadLine()) != null) 
            { 
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);

                if(s.Length == 0) { continue; }

                int id_produs = int.Parse(s[0]);
                string denumire_produs = s[1];
                string descriere = s[2];
                int pret = int.Parse(s[3]);
                int kcal = int.Parse(s[4]);
                int felul = int.Parse(s[5]);

                InsertProdus(id_produs, denumire_produs, descriere, pret, kcal, felul);
            }

        }

        private void InsertProdus(int id_produs, string denumire_produs, string descriere, int pret, int kcal, int felul)
        {        
            var con = new SqlConnection(conStr);
            con.Open();
            string query = "INSERT INTO Meniu VALUES (@id_produs, @denumire_produs, @descriere, @pret, @kcal, @felul)";
            var cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@id_produs", id_produs);
            cmd.Parameters.AddWithValue("@denumire_produs", denumire_produs);
            cmd.Parameters.AddWithValue("@descriere", descriere);
            cmd.Parameters.AddWithValue("@pret", pret);
            cmd.Parameters.AddWithValue("@kcal", kcal);
            cmd.Parameters.AddWithValue("@felul", felul);
            cmd.ExecuteNonQuery();

            con.Close();
            con.Dispose();
            cmd.Dispose();
        }

        private void btnGen_Click(object sender, EventArgs e)
        {
            int ani = int.Parse(txtVarsta.Text);
            int greutate = int.Parse(txtGreutate.Text);
            int inaltime = int.Parse(txtInaltime.Text);
            int sum = ani + greutate + inaltime;
            int kcal = 0;
            if (sum < 250)
                kcal = 1800;
            else if (sum >= 250 && sum <= 275)
                kcal = 2200;
            else
                kcal = 2500;

            UpdateKcal(email, kcal);

            Label lbl = new Label();
            lbl.Text = kcal.ToString();
            lbl.AutoSize = true;
            lbl.Font = new Font(new FontFamily("Arial"), 12f);
            tlp.Controls.Clear();
            tlp.Controls.Add(lbl);
            tlp.AutoSize = true;

            txtNecesar.Text = kcal.ToString();
            txtKcalZilnice.Text = kcal.ToString();
        }

        private void btnComanda_Click(object sender, EventArgs e)
        {
            var frm = new Vizualizare(elements,2200,kcal,pret);
            this.Visible = false;
            frm.ShowDialog();
            this.Visible = true;
        }

        private void tabControl1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (tabControl1.SelectedIndex == 3)
                IncarcaGraph();
        }

        private void IncarcaGraph()
        {
            cht.ChartAreas[0].AxisX.IntervalAutoMode = System.Windows.Forms.DataVisualization.Charting.IntervalAutoMode.VariableCount;
            cht.Series[0].Points.Clear();

            var aux = elements;
            Dictionary<string, KeyValuePair<int, int>> cantitati = new Dictionary<string, KeyValuePair<int, int>>();
            foreach (var x in elements)
            {
                if(cantitati.ContainsKey(x.nume))
                    cantitati[x.nume] = new KeyValuePair<int, int>(cantitati[x.nume].Key + x.cantitate, x.kcal);
                else
                    cantitati.Add(x.nume, new KeyValuePair<int, int>(x.cantitate, x.kcal));
            }

            foreach (var x in cantitati)
                cht.Series[0].Points.AddXY(x.Key, x.Value.Key * x.Value.Value);
        }

        private void btnGenereazaMeniuri_Click(object sender, EventArgs e)
        {
            meniuri = new List<List<Element>>();
            dgwMeniuri.DataSource = null;
            dgwMeniuri.Columns.Clear();
            dgwMeniuri.Rows.Clear();

            dt = mta.GetData();
            buget = int.Parse(txtBuget.Text);

            b = new Element[3];
            Back(0, 0, 0, 0);

            var col1 = new DataGridViewTextBoxColumn();
            col1.Name = "Felul1";
            dgwMeniuri.Columns.Add(col1);
            var col2 = new DataGridViewTextBoxColumn();
            col2.Name = "Felul2";
            dgwMeniuri.Columns.Add(col2);
            var col3 = new DataGridViewTextBoxColumn();
            col3.Name = "Felul3";
            dgwMeniuri.Columns.Add(col3);
            var col4 = new DataGridViewTextBoxColumn();
            col4.Name = "Total kcal";
            dgwMeniuri.Columns.Add(col4);
            var col5 = new DataGridViewTextBoxColumn();
            col5.Name = "Pret Total";
            dgwMeniuri.Columns.Add(col5);

            var col6 = new DataGridViewButtonColumn();
            col6.Name = "Alege";
            col6.Text = "Alege";
            col6.UseColumnTextForButtonValue = true;
            dgwMeniuri.Columns.Add(col6);

            dgwMeniuri.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;

            foreach(var meniu in meniuri)
            {
                string felul1 = meniu[0].nume;
                string felul2 = meniu[1].nume;
                string felul3 = meniu[2].nume;
                int kcaltotal = meniu[0].kcal + meniu[1].kcal + meniu[2].kcal;
                int prettotal = meniu[0].pret + meniu[1].pret + meniu[2].pret;

                dgwMeniuri.Rows.Add(felul1, felul2, felul3, kcaltotal, prettotal);
            }
        }

        private void Back(int x, int ind, int ktotal, int pret)
        {
            if(x == 3)
            {
                meniuri.Add(b.ToList());
                return;
            }
            for(int i = ind; i < dt.Rows.Count; ++i)
                if(pret + (int)dt.Rows[i]["pret"] <= buget && (int)dt.Rows[i]["felul"] == x + 1)
                {
                    b[x] = new Element((string)dt.Rows[i]["denumire_produs"], (int)dt.Rows[i]["kcal"],
                        (int)dt.Rows[i]["pret"], 0);
                    Back(x + 1, i + 1, ktotal + (int)dt.Rows[i]["kcal"], pret + (int)dt.Rows[i]["pret"]);
                    b[x] = null;
                }
        }

        private void dgwMeniuri_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex < 0 || e.ColumnIndex < 5) return;

            int i = e.RowIndex;
            string id_comanda = "" + (int)cta.Count();
            int id_client = (int)clientita.GetClient(email).Rows[0]["id_client"];
            DateTime data_comanda = DateTime.Now;

            cta.Insert(id_comanda, id_client, data_comanda);

            sta.Insert(id_comanda, (int)mta.GetMeniu(meniuri[i][0].nume).Rows[0]["id_produs"], 1);
            sta.Insert(id_comanda, (int)mta.GetMeniu(meniuri[i][1].nume).Rows[0]["id_produs"], 1);
            sta.Insert(id_comanda, (int)mta.GetMeniu(meniuri[i][2].nume).Rows[0]["id_produs"], 1);

            MessageBox.Show("Comanda trimisa!");
            this.Close();
        }

        private void UpdateKcal(string email, int kcal)
        {
            var con = new SqlConnection(conStr);
            con.Open();
            string query = "UPDATE Clienti SET kcal_zilnice = @kcal WHERE email = @email";
            var cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@email", email);
            cmd.Parameters.AddWithValue("@kcal", kcal);
            cmd.ExecuteNonQuery();

            con.Close();
            con.Dispose();
            cmd.Dispose();
        }
    }
}
