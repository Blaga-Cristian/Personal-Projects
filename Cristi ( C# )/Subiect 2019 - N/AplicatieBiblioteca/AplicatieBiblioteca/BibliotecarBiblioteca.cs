using AplicatieBiblioteca.BibliotecaDBTableAdapters;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net.Mail;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Text.RegularExpressions;
using System.Data.SqlClient;
using System.Data.OleDb;

namespace AplicatieBiblioteca
{
    public partial class BibliotecarBiblioteca : Form
    {
        UtilizatoriTableAdapter utilizatoriTableAdapter = new UtilizatoriTableAdapter();
        RezervariTableAdapter rezervariTableAdapter = new RezervariTableAdapter();
        Imprumuturi1TableAdapter imprumuturiTableAdapter = new Imprumuturi1TableAdapter();
        CartiTableAdapter cartiTableAdapter = new CartiTableAdapter();
        string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\ONTI_C#_2019_resurse\";
        string email;
        List<Cititor> cititori = new List<Cititor>();
        bool enabledCititor = false;
        int idCititor;
        int cartiImprumutate = 0;
        int cartiRezervate = 0;
        int nrp;
        List<Item> itemi;
        Item[] b;
        List<List<Item>> optiuni;

        public object Valid { get; private set; }

        public BibliotecarBiblioteca(string email)
        {
            this.email = email;
            InitializeComponent();
            IncarcaDate();
        }

        private void IncarcaDgw()
        {
            dgw.DataSource = null;
            dgw.Rows.Clear();
            dgw.Columns.Clear();
            cititori.Clear();

            DataTable dt = utilizatoriTableAdapter.GetCititori();
            DataTableReader rd = new DataTableReader(dt);

            while (rd.Read())
                cititori.Add(new Cititor((int)rd[0], (string)rd[2], (string)rd[3]));

            dgw.DataSource = cititori.ToArray();


            var col = new DataGridViewButtonColumn();
            col.Text = "Afiseaza";
            col.HeaderText = col.Text;
            col.UseColumnTextForButtonValue = true;
            dgw.Columns.Add(col);
            dgw.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            dgw.AutoSizeRowsMode = DataGridViewAutoSizeRowsMode.AllCells;
            dgw.AllowUserToAddRows = false;
            dgw.ReadOnly = true;
        }

        private void IncarcaDate()
        {
            DataTable dt = utilizatoriTableAdapter.GetUtilizator(email);
            int id = (int)dt.Rows[0][1];
            string numePrenume = (string)dt.Rows[0][2];
            lblBibliotecar.Text = "Bibliotecar = " + numePrenume;
            lblDateTime.Text = DateTime.Now.ToString("MM/dd/yyyy hh/mm/ss tt");
            pbUser.Image = Image.FromFile(respath + $@"\imagini\utilizatori\" + id + ".jpg");
            pbUser.SizeMode = PictureBoxSizeMode.StretchImage;
            Timer timer = new Timer();
            timer.Interval = 1000;
            timer.Tick += OnTimerTick;
            timer.Start();
        }

        private void OnTimerTick(object sender, EventArgs e)
        {
            lblDateTime.Text = DateTime.Now.ToString("MM/dd/yyyy hh/mm/ss tt");
            if (txtNumePrenume.Text == "" || !EmailValid(txtEmail.Text) || txtParola.Text == "" ||
                txtParola.Text != txtRepetareParola.Text || pbInregistreaza.Image == null ||
                (!rbBibliotecar.Checked && !rbCititor.Checked))
            {
                btnInregistreaza.Enabled = false;
                return;
            }
            btnInregistreaza.Enabled = true;
        }

        private void btnInregistreaza_Click(object sender, EventArgs e)
        {
            int tipUtilizator;
            if (rbBibliotecar.Checked)
                tipUtilizator = 2;
            else
                tipUtilizator = 1;
            string numePrenume = txtNumePrenume.Text;
            string email = txtEmail.Text;
            string parola = CriptareParola(txtParola.Text);

            utilizatoriTableAdapter.InsertUtilizator(tipUtilizator, numePrenume, email, parola);
            DataTable dt = utilizatoriTableAdapter.GetIdUtilizator(email);
            int id = (int)dt.Rows[0]["IdUtilizator"];
            pbInregistreaza.Image.Save(respath + $@"\imagini\utilizatori\" + 109 + ".jpg", System.Drawing.Imaging.ImageFormat.Jpeg);

            ClearInfo();
        }

        private void ClearInfo()
        {
            txtNumePrenume.Text = string.Empty;
            txtEmail.Text = string.Empty;
            txtParola.Text = string.Empty;
            rbBibliotecar.Checked = false;
            rbCititor.Checked = false;
            txtParola.Text = string.Empty;
            txtRepetareParola.Text = string.Empty;
            pbInregistreaza.Image = null;
        }

        private string CriptareParola(string parola)
        {
            char[] p = parola.ToCharArray();
            for (int i = 0; i < p.Length; ++i)
            {
                if (p[i] >= 'a' && p[i] <= 'z')
                {
                    p[i]++;
                    if (p[i] > 'z') p[i] = 'a';
                }
                if (p[i] >= 'A' && p[i] <= 'Z')
                {
                    p[i]--;
                    if (p[i] < 'A') p[i] = 'Z';
                }
                if (p[i] >= '0' && p[i] <= '9')
                {
                    int x = p[i] - '0';
                    x = 9 - x;
                    p[i] = (char)('0' + x);
                }
            }

            return new string(p);
        }

        private bool EmailValid(string email)
        {
            if(IsMatch(email))
                return utilizatoriTableAdapter.CountEmail(email) == 0;
            return false;
        }

        private bool IsMatch(string email)
        {
            char[] c = email.ToCharArray();
            int stage = 0;
            for(int i = 0; i < c.Length; ++i)
            {
                if ((c[i] == '@' && stage != 0) || (c[i] == '.' && stage != 1))
                    return false;

                if (c[i] == '@' && stage == 0)
                    stage = 1;
                if (c[i] == '.' && stage == 1)
                    stage = 2;                
            }
            return stage == 2;
        }

        private void btnRenunta_Click(object sender, EventArgs e)
        {
            ClearInfo();
        }

        private void bntIncarca_Click(object sender, EventArgs e)
        {
            var ofd = new OpenFileDialog();
            ofd.Filter = "Fisiere imagine (*.jpg)|*.jpg";
            if (ofd.ShowDialog() == DialogResult.OK)
                pbInregistreaza.Image = Image.FromFile(ofd.FileName);
        }

        private void tabControl1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (tabControl1.SelectedIndex == 1)
                IncarcaDgw();
            if (tabControl1.SelectedIndex == 2)
            {
                if (!enabledCititor)
                    tabControl1.SelectedIndex = 0;
                else
                    IncarcaCititor();
            }
        }

        private void IncarcaCititor()
        {
            DataTable dt = utilizatoriTableAdapter.GetCititor(idCititor);
            lblCititor.Text = "Cititor: " + dt.Rows[0]["IdUtilizator"] + ", " + "Nume si prenume: " + dt.Rows[0]["NumePrenume"];
            pbCititor.Image = Image.FromFile(respath + $@"Imagini\Utilizatori\" + idCititor + ".jpg");
            pbCititor.SizeMode = PictureBoxSizeMode.StretchImage;
            IncarcaDgwImprumutate();
            IncarcaDgwRezervare();
            IncarcaDgwCarti();
        }

        private void btnCauta_Click(object sender, EventArgs e)
        {
            char[] search = txtNumePrenumeCauta.Text.ToCharArray();
            string pattern = string.Empty;
            for(int i = 0; i < search.Length; ++i)
                pattern = pattern + ".*" + search[i].ToString();
            pattern = pattern + ".*";

            List<Cititor> newcititori = new List<Cititor>();
            var regex = new Regex(pattern);
            for (int i = 0; i < cititori.Count; ++i)
                if (regex.IsMatch(cititori[i].NumePrenume))
                    newcititori.Add(cititori[i]);

            dgw.DataSource = newcititori;
        }

        private void dgw_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex == -1 || e.ColumnIndex != 3) return;

            idCititor = int.Parse(dgw.Rows[e.RowIndex].Cells[0].Value.ToString());
            enabledCititor = true;
            tabControl1.SelectedIndex = 2;
        }

        private void tabControl2_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (tabControl2.SelectedIndex == 0)
                IncarcaDgwImprumutate();
            if (tabControl2.SelectedIndex == 1)
                IncarcaDgwRezervare();
            if (tabControl2.SelectedIndex == 2)
                IncarcaDgwCarti();
        }

        private void IncarcaDgwCarti()
        {
            dgwCarti.DataSource = null;
            dgwCarti.Rows.Clear();
            dgwCarti.Columns.Clear();

            DataGridViewTextBoxColumn col1 = new DataGridViewTextBoxColumn();
            col1.Name = "IdCarte";
            dgwCarti.Columns.Add(col1);
            var col2 = new DataGridViewTextBoxColumn();
            col2.Name = "Titlu";
            dgwCarti.Columns.Add(col2);
            var col3 = new DataGridViewTextBoxColumn();
            col3.Name = "Autor";
            dgwCarti.Columns.Add(col3);
            var col4 = new DataGridViewTextBoxColumn();
            col4.Name = "NrPag";
            dgwCarti.Columns.Add(col4);
            var col5 = new DataGridViewButtonColumn();
            col5.Name = "Rezerva";
            col5.Text = "Rezerva";
            col5.UseColumnTextForButtonValue = true;
            dgwCarti.Columns.Add(col5);
            var col6 = new DataGridViewButtonColumn();
            col6.Name = "Imprumuta";
            col6.Text = "Imprumuta";
            col6.UseColumnTextForButtonValue = true;
            dgwCarti.Columns.Add(col6);
            dgwCarti.AllowUserToAddRows = false;
            dgwCarti.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;


            var dt = cartiTableAdapter.GetData();
            foreach(DataRow row in dt)
            {
                if (Imprumutata((int)row["IdCarte"]) || Rezervata((int)row["IdCarte"])) continue;
                dgwCarti.Rows.Add((int)row["IdCarte"], (string)row["Titlu"], (string)row["Autor"], (int)row["Nrpag"]);
            }
        }

        private bool Rezervata(int idCarte)
        {
            bool ok = false;
            DataTable dt = rezervariTableAdapter.GetRezervaribyCarte(idCarte);
            foreach (DataRow row in dt.Rows)
                if (((DateTime)row["DataRezervare"]).AddDays(1) >= DateTime.Now && (int)row["StatusRezervare"] == 1) ok = true;

            return ok;
        }

        private bool Imprumutata(int idCarte)
        {
            bool ok = false;
            DataTable dt = imprumuturiTableAdapter.GetImprumuturi(idCarte);
            foreach (DataRow row in dt.Rows)
                if ((row["DataRestituire"] == DBNull.Value && ((DateTime)row["DataImprumut"]).AddDays(7) >= DateTime.Now)) ok = true;

            return ok;
        }

        private void IncarcaDgwRezervare()
        {
            dgwRezervare.DataSource = null;
            dgwRezervare.Rows.Clear();
            dgwRezervare.Columns.Clear();

            DataGridViewTextBoxColumn col1 = new DataGridViewTextBoxColumn();
            col1.Name = "Rezervare";
            dgwRezervare.Columns.Add(col1);
            var col2 = new DataGridViewTextBoxColumn();
            col2.Name = "IdCarte";
            dgwRezervare.Columns.Add(col2);
            var col3 = new DataGridViewTextBoxColumn();
            col3.Name = "Titlu";
            dgwRezervare.Columns.Add(col3);
            var col4 = new DataGridViewTextBoxColumn();
            col4.Name = "Autor";
            dgwRezervare.Columns.Add(col4);
            var col5 = new DataGridViewTextBoxColumn();
            col5.Name = "DataRezervare";
            dgwRezervare.Columns.Add(col5);
            var col6 = new DataGridViewTextBoxColumn();
            col6.Name = "DataExpirare";
            dgwRezervare.Columns.Add(col6);
            var col7 = new DataGridViewButtonColumn();
            col7.Name = "Anuleaza";
            col7.Text = "Anuleaza";
            col7.UseColumnTextForButtonValue = true;
            dgwRezervare.Columns.Add(col7);
            var col8 = new DataGridViewButtonColumn();
            col8.Name = "Imprumuta";
            col8.Text = "Imprumuta";
            col8.UseColumnTextForButtonValue = true;
            dgwRezervare.Columns.Add(col8);
            dgwRezervare.AllowUserToAddRows = false;
            dgwRezervare.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;

            cartiRezervate = 0;
            var dt = rezervariTableAdapter.GetRezervari(idCititor);
            foreach(DataRow row in dt.Rows)
            {
                if (Imprumutat((int)row["IdCarte"])) continue;

                int idRezervare = (int)row["IdRezervare"];
                int idCarte = (int)row["IdCarte"];
                var dt1 = cartiTableAdapter.GetCarte(idCarte);
                string titlu = dt1.Rows[0]["Titlu"].ToString();
                string autor = dt1.Rows[0]["Autor"].ToString();
                DateTime dataRezervare = (DateTime)row["DataRezervare"];
                DateTime dataExirare = dataRezervare.AddDays(1);

                if (dataExirare < DateTime.Now) continue;

                cartiRezervate++;
                dgwRezervare.Rows.Add(idRezervare, idCarte, titlu, autor, dataRezervare, dataExirare);
            }

            lblRezervari.Text = "Rezervari: " + (3 - cartiRezervate);
        }

        private bool Imprumutat(int idCarte)
        {
            foreach (DataGridViewRow row in dgwImprumutate.Rows)
                if (int.Parse(row.Cells["IdCarte"].Value.ToString()) == idCarte)
                    return true;
            return false;
        }

        private void IncarcaDgwImprumutate()
        {
            dgwImprumutate.DataSource = null;
            dgwImprumutate.Rows.Clear();
            dgwImprumutate.Columns.Clear();

            DataGridViewTextBoxColumn col1 = new DataGridViewTextBoxColumn();
            col1.Name = "IdImprumut";
            dgwImprumutate.Columns.Add(col1);
            var col2 = new DataGridViewTextBoxColumn();
            col2.Name = "IdCarte";
            dgwImprumutate.Columns.Add(col2);
            var col3 = new DataGridViewTextBoxColumn();
            col3.Name = "Titlu";
            dgwImprumutate.Columns.Add(col3);
            var col4 = new DataGridViewTextBoxColumn();
            col4.Name = "Autor";
            dgwImprumutate.Columns.Add(col4);
            var col5 = new DataGridViewTextBoxColumn();
            col5.Name = "DataImprumut";
            dgwImprumutate.Columns.Add(col5);
            var col6 = new DataGridViewTextBoxColumn();
            col6.Name = "DataExpirare";
            dgwImprumutate.Columns.Add(col6);
            var col7 = new DataGridViewButtonColumn();
            col7.Name = "Restituie";
            col7.Text = "Restituie";
            col7.UseColumnTextForButtonValue = true;
            dgwImprumutate.Columns.Add(col7);
            dgwImprumutate.AllowUserToAddRows = false;
            dgwImprumutate.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;

            var dt = imprumuturiTableAdapter.GetImprumuturiNefin(idCititor);

            cartiImprumutate = 0;
            foreach(DataRow row in dt.Rows)
            {
                int idImprumut = (int)row["IdImprumut"];
                int idCarte = (int)row["IdCarte"];
                var dt1 = cartiTableAdapter.GetCarte(idCarte);
                string titlu = (string)dt1.Rows[0]["Titlu"];
                string autor = (string)dt1.Rows[0]["Autor"];
                var date = (DateTime)row["DataImprumut"];
                string dataImprumut = date.ToString("MM/dd/yyyy hh:mm tt");
                string dataExpirare = date.AddDays(7).ToString("MM/dd/yyyy hh:mm tt");

                if (date.AddDays(7) < DateTime.Now) continue;

                cartiImprumutate++;
                dgwImprumutate.Rows.Add(idImprumut, idCarte, titlu, autor, dataImprumut, dataExpirare);
            }

            lblImprumuturi.Text = "Numar imprumuturi: " + (3 - cartiImprumutate);
        }

        private void dgwRezervare_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if(e.RowIndex < 0 || e.ColumnIndex < 6) return;

            if (e.ColumnIndex == 6)
            {
                rezervariTableAdapter.UpdateRezervare((int)dgwRezervare.Rows[e.RowIndex].Cells["Rezervare"].Value);
                IncarcaDgwRezervare();
                IncarcaDgwCarti();
            }
            else if(e.ColumnIndex == 7 && cartiImprumutate < 3)
            {
                int idCarte = (int)dgwRezervare.Rows[e.RowIndex].Cells["IdCarte"].Value;
                DateTime dataImprumut = DateTime.Now;

                rezervariTableAdapter.UpdateRezervare((int)dgwRezervare.Rows[e.RowIndex].Cells["Rezervare"].Value);
                imprumuturiTableAdapter.InsertImprumut(idCititor, idCarte, dataImprumut, null);
                IncarcaDgwImprumutate();
                IncarcaDgwRezervare();
                IncarcaDgwCarti();
            }
        }

        private void dgwImprumutate_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if(e.RowIndex < 0 || e.ColumnIndex != 6) return;
            imprumuturiTableAdapter.UpdateImprumut(DateTime.Now, (int)dgwImprumutate["IdImprumut", e.RowIndex].Value);
            IncarcaDgwImprumutate();
            IncarcaDgwCarti();
        }

        private void dgwCarti_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex < 0 || e.ColumnIndex < 4) return;

            if(e.ColumnIndex == 4 && cartiRezervate < 3)
            {
                int idCarte = (int)dgwCarti["IdCarte", e.RowIndex].Value;
                DateTime dataRezervare = DateTime.Now;
                rezervariTableAdapter.InsertRezervare(idCititor, idCarte, dataRezervare, 1);
            }
            else if(e.ColumnIndex == 5 && cartiImprumutate < 3)
            {
                int idCarte = (int)dgwCarti["IdCarte", e.RowIndex].Value;
                DateTime dataImprumut = DateTime.Now;
                imprumuturiTableAdapter.InsertImprumut(idCititor, idCarte, dataImprumut, null);
            }

            IncarcaDgwCarti();
            IncarcaDgwImprumutate();
            IncarcaDgwRezervare();
        }


        private void dgwCarti_CellDoubleClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex < 0 || e.ColumnIndex >= 4) return;

            int idCarte = (int)dgwCarti["IdCarte", e.RowIndex].Value;
            var frm = new PrevizualizareCarte(idCarte);
            frm.ShowDialog();
        }

        private void btnGen_Click(object sender, EventArgs e)
        {
            dgwPropunere.DataSource = null;
            dgwPropunere.Rows.Clear();
            dgwPropunere.Columns.Clear();
            
            for(int i = 1; i <= 3; ++i)
            {
                var col1 = new DataGridViewTextBoxColumn();
                col1.Name = "IdCarte_" + i;
                dgwPropunere.Columns.Add(col1);
                var col2 = new DataGridViewTextBoxColumn();
                col2.Name = "Titlu_" + i;
                dgwPropunere.Columns.Add(col2);
                var col3 = new DataGridViewTextBoxColumn();
                col3.Name = "Autor_" + i;
                dgwPropunere.Columns.Add(col3);
                var col4 = new DataGridViewTextBoxColumn();
                col4.Name = "NrPag_" + i;
                dgwPropunere.Columns.Add(col4);
            }

            var col5 = new DataGridViewTextBoxColumn();
            col5.Name = "Total_pag";
            dgwPropunere.Columns.Add(col5);

            var col6 = new DataGridViewButtonColumn();
            col6.Name = "Rezerva";
            col6.Text = "Rezerva";
            col6.UseColumnTextForButtonValue = true;
            dgwPropunere.Columns.Add(col6);
            var col7 = new DataGridViewButtonColumn();
            col7.Name = "Imprumuta";
            col7.Text = "Imprumuta";
            col7.UseColumnTextForButtonValue = true;
            dgwPropunere.Columns.Add(col7);

            dgwPropunere.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            dgwPropunere.AllowUserToAddRows = false;


            int nr = int.Parse(txtPag.Text);
            lbl.Text = "* 7 = " + nr * 7;
            nrp = nr * 7;

            int st = 1, dr = 1;

            itemi = new List<Item>();

            foreach (DataGridViewRow x in dgwCarti.Rows)
                itemi.Add(new Item((int)x.Cells["IdCarte"].Value, (string)x.Cells["Titlu"].Value, (string)x.Cells["Autor"].Value, (int)x.Cells["NrPag"].Value));

            b = new Item[3];

            optiuni = new List<List<Item>>();

            Back(0, 0, nrp);

            List<List<Item>> remove = new List<List<Item>>();

            foreach (var x in optiuni)
                if (!Valid1(x))
                    remove.Add(x);

            foreach (var x in remove)
                optiuni.Remove(x);

            foreach(var x in optiuni)
            {
                if(x.Count == 1)
                {
                    dgwPropunere.Rows.Add(
                        x[0].IdCarte, x[0].Titlu, x[0].Autor, x[0].NrPag,
                        "-", "-", "-", 0,
                        "-", "-", "-", 0,
                        x[0].NrPag);
                }
                else if(x.Count == 2)
                {
                    dgwPropunere.Rows.Add(
                        x[0].IdCarte, x[0].Titlu, x[0].Autor, x[0].NrPag,
                        x[1].IdCarte, x[1].Titlu, x[1].Autor, x[1].NrPag,
                        "-", "-", "-", 0,
                        x[0].NrPag + x[1].NrPag);
                }
                else if(x.Count == 3)
                {
                    dgwPropunere.Rows.Add(
                        x[0].IdCarte, x[0].Titlu, x[0].Autor, x[0].NrPag,
                        x[1].IdCarte, x[1].Titlu, x[1].Autor, x[1].NrPag,
                        x[2].IdCarte, x[2].Titlu, x[2].Autor, x[2].NrPag,
                        x[0].NrPag + x[1].NrPag + x[2].NrPag);
                }
            }
        }

        private bool Valid1(List<Item> x)
        {
            bool[] isinx = new bool[itemi.Count + 9];

            if (x.Count == 3) return true;

            for (int i = 0; i < x.Count; ++i)
                isinx[x[i].IdCarte] = true;

            int s = 0;
            for (int i = 0; i < x.Count; ++i)
                s += x[i].NrPag;

            for(int i = 0; i < itemi.Count; ++i)
                if (!isinx[itemi[i].IdCarte] && s + itemi[i].NrPag <= nrp) return false;

            return true;
        }

        private void Back(int x,int ind,  int nrp)
        {
            if(x == 3)
            {
                List<Item> aux = new List<Item>();
                for (int i = 0; i < x; ++i)
                    aux.Add(new Item(b[i].IdCarte, b[i].Titlu, b[i].Autor, b[i].NrPag));
                if (aux.Count > 0)
                    optiuni.Add(aux);

                return;
            }


            bool ok = true;
            for(int i = ind; i < itemi.Count; ++i)
            {
                if(nrp - itemi[i].NrPag >= 0)
                {
                    ok = false;
                    b[x] = new Item(itemi[i].IdCarte, itemi[i].Titlu, itemi[i].Autor, itemi[i].NrPag);
                    Back(x + 1, i + 1, nrp - itemi[i].NrPag);
                    b[x] = null;
                }
            }

            if(ok)
            {
                List<Item> aux = new List<Item>();
                for (int i = 0; i < x; ++i)
                    aux.Add(new Item(b[i].IdCarte, b[i].Titlu, b[i].Autor, b[i].NrPag));
                if (aux.Count > 0)
                    optiuni.Add(aux);
            }
        }

        private void dgwPropunere_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex < 0 || e.ColumnIndex < 13) return;

            List<int> ids = new List<int>();
            if (dgwPropunere.Rows[e.RowIndex].Cells["IdCarte_1"].Value.ToString() != "-") ids.Add((int)dgwPropunere.Rows[e.RowIndex].Cells["IdCarte_1"].Value);
            if (dgwPropunere.Rows[e.RowIndex].Cells["IdCarte_2"].Value.ToString() != "-") ids.Add((int)dgwPropunere.Rows[e.RowIndex].Cells["IdCarte_2"].Value);
            if (dgwPropunere.Rows[e.RowIndex].Cells["IdCarte_3"].Value.ToString() != "-") ids.Add((int)dgwPropunere.Rows[e.RowIndex].Cells["IdCarte_3"].Value);

            if(e.ColumnIndex == 13 && 3 - cartiRezervate >= ids.Count)
            {
                foreach(int id in ids)
                    rezervariTableAdapter.InsertRezervare(idCititor, id, DateTime.Now, 1);
            }
            if(e.ColumnIndex == 14 && 3 - cartiImprumutate >= ids.Count)
            {
                foreach (int id in ids)
                    imprumuturiTableAdapter.InsertImprumut(idCititor, id, DateTime.Now, null);
            }

            IncarcaDgwImprumutate();
            IncarcaDgwRezervare();
            IncarcaDgwCarti();
            btnGen_Click(new object(), new EventArgs());

        }

        private void btnFiltreaza_Click(object sender, EventArgs e)
        {
            

            char[] s1 = txtTitlu.Text.ToCharArray();
            char[] s2 = txtAutor.Text.ToCharArray();

            string p1 = string.Empty;
            string p2 = string.Empty;

            for (int i = 0; i < s1.Count(); ++i)
                p1 += ".*" + s1[i].ToString();
            p1 += ".*";

            for (int i = 0; i < s2.Count(); ++i)
                p2 += ".*" + s2[i].ToString();
            p2 += ".*";

            Regex r1 = new Regex(p1);
            Regex r2 = new Regex(p2);

            List<Item> newCarti = new List<Item>();
            foreach(DataGridViewRow row in dgwCarti.Rows)
            {
                int idCarte = (int)row.Cells["IdCarte"].Value;
                string titlu = (string)row.Cells["Titlu"].Value;
                string autor = (string)row.Cells["Autor"].Value;
                int nrPag = (int)row.Cells["NrPag"].Value;

                if (r1.IsMatch(titlu) && r2.IsMatch(autor))
                    newCarti.Add(new Item(idCarte, titlu, autor, nrPag));
            }

            dgwCarti.DataSource = null;
            dgwCarti.Columns.Clear();
            dgwCarti.Rows.Clear();
            dgwCarti.DataSource = newCarti;


            var col5 = new DataGridViewButtonColumn();
            col5.Name = "Rezerva";
            col5.Text = "Rezerva";
            col5.UseColumnTextForButtonValue = true;
            dgwCarti.Columns.Add(col5);
            var col6 = new DataGridViewButtonColumn();
            col6.Name = "Imprumuta";
            col6.Text = "Imprumuta";
            col6.UseColumnTextForButtonValue = true;
            dgwCarti.Columns.Add(col6);
            dgwCarti.AllowUserToAddRows = false;
            dgwCarti.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Sunteti digur ca doriti sa inchideti aplicatia?", "Confirmare", MessageBoxButtons.OKCancel) == DialogResult.OK)
                Application.Exit();
        }
    }
}
