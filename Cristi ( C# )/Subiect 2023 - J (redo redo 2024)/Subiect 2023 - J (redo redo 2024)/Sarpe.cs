using Subiect_2023___J__redo_redo_2024_.DSJocEducativTableAdapters;
using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Subiect_2023___J__redo_redo_2024_
{
    public partial class Sarpe : Form
    {
        RezulateTableAdapter rta = new RezulateTableAdapter();
        string email;

        int SCOR = 0, w = 30, h = 30;
        List<Point> sarpe = new List<Point>();
        int[] dx = { -1, 0, 1, 0 }, dy = { 0, 1, 0, -1 };
        int left = 0, down = 1, right = 2, up = 3, dir = 1;
        Point food;
        Timer tmr = new Timer();
        Random r = new Random();


        public Sarpe(string email)
        {
            InitializeComponent();
            this.email = email;
            lblScor.Text = $@"Scor: {SCOR}";
        }

        private void Sarpe_KeyDown(object sender, KeyEventArgs e)
        {
            if (tmr.Enabled == false) return;

            if (e.KeyCode == Keys.W && dir != down) dir = up;
            if (e.KeyCode == Keys.A && dir != right) dir = left;
            if (e.KeyCode == Keys.S && dir != up) dir = down;
            if (e.KeyCode == Keys.D && dir != left) dir = right;

            e.SuppressKeyPress = e.Handled = true;
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            btnStart.Enabled = false;
            btnStop.Enabled = true;

            sarpe.Add(RandomPoint());
            food = RandomPoint();
            tmr.Interval = 500;
            tmr.Tick += GameTick;
            tmr.Start();
        }

        private void GameTick(object sender, EventArgs e)
        {
            tmr.Stop();

            Point next = new Point(sarpe[0].X + w * dx[dir], sarpe[0].Y + h * dy[dir]);

            if (next.X < 0 || next.X > 200 || next.Y < 0 || next.Y > 330 || Collision(next))
            {
                GameOver();
                return;
            }


            if (next == food)
            {
                sarpe.Insert(0, next);
                SCOR += 10;

                Intrebare frm = new Intrebare();
                frm.ShowDialog();
                SCOR += frm.Puncte;

                food = RandomPoint();
            }
            else
            {
                for (int i = sarpe.Count - 1; i > 0; --i)
                    sarpe[i] = new Point(sarpe[i - 1].X, sarpe[i - 1].Y);
                sarpe[0] = new Point(next.X, next.Y);
            }

            tmr.Start();
            pb.Invalidate();
            lblScor.Text = $@"Scor: {SCOR}";
        }

        private void pb_Paint(object sender, PaintEventArgs e)
        {
            if (tmr.Enabled == false) return;

            e.Graphics.FillEllipse(Brushes.Red, food.X, food.Y, w, h);
            e.Graphics.FillEllipse(Brushes.White, sarpe[0].X, sarpe[0].Y, w, h);

            for (int i = 1; i < sarpe.Count; ++i)
                e.Graphics.FillEllipse(Brushes.Green, sarpe[i].X, sarpe[i].Y, w, h);
        }

        Point RandomPoint()
        {
            int x = r.Next(7), y = r.Next(10);

            while (true)
            {
                x = r.Next(7); y = r.Next(10);

                bool ok = true;
                for(int i = 0; i < sarpe.Count; ++i)
                    if(x * w == sarpe[i].X && y * h == sarpe[i].Y)
                        ok = false;

                if (ok) break;
            }

            return new Point(x * w, y * h);
        }

        bool Collision(Point pt)
        {
            for(int i = 0; i + 1 < sarpe.Count; ++i)
                if(pt == sarpe[i])
                   return true;
            return false;
        }

        void GameOver()
        {
            tmr.Stop();
            rta.Insert(1, email, SCOR);
            MessageBox.Show("Jocul s-a terminat", "Game over", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            this.Close();
        }

        private void btnStop_Click(object sender, EventArgs e)
        {
            GameOver();
        }


    }
}
