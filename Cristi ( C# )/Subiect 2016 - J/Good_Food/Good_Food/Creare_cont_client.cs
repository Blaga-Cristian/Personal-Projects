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
using System.Net.Mail;

namespace Good_Food
{
    public partial class Creare_cont_client : Form
    {
        private string conStr = $@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\GOOD_FOOD.mdf;Integrated Security=True";
        public Creare_cont_client()
        {
            InitializeComponent();
        }

        private void btnCreaza_Click(object sender, EventArgs e)
        {
            string email = txtEmail.Text;
            bool res1 = Valid(txtEmail.Text);
            bool res2 = Unic(txtEmail.Text);
            if (!res1 || !res1)
            {
                txtEmail.Text = "";
                return;
            }

            AdaugaCont(txtParola.Text, txtNume.Text, txtPrenume.Text, txtAdresa.Text, txtEmail.Text, 0);

            this.Close();
        }

        private bool Valid(string text)
        {
            try
            {
                var x = new MailAddress(text);
                return true;
            }
            catch { return false; }
        }

        private void AdaugaCont(string parola, string nume, string prenume, string adresa, string email, int kcal)
        {
            var con = new SqlConnection(conStr);
            con.Open();
            string query = "INSERT INTO Clienti VALUES ( @parola, @nume, @prenume, @adresa, @email, @kcal)";
            var cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@parola", parola);
            cmd.Parameters.AddWithValue("@nume", nume);
            cmd.Parameters.AddWithValue("@prenume", prenume);
            cmd.Parameters.AddWithValue("@adresa", adresa);
            cmd.Parameters.AddWithValue("@email", email);
            cmd.Parameters.AddWithValue("@kcal", kcal);
            cmd.ExecuteNonQuery();

            con.Close();
            con.Dispose();
            cmd.Dispose();
        }

        private bool Unic(string email)
        {
            SqlConnection con = new SqlConnection(conStr);
            con.Open();
            string query = "SELECT COUNT(*) FROM Clienti WHERE email = @email";
            var cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@email", email);
            var sr = cmd.ExecuteScalar();

            con.Close();
            con.Dispose();
            cmd.Dispose();

            return (int)sr == 1;
        }
    }
}
