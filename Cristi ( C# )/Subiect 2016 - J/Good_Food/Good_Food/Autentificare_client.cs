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

namespace Good_Food
{
    public partial class Autentificare_client : Form
    {
        private string conStr = $@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\GOOD_FOOD.mdf;Integrated Security=True";

        public Autentificare_client()
        {
            InitializeComponent();
        }

        private void btnIntra_Click(object sender, EventArgs e)
        {
            if(!Exista(txtEmail.Text, txtParola.Text))
            {
                txtParola.Text = "";
                txtEmail.Text = "";
                MessageBox.Show("Eroare autentificare!", "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            var frm = new Optiuni(txtEmail.Text);
            this.Visible = false;
            frm.ShowDialog();
            this.Close();
        }

        private bool Exista(string email, string parola)
        {
            var con = new SqlConnection(conStr);
            con.Open();
            string query = "SELECT COUNT(*) FROM Clienti WHERE email = @email AND parola = @parola";
            var cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@email", email);
            cmd.Parameters.AddWithValue("@parola", parola);
            var res = cmd.ExecuteScalar();
            return (int)res == 1;
        }
    }
}
