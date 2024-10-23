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
using System.Security.Cryptography.X509Certificates;

namespace PollutionMap
{
    public partial class VizualizareForm : Form
    {
        private string connStr = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\PoluareDB.mdf;Integrated Security=True;";
        private string mapPath = $@"{Directory.GetCurrentDirectory()}\..\..\Resurse\Harti\";
        private List<Cerc> cercuri = null;
        private List<Cerc> cercuriCurente = new List<Cerc>();
        // cercuri selectate dupa data masurarii

        private List<Cerc> cercuriFiltrate = new List<Cerc>();
        private int r = 20;                // raza cercurilor
        private bool filtruPus = false;
        private Cerc first, second, third;  // cercurile intre care trebuie trasate segmente
        private float X1, Y1, X2, Y2;       // punctele curente intre first si second, respectiv intre second si third
        private float dx1, dx2, dy1, dy2;   // variatiile coordonatelor pt cele doua segmente
        private int steps = 30, cnt1, cnt2;
        private Timer timer = new Timer();
        private bool gataPrimaLinie = false;
        public VizualizareForm(List<Cerc> cercuri, string user)
        {
            this.cercuri = cercuri;
            InitializeComponent();
            PopuleazaComboHarta();
            cmbFiltru.SelectedIndex = 0;
            timer.Interval = 20;
            timer.Tick += OnTimerTick;
            lblUtiliz.Text = "Utilizator: " + user;
        }

        private void OnTimerTick(object sender, EventArgs e)
        {
            if (!gataPrimaLinie)
            {
                cnt1++;
                X1 += dx1;
                Y1 += dy1;
                if (cnt1 == steps)
                {
                    gataPrimaLinie = true;
                    X1 = second.X;
                    Y1 = second.Y;
                }

            }

            if (gataPrimaLinie)
            {
                cnt2++;
                X2 += dx2;
                Y2 += dy2;
                if (cnt2 == steps)
                {
                    X2 = third.X;
                    Y2 = third.Y;
                    timer.Stop();
                }
            }
            pbTraseu.Invalidate();

        }

        private void PopuleazaComboHarta()
        {
            cmbHarta.Items.Add("Selecteaza o harta");
            cmbHarta.SelectedIndex = 0;

            var con = new SqlConnection(connStr);
            con.Open();
            string query = "SELECT NumeHarta FROM Harti";
            var cmd = new SqlCommand(query, con);
            var dr  = cmd.ExecuteReader();

            while (dr.Read()) 
            {
                cmbHarta.Items.Add(dr[0].ToString());
            }
            dr.Close();
            con.Close();
            con.Dispose();
            cmd.Dispose();
        }

        private void cmbHarta_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (cmbHarta.SelectedIndex== 0)
            {
                pbHarta.Image = Image.FromFile(mapPath + "default_harta.png");
                pbTraseu.Image = Image.FromFile(mapPath + "default_harta.png");
            }
            else
            {
                string harta = cmbHarta.Text;
                string fisierHarta = GetFisierHarta(harta);
                pbHarta.Image = Image.FromFile(mapPath + fisierHarta);
                pbTraseu.Image = Image.FromFile(mapPath + fisierHarta);
                DeterminaCercuriCurente();
            }
        }

        private string GetFisierHarta(string harta)
        {
            string fisierHarta;
            var con = new SqlConnection(connStr);
            con.Open();
            string query = "SELECT FisierHarta FROM Harti WHERE NumeHarta = @harta";       
            var cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@harta", harta);
            var rd = cmd.ExecuteReader();
            rd.Read();
            fisierHarta = rd[0].ToString();
            rd.Close();
            con.Close();
            con.Dispose();
            cmd.Dispose();

            return fisierHarta;
        }

        private void dtpDataMas_CloseUp(object sender, EventArgs e)
        {
            DeterminaCercuriCurente();
        }

        private void DeterminaCercuriCurente()
        {
            DateTime data = dtpDataMas.Value.Date;
            string numeHarta = cmbHarta.Text;
            cercuriCurente = cercuri.FindAll(c => c.Dt.Date == data && c.Harta == numeHarta);
            pbHarta.Invalidate();
            pbTraseu.Invalidate();
        }

        private void pbHarta_Paint(object sender, PaintEventArgs e)
        {
            if (cercuriCurente.Count == 0) return;

            if (!filtruPus)
                DeseneazaCercuri(cercuriCurente, e);
            else
                DeseneazaCercuri(cercuriFiltrate, e);
        }

        private void DeseneazaCercuri(List<Cerc> cercuriCurente, PaintEventArgs e)
        {
            e.Graphics.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;
            Pen pen = new Pen(Color.Green, 5);
            Font font = new Font("Arial", 12);
            foreach (var c in cercuriCurente)
            {
                pen.Color = c.C;
                e.Graphics.DrawEllipse(pen, c.X - r, c.Y - r, 2 * r, 2 * r);
                e.Graphics.DrawString(c.P.ToString(), font, new SolidBrush(c.C),
                    c.X - 11, c.Y - 9);
            }
            font.Dispose();
            pen.Dispose();
        }

        private void cmbFiltru_SelectedIndexChanged(object sender, EventArgs e)
        {
            int index = cmbFiltru.SelectedIndex;
            if (index == 0)
            {
                filtruPus = false;
                pbHarta.Invalidate();
                pbTraseu.Invalidate();
            }
            else
                filtruPus = true;

            if (!filtruPus) return;

            switch (index)
            {
                case 1:
                    cercuriFiltrate = cercuriCurente.FindAll(c => c.P < 20);
                    break;
                case 2:
                    cercuriFiltrate = cercuriCurente.FindAll(c => c.P >= 20 && c.P <= 40);
                    break;
                case 3:
                    cercuriFiltrate = cercuriCurente.FindAll(c => c.P > 40);
                    break;

            }
            pbHarta.Invalidate();
            pbTraseu.Invalidate();
        }

        private void btnResetFiltru_Click(object sender, EventArgs e)
        {
            filtruPus = false;
            cmbFiltru.SelectedIndex = 0;
           
        }

        private void VizualizareForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            DialogResult dr = MessageBox.Show("Esti sigur ca vrei sa inchizi aplicatia?", "Inchidere aplicatie", MessageBoxButtons.YesNoCancel);
            if(dr == DialogResult.Yes)
                this.Close();
        }


        // daca punctul (x, y) se gaseste in interiorul cercului  c
        private bool Hit(int x, int y, Cerc c)
        {
            return (x - c.X) * (x - c.X) + (y - c.Y) * (y - c.Y) <= r * r; ;

        }

        private void pbHarta_MouseClick(object sender, MouseEventArgs e)
        {
        
            if (filtruPus)
                foreach (var c in cercuriFiltrate)
                {
                    if (Hit(e.X, e.Y, c))
                        return;
                }   
            else
                foreach (var c in cercuriCurente)
                {
                    if (Hit(e.X, e.Y, c))
                        return;
                }

            AdaugaMasurareForm frm = new AdaugaMasurareForm();
            frm.ShowDialog();
            string harta = cmbHarta.Text;
            int id = GetIdHarta(harta);
            int x = e.X;
            int y = e.Y;
            int p = frm.Poluare;
            DateTime dt = DateTime.Now;
            InsertMasurare(id, x, y, p, dt);
            cercuri.Add(new Cerc(harta, x, y, p, dt));
            DeterminaCercuriCurente();
            pbHarta.Invalidate();
            pbTraseu.Invalidate();
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

        private void pbTraseu_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;
            if (cercuriCurente.Count == 0) return;

            if (!filtruPus)
                DeseneazaCercuri(cercuriCurente, e);
            else
                DeseneazaCercuri(cercuriFiltrate, e);
            DeseneazaLinii(e);
        }

        private void DeseneazaLinii(PaintEventArgs e)
        {
            if (!cercLovit) return;
            Pen pen = new Pen(Color.Red, 5);
            // deseneaza prima linie
            e.Graphics.DrawLine(pen, first.X, first.Y, X1, Y1);
            e.Graphics.DrawLine(pen, second.X, second.Y, X2, Y2);
            pen.Dispose();
        }

        private bool cercLovit = false;
        private void pbTraseu_MouseClick(object sender, MouseEventArgs e)
        {
            List<Cerc> listaTraseu;
            if (filtruPus)
                listaTraseu = cercuriFiltrate;
            else
                listaTraseu = cercuriCurente;
            if (filtruPus)
                listaTraseu = new List<Cerc>(cercuriFiltrate);
            else
                listaTraseu = new List<Cerc>(cercuriCurente);
 
            foreach (var c in listaTraseu)
                if (Hit(e.X, e.Y, c))
                {
              
                    first = c;
                    cercLovit = true;
                    gataPrimaLinie = false;
                    break;
                }

            if (!cercLovit) return;
            List<Cerc> sortDM = new List<Cerc>(listaTraseu);
            sortDM.Sort((c1, c2) => -c1.P.CompareTo(c2.P));
            second = sortDM[0];
            third = sortDM[1];
            if (Egale(first, second))
                gataPrimaLinie = true;
            else
            if (Egale(first, third))
            {
                gataPrimaLinie = true;
                Cerc aux = second;
                second = third;
                third = aux;
            }
            else
            if (Dist2(first, second) > Dist2(first, third))
            {
                Cerc aux = second;
                second = third;
                third = aux;
            }
            cnt1 = 0; cnt2 = 0;
            float DX1 = second.X - first.X;
            float DX2 = third.X - second.X;
            float DY1 = second.Y - first.Y;
            float DY2 = third.Y - second.Y;
            dx1 = DX1 / steps; dx2 = DX2 / steps;
            dy1 = DY1 / steps; dy2 = DY2 / steps;
            Y1 = first.Y;
            X1 = first.X;
            X2 = second.X;
            Y2 = second.Y;
            timer.Start();
            
            
        }

        private bool Egale(Cerc c1, Cerc c2)
        {
            return c1.X == c2.X && c1.Y == c2.Y;
        }
        // returneaza patratul distantei dintre cercurile c1 si c2
        private int Dist2(Cerc c1, Cerc c2)
        {
            return (c1.X - c2.X) * (c1.X - c2.X) + (c1.Y - c2.Y) * (c1.Y - c2.Y);
        }
    }
}
