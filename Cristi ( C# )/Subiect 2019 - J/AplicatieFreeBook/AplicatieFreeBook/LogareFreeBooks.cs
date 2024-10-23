using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AplicatieFreeBook
{
    public partial class LogareFreeBooks : Form
    {
        string connStr = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\FreeBook.mdf;Integrated Security = True; Connect Timeout = 30";

        public LogareFreeBooks()
        {
            InitializeComponent();
        }

        private void btnLogare_Click(object sender, EventArgs e)
        {
            string email = txtEmail.Text;
            string parola = txtParola.Text;
            SqlConnection con = new SqlConnection(connStr);
            con.Open();
            string query = "SELECT COUNT(email) FROM utilizatori WHERE email = @email AND parola = @parola";
            SqlCommand cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@email", email);
            cmd.Parameters.AddWithValue("@parola", parola);
            bool ans = ((int)cmd.ExecuteScalar() == 1);
            if (ans) 
            {
                MeniuFreeBookForm frm = new MeniuFreeBookForm(email);
                this.Visible = false;
                frm.ShowDialog();
                Application.Exit();
            }
            else
            {
                MessageBox.Show("Eroare autentificare!", "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
        }
    }
}
