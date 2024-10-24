using PollutionMap.DSPoluareTableAdapters;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.ExceptionServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;

namespace PollutionMap
{
    public partial class Vizualizare : Form
    {
        DSPoluareTableAdapters.HartiTableAdapter hta = new DSPoluareTableAdapters.HartiTableAdapter();
        DSPoluareTableAdapters.MasurareTableAdapter mta = new DSPoluareTableAdapters.MasurareTableAdapter();
        DSPoluareTableAdapters.UtilizatoriTableAdapter uta = new DSPoluareTableAdapters.UtilizatoriTableAdapter();
        string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\OJTI_2022_C#_Resurse\";


        string nume;
        List<Harta> harti = new List<Harta>();
        DataTable currCircles;
        int cnt;
        Timer t = new Timer();
        Point first, second, third;

        public Vizualizare(string nume)
        {
            this.nume = nume;
            InitializeComponent();
            cmbFiltru.SelectedIndex = 0;
            lbl.Text = $"Utilizator = {nume}";
            PopCmbHarti();
        }

        private void PopCmbHarti()
        {
            //harti.Add(new Harta(0, "Incarcati o harta", $@"default_harta.png"));
            //DataTable dt = hta.GetData();
            //foreach (DataRow dr in dt.Rows)
            //    harti.Add(new Harta((int)dr["IdHarta"], (string)dr["NumeHarta"], (string)dr["FisierHarta"]));

            cmbHarti.DataSource = hta.GetData();

            cmbHarti.DisplayMember = "NumeHarta";
            cmbHarti.ValueMember = "FisierHarta";
        }

        private void cmbHarti_SelectedIndexChanged(object sender, EventArgs e)
        {
            pb.Image = Image.FromFile(respath + $@"Harti\{((DataRowView)cmbHarti.SelectedItem)["FisierHarta"]}");

            pb.Invalidate();
        }

        private void pb_Paint(object sender, PaintEventArgs e)
        {
            if (cmbHarti.Items.Count == 0) return;

            DateTime date = dtp.Value;
            DataTable dt;
            int id = (int)((DataRowView)cmbHarti.SelectedItem)["IdHarta"];
            int filtru = cmbFiltru.SelectedIndex;


            if (filtru == 0)
                dt = mta.GetDataByDateValue(id, date.ToString("yyyy-MM-dd"), -99999, 99999);
            else if (filtru == 1)
                dt = mta.GetDataByDateValue(id, date.ToString("yyyy-MM-dd"), -99999, 19);
            else if (filtru == 2)
                dt = mta.GetDataByDateValue(id, date.ToString("yyyy-MM-dd"), 20, 40);
            else
                dt = mta.GetDataByDateValue(id, date.ToString("yyyy-MM-dd"), 41, 99999);

            foreach (DataRow dr in dt.Rows)
            {
                Color clr;
                float v = (float)dr["ValoareMasurare"];
                if (v < 20)
                    clr = Color.Green;
                else if (v <= 40)
                    clr = Color.Yellow;
                else
                    clr = Color.Red;

                e.Graphics.DrawEllipse(new Pen(clr, 3f),
                    (int)dr["PozitieX"] - 20, (int)dr["PozitieY"] - 20, 40, 40);

                e.Graphics.DrawString(v.ToString(), new Font("Arial", 12f), new SolidBrush(clr),
                    (int)dr["PozitieX"] - 10 , (int)dr["PozitieY"] - 10);
            }
        }

        private void dtp_ValueChanged(object sender, EventArgs e)
        {
            pb.Invalidate();
        }

        private void cmbFiltru_SelectedIndexChanged(object sender, EventArgs e)
        {
            pb.Invalidate();
        }

        private void pb_MouseClick(object sender, MouseEventArgs e)
        {
            var frm = new AdaugareMasurare();
            frm.ShowDialog();


            DateTime now = DateTime.Now;
            DateTime date = dtp.Value;
            date = date.AddHours(now.Hour - date.Hour);
            date = date.AddMinutes(now.Minute - date.Minute);
            date = date.AddSeconds(now.Second - date.Second);

            mta.Insert((int)((DataRowView)cmbHarti.SelectedItem)["IdHarta"], e.X, e.Y, frm.Valoare, date);

            pb.Invalidate();
        }

        private void tabControl1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (tabControl1.SelectedIndex == 1)
            {
                int id = (int)((DataRowView)cmbHarti.SelectedItem)["IdHarta"];
                int filtru = cmbFiltru.SelectedIndex;
                DateTime date = dtp.Value;

                if (filtru == 0)
                    currCircles = mta.GetDataByDateValue(id, date.ToString("yyyy-MM-dd"), -99999, 99999);
                else if (filtru == 1)
                    currCircles = mta.GetDataByDateValue(id, date.ToString("yyyy-MM-dd"), -99999, 19);
                else if (filtru == 2)
                    currCircles = mta.GetDataByDateValue(id, date.ToString("yyyy-MM-dd"), 20, 40);
                else
                    currCircles = mta.GetDataByDateValue(id, date.ToString("yyyy-MM-dd"), 41, 99999);

                var img = new Bitmap(pb.Image, pb.Size);
                pb.DrawToBitmap(img, new Rectangle(0, 0, pb.Width, pb.Height));
                var bmp = new Bitmap(img, pbTraseu.Size);
                pbTraseu.Image = bmp;
                img.Dispose();
            }
        }

        private void pbTraseu_MouseClick(object sender, MouseEventArgs e)
        {
            float widthRatio = (float)pbTraseu.Width / pb.Width, heightRatio = (float)pbTraseu.Height / pb.Height;

            bool ok = false;
            int ind;
            for(int i = 0; i < currCircles.Rows.Count; ++i)
            {
                int x = (int)((int)currCircles.Rows[i]["PozitieX"] * widthRatio);
                int y = (int)((int)currCircles.Rows[i]["PozitieY"] * heightRatio);

                if (Hit(x, y, e.X, e.Y))
                {
                    ind = i;
                    ok = true;
                }
            }

            if (!ok) return;

            pbTraseu.Invalidate();

            Point p1 = new Point(0, 0);
            Point p2 = new Point(0, 0);
            float v1 = -9999, v2 = -9999;

            foreach(DataRow dr in currCircles.Rows)
            { 
                if ((float)dr["ValoareMasurare"] > v1)
                {
                    v2 = v1;
                    p2 = p1;
                    v1 = (float)dr["ValoareMasurare"];
                    p1 = new Point((int)((int)dr["PozitieX"] * widthRatio), (int)((int)dr["PozitieY"] * heightRatio));
                }
                else if ((float)dr["ValoareMasurare"] > v2)
                {
                    v2 = (float)dr["ValoareMasurare"];
                    p2 = new Point((int)((int)dr["PozitieX"] * widthRatio), (int)((int)dr["PozitieY"] * heightRatio));
                }
            }


            first = new Point(e.X, e.Y);
            second = p1;
            third = p2;

            if(Dist(first, second) > Dist(first, third))
            {
                Point aux = new Point(third.X, third.Y);
                third = new Point(second.X, second.Y);
                second = new Point(aux.X, aux.Y);
            }


            t.Tick -= DrawLine;

            cnt = 0;
            t = new Timer();
            t.Interval = 100;
            t.Tick += DrawLine;
            t.Start();

        }

        private void DrawLine(object sender, EventArgs e)
        {
            if(cnt >= 20)
            {
                t.Stop();
                t.Tick -= DrawLine;
                return;
            }
            cnt++;

            if(cnt <= 10)
            {
                Point p = new Point((int)(first.X - (first.X - second.X) * (float)cnt / 10),
                    (int)(first.Y - (first.Y - second.Y) * (float)cnt / 10));

                var g = pbTraseu.CreateGraphics();
                g.DrawLine(new Pen(Color.Red, 3f), first, p);
            }
            else
            {
                Point p = new Point((int)(second.X - (second.X - third.X) * (float)(cnt - 10) / 10),
                    (int)(second.Y - (second.Y - third.Y) * (float)(cnt - 10) / 10));

                var g = pbTraseu.CreateGraphics();
                g.DrawLine(new Pen(Color.Red, 3f), second, p);
            }
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Sunteti sigur ca doriti sa inchideti aplicatia?", "Confirmare",
                MessageBoxButtons.YesNo) == DialogResult.Yes)
                this.Close();
        }

        private void btnReseteaza_Click(object sender, EventArgs e)
        {
            cmbFiltru.SelectedIndex = 0;
        }

        private int Dist(Point first, Point second)
        {
            return (first.X - second.X) * (first.X - second.X) + (first.Y - second.Y) * (first.Y - second.Y);
        }

        private bool Hit(int circleX, int circleY, int x, int y)
        {
            return (x - circleX) * (x - circleX) + (y - circleY) * (y - circleY) <= 20 * 20;
        }
    }
}
