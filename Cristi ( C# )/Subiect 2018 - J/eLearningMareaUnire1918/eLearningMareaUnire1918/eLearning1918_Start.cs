using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.Remoting.Contexts;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace eLearningMareaUnire1918
{
    public partial class eLearning1918_Start : Form
    {
        private int poz;
        private int index = 0;
        public string connStr = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\eLearning1918.mdf;Integrated Security = True; Connect Timeout = 30";
        //string connStr = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\FreeBook.mdf;Integrated Security = True; Connect Timeout = 30";

        public string resPath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\csarp\";
        private Timer timer = new Timer();
        private bool isOnAuto = true;
        string[] files;
        public eLearning1918_Start()
        {
            InitializeComponent();
            
            pbSlide.SizeMode = PictureBoxSizeMode.StretchImage;
            files = Directory.GetFiles(resPath + @"imaginislideshow\");
            SchimbaImagine();

            timer.Interval = 2000;
            timer.Tick += TimerTickHandler;
            SetAuto();

        }

        private void SchimbaImagine()
        {
            pbSlide.Image = Image.FromFile(files[index]);
            pbSlide.Invalidate();
        }

        private void SetAuto()
        {
            timer.Start();
            isOnAuto = true;
            btnStare.Text = "Manual";
            btnInainte.Enabled = false;
            btnInapoi.Enabled = false;
        }

        private void SetManual()
        {
            timer.Stop();
            isOnAuto = false;   
            btnStare.Text = "Auto";
            btnInainte.Enabled = true;
            btnInapoi.Enabled = true;
        }

        private void TimerTickHandler(object sender, EventArgs e)
        {
            ++index;
            if (index == files.Length)
                index = 0;
            SchimbaImagine();
        }

        private void Form1_Load(object sender, EventArgs e)
        {            
            StreamReader sr = new StreamReader(resPath + "date.txt");
            string line;
            string[] s;
            char[] sep = {';'};


            while((line = sr.ReadLine()) != null) 
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                if(s[0][s[0].Length - 1] == ':')
                {
                    if (s[0] == "Utilizatori:")
                        poz = 1;
                    if (s[0] == "Itemi:")
                        poz = 2;
                    if (s[0] == "Evaluari:")
                        poz = 3;

                    line = sr.ReadLine();
                    s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                }

                if (poz == 1)
                    InsertUtilizator(s);
                if (poz == 2)
                    InsertItemi(s);
                if (poz == 3)
                    InsertEvaluari(s);
            }

            sr.Close();
            sr.Dispose();
        }

        private void InsertUtilizator(string[] s)
        {
            SqlConnection con = new SqlConnection(connStr);
            con.Open();
            string query = "INSERT INTO Utilizatori VALUES (@numePrenumeUtilizator,@parolaUtilizator,@emailUtilizator,@clasaUtilizator)";
            SqlCommand cmd = new SqlCommand(query, con);
            string numePrenumeUtilizator = s[0];
            string parolaUtilizator = s[1];
            string emailUtilizator = s[2];
            string clasaUtilizator = s[3];
            cmd.Parameters.AddWithValue("@numePrenumeUtilizator", numePrenumeUtilizator);
            cmd.Parameters.AddWithValue("@parolaUtilizator", parolaUtilizator);
            cmd.Parameters.AddWithValue("@emailUtilizator", emailUtilizator);
            cmd.Parameters.AddWithValue("@clasaUtilizator", clasaUtilizator);
            cmd.ExecuteNonQuery();

            con.Close();
            con.Dispose();
            cmd.Dispose();
        }

        private void InsertItemi(string[] s)
        {
            SqlConnection con = new SqlConnection(connStr);
            con.Open();
            string query = "INSERT INTO Itemi VALUES (@tipItem,@enuntItem,@raspuns1Item,@raspuns2Item,@raspuns3Item,@raspuns4Item,@raspunsCorectItem)";
            SqlCommand cmd = new SqlCommand(query, con);
            int tipItem = int.Parse(s[0]);
            string enuntItem = s[1];
            string raspuns1Item = s[2];
            string raspuns2Item = s[3];
            string raspuns3Item = s[4];
            string raspuns4Item = s[5];
            string raspunsCorectItem = s[6];
            cmd.Parameters.AddWithValue("@tipItem", tipItem);
            cmd.Parameters.AddWithValue("@enuntItem", enuntItem);
            cmd.Parameters.AddWithValue("@raspuns1Item", raspuns1Item);
            cmd.Parameters.AddWithValue("@raspuns2Item", raspuns2Item);
            cmd.Parameters.AddWithValue("@raspuns3Item", raspuns3Item);
            cmd.Parameters.AddWithValue("@raspuns4Item", raspuns4Item);
            cmd.Parameters.AddWithValue("@raspunsCorectItem", raspunsCorectItem);
            cmd.ExecuteNonQuery();

            con.Close();
            con.Dispose();
            cmd.Dispose();
        }

        private void InsertEvaluari(string[] s)
        {
            SqlConnection con = new SqlConnection(connStr);
            con.Open();
            string query = "INSERT INTO Evaluari VALUES (@idElev,@dataEvaluare,@notaEvaluare)";
            SqlCommand cmd = new SqlCommand(query, con);
            int idElev = int.Parse(s[0]);
            DateTime dataEvaluare = DateTime.ParseExact(s[1], "M/d/yyyy h:mm:ss tt", System.Globalization.CultureInfo.InvariantCulture);
            int notaEvaluare = int.Parse(s[2]);
            cmd.Parameters.AddWithValue("@idElev", idElev);
            cmd.Parameters.AddWithValue("@dataEvaluare", dataEvaluare);
            cmd.Parameters.AddWithValue("@notaEvaluare", notaEvaluare);
            cmd.ExecuteNonQuery();

            con.Close();
            con.Dispose();
            cmd.Dispose();
        }

        private void btnStare_Click(object sender, EventArgs e)
        {
            if (isOnAuto)
                SetManual();
            else
                SetAuto();
        }

        private void btnInapoi_Click(object sender, EventArgs e)
        {
            --index;
            if(index == -1)
                index = files.Length - 1;
            SchimbaImagine();
        }

        private void btnInainte_Click(object sender, EventArgs e)
        {
            ++index;
            if (index == files.Length)
                index = 0;
            SchimbaImagine();
        }

        private void btnLogare_Click(object sender, EventArgs e)
        {
            string email = txtEmail.Text;
            string parola = txtParola.Text;
            SqlConnection con = new SqlConnection(connStr);
            con.Open();
            string query = "SELECT COUNT(IdUtilizator) FROM Utilizatori WHERE EmailUtilizator = @email AND ParolaUtilizator = @parola";
            SqlCommand cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@email", email);
            cmd.Parameters.AddWithValue("@parola", parola);
            int ans = (int)cmd.ExecuteScalar();

            if(ans == 0)
            {
                MessageBox.Show("Eroare de autentificare","Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);
                txtEmail.Text = "";
                txtParola.Text = "";
            }
            else
            {
                query = "SELECT * FROM Utilizatori WHERE EmailUtilizator = @email AND ParolaUtilizator = @parola";
                cmd = new SqlCommand(query, con);
                cmd.Parameters.AddWithValue("@email", email);
                cmd.Parameters.AddWithValue("@parola", parola);
                var rd = cmd.ExecuteReader();
                rd.Read();
                int id = (int)rd[0];
                string clasa = (string)rd[4];

                var frm = new eLearning1918_Elev(id,clasa);
                this.Visible = false;
                frm.ShowDialog();
                this.Close();
            }

            con.Close();
            con.Dispose();
            cmd.Dispose();
        }
    }
}
