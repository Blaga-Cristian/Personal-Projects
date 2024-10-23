using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Runtime.CompilerServices;

namespace AplicatieFreeBook
{
    public partial class MeniuFreeBookForm : Form
    {
        string connStr = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\FreeBook.mdf;Integrated Security = True; Connect Timeout = 30";
        private List<Carte> carti = new List<Carte>();
        private List<Carte> cartidisponibile = new List<Carte>();
        private List<Carte> cartiINdisponibile = new List<Carte>();
        private DateTime today = DateTime.Now;
        private string email;
        private List<Row> rows = new List<Row>();
        private Dictionary<string,int> value = new Dictionary<string,int>();
        private List<DateTime> imprumuturi = new List<DateTime>();
        private SortedDictionary<int, int> imprumutID = new SortedDictionary<int, int>();
        private List<KeyValuePair<string,int>> kvpl = new List<KeyValuePair<string,int>>();

        int cartiActive = 0;

        public MeniuFreeBookForm(string email)
        {
            InitializeComponent();

            this.email = email;
            lblEmail.Text = "Email: " + email;
            PopuleazaDgw();
            dgwImprumuturi.AllowUserToAddRows = false;

            cmbAn.SelectedIndex = 0;
            foreach (var m in System.Globalization.CultureInfo.CurrentCulture.DateTimeFormat.MonthGenitiveNames)
                value[m] = 0;
            GetImprumuturi();
            PopuleazaCmb();
            BuildChartPie();

            PopuleazaDgwImprumuturi();
        }

        private void BuildChartPie()
        {
            kvpl.Clear();
            GetImprumuturi();
            foreach (var i in imprumutID)
                kvpl.Add(new KeyValuePair<string, int>(carti[i.Key - 1].Titlu, i.Value));
            kvpl.Sort((a, b) => -a.Value.CompareTo(b.Value));

            chtPie.Series["Series1"].Points.AddXY(kvpl[0].Key, kvpl[0].Value);
            chtPie.Series["Series1"].Points.AddXY(kvpl[1].Key, kvpl[1].Value);
            chtPie.Series["Series1"].Points.AddXY(kvpl[2].Key, kvpl[2].Value);
            chtPie.Series["Series1"].Points.AddXY(kvpl[3].Key, kvpl[3].Value);

            chtPie.Series["Series1"].Points[0].LegendText = kvpl[0].Key;
            chtPie.Series["Series1"].Points[1].LegendText = kvpl[1].Key;
            chtPie.Series["Series1"].Points[2].LegendText = kvpl[2].Key;
            chtPie.Series["Series1"].Points[3].LegendText = kvpl[3].Key;

            chtPie.Series["Series1"].Points[0].Label = kvpl[0].Value.ToString();
            chtPie.Series["Series1"].Points[1].Label = kvpl[1].Value.ToString();
            chtPie.Series["Series1"].Points[2].Label = kvpl[2].Value.ToString();
            chtPie.Series["Series1"].Points[3].Label = kvpl[3].Value.ToString();
        }

        private void PopuleazaCmb()
        {
            Dictionary<int,int> anivalizi = new Dictionary<int,int>();
            foreach (var x in imprumuturi)
                anivalizi[x.Year] = 1;

            foreach (var i in anivalizi)
                if(i.Value == 1)
                    cmbAn.Items.Add(i.Key.ToString());
        }

        private void GetImprumuturi()
        {
            SqlConnection con = new SqlConnection(connStr);
            con.Open();
            string query = "SELECT * FROM imprumut";
            var cmd = new SqlCommand(query, con);
            var rd = cmd.ExecuteReader();

            while (rd.Read())
            {
                int id = (int)rd[1];
                try
                {
                    imprumutID.Add(id, 1);
                }
                catch
                {
                    imprumutID[id]++;
                }
                imprumuturi.Add((DateTime)rd[3]);
            }
        }

        private void PopuleazaDgwImprumuturi()
        {
            rows.Clear();
            dgwImprumuturi.Rows.Clear();
            cartiActive = 0;

            SqlConnection con = new SqlConnection(connStr);
            con.Open();
            string query = "SELECT * FROM imprumut WHERE email = @email";
            SqlCommand cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@email", email);
            var sr = cmd.ExecuteReader();
            int idx = 0;
            while (sr.Read())
            {
                idx++;
                DateTime dt = (DateTime)sr[3];
                int id = (int)sr[1];
                var dif = today - dt;
                var titlu = carti[id - 1].Titlu;
                var limit = dt;
                limit = limit.AddDays(30);
                rows.Add(new Row(id, titlu, carti[id-1].Autor, dt, limit));
            }

            for (int i = rows.Count - 1; i >= 0; --i)
            {
                var r = rows[i];
                dgwImprumuturi.Rows.Add(rows.Count - i, r.Titlu, r.Nume_Autor, r.Dataimprumut, r.Datadisponibil);
                if (r.Datadisponibil < DateTime.Now)
                    dgwImprumuturi.Rows[rows.Count - i - 1].DefaultCellStyle.BackColor = Color.Red;
                else
                {
                    dgwImprumuturi.Rows[rows.Count - i - 1].DefaultCellStyle.BackColor = Color.Green;
                    cartiActive++;
                }
            }

            bookCount.Text = "Disponibilitate imprumutri " + cartiActive + "/3";

            Bitmap bp = new Bitmap(pbLoader.Width, pbLoader.Height);
            var g = Graphics.FromImage(bp);
            g.FillRectangle(Brushes.Gray, new Rectangle(0, 0, bp.Size.Width, bp.Size.Height));
            g.FillRectangle(Brushes.Green, new Rectangle(0, 0, bp.Size.Width / 3 * cartiActive, bp.Size.Height));
            pbLoader.Image = bp;
        }

        private void PopuleazaDgw()
        {
            SqlConnection con = new SqlConnection(connStr);
            con.Open();
            string query = "SELECT * FROM carti";
            SqlCommand cmd = new SqlCommand(query, con);
            var sr = cmd.ExecuteReader();
            while (sr.Read()) 
                carti.Add(new Carte((int)sr[0],(string)sr[1], (string)sr[2], (string)sr[3]));

            sr.Close();
            query = "SELECT * FROM imprumut";
            cmd = new SqlCommand (query, con);
            sr = cmd.ExecuteReader();
            while (sr.Read())
            {
                DateTime dt = (DateTime)sr[3];
                var dif = today - dt;
                if (dif.TotalDays < 30)
                    cartiINdisponibile.Add(carti[(int)sr[1] - 1]);
            }

            cartidisponibile = new List<Carte>();

            foreach(var c in carti)
            {
                bool ok = true;
                foreach(var c2 in cartiINdisponibile)
                {
                    if(c == c2)
                    { 
                        ok = false;
                        break;
                    }
                }

                if (ok)
                    cartidisponibile.Add(c);
            }

            dgw.DataSource = cartidisponibile;
            DataGridViewButtonColumn bc = new DataGridViewButtonColumn();
            bc.Name = "Imprumuta";
            bc.Text = "Imprumuta";
            dgw.Columns.Add(bc);

            dgw.CellClick += new DataGridViewCellEventHandler(CellClickHandler);
        }

        private void CellClickHandler(object sender, DataGridViewCellEventArgs e)
        {

        }

        private int GetIdCarte(string titlu)
        {
            SqlConnection con = new SqlConnection(connStr);
            con.Open();
            string query = "SELECT Id_carte FROM carti WHERE titlu = @titlu";
            SqlCommand cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@titlu", titlu);
            var cr = cmd.ExecuteReader();
            cr.Read();
            int id = (int)cr[0];
            return id;
        }


        private void dgwImprumuturi_MouseClick(object sender, MouseEventArgs e)
        {
            if (dgwImprumuturi.SelectedCells.Count == 0) return;

            string titlu = dgwImprumuturi[1, dgwImprumuturi.SelectedCells[0].RowIndex].Value.ToString();
            var frm = new AfiseazaCarte(titlu);
            this.Visible = false;
            frm.ShowDialog();
            this.Visible = true;
        }

        private void cmbAn_SelectedIndexChanged(object sender, EventArgs e)
        {

            chtNumarU.Series["Numar de utilizatori"].Points.Clear();

            if (cmbAn.SelectedIndex == 0) return;

            foreach (var m in System.Globalization.CultureInfo.CurrentCulture.DateTimeFormat.MonthGenitiveNames)
                value[m] = 0;

            foreach (var i in imprumuturi)
            {
                int an = int.Parse(cmbAn.SelectedItem.ToString());
                if (i.Year == an)
                {
                    string month = i.ToString("MMMM");
                    value[month] = value[month] + 1;
                }
            }

            foreach (var i in value)
            {
                if (i.Key == "") continue;
                string month = i.Key.Substring(0, 3);
                chtNumarU.Series["Numar de utilizatori"].Points.AddXY(month, i.Value);
            }

            chtNumarU.ChartAreas[0].AxisX.IntervalAutoMode = System.Windows.Forms.DataVisualization.Charting.IntervalAutoMode.VariableCount;

            chtNumarU.Series["Numar de utilizatori"].LabelBackColor = Color.White;
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            var dr = MessageBox.Show("Sunteti sigura ca vreti sa inchideti aplicatia?","Inchidere",MessageBoxButtons.YesNo,MessageBoxIcon.Question);
            if (dr == DialogResult.Yes)
                this.Close();
        }

        private void dgwImprumuturi_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if (dgwImprumuturi.SelectedCells.Count == 0) return;

            string titlu = dgwImprumuturi[1, dgwImprumuturi.SelectedCells[0].RowIndex].Value.ToString();
            var frm = new AfiseazaCarte(titlu);
            this.Visible = false;
            frm.ShowDialog();
            this.Visible = true;
        }
    }
}
