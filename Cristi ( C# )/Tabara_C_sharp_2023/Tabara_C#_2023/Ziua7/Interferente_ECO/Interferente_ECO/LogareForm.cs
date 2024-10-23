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
using System.IO;

namespace Interferente_ECO
{
    public partial class LogareForm : Form
    {
        private string appPath = null;
        private string resorcesPath = null;
        private Image img = null;
        private string conStr = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\EcoDB.mdf;Integrated Security=True;Connect Timeout=30";

        public LogareForm()
        {
            InitializeComponent();
            appPath = Directory.GetCurrentDirectory(); 
            resorcesPath = $@"{appPath}\..\..\Resurse\"; 
            lblMsg1.BackColor = Color.Transparent;
            lblMsg2.BackColor = Color.Transparent;
            lblMsg3.BackColor = Color.Transparent;
            pb1.Click += OnPbClick;
            pb2.Click += OnPbClick;
            pb3.Click += OnPbClick;
            pb4.Click += OnPbClick;
            pb5.Click += OnPbClick;
        }

        public Image GetBackgroundImage()
        {
            return img;
        }

        private bool VerifPasswordOK()
        {
            txtPass.ForeColor = Color.Black;
            if (txtPass.Text == "")
            {
                txtPass.ForeColor = Color.Red;
                MessageBox.Show("Parola trebuie sa contina caractere");
                return false;
            }

            string query = "SELECT Parola FROM Utilizatori WHERE Nume = @nume;";
            var conn = new SqlConnection(conStr);
            conn.Open();
            var cmd = new SqlCommand(query, conn);
            cmd.Parameters.AddWithValue("@nume", cmbUsers.Text);
            var dr = cmd.ExecuteReader();
            
           
            dr.Read();
            if (!dr.HasRows)
                return false;
         
            if (dr[0].ToString() != txtPass.Text)
            {
                Console.WriteLine(dr[0].ToString());
                txtPass.ForeColor = Color.Red;
                MessageBox.Show("Parola nu este corecta!");
                txtPass.Text = "";
                conn.Close();
                dr.Close();
                return false;
            }
            
            conn.Close();
            dr.Close();

            return true;
        }
        private void OnPbClick(object sender, EventArgs e)
        {
            if (!VerifPasswordOK()) return;
                
            PictureBox pb = (PictureBox)sender;
            img = pb.Image;
            this.Visible = false;
            InterfeteEcoForm frm = new InterfeteEcoForm(img);
            frm.ShowDialog();
            Application.Exit();
        }

        private void LogareForm_Load(object sender, EventArgs e)
        {
            PopulateDataBaseAndCombo();
        }

        private void PopulateDataBaseAndCombo()
        {
            string query = "INSERT INTO Utilizatori VALUES(@user, @pass)";
            var conn = new SqlConnection(conStr);
            conn.Open();

            var cmd = new SqlCommand(query, conn);

            var sr = new StreamReader($"{resorcesPath}Useri.txt");
            string line = null;
            char[] sep = { ' ' };
            while ((line = sr.ReadLine()) != null)
            {
                string[] s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                cmd.Parameters.AddWithValue("@user", s[0]);
                cmd.Parameters.AddWithValue("@pass", s[1]);
                cmbUsers.Items.Add(s[0]);
                var dr = cmd.ExecuteNonQuery();
                cmd.Parameters.Clear();
            }

            conn.Close();
            sr.Close();
            conn.Dispose();
            sr.Dispose();
        }
    }
}
