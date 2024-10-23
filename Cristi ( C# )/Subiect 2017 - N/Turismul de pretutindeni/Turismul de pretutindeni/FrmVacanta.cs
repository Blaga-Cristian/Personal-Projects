using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Turismul_de_pretutindeni
{
    public partial class FrmVacanta : Form
    {
        string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\clasa_c#_oti_2017_resurse\Resurse\";

        static TurismDSTableAdapters.VacanteTableAdapter vtb = new TurismDSTableAdapters.VacanteTableAdapter();
        static TurismDSTableAdapters.UtilizatoriTableAdapter utb = new TurismDSTableAdapters.UtilizatoriTableAdapter();
        static TurismDSTableAdapters.RezervariTableAdapter rtb = new TurismDSTableAdapters.RezervariTableAdapter();

        Timer tmr = new Timer();
        string email;
        int idx = 1;
        int cnt = (int)vtb.GetCountVacante();
        float m = 0.241f, n = 0.691f, p = 0.068f;
        int w, h;

        public bool Exited { get; set; }

        public FrmVacanta(string email)
        {
            InitializeComponent();
            var dt = utb.GetUtilizator(email);
            if ((int)dt.Rows[0]["TipCont"] != 0)
                menuStrip1.Items["fileToolStripMenuItem"].Enabled = false;

            tmr.Interval = 2000;
            tmr.Tick += delegate
            {
                idx++;
                if (idx > cnt) idx = 1;
                SetImagine();
            };
            this.email = email;
            emailToolStripMenuItem.Text = email;
            this.Controls.Remove(lblDescriere);
            this.Controls.Remove(lblNrLocuri);
            this.Controls.Remove(lblNume);
            this.Controls.Remove(lblPret);
            pb.Controls.Add(lblDescriere);
            pb.Controls.Add(lblNrLocuri);
            pb.Controls.Add(lblNume);
            pb.Controls.Add(lblPret);
            SetImagine();
        }

        private void SetImagine()
        {
            DataTable dt = vtb.GetVacanta(idx);
            string numeVacanta = (string)dt.Rows[0]["NumeVacanta"];
            string descriere = (string)dt.Rows[0]["Descriere"];
            string caleFisier = (string)dt.Rows[0]["CaleFisier"];
            float pret = (float)dt.Rows[0]["Pret"];
            int nrLocuri = (int)dt.Rows[0]["NrLocuri"];

            if(pb.Image != null)pb.Image.Dispose();
            pb.Image = Image.FromFile(caleFisier);
            lblDescriere.Text = descriere;
            lblNrLocuri.Text = "" + nrLocuri + "  locuri";
            lblNume.Text = numeVacanta;
            lblPret.Text = "" + pret + " lei";
        }

        private void pbStanga_Click(object sender, EventArgs e)
        {
            idx--;
            if (idx <= 0) idx = cnt;
            SetImagine();
        }

        private void pbDreapta_Click(object sender, EventArgs e)
        {
            idx++;
            if (idx > cnt) idx = 1;
            SetImagine();
        }

        private void chk_CheckedChanged(object sender, EventArgs e)
        {
            if (chk.Checked)
                tmr.Start();
            else
                tmr.Stop();
        }

        private void btnRezerva_Click(object sender, EventArgs e)
        {
            var frm = new FrmRezervare(idx, email);
            frm.ShowDialog();
        }

        private void adaugaAdminNouToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var frm = new FrmAdminNou();
            frm.ShowDialog();
        }

        private void adaugaVacanteNoiToolStripMenuItem_Click(object sender, EventArgs e)
        {
            tmr.Stop();
            chk.Checked = false;
            idx = 1;

            var pro = System.Diagnostics.Process.Start(respath + "Vacante.txt");
            pro.WaitForExit();
            vtb.Clear();
            rtb.Clear(0, null, null, null, null, null, null, null, null, null, null, null, null);


            var sr = new StreamReader(respath + "Vacante.txt");
            string line;
            string[] s;
            char[] sep = { '|' };

            while ((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                string numeVacanta = s[0];
                string descriere = s[1];
                string caleFisier;

                try
                {
                    caleFisier = Directory.GetFiles(respath + $@"Imagini\", $@"{numeVacanta}.*")[0];
                }
                catch
                {
                    caleFisier = respath + $@"Imagini\" + "implicit.jpg";
                }

                float pret = float.Parse(s[2]);
                int nrLocuri = int.Parse(s[3]);

                vtb.InsertVacanta(numeVacanta, descriere, caleFisier, pret, nrLocuri);
            }
        }

        private void vacanteleMeleToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var frm = new FrmVacanteleMele(email);
            frm.ShowDialog();
        }

        private void deconectareToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void iesireToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Exited = true;
            Application.Exit();            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string nume = lblNume.Text;
            Point pl = new Point(0,0), pi = new Point(0,0);
            int lumi = 0, intu = 0;
            w = lblNume.Text.Length * 10;
            h = 30;

            int[,] dpl = new int[pb.Image.Height, pb.Image.Width];
            int[,] dpi = new int[pb.Image.Height, pb.Image.Width];
            var bmp = new Bitmap(pb.Image, pb.Size);

            for(int i = 0; i < h; ++i)
                for(int j = 0; j < w; ++j)
                {
                    dpl[0, 0] += Luminos(bmp.GetPixel(j, i));
                    dpi[0, 0] += Intunecos(bmp.GetPixel(j, i));
                }

            for(int i = 1; i <= pb.Height - h; ++i)
            {
                dpl[i, 0] = dpl[i - 1, 0];
                dpi[i, 0] = dpi[i - 1, 0];

                for(int j = 0; j < w; ++j)
                {
                    dpl[i, 0] -= Luminos(bmp.GetPixel(j, i - 1));
                    dpl[i, 0] += Luminos(bmp.GetPixel(j, i + h - 1));

                    dpi[i, 0] -= Intunecos(bmp.GetPixel(j, i - 1));
                    dpi[i, 0] += Intunecos(bmp.GetPixel(j, i + h - 1));
                }

                for(int j = 1; j <= pb.Width - w; ++j)
                {
                    dpl[i, j] = dpl[i, j - 1];
                    dpi[i, j] = dpi[i, j - 1];

                    for(int k = 0; k < h; ++k)
                    {
                        dpl[i, j] -= Luminos(bmp.GetPixel(j - 1, i + k));
                        dpl[i, j] += Luminos(bmp.GetPixel(j + w - 1, i + k));

                        dpi[i, j] -= Intunecos(bmp.GetPixel(j - 1, i + k));
                        dpi[i, j] += Intunecos(bmp.GetPixel(j + w - 1, i + k));
                    }
                }
            }

            for(int i = 0; i <= pb.Height - h; ++i)
                for(int j = 0; j <= pb.Width - w; ++j)
                {
                    if (dpl[i,j] > lumi)
                    {
                        lumi = dpl[i, j];
                        pl = new Point(j, i);
                    }

                    if (dpi[i,j] > intu)
                    {
                        intu = dpi[i, j];
                        pi = new Point(j, i);
                    }
                }

            var g = Graphics.FromImage(bmp);
            g.DrawString(nume, new Font(FontFamily.GenericSansSerif, 10f), Brushes.Black, pl);
            g.DrawString(nume, new Font(FontFamily.GenericSansSerif, 10f), Brushes.Wheat, pi);

            var sfd = new SaveFileDialog();
            sfd.Filter = "Fisiere imagine (*.jpg)|*.jpg";
            if (sfd.ShowDialog() != DialogResult.OK) return;
            
            bmp.Save(sfd.FileName, System.Drawing.Imaging.ImageFormat.Jpeg);
        }

        private int Luminos(Color a)
        {
            if (200 * 200 <= m * a.R * a.R + n * a.G * a.G + p * a.B * a.B)
                return 1;
            return 0;
        }
        private int Intunecos(Color a)
        {
            if (50 * 50 >= m * a.R * a.R + n * a.G * a.G + p * a.B * a.B)
                return 1;
            return 0;
        }
    }
}
