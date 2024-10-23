using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Data.SqlClient;


namespace PollutionMap
{
    public partial class AutentificareForm : Form
    {
        private string connStr = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\PoluareDB.mdf;Integrated Security=True;";
        private string resPath = $@"{Directory.GetCurrentDirectory()}\..\..\Resurse\";
        private List<Cerc> cercuri = new List<Cerc>();

        public AutentificareForm()
        {
            InitializeComponent();

            IncarcaHarti();
            IncarcaMasurari();
             
        }

        private void IncarcaMasurari()
        {
            StreamReader sr = new StreamReader(resPath + "masurari.txt");
            string line;
            string[] s;
            char[] sep = { '#' };
            while ((line = sr.ReadLine()) != null)
            {
                
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                string nume_harta = s[0];
                int id_harta = GetIdHarta(nume_harta);
                int x = int.Parse(s[1]);
                int y = int.Parse(s[2]);
                int poluare = int.Parse(s[3]);
                DateTime dt = DateTime.ParseExact(s[4], "dd/MM/yyyy HH:mm", 
                    System.Globalization.CultureInfo.InvariantCulture);

                InsertMasurare(id_harta, x, y, poluare, dt);
                cercuri.Add(new Cerc(nume_harta, x, y, poluare, dt));
            }
        }

        private void InsertMasurare(int id_harta, int x, int y, int poluare, DateTime dt)
        {
            var con = new SqlConnection(connStr);
            con.Open();
            string query = "INSERT INTO Masurare VALUES (@id_harta, @pozX, @pozY, @poluare, @dataMas)";
            var cmd = new SqlCommand(query, con);   
            cmd.Parameters.AddWithValue("@id_harta", id_harta);
            cmd.Parameters.AddWithValue("@pozX", x);
            cmd.Parameters.AddWithValue("@pozY", y);
            cmd.Parameters.AddWithValue("@poluare", poluare);
            cmd.Parameters.AddWithValue("@dataMas", dt);
            cmd.ExecuteNonQuery();

            con.Close();
            con.Dispose();
            cmd.Dispose();
        }

        private int GetIdHarta(string nume_harta)
        {
            var con = new SqlConnection(connStr); 
            con.Open();
            int id;
            string query = "SELECT IdHarta FROM Harti WHERE NumeHarta = @nume_harta";
            
            var cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@nume_harta", nume_harta);
            var rd = cmd.ExecuteReader();
            rd.Read();
            id = (int)rd[0];

            rd.Close();
            con.Close();
            cmd.Dispose();
            con.Dispose();

            return id;
        }

        private void IncarcaHarti()
        {
            StreamReader sr = new StreamReader(resPath + "harti.txt");
            string line;
            string[] s;
            char[] sep = {'#'};
            while ((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                string nume_harta = s[0];
                string fisier_harta = s[1];
                InsertHarta(nume_harta, fisier_harta);
            }
            sr.Close();
        }

        private void InsertHarta(string nume_harta, string fisier_harta)
        {
            SqlConnection con = new SqlConnection(connStr);
            con.Open();
            string query = "INSERT INTO Harti VALUES(@nume_harta, @fisier_harta)";
            var cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@nume_harta", nume_harta);
            cmd.Parameters.AddWithValue("@fisier_harta", fisier_harta);
            cmd.ExecuteNonQuery();
            con.Close();
            con.Dispose();
            cmd.Dispose();
        }

        private void btnContNou_Click(object sender, EventArgs e)
        {
            InregistrareForm frm = new InregistrareForm();
            this.Visible = false;
            frm.ShowDialog();
            this.Visible = true;
        }

        private void btnLogare_Click(object sender, EventArgs e)
        {
            Logare();
        }

        private void Logare()
        {
            string user = txtNume.Text;
            string pass = txtParola.Text;
            if (!ExistaUtilizator(user, pass))
            {
                MessageBox.Show("Nume de utilizator sau parola incorecte!");
                txtNume.Text = "";
                txtParola.Text = "";
                return;
            }
            else
            {
                UpdateLoginTime(user, pass);
                VizualizareForm frm = new VizualizareForm(cercuri, user);
                this.Visible = false;
                frm.ShowDialog();
                Application.Exit();
            }
        }

        private void UpdateLoginTime(string user, string pass)
        {
            string query = "UPDATE Utilizatori SET UltimaUtilizare = @data WHERE NumeUtilizator = @user AND Parola = @pass";
            var con = new SqlConnection(connStr);
            con.Open();
            var cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@data", DateTime.Now);
            cmd.Parameters.AddWithValue("@user", user);
            cmd.Parameters.AddWithValue("@pass", pass);
            int x = (int)cmd.ExecuteNonQuery(); // pt INSERT, UPDATE, DELETE
            con.Close();
            cmd.Dispose();
            con.Dispose();
        }

        private bool ExistaUtilizator(string user, string pass)
        {
            string query = "SELECT COUNT(NumeUtilizator) FROM Utilizatori WHERE NumeUtilizator = @nume AND Parola = @parola";
            var con = new SqlConnection(connStr);
            con.Open();
            var cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@nume", user);
            cmd.Parameters.AddWithValue("@parola", pass);
            int x = (int)cmd.ExecuteScalar();
            con.Close();
            cmd.Dispose();
            con.Dispose();
            return x == 1;
        }

        private void txtParola_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                Logare();
            }
        }
    }
}
