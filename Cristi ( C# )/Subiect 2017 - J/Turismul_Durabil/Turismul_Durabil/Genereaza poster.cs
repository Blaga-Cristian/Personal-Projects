using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Runtime.Remoting.Contexts;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.VisualStyles;
using System.Drawing.Imaging;

namespace Turismul_Durabil
{
    public partial class GenerarePoster : Form
    {
        private string conStr = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\Turism.mdf;Integrated Security=True";
        private string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\Resurse_C#\Resurse\";
        private string impath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\Resurse_C#\Resurse\Imagini\";
        private List<KeyValuePair<int,string>> localitati = new List<KeyValuePair<int, string>>();
        private List<KeyValuePair<string,string>> imagini = new List<KeyValuePair<string, string>>();
        private Bitmap bmp;
        int width, height;

        public GenerarePoster()
        {
            InitializeComponent();

            btnAdauga.Enabled = false;
            IncarcaPlanificari();
            IncarcaLocalitati();
            PopCmbLoc();


            var frm = new Vizualizare_excursie();
            frm.ShowDialog();
        }

        private void PopCmbLoc()
        {
            foreach (var x in localitati)
                cmbLocalitate.Items.Add(x.Value);
        }

        private void IncarcaLocalitati()
        {
            SqlConnection con = new SqlConnection(conStr);
            con.Open();
            string query = "SELECT * FROM Localitati";
            SqlCommand cmd = new SqlCommand(query, con);
            var rd = cmd.ExecuteReader();
            while (rd.Read())
                localitati.Add(new KeyValuePair<int, string>((int)rd[0], (string)rd[1]));
        }

        private void IncarcaPlanificari()
        {
            int cnt = 1;
            var sr = new StreamReader(respath + "planificari.txt");
            string line;
            string[] s;
            char[] sep = { '*' };

            while((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                InsertData(s,cnt);
                cnt++;
            }
        }

        private void InsertData(string[] s, int id)
        {
            string query;
            SqlCommand cmd;
            SqlConnection con = new SqlConnection(conStr);
            con.Open();
            query = "INSERT INTO Localitati VALUES (@nume)";
            cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@nume", s[0].Trim());
            cmd.ExecuteNonQuery();

            query = "INSERT INTO Planificari VALUES (@idLocalitate, @frecventa, @dataStart, @dataStop, @ziua)";
            cmd = new SqlCommand(query, con);
            int idLocalitate = id;
            string frecventa = s[1].Trim();
            DateTime dataStart;
            DateTime dataStop;
            int ziua;
            if (frecventa == "lunar" || frecventa == "anual")
            {
                ziua = int.Parse(s[2].Trim());
                cmd.Parameters.AddWithValue("@idLocalitate", idLocalitate);
                cmd.Parameters.AddWithValue("@frecventa", frecventa);
                cmd.Parameters.AddWithValue("@dataStart", DBNull.Value);
                cmd.Parameters.AddWithValue("@dataStop", DBNull.Value);
                cmd.Parameters.AddWithValue("@ziua", ziua);
            }
            else
            {
                string aux = s[2].Trim();
                string aux2 = s[3].Trim();
                dataStart = DateTime.ParseExact(s[2].Trim(), "dd.MM.yyyy", null);
                dataStop = DateTime.ParseExact(s[3].Trim(), "dd.MM.yyyy", null);
                cmd.Parameters.AddWithValue("@idLocalitate", idLocalitate);
                cmd.Parameters.AddWithValue("@frecventa", frecventa);
                cmd.Parameters.AddWithValue("@dataStart", dataStart);
                cmd.Parameters.AddWithValue("@dataStop", dataStop);
                cmd.Parameters.AddWithValue("@ziua", DBNull.Value);
            }
            cmd.ExecuteNonQuery();

            query = "INSERT INTO Imagini VALUES ( @idLocatie, @caleFisier)";
            string caleFisier;
            if (frecventa == "lunar" || frecventa == "anual")
            {
                for(int i = 3; i < s.Length; ++i)
                {
                    caleFisier = respath + $@"\Imagini\{s[i].Trim()}";
                    cmd = new SqlCommand(query, con);
                    cmd.Parameters.AddWithValue("@idLocatie", idLocalitate);
                    cmd.Parameters.AddWithValue("@caleFisier", caleFisier);
                    cmd.ExecuteNonQuery();
                }
            }
            else
            {
                for (int i = 4; i < s.Length; ++i)
                {
                    caleFisier = respath + $@"\Imagini\{s[i].Trim()}";
                    cmd = new SqlCommand(query, con);
                    cmd.Parameters.AddWithValue("@idLocatie", idLocalitate);
                    cmd.Parameters.AddWithValue("@caleFisier", caleFisier);
                    cmd.ExecuteNonQuery();
                }
            }

            con.Close();
            con.Dispose();
            cmd.Dispose();
        }

        private void cmbLocalitate_SelectedIndexChanged(object sender, EventArgs e)
        {
            imagini.Clear();
            cmbIm.Items.Clear();

            int id = cmbLocalitate.SelectedIndex + 1;
            SqlConnection con = new SqlConnection(conStr);
            con.Open();
            string query = "SELECT CaleFisier FROM Imagini WHERE IdLocatie = @id";
            SqlCommand cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@id", id);
            var rd = cmd.ExecuteReader();
            while (rd.Read())
            {
                string path = (string)rd[0];
                string name = path.Substring(impath.Length + 1);
                imagini.Add(new KeyValuePair<string, string>(name,path));
            }

            foreach (var x in imagini)
                cmbIm.Items.Add(x.Key);
        }

        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            pb.Image = Image.FromFile(imagini[cmbIm.SelectedIndex].Value);
            pb.SizeMode = PictureBoxSizeMode.StretchImage;
            pb.Invalidate();
            btnAdauga.Enabled = true;
        }

        private void btnAdauga_Click(object sender, EventArgs e)
        {
            if (lstbFisiere.Items.Count == 10) return;
            lstbFisiere.Items.Add(imagini[cmbIm.SelectedIndex].Key);
        }


        private void btnGen_Click(object sender, EventArgs e)
        {
            int hmax = 1000;
            int wmax = 1000;
            int padding = 10;//marimea o sa fie de 90
            int him = (hmax - padding * lstbFisiere.Items.Count) / lstbFisiere.Items.Count;
            int wim = wmax / lstbFisiere.Items.Count;

            bmp = new Bitmap(wmax, hmax);
            Graphics g = Graphics.FromImage(bmp);

            for (int i = 0; i < lstbFisiere.Items.Count; ++i)
            {
                var img = Image.FromFile(impath + lstbFisiere.Items[i]);
                g.DrawImage(img, new Rectangle(0, i * (him + padding), wim, him), new Rectangle(0, 0, img.Size.Width, img.Size.Height), GraphicsUnit.Pixel);
            }

            SaveFileDialog sfd = new SaveFileDialog();
            sfd.Filter = "PNG(*.PNG)|*.png";
            sfd.FileName = txtTitlu.Text;


            if(sfd.ShowDialog() == DialogResult.OK)
                bmp.Save(sfd.FileName);
        }
    }
}
