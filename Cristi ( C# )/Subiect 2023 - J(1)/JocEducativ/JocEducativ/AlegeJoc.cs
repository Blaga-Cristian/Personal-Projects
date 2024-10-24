using JocEducativ.JocEducativDBTableAdapters;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Drawing.Text;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace JocEducativ
{
    public partial class AlegeJoc : Form
    {
        private string conStr = $@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\JocEducativ.mdf;Integrated Security=True";

        private JocEducativDBTableAdapters.UtilizatoriTableAdapter utilizatoriTableAdapter = new JocEducativDBTableAdapters.UtilizatoriTableAdapter();
        private JocEducativDBTableAdapters.RezultateTableAdapter rezultateTableAdapter = new JocEducativDBTableAdapters.RezultateTableAdapter();
        private JocEducativDBTableAdapters.ItemiTableAdapter itemiTableAdapter = new JocEducativDBTableAdapters.ItemiTableAdapter();
        private JocEducativDB.UtilizatoriDataTable dataTable = new JocEducativDB.UtilizatoriDataTable();
        private List<Scor> scoruriGhiceste = new List<Scor>();
        private List<Scor> scoruriSarpeEducativ = new List<Scor>();

        private string emailUtilizator;
        private string numeUtilizator;
        public AlegeJoc(string emailUtilizator)
        {
            InitializeComponent();
            this.emailUtilizator = emailUtilizator;
            numeUtilizator = GetNumeUtilizator(emailUtilizator);
            lblEmail.Text = "Bine ai venit, " + numeUtilizator + "! (" + emailUtilizator + ")";
            IncarcaGhiceste();
            IncarcaSarpeEducativ();
        }

        private void IncarcaSarpeEducativ()
        {
            scoruriSarpeEducativ.Clear();
            var con = new SqlConnection(conStr);
            con.Open();
            string query = "SELECT EmailUtilizator, PunctajJoc FROM Rezultate WHERE TipJoc = 1 ORDER BY PunctajJoc DESC";
            var cmd = new SqlCommand(query, con);
            var rd = cmd.ExecuteReader();

            int i = 1;
            while (rd.Read() && i <= 3)
            {
                string emailUtilizator = rd[0].ToString();
                string numeUtilizator = GetNumeUtilizator(emailUtilizator);
                int punctajJoc = (int)rd[1];

                scoruriSarpeEducativ.Add(new Scor(numeUtilizator, emailUtilizator, punctajJoc));
                ++i;
            }

            dgw2.DataSource = scoruriSarpeEducativ;
            dgw2.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
        }

        private void IncarcaGhiceste()
        {
            scoruriGhiceste.Clear();
            var con = new SqlConnection(conStr);
            con.Open();
            string query = "SELECT EmailUtilizator, PunctajJoc FROM Rezultate WHERE TipJoc = 0 ORDER BY PunctajJoc DESC";
            var cmd = new SqlCommand(query, con);
            var rd = cmd.ExecuteReader();

            int i = 1;
            while(rd.Read() && i <= 3)
            {
                string emailUtilizator = rd[0].ToString();
                string numeUtilizator = GetNumeUtilizator(emailUtilizator);
                int punctajJoc = (int)rd[1];

                scoruriGhiceste.Add(new Scor(numeUtilizator, emailUtilizator, punctajJoc));
                ++i;
            }

            dgw1.DataSource = scoruriGhiceste;
            dgw1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
        }

        private string GetNumeUtilizator(string emailUtilizator)
        {
            var con = new SqlConnection(conStr);
            con.Open();
            string query = "SELECT NumeUtilizator FROM Utilizatori WHERE EmailUtilizator = @emailUtilizator";
            var cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("emailUtilizator", emailUtilizator);
            var rd = cmd.ExecuteReader();
            rd.Read();
            string ans = rd[0].ToString();
            con.Close();
            con.Dispose();
            cmd.Dispose();
            return ans;
        }

        private void btnGhiceste_Click(object sender, EventArgs e)
        {
            var frm = new GhicesteCuvant(emailUtilizator);
            this.Visible = false;
            frm.ShowDialog();
            this.Visible = true;
            IncarcaGhiceste();
        }

        private void btnSarpeEducativ_Click(object sender, EventArgs e)
        {
            var frm = new SarpeEducativ(emailUtilizator);
            this.Visible = false;
            frm.ShowDialog();
            this.Visible = true;
            IncarcaSarpeEducativ();
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            var dr = MessageBox.Show("Sunteti sigur ca doriti sa iesiti din aplicatie?", "Iesire", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (dr == DialogResult.Yes)
                this.Close();
        }
    }
}
