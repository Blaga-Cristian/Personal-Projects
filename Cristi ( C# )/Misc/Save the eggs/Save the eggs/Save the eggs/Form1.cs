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

namespace Save_the_eggs
{
    public partial class Form1 : Form
    {
        string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\Resurse\";

        Image chickenst, chickendr, splash, hurt, egg;
        Random rand = new Random();
        Timer gameTimer = new Timer();
        Timer cleanup = new Timer();
        bool goingLeft, goingRight;
        int speed = 30;
        static int basegravity = 10;
        int gravity = basegravity;
        int scor;
        int lives = 10;
        bool hurting;

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.KeyCode == Keys.R)
            {
                Reset();
                return;
            }
            if (e.KeyCode == Keys.A)
                goingLeft = true;
            if (e.KeyCode == Keys.D)
                goingRight = true;
        }

        private void Reset()
        {
            gameTimer.Stop();
            cleanup.Stop();
            goingLeft = goingRight = hurting = false;
            pbPlayer.Image = chickenst;
            scor = 0;
            gravity = basegravity = 10;
            lives = 10;

            pbPlayer.Left = 315;

            foreach(var pb in PictureBoxes)
            {
                if (pb.Tag == "jucator") continue;
                pb.Left = rand.Next(0, 705);
                pb.Top = rand.Next(-150, -50);
                pb.Tag = "egg";
                pb.Image = egg;
            }

            gameTimer.Start();
            cleanup.Start();
        }

        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.A)
                goingLeft = false;
            if(e.KeyCode == Keys.D)
                goingRight = false;
        }

        public Form1()
        {
            InitializeComponent();
            this.KeyPreview = true;

            chickenst = Image.FromFile(respath + "chicken_normal2.png");
            chickendr = Image.FromFile(respath + "chicken_normal.png");
            splash = Image.FromFile(respath + "splash.png");
            egg = Image.FromFile(respath + "egg.png");
            hurt = Image.FromFile(respath + "chicken_hurt.png");

            foreach(var pb in PictureBoxes)
                if(pb.Tag == "egg")
                {
                    pb.Left = rand.Next(0, 705);
                    pb.Top = rand.Next(-100, -10);
                }

            cleanup.Interval = 300;
            cleanup.Tick += Clean;
            cleanup.Start();
            gameTimer.Interval = 100;
            gameTimer.Tick += GameEvent;
            gameTimer.Start();
        }

        private void Clean(object sender, EventArgs e)
        {
            bool ok = true;
            foreach(var pb in PictureBoxes)
            {
                if (pb.Tag == "splash1")
                {
                    pb.Image = egg;
                    pb.Tag = "egg";
                    pb.Left = rand.Next(0, 705);
                    pb.Top = rand.Next(-100, -10);
                }
                else if (pb.Tag == "splash2")
                {
                    ok = false;
                    pb.Tag = "splash1";
                }
            }

            if (ok)
                hurting = false;
        }

        private void GameEvent(object sender, EventArgs e)
        {
            if (goingLeft && pbPlayer.Left <= 0)
                goingLeft = false;

            if (goingRight && pbPlayer.Left >= 800 - pbPlayer.Width)
                goingRight = false;


            if (goingLeft)
            {
                if(!hurting)pbPlayer.Image = chickenst;
                pbPlayer.Left -= speed;
            }
            if(goingRight)
            {
                if(!hurting)pbPlayer.Image = chickendr;
                pbPlayer.Left += speed;
            }

            

            foreach(var pb in PictureBoxes)
                if(pb.Tag == "egg")
                {
                    pb.Top += gravity;


                    if(pbPlayer.Bounds.IntersectsWith(pb.Bounds))
                    {
                        scor++;
                        pb.Left = rand.Next(0, 705);
                        pb.Top = rand.Next(-100, -10);
                    }

                    if(pb.Top >= 450 - pb.Height)
                    {
                        pb.Image = splash;
                        pb.Tag = "splash2";
                        pbPlayer.Image = hurt;
                        hurting = true;
                        lives--;
                    }
                }

            if(lives <= 0)
            {
                gameTimer.Stop();
                cleanup.Stop();
                MessageBox.Show("Ai pierdut");
                Reset();
            }

            lblScor.Text = "Scor: " + scor;
            lblLives.Text = "Vieti: " + lives;
            gravity = basegravity + (scor / 10) * 2;
        }

        private PictureBox[] PictureBoxes
        {
            get { return this.Controls.OfType<PictureBox>().ToArray(); }
        }
    }
}
