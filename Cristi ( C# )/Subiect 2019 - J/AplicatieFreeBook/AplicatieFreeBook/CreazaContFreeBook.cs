using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Net.Mail;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AplicatieFreeBook
{
    public partial class CreazaContFreeBook : Form
    {
        string connStr = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\FreeBook.mdf;Integrated Security = True; Connect Timeout = 30";

        public CreazaContFreeBook()
        {
            InitializeComponent();
        }

        private void btnInregistrare_Click(object sender, EventArgs e)
        {
            string email = txtEmail.Text;
            string nume = txtNume.Text;
            string prenume = txtPrenume.Text;
            string parola = txtParola.Text;
            string confparola = txtConfParola.Text;

            if (!IsValid(email) || !Unic(email))
            {
                MessageBox.Show("Adresa de email este invalida", "Eroare", MessageBoxButtons.OK);
                return;
            }
            if (nume == "")
            {
                MessageBox.Show("Numele este invalid", "Eroare", MessageBoxButtons.OK);
                return;
            }
            if (prenume == "")
            {
                MessageBox.Show("Prenumele este invalid", "Eroare", MessageBoxButtons.OK);
                return;
            }
            if (parola == "")
            {
                MessageBox.Show("Parola este invalida", "Eroare", MessageBoxButtons.OK);
                return;
            }
            if (parola != confparola)
            {
                MessageBox.Show("Parolele nu coincid", "Eroare", MessageBoxButtons.OK);
                return;
            }

            InsertUtilizator(email, parola, nume, prenume);

            MeniuFreeBookForm frm = new MeniuFreeBookForm(email);
            this.Visible = false;
            frm.ShowDialog();
            Application.Exit();
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

        private bool Unic(string email)
        {
            SqlConnection con = new SqlConnection(connStr);
            con.Open();
            string query = "SELECT COUNT(email) FROM utilizatori WHERE email = @email";
            SqlCommand cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@email", email);
            return (int)cmd.ExecuteScalar() == 0;
        }

        private bool IsValid(string email)
        {
            try
            {
                new MailAddress(email);
                return true;
            }
            catch
            {
                return false;
            }
        }
    }
}
