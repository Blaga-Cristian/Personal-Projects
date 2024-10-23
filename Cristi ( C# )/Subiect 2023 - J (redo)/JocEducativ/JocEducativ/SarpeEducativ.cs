using JocEducativ.DSJocEducativTableAdapters;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace JocEducativ
{
    public partial class SarpeEducativ : Form
    {
        ItemiTableAdapter ita = new ItemiTableAdapter();
        RezultateTableAdapter rta = new RezultateTableAdapter();
        UtilizatoriTableAdapter uta = new UtilizatoriTableAdapter();
        static string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\csarp\";

        static int w = 30, h = 30;
        static int[] dx = { 0, 1, 0, -1 }, dy = { -1, 0, 1, 0 };
        static int up = 0, right = 1, down = 2, left = 3;
        int dir = down;
        int scor;
        string email;
        List<Point> corpSarpe = new List<Point>();
        Point apple;

        Timer gameTimer = new Timer();

        Random rand = new Random();

        public SarpeEducativ(string email)
        {
            this.email = email;
            InitializeComponent();
            btnStop.Enabled = false;
            this.KeyPreview = true;
            lblScor.Text = $@"Scor: {scor}";
            corpSarpe.Add(RandPoint());
            apple = RandPoint();
            gameTimer.Interval = 500;
            gameTimer.Tick += GameEvent;
        }


        private void SarpeEducativ_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.A && (dir == up || dir == down))
                dir = left;
            if (e.KeyCode == Keys.W && (dir == left || dir == right))
                dir = up;
            if (e.KeyCode == Keys.D && (dir == up || dir == down))
                dir = right;
            if (e.KeyCode == Keys.S && (dir == left || dir == right))
                dir = down;

            e.Handled = e.SuppressKeyPress = true;
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            btnStart.Enabled = false;
            btnStop.Enabled = true;
            gameTimer.Start();
        }

        private void btnStop_Click(object sender, EventArgs e)
        {
            btnStop.Enabled = false;
            btnStart.Enabled = true;
            gameTimer.Stop();
        }

        private void GameEvent(object sender, EventArgs e)
        {
            int nx = corpSarpe[0].X + dx[dir];
            int ny = corpSarpe[0].Y + dy[dir];

            gameTimer.Stop();

            if(nx >= 10 || ny >= 10 || corpSarpe.TakeWhile((value, index) => index < corpSarpe.Count - 1).Any(p => p.X == nx && p.Y == ny))
            {
                MessageBox.Show("Jocul s-a terminat", "SarpeEducativ", MessageBoxButtons.OK);

                rta.Insert(1, email, scor);

                this.Close();

                return;
            }

            if(nx == apple.X && ny == apple.Y)
            {
                scor += 10;
                var frm = new Intrebare();
                frm.ShowDialog();
                scor += frm.PuncteExtra;

                List<Point> aux = new List<Point>() { new Point(nx, ny) };
                aux.AddRange(corpSarpe);
                corpSarpe = aux;

                apple = RandPoint();
            }
            else
            {
                for (int i = corpSarpe.Count - 1; i > 0; --i)
                    corpSarpe[i] = new Point(corpSarpe[i - 1].X, corpSarpe[i - 1].Y);
                corpSarpe[0] = new Point(nx, ny);
            }

            lblScor.Text = $@"Scor: {scor}";

            pb.Invalidate();

            gameTimer.Start();
        }

        private Point RandPoint()
        {
            int x, y;
            do
            {
                x = rand.Next(10);
                y = rand.Next(10);
            }while(corpSarpe.Any(it => it.X == x && it.Y == y));

            return new Point(x, y);
        }

        private void pb_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.FillEllipse(Brushes.Red,
                new Rectangle(w * apple.X, h * apple.Y, w, h));

            e.Graphics.FillEllipse(Brushes.White,
                new Rectangle(w * corpSarpe[0].X, h * corpSarpe[0].Y, w, h));

            for(int i = 1; i < corpSarpe.Count; ++i)
                e.Graphics.FillEllipse(Brushes.Green,
                new Rectangle(w * corpSarpe[i].X, h * corpSarpe[i].Y, w, h));
        }
    }
}
