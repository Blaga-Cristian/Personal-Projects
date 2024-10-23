using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net.Mail;
using System.Runtime.InteropServices;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Aplicatie_Biblioteca
{

    public partial class BibliotecarBiblioteca : Form
    {
        DSBibliotecaTableAdapters.CartiTableAdapter cta = new DSBibliotecaTableAdapters.CartiTableAdapter();
        DSBibliotecaTableAdapters.ImprumuturiTableAdapter ita = new DSBibliotecaTableAdapters.ImprumuturiTableAdapter();
        DSBibliotecaTableAdapters.RezervariTableAdapter rta = new DSBibliotecaTableAdapters.RezervariTableAdapter();
        DSBibliotecaTableAdapters.UtilizatoriTableAdapter uta = new DSBibliotecaTableAdapters.UtilizatoriTableAdapter();
        string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\ONTI_C#_2019_resurse\";

        int idCititor;
        string email;
        DataRow bibliotecar;
        DataRow cititor;
        Timer t = new Timer();
        int[] b;
        int nrPag;
        List<List<int>> optiuni;


        public BibliotecarBiblioteca(string email)
        {
            this.email = email;
            InitializeComponent();
            t.Interval = 1000;
            t.Tick += CheckData;
            t.Start();
            IncarcaDate();
        }

        private void CheckData(object sender, EventArgs e)
        {
            string numePrenume = txtNumePrenume.Text;
            string email = txtEmail.Text;
            string parola = txtParola.Text;
            int tip = 0;
            if (rbB.Checked) tip = 1;
            else if (rbC.Checked) tip = 2;

            if(numePrenume == "" || !Valid(email) || parola == "" || parola != txtParola2.Text || tip == 0 || pb.Image == null)
            {
                btnInregistreaza.Enabled = false;
                return;
            }

            btnInregistreaza.Enabled = true;
        }

        private bool Valid(string email)
        {
            try
            {
                new MailAddress(email);
                return uta.GetUtilizator(email).Rows.Count == 0;
            }
            catch
            {
                return false;
            }
        }

        private void IncarcaDate()
        {
            DataTable dt = uta.GetUtilizator(email);
            bibliotecar = dt.Rows[0];
            lblBibliotecar.Text = "Bibliotecar = " + (string)bibliotecar["NumePrenume"];

            lblTimp.Text = DateTime.Now.ToString("MM/dd/yyyy hh/mm/ss tt");
            Timer t = new Timer();
            t.Tick += delegate
            {
                lblTimp.Text = DateTime.Now.ToString("MM/dd/yyyy hh/mm/ss tt");
            };
            t.Interval = 1000;
            t.Start();

            pbBibliotecar.Image = Image.FromFile(respath + $@"Imagini\utilizatori\{(int)bibliotecar["IdUtilizator"]}.jpg");
        }

        private void btnInregistreaza_Click(object sender, EventArgs e)
        {
            string numePrenume = txtNumePrenume.Text;
            string email = txtEmail.Text;
            string parola = txtParola.Text;
            int tip = 0;
            if (rbB.Checked) tip = 1;
            else if (rbC.Checked) tip = 2;

            uta.Insert(tip, numePrenume, email, parola);
            pb.Image.Save(respath + $@"Imagini\utilizatori\{(int)uta.GetUtilizator(email).Rows[0]["IdUtilizator"]}.jpg", System.Drawing.Imaging.ImageFormat.Jpeg);

            btnRenunta_Click(new object(), new EventArgs());
        }

        private void btnRenunta_Click(object sender, EventArgs e)
        {
            txtNumePrenume.Text = txtEmail.Text = txtParola.Text = txtParola2.Text = "";
            rbB.Checked = rbC.Checked = false;
            pb.Image = null;
        }

        private void btnChoose_Click(object sender, EventArgs e)
        {
            var ofd = new OpenFileDialog();
            ofd.Filter = "Fisiere imagine(*.jpg)|*.jpg";
            if (ofd.ShowDialog() != DialogResult.OK) return;
            pb.Image = Image.FromFile(ofd.FileName);
        }

        private void tabControl1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (tabControl1.SelectedIndex == 2 && idCititor == 0)
                tabControl1.SelectedIndex = 0;
            else if (tabControl1.SelectedIndex == 2)
                IncarcaCitior();
            else if (tabControl1.SelectedIndex == 1)
                IncarcaDgwCititori();
        }

        private void IncarcaCitior()
        {
            cititor = uta.GetById(idCititor).Rows[0];

            lblCititor.Text = $@"Citior: IdCititor = {cititor["IdUtilizator"]}, Nume si prenume = {cititor["NumePrenume"]}";
            pbCititor.Image = Image.FromFile(respath + $@"Imagini\utilizatori\{idCititor}.jpg");

            IncarcaDgwImprumuturi();
            IncarcaDgwRezervari();
            IncarcaDgwCarti();          
            
        }

        private void IncarcaDgwCarti()
        {
            dgwCarti.Rows.Clear();

            DataTable dt = cta.GetData();
            foreach(DataRow dr in dt.Rows)
            {
                int idCarte = (int)dr["IdCarte"];
                if(!Imprumutat(idCarte) && !Rezervat(idCarte))
                {
                    string titlu = (string)dr["Titlu"];
                    string autor = (string)dr["Autor"];
                    int nrPag = (int)dr["NrPag"];
                    dgwCarti.Rows.Add(idCarte, titlu, autor, nrPag);
                }
            }
        }

        private bool Rezervat(int idCarte)
        {
            bool ok = false;
            DataTable dt = rta.GetData();
            foreach (DataRow dr in dt.Rows)
                if ((int)dr["IdCarte"] == idCarte && (int)dr["StatusRezervare"] == 1 && ((DateTime)dr["DataRezervare"]).AddDays(1) > DateTime.Now)
                    ok = true;

            return ok;
        }

        private bool Imprumutat(int idCarte)
        {
            bool ok = false;
            DataTable dt = ita.GetData();
            foreach (DataRow dr in dt.Rows)
                if ((int)dr["IdCarte"] == idCarte && dr["DataRestituire"] == DBNull.Value && ((DateTime)dr["DataImprumut"]).AddDays(7) > DateTime.Now)
                    ok = true;

            return ok;
        }

        private void IncarcaDgwRezervari()
        {
            dgwRezervari.Rows.Clear();

            DataTable dt = rta.GetData();
            foreach (DataRow dr in dt.Rows)
                if ((int)dr["IdCititor"] == idCititor && (int)dr["StatusRezervare"] == 1 && ((DateTime)dr["DataRezervare"]).AddDays(1) > DateTime.Now)
                {
                    int idRezervare = (int)dr["IdRezervare"];
                    DataRow carte = cta.GetById((int)dr["IdCarte"]).Rows[0];
                    int idCarte = (int)carte["IdCarte"];
                    string titlu = (string)carte["Titlu"];
                    string autor = (string)carte["Autor"];
                    DateTime dataRezervare = (DateTime)dr["DataRezervare"];
                    DateTime dataExpirare = dataRezervare.AddDays(1);

                    dgwRezervari.Rows.Add(idRezervare, idCarte, titlu, autor, dataRezervare, dataExpirare);
                }

            lblRezervari.Text = "Rezervari ramase: " + (3 - dgwRezervari.Rows.Count);
        }

        private void IncarcaDgwImprumuturi()
        {
            dgwImprumuturi.Rows.Clear();

            DataTable dt = ita.GetData();
            foreach(DataRow dr in dt.Rows)
                if ((int)dr["IdCititor"] == idCititor && dr["DataRestituire"] == DBNull.Value && ((DateTime)dr["DataImprumut"]).AddDays(7) > DateTime.Now)
                {
                    int idImprumut = (int)dr["IdImprumut"];
                    DataRow carte = cta.GetById((int)dr["IdCarte"]).Rows[0];
                    int idCarte = (int)carte["IdCarte"];
                    string titlu = (string)carte["Titlu"];
                    string autor = (string)carte["Titlu"];
                    DateTime dataImprumut = (DateTime)dr["DataImprumut"];
                    DateTime dataExpirare = dataImprumut.AddDays(7);

                    dgwImprumuturi.Rows.Add(idImprumut, idCarte, titlu, autor, dataImprumut, dataExpirare);
                }

            lblImprumuturi.Text = "Imprumuturi ramase: " + (3 - dgwImprumuturi.Rows.Count);
        }

        private void IncarcaDgwCititori()
        {
            dgwCitiori.Rows.Clear();

            DataTable dt = uta.GetByType(2);
            foreach (DataRow dr in dt.Rows)
                dgwCitiori.Rows.Add((int)dr["IdUtilizator"], (string)dr["NumePrenume"], (string)dr["Email"]);
        }

        private void dgwCitiori_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex < 0 || e.ColumnIndex != 3) return;

            idCititor = (int)dgwCitiori[0, e.RowIndex].Value;
        }

        private void btnCautaNP_Click(object sender, EventArgs e)
        {
            dgwCitiori.Rows.Clear();
            string search = txtSNumePrenume.Text;
            string pattern = ".*";
            for (int i = 0; i < search.Length; ++i)
                pattern += search[i] + ".*";

            Regex reg = new Regex(pattern);

            DataTable dt = uta.GetByType(2);
            foreach (DataRow dr in dt.Rows)
                if (reg.IsMatch((string)dr["NumePrenume"]))
                    dgwCitiori.Rows.Add((int)dr["IdUtilizator"], (string)dr["NumePrenume"], (string)dr["Email"]);
        }

        private void dgwImprumuturi_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex < 0 || e.ColumnIndex != 6) return;

            int idImprumut = (int)dgwImprumuturi["IdImprumut", e.RowIndex].Value;
            ita.Restituie(DateTime.Now, idImprumut);

            IncarcaDgwImprumuturi();

            IncarcaDgwCarti();
        }

        private void dgwRezervari_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            if(e.RowIndex < 0 || e.ColumnIndex < 6)return;

            if (e.ColumnIndex == 6)
            {
                rta.SchimbaStatus(0, (int)dgwRezervari["Rezervare", e.RowIndex].Value);
                IncarcaDgwRezervari();
            }
            else
            {
                int idCarte = (int)dgwRezervari["IdCarteRez", e.RowIndex].Value;
                ita.Insert(idCititor, idCarte, DateTime.Now, null);
                rta.DeleteById((int)dgwRezervari["Rezervare", e.RowIndex].Value);
                IncarcaDgwImprumuturi();
                IncarcaDgwRezervari();
            }

            IncarcaDgwCarti();
        }

        private void dgwCarti_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex < 0) return;

            int idCarte = (int)dgwCarti["IdCarteCarti", e.RowIndex].Value;

            if(e.ColumnIndex == 4)
            {
                rta.Insert(idCititor, idCarte, DateTime.Now, 1);
                IncarcaDgwRezervari();
                IncarcaDgwCarti();
            }
            else if(e.ColumnIndex == 5)
            {
                ita.Insert(idCititor, idCarte, DateTime.Now, null);
                IncarcaDgwImprumuturi();
                IncarcaDgwCarti();
            }
            else
            {
                var frm = new PrevizualizareCarte(idCarte);
                this.Visible = false;
                frm.ShowDialog();
                this.Visible = true;
            }            
        }

        private void btnFiltreaza_Click(object sender, EventArgs e)
        {
            dgwCarti.Rows.Clear();

            string titlureg = txtTitlu.Text;
            string autorreg= txtAutor.Text;

            string pattern1 = ".*", pattern2 = ".*";

            for (int i = 0; i < titlureg.Length; ++i)
                pattern1 += titlureg[i] + ".*";
            for (int i = 0; i < autorreg.Length; ++i)
                pattern2 += autorreg[i] + ".*";

            Regex r1 = new Regex(pattern1);
            Regex r2 = new Regex(pattern2);

            DataTable dt = cta.GetData();
            foreach (DataRow dr in dt.Rows)
            {
                int idCarte = (int)dr["IdCarte"];
                string titlu = (string)dr["Titlu"];
                string autor = (string)dr["Autor"];
                if (!Imprumutat(idCarte) && !Rezervat(idCarte) && r1.IsMatch(titlu) && r2.IsMatch(autor))
                {                    
                    int nrPag = (int)dr["NrPag"];
                    dgwCarti.Rows.Add(idCarte, titlu, autor, nrPag);
                }
            }
        }

        private void txtNrPag_TextChanged(object sender, EventArgs e)
        {
            try
            {
                int x = int.Parse(txtNrPag.Text);
                lbl.Text = $@" * 7 = {7 * x}";
            }
            catch
            {
                lbl.Text = $@" * 7 = 0";
            }
        }

        private void btnGen_Click(object sender, EventArgs e)
        {
            dgwLecturi.Rows.Clear();

            try { nrPag = 7 * int.Parse(txtNrPag.Text); }
            catch { nrPag = 0; }

            IncarcaDgwCarti();


            optiuni = new List<List<int>>();
            b = new int[3];
            Back(0, 0,  0);

            List<List<int>> remove = new List<List<int>>();

            foreach (List<int> l in optiuni)
                if (!Ok(l))
                    remove.Add(l);

            foreach (List<int> r in remove)
                optiuni.Remove(r);

            foreach(List<int> l in optiuni)
            {
                if(l.Count == 3)
                {
                    DataGridViewRow c1 = dgwCarti.Rows[l[0]];
                    DataGridViewRow c2 = dgwCarti.Rows[l[1]];
                    DataGridViewRow c3 = dgwCarti.Rows[l[2]];

                    dgwLecturi.Rows.Add(
                        c1.Cells["IdCarteCarti"].Value, c1.Cells["TitluCarti"].Value, c1.Cells["AutorCarti"].Value, c1.Cells["NrPag"].Value,
                        c2.Cells["IdCarteCarti"].Value, c2.Cells["TitluCarti"].Value, c2.Cells["AutorCarti"].Value, c2.Cells["NrPag"].Value,
                        c3.Cells["IdCarteCarti"].Value, c3.Cells["TitluCarti"].Value, c2.Cells["AutorCarti"].Value, c3.Cells["NrPag"].Value,
                        (int)c1.Cells["NrPag"].Value + (int)c2.Cells["NrPag"].Value + (int)c3.Cells["NrPag"].Value);
                }
                else if(l.Count == 2)
                {
                    DataGridViewRow c1 = dgwCarti.Rows[l[0]];
                    DataGridViewRow c2 = dgwCarti.Rows[l[1]];

                    dgwLecturi.Rows.Add(
                        c1.Cells["IdCarteCarti"].Value, c1.Cells["TitluCarti"].Value, c1.Cells["AutorCarti"].Value, c1.Cells["NrPag"].Value,
                        c2.Cells["IdCarteCarti"].Value, c2.Cells["TitluCarti"].Value, c2.Cells["AutorCarti"].Value, c2.Cells["NrPag"].Value,
                        "-", "-", "-", "0",
                        (int)c1.Cells["NrPag"].Value + (int)c2.Cells["NrPag"].Value);
                }
                else if (l.Count == 1)
                {
                    DataGridViewRow c1 = dgwCarti.Rows[l[0]];

                    dgwLecturi.Rows.Add(
                        c1.Cells["IdCarteCarti"].Value, c1.Cells["TitluCarti"].Value, c1.Cells["AutorCarti"].Value, c1.Cells["NrPag"].Value,
                        "-", "-", "-", "0",
                        "-", "-", "-", "0",
                        (int)c1.Cells["NrPag"].Value);
                }
            }
        }

        private bool Ok(List<int> l)
        {
            if (l.Count == 3) return true;

            bool ok = true;

            int s = 0;
            bool[] used = new bool[dgwCarti.Rows.Count + 9];
            foreach (int i in l)
            {
                used[(int)dgwCarti.Rows[i].Cells["IdCarteCarti"].Value] = true;
                s += (int)dgwCarti.Rows[i].Cells["NrPag"].Value;
            }

            foreach(DataGridViewRow x in dgwCarti.Rows)
            {
                int idCarte = (int)x.Cells["IdCarteCarti"].Value;
                int nr = (int)x.Cells["NrPag"].Value;

                if (!used[idCarte] && s + nr <= nrPag)
                    ok = false;
            }

            return ok;
        }

        private void Back(int x, int ind, int pagini)
        {
            if(x == 3)
            {
                optiuni.Add(new List<int>(){ b[0], b[1], b[2] });
                return;
            }


            bool ok = true;
            for(int i = ind; i < dgwCarti.Rows.Count; ++i)
            {
                int idCarte = (int)dgwCarti.Rows[0].Cells["IdCarteCarti"].Value;
                int nr = (int)dgwCarti.Rows[0].Cells["NrPag"].Value;

                if(pagini + nr <= nrPag)
                {
                    ok = false;
                    b[x] = i;
                    Back(x + 1, i + 1, pagini + nr);
                    b[x] = -1;
                }
            }

            if(ok)
            {
                if (x == 1)
                    optiuni.Add(new List<int>() { b[0] });
                else if (x == 2)
                    optiuni.Add(new List<int>() { b[0], b[1] });
            }
        }

        private void dgwLecturi_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex < 0 || e.ColumnIndex < 13) return;


            List<int> idCarti = new List<int>();
            if (dgwLecturi["IdCarte_1", e.RowIndex].Value.ToString() != "-")
                idCarti.Add((int)dgwLecturi["IdCarte_1", e.RowIndex].Value);
            if (dgwLecturi["IdCarte_2", e.RowIndex].Value.ToString() != "-")
                idCarti.Add((int)dgwLecturi["IdCarte_2", e.RowIndex].Value);
            if (dgwLecturi["IdCarte_3", e.RowIndex].Value.ToString() != "-")
                idCarti.Add((int)dgwLecturi["IdCarte_3", e.RowIndex].Value);


            if (e.ColumnIndex == 13 && dgwRezervari.Rows.Count + idCarti.Count <= 3) // Rezerva
            {
                foreach (int id in idCarti)
                    rta.Insert(idCititor, id, DateTime.Now, 1);

                IncarcaDgwRezervari();
            }
            else if(e.ColumnIndex == 14 && dgwImprumuturi.Rows.Count + idCarti.Count <= 3)
            {
                foreach (int id in idCarti)
                    ita.Insert(idCititor, id, DateTime.Now, null);

                IncarcaDgwImprumuturi();
            }

            IncarcaDgwCarti();
            btnGen_Click(new object(), new EventArgs());
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Sunteti sigur ca doriti sa inchideti aceasta aplciatie ?",
                "Confirmare", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
                this.Close();
        }
    }
}
