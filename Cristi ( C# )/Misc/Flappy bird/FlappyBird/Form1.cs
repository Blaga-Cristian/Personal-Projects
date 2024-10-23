using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SniperGame
{
    public partial class Form1 : Form
    {
        Timer gameTimer = new Timer();
        Random rand = new Random();
        int speed = 30, gravity = 20;
        int scor = 0;

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Space)
                gravity = -Math.Abs(gravity);
        }

        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Space)
                gravity = Math.Abs(gravity);
        }

        public Form1()
        {
            InitializeComponent();
            this.KeyPreview = true;
            gameTimer.Interval = 100;

            int v = rand.Next(900, 1200);
            foreach (PictureBox x in this.Controls.OfType<PictureBox>())
            {
                if (x.Tag == "top")
                    x.Left = v;
                if (x == topPipeHead)
                    x.Left -= 10;
            }

            v = rand.Next(900, 1200);
            foreach (PictureBox x in this.Controls.OfType<PictureBox>())
            {
                if (x.Tag == "bot")
                    x.Left = v;
                if (x == BotPipeHead)
                    x.Left -= 10;
            }

            gameTimer.Tick += GameEvent;

            gameTimer.Start();
        }

        private void GameEvent(object sender, EventArgs e)
        {
            pbJucator.Top += gravity;

            bool ok = false;
            foreach(PictureBox x in this.Controls.OfType<PictureBox>())
            {
                if(x.Tag == "top")
                    x.Left -= speed;
                if (x.Left < -110)
                    ok = true;
            }
            if(ok)
            {
                scor++;
                int v = rand.Next(900, 1200);
                foreach (PictureBox x in this.Controls.OfType<PictureBox>())
                {
                    if (x.Tag == "top")
                        x.Left = v;
                    if (x == topPipeHead)
                        x.Left -= 10;
                }
            }


            ok = false;
            foreach (PictureBox x in this.Controls.OfType<PictureBox>())
            {
                if (x.Tag == "bot")
                    x.Left -= speed;
                if (x.Left < -110)
                    ok = true;
            }
            if (ok)
            {
                scor++;
                int v = rand.Next(900, 1200);
                foreach (PictureBox x in this.Controls.OfType<PictureBox>())
                {
                    if (x.Tag == "bot")
                        x.Left = v;
                    if (x == BotPipeHead)
                        x.Left -= 10;
                }
            }


            foreach(PictureBox x in this.Controls.OfType<PictureBox>())
            {
                if (x.Tag == "jucator") continue;
                if(pbJucator.Bounds.IntersectsWith(x.Bounds))
                {
                    gameTimer.Stop();
                    //MessageBox.Show("Jocul s-a terminat");
                    GameOver.Visible = true;
                    lblFinal.Text = "Scor final: " + scor;
                    lblFinal.Visible = true;
                    label4.Visible = true;
                }
            }

            lblScor.Text = "Punctaj: " + scor;
        }
    }
}
