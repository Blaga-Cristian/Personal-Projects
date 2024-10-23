using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Testing
{
    public partial class Form1 : Form
    {
        Timer tmr = new Timer();
        int ballx = -5, bally = -5;
        int w, h;
        Random rand = new Random();
        bool goingLeft, goingRight;
        int speed = 20;
        int scor;

        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.A)
                goingLeft = false;
            if (e.KeyCode == Keys.D)
                goingRight = false;

            
        }

        private void SFSd(int scor)
        {
            scor = 5;
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.KeyCode == Keys.A)
                goingLeft = true;
            if(e.KeyCode == Keys.D)
                goingRight = true;
        }

        public Form1()
        {
            InitializeComponent();

            List<int> lst = new List<int>() { 1, 3, 5, 2, 4, 5, 6, 6 };

            foreach(var x in lst)
            {
                if (x % 2 == 1)
                {
                    lst.Remove(x);
                }
                else
                    lbl.Text += " " + x;
            }

            foreach (PictureBox pb in this.Controls.OfType<PictureBox>())
                pb.BackColor = Color.FromArgb(rand.Next(256), rand.Next(256), rand.Next(256));
            w = this.ClientRectangle.Width; h = this.ClientRectangle.Height;
            tmr.Interval = 1;
            tmr.Tick += GameEvent;
            //tmr.Start();
            this.KeyPreview = true;
        }

        private void GameEvent(object sender, EventArgs e)
        {
            ball.Left += ballx;
            ball.Top += bally;

            lbl.Text = "Scor: " + scor;

            if (ball.Left < 0 || ball.Left + ball.Width > w)
                ballx = -ballx;
            if(ball.Top < 0 || ball.Bounds.IntersectsWith(pbPlayer.Bounds))
                bally = -bally;

            if (goingLeft && pbPlayer.Left < 0)
                goingLeft = false;
            if (goingRight && pbPlayer.Left + pbPlayer.Width > w)
                goingRight = false;

            if (goingLeft) pbPlayer.Left -= speed;
            if (goingRight) pbPlayer.Left += speed;

            

            if (ball.Top > h)
            {
                tmr.Stop();
                MessageBox.Show("Jocul s-a terminat");
                this.Close();
            }

            foreach (Control pb in this.Controls)
            {
                if(pb is PictureBox && pb.Tag == "joc")
                {
                    if(ball.Bounds.IntersectsWith(pb.Bounds))
                    {
                        this.Controls.Remove(pb);
                        scor++;
                        bally = -bally;
                    }
                }
            }

            if(scor == 24)
            {
                tmr.Stop();
                MessageBox.Show("Ai castigat");
                this.Close();
            }
        }
    }
}
