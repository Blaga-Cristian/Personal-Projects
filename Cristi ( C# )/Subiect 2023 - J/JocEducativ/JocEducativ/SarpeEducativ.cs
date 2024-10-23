using JocEducativ.JocEducativDBTableAdapters;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace JocEducativ
{
    public partial class SarpeEducativ : Form
    {
        private JocEducativDBTableAdapters.RezultateTableAdapter rezultateTableAdapter = new JocEducativDBTableAdapters.RezultateTableAdapter();
        string emailUtilizator;
        int[] dx = { 0, 30, 0, -30 };
        int[] dy = { -30, 0, 30, 0 };
        static int up = 0, right = 1, down = 2, left = 3;
        int w = 30, h = 30;
        int dir = down;
        int scor = 0;
        Random rand = new Random();
        List<Point> corpsarpe = new List<Point>();
        Point fruit;
        Timer tmr;

        public SarpeEducativ(string emailUtilizator)
        {
            InitializeComponent();
            this.KeyPreview = true;
            this.emailUtilizator = emailUtilizator;
            SetScor();
        }

        private void SetScor()
        {
            lblScor.Text = "Punctaj: " + scor;
        }

        private Point GetPoint()
        {
            Point p = new Point();

            bool ok = true;
            while(ok)
            {
                ok = false;
                p.X = w * (rand.Next() % 10);
                p.Y = h * (rand.Next() % 10);
                for (int i = 0; i < corpsarpe.Count; ++i)
                    if (corpsarpe[i] == p)
                        ok = true;
            }

            return p;
        }

        private void SarpeEducativ_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyValue == 'A')
                if (dir == up || dir == down)
                    dir = left;
            if (e.KeyValue == 'D')
                if (dir == up || dir == down)
                    dir = right;
            if (e.KeyValue == 'W')
                if (dir == left || dir == right)
                    dir = up;
            if (e.KeyValue == 'Z')
                if (dir == left || dir == right)
                    dir = down;

            e.SuppressKeyPress = true;
        }

        private void btnStop_Click(object sender, EventArgs e)
        {
            tmr.Stop();
            MessageBox.Show("Jocul s-a terminat", "Game Over", MessageBoxButtons.OK);
            rezultateTableAdapter.InsertRezultat(1, emailUtilizator, scor);
            this.Close();
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            btnStart.Enabled = false;
            btnStop.Enabled = true;
            corpsarpe.Add(GetPoint());
            fruit = GetPoint();
            tmr = new Timer();
            tmr.Interval = 1000;
            tmr.Tick += TimerTickHandler;
            tmr.Start();
        }

        private void TimerTickHandler(object sender, EventArgs e)
        {
            var p = new Point(corpsarpe[0].X + dx[dir], corpsarpe[0].Y + dy[dir]);
            if(p == fruit)
            {
                tmr.Stop();
                corpsarpe.Insert(0, p);
                scor += 10;
                var frm = new Intrebare();
                frm.ShowDialog();
                scor += frm.ScorExtra;
                fruit = GetPoint();
                SetScor();
                Draw();
                tmr.Start();
                return;
            }

            if(p.X < 0 || p.Y < 0 || p.X > 270 || p.Y > 270 || Hit(p) || corpsarpe.Count == 100)
            {
                tmr.Stop();
                MessageBox.Show("Jocul s-a terminat", "Game Over", MessageBoxButtons.OK);
                rezultateTableAdapter.InsertRezultat(1, emailUtilizator, scor);
                this.Close();
                return;
            }

            corpsarpe.Insert(0, p);
            corpsarpe.RemoveAt(corpsarpe.Count - 1);

            Draw();
            SetScor();
        }

        private void Draw()
        {
            Bitmap bmp = new Bitmap(300, 300);
            Graphics g = Graphics.FromImage(bmp);

            g.DrawEllipse(Pens.Black, new Rectangle(corpsarpe[0], new Size(w, h)));
            g.FillEllipse(Brushes.White, new Rectangle(corpsarpe[0], new Size(w, h)));

            for(int i = 1; i < corpsarpe.Count; ++i)
            {
                g.DrawEllipse(Pens.Black, new Rectangle(corpsarpe[i], new Size(w, h)));
                g.FillEllipse(Brushes.Green, new Rectangle(corpsarpe[i], new Size(w, h)));
            }

            g.DrawEllipse(Pens.Black, new Rectangle(fruit, new Size(w, h)));
            g.FillEllipse(Brushes.Red, new Rectangle(fruit, new Size(w, h)));

            pb.Image = bmp;
        }

        private bool Hit(Point p)
        {
            for (int i = 0; i < corpsarpe.Count - 1; ++i)
                if (p == corpsarpe[i])
                    return true;
            return false;
        }
    }
}
