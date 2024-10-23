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
using System.Data.SqlTypes;
using System.Runtime.Remoting.Metadata.W3cXsd2001;
using System.Globalization;

namespace Turismul_Durabil
{
    public partial class Vizualizare_excursie : Form
    {
        private string conStr = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\Turism.mdf;Integrated Security=True";
        private List<Excursie> planificari = new List<Excursie>();
        private DateTime now = DateTime.Now;
        private List<Excursie> itinerariu = new List<Excursie>();
        private List<Excursie> sortareit = new List<Excursie>();
        private List<string> impaths = new List<string>();
        private int idx = 0;

        int index;
        string nume;
        DateTime data;
        Timer timer = new Timer();

        public Vizualizare_excursie()
        {
            InitializeComponent();

            IncarcaPlanificari();
            prgb.Maximum = 1000;
            pb.SizeMode = PictureBoxSizeMode.StretchImage;
        }

        private void IncarcaPlanificari()
        {
            dgw.Columns.Clear();
            for (int i = 0; i < 5; ++i)
                dgw.Columns.Add(new DataGridViewTextBoxColumn());
            dgw.Columns[0].HeaderText = "Nume";
            dgw.Columns[1].HeaderText = "Data start";
            dgw.Columns[2].HeaderText = "Data stop";
            dgw.Columns[3].HeaderText = "Frecventa";
            dgw.Columns[4].HeaderText = "Ziua";
            dgw.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;

            SqlConnection con = new SqlConnection(conStr);con.Open();
            string query = "SELECT * FROM Planificari";
            var cmd = new SqlCommand(query, con);
            var rd = cmd.ExecuteReader();
            while(rd.Read())
            {
                var id = rd.GetInt32(1);
                var nume = GetNumeLoc(id);
                var frecventa = (string)rd[2];
                var dataStart = rd.GetSqlDateTime(3);
                var dataStop = rd.GetSqlDateTime(4);
                var ziua = rd.GetSqlInt32(5);

                dgw.Rows.Add(GetNumeLoc(id), frecventa, dataStart, dataStop, ziua);
                if (frecventa == "ocazional")
                    planificari.Add(new Excursie(nume, (DateTime)dataStart, (DateTime)dataStop, frecventa, 0));
                else
                    planificari.Add(new Excursie(nume, now, now, frecventa, (int)ziua));

            }

            for (int i = 0; i < dgw.Rows.Count; ++i)
            {
                for (int j = 0; j < dgw.Columns.Count; ++j)
                {
                    if (dgw.Rows[i].Cells[j].Value.ToString() == "Null")
                        dgw.Rows[i].Cells[j].Value = "";
                }

                string s0 = dgw.Rows[i].Cells[0].Value.ToString();
                string s1 = dgw.Rows[i].Cells[1].Value.ToString();
                string s2 = dgw.Rows[i].Cells[2].Value.ToString();
                string s3 = dgw.Rows[i].Cells[3].Value.ToString();


                if (dgw.Rows[i].Cells[2].Value.ToString() != "")
                    dgw.Rows[i].Cells[2].Value = (DateTime.Parse(dgw.Rows[i].Cells[2].Value.ToString())).ToString("dd.MM.yyyy");
                if (dgw.Rows[i].Cells[3].Value.ToString() != "")
                    dgw.Rows[i].Cells[3].Value = (DateTime.Parse(dgw.Rows[i].Cells[3].Value.ToString())).ToString("dd.MM.yyyy");
            }
        }

        private string GetNumeLoc(int id)
        {
            SqlConnection con = new SqlConnection(conStr); con.Open();
            string query = "SELECT * FROM Localitati WHERE IdLocalitate = @id";
            SqlCommand cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@id", id);
            var rd = cmd.ExecuteReader();
            rd.Read();
            return (string)rd[1];
        }

        private void btnGen_Click(object sender, EventArgs e)
        {
            itinerariu.Clear();
            IncarcaPerioade();
            IncarcaItinierariu();
        }

        private void IncarcaItinierariu()
        {
            sortareit.Clear();
            dgwItinerariu.Rows.Clear();
            dgwItinerariu.Columns.Clear();

            for (int i = 0; i < 2; ++i)
                dgwItinerariu.Columns.Add(new DataGridViewTextBoxColumn());

            dgwItinerariu.Columns[0].HeaderText = "Nume";
            dgwItinerariu.Columns[1].HeaderText = "Data";

            dgwItinerariu.AllowUserToAddRows = false;
            dgwItinerariu.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;

            foreach (var x in itinerariu)
                InsertDates(x);

            sortareit.Sort((a,b) => a.DataStart.CompareTo(b.DataStart));

            foreach(var x in sortareit)
                dgwItinerariu.Rows.Add(x.Nume, x.DataStart.ToString("dd.MM.yyyy"));
        }

        private void InsertDates(Excursie x)
        {
            for (var date = x.DataStart; date.Date <= x.DataStop.Date; date = date.AddDays(1))
                sortareit.Add(new Excursie(x.Nume, date, date, "", 0));
        }

        private void IncarcaPerioade()
        {
            dgwPer.Columns.Clear();
            dgwPer.Rows.Clear();

            for (int i = 0; i < 4; ++i)
                dgwPer.Columns.Add(new DataGridViewTextBoxColumn());

            dgwPer.Columns[0].HeaderText = "Nume";
            dgwPer.Columns[1].HeaderText = "Data Start";
            dgwPer.Columns[2].HeaderText = "Data Stop";
            dgwPer.Columns[3].HeaderText = "Frecventa";

            dgwPer.AllowUserToAddRows = false;
            dgwPer.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;

            DateTime start = dtpStart.Value;
            DateTime stop = dtpStop.Value;

            foreach (var x in planificari)
            {
                if (x.Frecventa == "ocazional")
                {
                    if ((x.DataStart >= start && x.DataStart <= stop) || (x.DataStop >= start && x.DataStop <= stop))
                    {
                        var auxstart = x.DataStart;
                        var auxstop = x.DataStop;
                        if (x.DataStart < start)
                            auxstart = start;
                        if (x.DataStop > stop)
                            auxstop = stop;

                        dgwPer.Rows.Add(x.Nume, auxstart.ToString("dd.MM.yyyy"), auxstop.ToString("dd.MM.yyyy"), x.Frecventa);
                        itinerariu.Add(new Excursie(x.Nume, auxstart, auxstop, "", 0));
                    }
                }
                else if (x.Frecventa == "lunar")
                    GenRowsMon(x, start, stop);
                else
                    GenRowsYear(x, start, stop);
            }
        }

        private void GenRowsYear(Excursie x, DateTime start, DateTime stop)
        {
            var date = start;
            int year = start.Year;
            while(date <= stop)
            {
                date = DateTime.ParseExact($"01.01.{year}", "dd.MM.yyyy", CultureInfo.InvariantCulture);
                date = date.AddDays(x.Ziua - 1);

                if (date > stop) break;

                if (date >= start)
                {
                    dgwPer.Rows.Add(x.Nume, date.ToString("dd.MM.yyyy"), date.Date.ToString("dd.MM.yyyy"), x.Frecventa);
                    itinerariu.Add(new Excursie(x.Nume, date, date, "", 0));
                }

                year++;
            }
        }

        private void GenRowsMon(Excursie x, DateTime start, DateTime stop)
        {
            var date = start;
            int month = start.Month, year = start.Year;
            int ziua = x.Ziua;
            while(date <= stop)
            {
                try
                {
                    date = DateTime.ParseExact($"{x.Ziua}/{month}/{year}", "d/M/yyyy", CultureInfo.InvariantCulture);

                    if (date > stop) break;

                    if (date >= start)
                    {
                        dgwPer.Rows.Add(x.Nume, date.ToString("dd.MM.yyyy"), date.ToString("dd.MM.yyyy"), x.Frecventa);
                        itinerariu.Add(new Excursie(x.Nume, date, date, "", 0));
                    }
                }
                catch
                {
                }

                string s = $"1/{month}/{year}";
                if (DateTime.ParseExact(s, "d/M/yyyy", CultureInfo.InvariantCulture) > stop)break;                

                month++;
                if(month == 13)
                {
                    month = 1;
                    year++;
                }                                
            }
        }

        private void tabControl1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (tbc.SelectedIndex == 0)
                IncarcaPlanificari();
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            nume = "";
            index = 0;

            IncarcaImagine();
            timer.Interval = 2000;
            timer.Tick += TickEventHandler;
            timer.Start();
        }

        private void TickEventHandler(object sender, EventArgs e)
        {
            IncarcaImagine();
        }

        private void IncarcaImagine()
        {
            if(index == sortareit.Count)
            {
                timer.Stop();
                timer.Tick -= TickEventHandler;
                lblNume.Text = "";
                lblData.Text = "";
                prgb.Value = 0;
                pb.Image.Dispose();
                pb.Image = null;
                return;
            }

            if (nume != sortareit[index].Nume)
            {
                GetImagini(sortareit[index].Nume);
                nume = sortareit[index].Nume;
            }
            data = sortareit[index].DataStart;

            lblNume.Text = nume;
            lblData.Text = data.ToString("dd.MM.yyyy");

            pb.Image = Image.FromFile(impaths[idx]);
            idx = (idx + 1) % impaths.Count;

            prgb.Value = prgb.Maximum / sortareit.Count * (index + 1);

            index++;
        }

        private void GetImagini(string nume)
        {
            impaths.Clear();
            idx = 0;

            SqlConnection con = new SqlConnection(conStr);
            con.Open();
            string query = "SELECT IdLocalitate FROM Localitati WHERE Nume = @nume";
            SqlCommand cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@nume", nume);
            var rd = cmd.ExecuteScalar();
            int id = (int)rd;

            query = "SELECT CaleFisier FROM Imagini WHERE Idlocatie = @id";
            cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@id", id);
            var reader = cmd.ExecuteReader();

            while (reader.Read())
                impaths.Add((string)reader[0]);

            reader.Close();
            reader.Dispose();
            con.Close();
            con.Dispose();
            cmd.Dispose();
        }
    }
}
