using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Runtime.Remoting.Contexts;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.ListView;

namespace AplicatieFreeBook
{
    public partial class FreeBookHome : Form
    {
        private string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\csarp\";
        string connStr = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\FreeBook.mdf;Integrated Security = True; Connect Timeout = 30";

        public FreeBookHome()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            StreamReader sr = new StreamReader(respath + "utilizatori.txt");
            string line;
            string[] s;
            char[] sep = { '*' };

            while((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                string email = s[0];
                string parola = s[1];
                string nume = s[2];
                string prenume = s[3];

                InsertUtilizator(email,parola, nume, prenume);
            }

            sr = new StreamReader(respath + "carti.txt");

            while ((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                string titlu = s[0];
                string autor = s[1];
                string gen = s[2];

                InsertCarte(titlu, autor, gen);
            }

            sr = new StreamReader(respath + "imprumuturi.txt");

            while ((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                int id_carte = GetIdCarte(s[0]);
                string email = s[1];
                int x = s[2].Length;
                s[2] = s[2].Substring(0, x - 1);

                DateTime dataimprumut = DateTime.ParseExact(s[2], "M/d/yyyy", System.Globalization.CultureInfo.InvariantCulture);

                InsertImprumut(id_carte,email,dataimprumut);
            }            
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

        private void InsertCarte(string titlu, string autor, string gen)
        {
            SqlConnection con = new SqlConnection(connStr);
            con.Open();
            string query = "INSERT INTO carti VALUES (@titlu,@autor,@gen)";
            SqlCommand cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@titlu", titlu);
            cmd.Parameters.AddWithValue("@autor", autor);
            cmd.Parameters.AddWithValue("@gen", gen);

            cmd.ExecuteNonQuery();
            con.Close();
            con.Dispose();
            cmd.Dispose();
        }

        private void InsertImprumut(int id_carte, string email, DateTime dataimprumut)
        {
            SqlConnection con = new SqlConnection(connStr);
            con.Open();
            string query = "INSERT INTO imprumut VALUES (@id_carte,@email,@datetime)";
            SqlCommand cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@id_carte", id_carte);
            cmd.Parameters.AddWithValue("@email", email);
            cmd.Parameters.AddWithValue("@datetime", dataimprumut);

            cmd.ExecuteNonQuery();
            con.Close();
            con.Dispose();
            cmd.Dispose();
        }

        private void InsertUtilizator(string email, string parola, string nume, string prenume)
        {
            SqlConnection con = new SqlConnection(connStr);
            con.Open();
            string query = "INSERT INTO utilizatori VALUES (@email,@parola,@nume,@prenume)";
            SqlCommand cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@email", email);
            cmd.Parameters.AddWithValue("@parola", parola);
            cmd.Parameters.AddWithValue("@nume", nume);
            cmd.Parameters.AddWithValue("@prenume", prenume);

            cmd.ExecuteNonQuery();
            con.Close();
            con.Dispose();
            cmd.Dispose();
        }

        private void btnAutentificare_Click(object sender, EventArgs e)
        {
            CreazaContFreeBook frm = new CreazaContFreeBook();
            this.Visible = false;
            frm.ShowDialog();
            this.Visible = true;
        }

        private void btnLogare_Click(object sender, EventArgs e)
        {
            LogareFreeBooks frm = new LogareFreeBooks();
            this.Visible = false;
            frm.ShowDialog();
            this.Visible=true;
        }
    }
}
