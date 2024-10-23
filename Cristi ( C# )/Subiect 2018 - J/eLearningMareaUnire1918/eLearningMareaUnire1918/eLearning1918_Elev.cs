using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Drawing.Printing;
using System.IO;
using System.Linq;
using System.Net.Http.Headers;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace eLearningMareaUnire1918
{
    public partial class eLearning1918_Elev : Form
    {
        public string connStr = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\eLearning1918.mdf;Integrated Security = True; Connect Timeout = 30";
        int idx = 0;
        int nota = 1;
        int id;
        string clasa;
        string stringtoprint;

        
        private List<Item> itemi = new List<Item>();
        private List<Item> positemi = new List<Item>();
        private List<Item> ritemi = new List<Item>();
        private List<string> intrebari = new List<string>();
        private List<string> rintrebari = new List<string>();
        private List<string> posintrebari =new List<string>();
        private Random rnd = new Random();
        private List<int> idclasa = new List<int>();
        private List<int> noteclasa = new List<int>();
        private List<KeyValuePair<int,DateTime>> noteElev = new List<KeyValuePair<int, DateTime>>();
        private List<string> elevans = new List<string>();
        private List<string> corectans = new List<string>();


        public eLearning1918_Elev(int id,string clasa)
        {
            this.id = id;
            this.clasa = clasa;

            InitializeComponent();

            AscundeTot();

            txt1.TextChanged += Txt1_TextChanged;
            chk21.CheckedChanged += CheckedChanged;
            chk22.CheckedChanged += CheckedChanged;
            chk23.CheckedChanged += CheckedChanged;
            chk24.CheckedChanged += CheckedChanged;
            chk31.CheckedChanged += CheckedChanged;
            chk32.CheckedChanged += CheckedChanged;
            chk33.CheckedChanged += CheckedChanged;
            chk34.CheckedChanged += CheckedChanged;
            chk41.CheckedChanged += CheckedChanged;
            chk42.CheckedChanged += CheckedChanged;


            GetItems();
        }

        private void AscundeTot()
        {
            btnAns.Visible = false;
            btnUrm.Visible = false;
            lblItem.Visible = false;
            txtInt.Visible = false;
        }

        private void GetItems()
        {
            SqlConnection con = new SqlConnection(connStr);
            con.Open();
            string query = "SELECT * FROM Itemi";
            SqlCommand cmd = new SqlCommand(query, con);
            var rd = cmd.ExecuteReader();

            while (rd.Read())
            {
                intrebari.Add((string)rd[2]);
                itemi.Add(new Item((int)rd[1], (string)rd[3], (string)rd[4], (string)rd[5], (string)rd[6], (string)rd[7]));
            }

            con.Close();
            con.Dispose();
            cmd.Dispose();
        }

        private void testeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            tbc.SelectedIndex = 0;
        }

        private void carnetDeNoteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            tbc.SelectedIndex = 1;
        }

        private void graficNoteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            tbc.SelectedIndex = 2;
        }

        private void iesireToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var dr = MessageBox.Show("Sunteti sugur ca doriti sa inchideti aplicatia?", "Inchidere", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (dr == DialogResult.Yes)
                this.Close();
        }

        private void btnStartTest_Click(object sender, EventArgs e)
        {
            idx = 0;
            nota = 1;
            positemi = itemi;
            posintrebari = intrebari;
            ritemi.Clear();
            rintrebari.Clear();
            elevans.Clear();
            corectans.Clear();

            for(int i = 0; i < 9; ++i)
            {
                int idx = rnd.Next(positemi.Count);
                ritemi.Add(positemi[idx]);
                rintrebari.Add(posintrebari[idx]);
                posintrebari.RemoveAt(idx);
                positemi.RemoveAt(idx);
            }

            btnUrm.Visible = true;
            lblItem.Visible = true;
            txtInt.Visible = true;
            LoadInt();
        }

        private void LoadInt()
        {
            btnAns.Visible = false;
            lblPunctaj.Text = "Punctaj: " + nota;

            if (idx == 9)
            {
                btnUrm.Visible = false;
                AscundeTot();
                InsertEvaluari(id, DateTime.Now, nota);
                var frm = new Vizualizare_rezultate(elevans, corectans);
                this.Visible = false;
                frm.ShowDialog();
                this.Visible = true;
                return;
            }

            lblItem.Text = "Tipul: " + ritemi[idx].Tip.ToString();
            txtInt.Text = rintrebari[idx];

            var it = ritemi[idx];

            if(it.Tip == 1)
            {
                lbl1.Visible = true;
                txt1.Visible = true;
            }
            if(it.Tip == 2)
            {
                chk21.Visible = true;
                chk22.Visible = true;
                chk23.Visible = true;
                chk24.Visible = true;
                chk21.Text = it.R1;
                chk22.Text = it.R2;
                chk23.Text = it.R3;
                chk24.Text = it.R4;
            }
            if(it.Tip == 3)
            {
                chk31.Visible = true;
                chk32.Visible = true;
                chk33.Visible = true;
                chk34.Visible = true;
                chk31.Text = it.R1;
                chk32.Text = it.R2;
                chk33.Text = it.R3;
                chk34.Text = it.R4;
            }
            if(it.Tip == 4)
            {
                chk41.Visible = true;
                chk42.Visible = true;
                chk41.Text = "Adevarat";
                chk42.Text = "Fals";
            }
        }

        private void Txt1_TextChanged(object sender, EventArgs e)
        {
            btnAns.Visible = true;
        }
        
        private void CheckedChanged(object sender, EventArgs e)
        {
            btnAns.Visible = true;
        }

        private void btnAns_Click(object sender, EventArgs e)
        {
            var it = ritemi[idx];
            bool ok = true;
            if(it.Tip == 1)
            {
                string[] s1 = txt1.Text.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                string[] s2 = it.Rcorect.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                for (int i = 0; i < s1.Length; ++i)
                    if (!string.Equals(s1[i], s2[i], StringComparison.OrdinalIgnoreCase))
                        ok = false;
            }
            if(it.Tip == 2)
            {
                chk21.BackColor = Color.Red;
                chk22.BackColor = Color.Red;
                chk23.BackColor = Color.Red;
                chk24.BackColor = Color.Red;
                if (int.Parse(it.Rcorect) == 1) chk21.BackColor = Color.Green;
                if (int.Parse(it.Rcorect) == 2) chk22.BackColor = Color.Green;
                if (int.Parse(it.Rcorect) == 3) chk23.BackColor = Color.Green;
                if (int.Parse(it.Rcorect) == 4) chk24.BackColor = Color.Green;

                if(int.Parse(it.Rcorect) != 1 && chk21.Checked == true)
                    ok = false;
                if(int.Parse(it.Rcorect) != 2 && chk22.Checked == true)
                    ok = false;
                if(int.Parse(it.Rcorect) != 3 && chk23.Checked == true)
                    ok = false;
                if(int.Parse(it.Rcorect) != 4 && chk24.Checked == true)
                    ok = false;
            }
            if(it.Tip == 3)
            {
                chk31.BackColor = Color.Red;
                chk32.BackColor = Color.Red;
                chk33.BackColor = Color.Red;
                chk34.BackColor = Color.Red;
                if (it.Rcorect.IndexOf("1") != -1) chk31.BackColor = Color.Green;
                if (it.Rcorect.IndexOf("2") != -1) chk32.BackColor = Color.Green;
                if (it.Rcorect.IndexOf("3") != -1) chk33.BackColor = Color.Green;
                if (it.Rcorect.IndexOf("4") != -1) chk34.BackColor = Color.Green;

                if (it.Rcorect.IndexOf("1") != -1 && chk31.Checked == false)
                    ok = false;
                if (it.Rcorect.IndexOf("2") != -1 && chk32.Checked == false)
                    ok = false;
                if (it.Rcorect.IndexOf("3") != -1 && chk33.Checked == false)
                    ok = false;
                if (it.Rcorect.IndexOf("4") != -1 && chk34.Checked == false)
                    ok = false;
            }
            if(it.Tip == 4)
            {
                chk41.BackColor = Color.Red;
                chk42.BackColor = Color.Red;
                if (int.Parse(it.Rcorect) == 1) chk41.BackColor = Color.Green;
                if (int.Parse(it.Rcorect) == 0) chk42.BackColor = Color.Green;

                if (int.Parse(it.Rcorect) != 1 && chk41.Checked == true)
                    ok = false;
                if (int.Parse(it.Rcorect) != 0 && chk42.Checked == true)
                    ok = false;
            }

            if (ok)
                GoodAns();
            else
                BadAns();
        }

        private void BadAns()
        {
        }

        private void GoodAns()
        {
            nota++;
        }

        private void btnUrm_Click(object sender, EventArgs e)
        {
            var it = ritemi[idx];
            string aux = "";
            if (it.Tip == 1)
                aux = txt1.Text;
            if(it.Tip == 2)
            {
                if (chk21.Checked)
                    aux = aux + "1";
                if (chk22.Checked)
                    aux = aux + "2";
                if (chk23.Checked)
                    aux = aux + "3";
                if (chk24.Checked)
                    aux = aux + "4";
            }
            if(it.Tip == 3)
            {
                if (chk31.Checked)
                    aux = aux + "1";
                if (chk32.Checked)
                    aux = aux + "2";
                if (chk33.Checked)
                    aux = aux + "3";
                if (chk34.Checked)
                    aux = aux + "4";
            }
            if(it.Tip == 4)
            {
                if (chk41.Checked)
                    aux = aux + "1";
                if (chk42.Checked)
                    aux = aux + "0";
            }

            
            corectans.Add(it.Rcorect);
            elevans.Add(aux);

            CleanUp();
            idx++;
            LoadInt();
        }

        private void CleanUp()
        {
            var it = ritemi[idx];


            lblItem.Text = "";
            txtInt.Text = "";

            if(it.Tip == 1)
            {
                lbl1.Visible = false;
                txt1.Text = "";
                txt1.Visible = false;
            }
            if(it.Tip == 2)
            {
                chk21.BackColor = TransparencyKey;
                chk22.BackColor = TransparencyKey;
                chk23.BackColor = TransparencyKey;
                chk24.BackColor = TransparencyKey;

                chk21.Checked = false;
                chk21.Visible = false;
                chk22.Checked = false;
                chk22.Visible = false;
                chk23.Checked = false;
                chk23.Visible = false;
                chk24.Checked = false;
                chk24.Visible = false;
            }
            if(it.Tip == 3)
            {
                chk31.BackColor = TransparencyKey;
                chk32.BackColor = TransparencyKey;
                chk33.BackColor = TransparencyKey;
                chk34.BackColor = TransparencyKey;

                chk31.Checked = false;
                chk31.Visible = false;
                chk32.Checked = false;
                chk32.Visible = false;
                chk33.Checked = false;
                chk33.Visible = false;
                chk34.Checked = false;
                chk34.Visible = false;
            }
            if (it.Tip == 4)
            {
                chk41.BackColor = TransparencyKey;
                chk42.BackColor = TransparencyKey;

                chk41.Checked = false;
                chk41.Visible = false;
                chk42.Checked = false;
                chk42.Visible = false;
            }

            btnAns.Visible = false;
        }

        private void InsertEvaluari(int idElev, DateTime dataEvaluare, int notaEvaluare)
        {
            SqlConnection con = new SqlConnection(connStr);
            con.Open();
            string query = "INSERT INTO Evaluari VALUES (@idElev,@dataEvaluare,@notaEvaluare)";
            SqlCommand cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@idElev", idElev);
            cmd.Parameters.AddWithValue("@dataEvaluare", dataEvaluare);
            cmd.Parameters.AddWithValue("@notaEvaluare", notaEvaluare);
            cmd.ExecuteNonQuery();

            con.Close();
            con.Dispose();
            cmd.Dispose();
        }

        private void tbc_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (tbc.SelectedIndex == 1)
                LoadCarnetDeNote();
            if (tbc.SelectedIndex == 2)
                LoadGraph();
        }

        private void LoadGraph()
        {
            idclasa.Clear();
            noteclasa.Clear();
            noteElev.Clear();
            chtNote.Series[0].Points.Clear();
            chtNote.Series[1].Points.Clear();
            chtNote.ChartAreas[0].AxisY.IntervalAutoMode = IntervalAutoMode.VariableCount;
            chtNote.Series[0].Color = Color.Red;
            chtNote.Series[0].BorderWidth = 7;
            chtNote.Series[0].LegendText = "Nota elev";
            chtNote.Series[1].Color = Color.Blue;
            chtNote.Series[1].BorderWidth = 7;
            chtNote.Series[1].LegendText = "Nota medie a clasei";
            chtNote.ChartAreas[0].AxisX.Title = "Data evaluarii";
            chtNote.ChartAreas[0].AxisY.Title = "Nota";

            DateTime dday = DateTime.Now;
            DateTime p1 = dday, p2 = dday;

            SqlConnection con = new SqlConnection(connStr);
            con.Open();
            string query = "SELECT IdUtilizator FROM Utilizatori WHERE ClasaUtilizator = @clasa";
            SqlCommand cmd = new SqlCommand(query,con);
            cmd.Parameters.AddWithValue("@clasa", clasa);
            var rd = cmd.ExecuteReader();

            while(rd.Read())
                idclasa.Add(rd.GetInt32(0));

            foreach(int x in idclasa)
            {
                rd.Close();
                query = "SELECT NotaEvaluare FROM Evaluari WHERE IdElev = @id";
                cmd = new SqlCommand(query,con);
                cmd.Parameters.AddWithValue("@id", x);
                rd = cmd.ExecuteReader();

                while( rd.Read())
                    noteclasa.Add(rd.GetInt32(0));
            }

            int sum = 0;
            foreach (int x in noteclasa)
                sum += x;

            double y = sum / (double) noteclasa.Count;

            rd.Close();
            query = "SELECT * FROM Evaluari WHERE IdElev = @id";
            cmd = new SqlCommand(query,con);
            cmd.Parameters.AddWithValue("@id", id);
            rd = cmd.ExecuteReader();

            while (rd.Read())
                noteElev.Add(new KeyValuePair<int, DateTime>((int)rd[3], (DateTime)rd[2]));

            foreach (var x in noteElev)
            {
                if (p1 == dday || p1 > x.Value)
                    p1 = x.Value;
                if (p2 == dday || p2 < x.Value)
                    p2 = x.Value;

                chtNote.Series[0].Points.AddXY(x.Value, x.Key);
            }

            chtNote.Series[1].Points.AddXY(p1, y);
            chtNote.Series[1].Points.AddXY(p2, y);

            con.Close();
            con.Dispose();
            cmd.Dispose();
            rd.Close();
            rd.Dispose();

        }

        private void LoadCarnetDeNote()
        {
            dgwCarnet.Rows.Clear();
            dgwCarnet.Columns.Clear();
            dgwCarnet.AllowUserToAddRows = false;

            SqlConnection con = new SqlConnection(connStr);
            con.Open();
            string query = "SELECT * FROM Utilizatori WHERE IdUtilizator = @id";
            SqlCommand cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@id", id);
            var rd = cmd.ExecuteReader();
            rd.Read();

            lblCarnet.Text = $"Carnetul de note al elevului {(string)rd[1]}";
            rd.Close();

            DataGridViewTextBoxColumn nt = new DataGridViewTextBoxColumn();
            nt.Width = 300;
            nt.Name = "Note";
            nt.HeaderText = "Note";
            dgwCarnet.Columns.Add(nt);
            DataGridViewTextBoxColumn dt = new DataGridViewTextBoxColumn();
            dt.Width = 300;
            dt.Name = "Data";
            dt.HeaderText = "Data";
            dgwCarnet.Columns.Add(dt);

            dgwCarnet.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;

            query = "SELECT * FROM Evaluari WHERE IdElev = @id";
            cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@id", id);
            rd = cmd.ExecuteReader();
            while (rd.Read())
                dgwCarnet.Rows.Add((int)rd[3], (DateTime)rd[2]);

            con.Close();
            con.Dispose();
            cmd.Dispose();
        }

        private void btnPre_Click(object sender, EventArgs e)
        {
            stringtoprint = "";
            var sw = new StreamWriter($@"{Directory.GetCurrentDirectory()}\carnetnote.txt");

            foreach (DataGridViewRow x in dgwCarnet.Rows)
            {
                stringtoprint += $"{x.Cells[0].Value}      {x.Cells[1].Value}\n";
                sw.WriteLine($@"{x.Cells[0].Value}      {x.Cells[1].Value}");
            }

            sw.Close();

            var doc = new System.Drawing.Printing.PrintDocument();
            doc.DocumentName = $@"{Directory.GetCurrentDirectory()}\carnetnote.txt";
            doc.PrintPage += doc_PrintPage;

            var ppd = new PrintPreviewDialog();
            ppd.Document = doc;
            ppd.ShowDialog();
        }

        private void doc_PrintPage(object sender, PrintPageEventArgs e)
        {
            int charfitted, linefitted;
            e.Graphics.MeasureString(stringtoprint, this.Font, e.MarginBounds.Size, StringFormat.GenericTypographic,
                out charfitted, out linefitted);

            e.Graphics.DrawString(stringtoprint, this.Font, Brushes.Black, e.MarginBounds);

            stringtoprint.Substring(charfitted);

            if (stringtoprint.Length == 0)
                e.HasMorePages = false;
        }
    }
}
