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

namespace Space_Battle_Game
{
    public partial class Form1 : Form
    {
        Random rand = new Random();
        Timer gameTimer = new Timer();

        int enemySpeed = 5, playerSpeed = 25, bulletSpeed = 35, GAMESPEED = 100;
        bool shooting, goingLeft, goingRight;

        int scor;



        public Form1()
        {
            InitializeComponent();
            Reset();
            this.KeyPreview = true;
        }

        private PictureBox[] Enemies
        {
            get { return this.Controls.OfType<PictureBox>().Where(x => x.Tag != null && x.Tag.ToString() == "enemy").ToArray(); }
        }

        private void Reset()
        {            
            scor = 0;

            shooting = goingLeft = goingRight = false;


            pbPlayer.Left = 320;
            pbBullet.Top = ClientRectangle.Height + 200;
            foreach (PictureBox p in Enemies)
            {
                do
                {
                    p.Top = rand.Next(-200, -100);
                    p.Left = rand.Next(0, ClientRectangle.Width - p.Width);
                } while (Enemies.Any(x => x != p && x.Bounds.IntersectsWith(p.Bounds)));
            }


            gameTimer.Stop();
            gameTimer.Tick -= GameEvent;
            gameTimer.Interval = GAMESPEED;
            gameTimer.Tick += GameEvent;
            gameTimer.Start();

            lblScor.Text = $@"Scor: {scor}";
        }

        private void GameEvent(object sender, EventArgs e)
        {
            if (goingLeft && pbPlayer.Left > 0) pbPlayer.Left -= playerSpeed;
            if (goingRight && pbPlayer.Left < ClientRectangle.Width - pbPlayer.Width) pbPlayer.Left += playerSpeed;
            if(shooting)
            {
                if (pbBullet.Top < -pbBullet.Height)
                {
                    shooting = false;
                    pbBullet.Top = ClientRectangle.Height + 200;
                }
                else pbBullet.Top -= bulletSpeed;
            }

            foreach (PictureBox p in Enemies)
            {
                p.Top += enemySpeed + (scor / 10) * 5;
                if (pbBullet.Bounds.IntersectsWith(p.Bounds))
                {
                    do
                    {
                        p.Top = rand.Next(-200, -100);
                        p.Left = rand.Next(0, ClientRectangle.Width - p.Width);
                    } while (Enemies.Any(x => x != p && x.Bounds.IntersectsWith(p.Bounds)));


                    pbBullet.Top = ClientRectangle.Height + 200;
                    shooting = false;                    

                    scor++;
                }

                if (p.Top > ClientRectangle.Height + p.Height)
                    do
                    {
                        p.Top = rand.Next(-200, -100);
                        p.Left = rand.Next(0, ClientRectangle.Width - p.Width);
                    } while (Enemies.Any(x => x != p && x.Bounds.IntersectsWith(p.Bounds)));

                if (pbPlayer.Bounds.IntersectsWith(p.Bounds))
                {
                    gameTimer.Stop();
                    MessageBox.Show("Jocul s-a terminat");
                    Reset();
                }
            }

            lblScor.Text = $@"Scor: {scor}";
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.A)
                goingLeft = true;
            else if (e.KeyCode == Keys.D)
                goingRight = true;
            else if (e.KeyCode == Keys.Space && !shooting)
            {
                shooting = true;
                pbBullet.Top = pbPlayer.Top;
                pbBullet.Left = pbPlayer.Left + pbPlayer.Width / 2;
            }
            else if (e.KeyCode == Keys.R)
                Reset();

            e.Handled = e.SuppressKeyPress = true;
        }

        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.A)
                goingLeft = false;
            else if (e.KeyCode == Keys.D)
                goingRight = false;

            e.Handled = e.SuppressKeyPress = true;
        }
    }
}
