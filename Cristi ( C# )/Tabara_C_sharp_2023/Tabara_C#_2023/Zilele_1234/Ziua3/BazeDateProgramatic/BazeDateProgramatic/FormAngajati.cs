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

namespace BazeDateProgramatic
{
    public partial class FormAngajati : Form
    {
        private string connStr = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\FirmaDB.mdf;Integrated Security=True;";
      

        public FormAngajati()
        {
            InitializeComponent();

            SelectTotiAngajatii();
        }

        private void SelectTotiAngajatii()
        {
            SqlConnection conn = new SqlConnection(connStr);
            conn.Open();
            string query = "SELECT * FROM Angajati";
            SqlCommand cmd = new SqlCommand(query, conn);
            SqlDataReader dr = cmd.ExecuteReader(); // pentru SELECT
            DataTable dt = new DataTable();
            dt.Load(dr);
            dgwAngajati.DataSource = dt;
            dgwAngajati.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            dgwAngajati.AllowUserToAddRows = false;

            // IMPORTANT!
            dr.Close();
            conn.Close();

            conn.Dispose();
            cmd.Dispose();
        }

        private void btnAdauga_Click(object sender, EventArgs e)
        {

            string nume = txtNume.Text;
            string pozitie = txtPozitie.Text;
            int salariu = int.Parse(txtSalariu.Text);
            DateTime data_ang = dtpDataAng.Value;

            InsertAngajat(nume, pozitie, salariu, data_ang);

            SelectTotiAngajatii();
        }

        private void InsertAngajat(string nume, string pozitie, int salariu, DateTime data_ang)
        {
            SqlConnection con = new SqlConnection(connStr);
            con.Open();
            string query = "INSERT INTO Angajati VALUES (@nume, @pozitie, @salariu, @dataAngajarii)";

            SqlCommand cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@nume", nume);
            cmd.Parameters.AddWithValue("@pozitie", pozitie);
            cmd.Parameters.AddWithValue("@salariu", salariu);
            cmd.Parameters.AddWithValue("@dataAngajarii", data_ang);

            cmd.ExecuteNonQuery(); // pt INSERT, DELETE, UPDATE
            con.Close();
            con.Dispose();
            cmd.Dispose();
        }

        private void UpdateAngajat(int id, string nume, string pozitie, int salariu, DateTime data_ang)
        {
            var con = new SqlConnection(connStr);
            con.Open();
            string query = "UPDATE Angajati SET Nume=@nume, Pozitia=@pozitie, Salariu=@salariu, DataAngajarii = @dataAngajarii WHERE IdAngajat = @id";

            var cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@nume", nume);
            cmd.Parameters.AddWithValue("@pozitie", pozitie);
            cmd.Parameters.AddWithValue("@salariu", salariu);
            cmd.Parameters.AddWithValue("@dataAngajarii", data_ang);
            cmd.Parameters.AddWithValue("@id", id);

            cmd.ExecuteNonQuery(); // pt INSERT, DELETE, UPDATE
            con.Close();
            con.Dispose();
            cmd.Dispose();
        }

        private void btnModifica_Click(object sender, EventArgs e)
        {
            string nume = txtNumeNou.Text;
            string pozitie = txtPozitieNou.Text;
            int salariu = int.Parse(txtSalariuNou.Text);
            DateTime dataAng = dtpDataAngNou.Value;
            int id = int.Parse(txtID.Text);
            UpdateAngajat(id, nume, pozitie, salariu, dataAng);
            SelectTotiAngajatii();
        }
    }
}
