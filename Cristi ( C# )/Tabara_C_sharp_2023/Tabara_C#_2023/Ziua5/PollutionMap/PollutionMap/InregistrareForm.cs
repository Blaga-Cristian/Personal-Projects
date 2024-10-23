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

namespace PollutionMap
{
    public partial class InregistrareForm : Form
    {
        private string connStr = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\PoluareDB.mdf;Integrated Security=True;";
        
        public InregistrareForm()
        {
            InitializeComponent();
        }

        private void btnRenunta_Click(object sender, EventArgs e)
        {
            Close();
        }

        bool EmailValid(string email)
        {
            var trimmedEmail = email.Trim(); // inlatura spatiile de la capete

            if (trimmedEmail.EndsWith("."))
            {
                return false; // suggested by @TK-421
            }
            try
            {
                var addr = new System.Net.Mail.MailAddress(email);
                return addr.Address == trimmedEmail;
            }
            catch
            {
                return false;
            }
        }
        private void btnSalveaza_Click(object sender, EventArgs e)
        {
            string user = txtUtiliz.Text;
            if (user == "")
            {
                MessageBox.Show("Campul Nume utilizator nu trebuie s afie vid!");
                return;
            }
            if (user.Length < 4)
            {
                MessageBox.Show("Lungimea Numelui de utilizator trebuie sa fie cel putin patru caractere!");
                return;
            }

            string pass = txtParola.Text;
            string confirm = txtConfirm.Text;

            if (pass == "" || confirm == "")
            {
                MessageBox.Show("Campul parola trebuie sa fie nevide!");
                return;
            }

            if (pass.Length < 6 || confirm.Length < 6)
            {
                MessageBox.Show("Lungimea parole trebuie sa fie cel putin sase caractere!");
                return;
            }
            if (pass != confirm)
            {
                MessageBox.Show("parola nu coincide cu confirmarea parolei!");
                return;
            }

            string email = txtEmail.Text;
            if (!EmailValid(email))
            {
                MessageBox.Show("Adresa de email invalida!");
                return;
            }

            InsertUtilizator(user, pass, email);
            this.Close();
        }

        private void InsertUtilizator(string user, string pass, string email)
        {
            var con = new SqlConnection(connStr); 
            con.Open();
            string query = "INSERT INTO Utilizatori VALUES(@utilizator, @parola, @email, @data)";
            var cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@utilizator", user);
            cmd.Parameters.AddWithValue("@parola", pass);
            cmd.Parameters.AddWithValue("@email", email);
            cmd.Parameters.AddWithValue("@data", DateTime.Now);
            cmd.ExecuteNonQuery();

            con.Close();
            con.Dispose();
            cmd.Dispose();
        }
    }
}
