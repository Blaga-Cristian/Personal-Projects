using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TRexActually
{
    public partial class Form1 : Form
    {
        string respath = $@"E:\DOWNLOADS\";
        int v, acc;
        Random rand = new Random();
        bool jumping = false;
        Timer timer;
        int scor;
        int gamespeed;
        static int jumpforce = 40, graviti = 5;
        public Form1()
        {
            InitializeComponent();
            Reset();
        }


        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.R)
                Reset();
            if (e.KeyCode == Keys.Space)
                Jump();
        }

        private void Jump()
        {
            if (jumping) return;
            jumping = true;
            v = 0;
            acc = jumpforce;
        }

        private void Reset()
        {
            if(timer != null)timer.Stop();
            timer = new Timer();
            timer.Interval = 20;
            timer.Tick += GameEvent;
            trex.Image = Image.FromFile(respath + "Running.png");
            trex.Location = new Point(60, 330);
            gamespeed = 10;
            v = acc = 0;
            scor = 0;
            jumping = false;

            int max = 0;
            foreach (PictureBox x in this.Controls.OfType<PictureBox>())
                if (x.Tag.ToString() == "obstacle")
                {
                    x.Image = Image.FromFile(respath + "Cactus.png");
                    x.Top = 330;
                    int cmp = rand.Next(800, 1200);
                    if (max + 200 < cmp)
                        x.Left = cmp;
                    else
                        x.Left = max + 200;

                    if (max < x.Left)
                        max = x.Left;
                }

            timer.Start();
        }

        private void GameEvent(object sender, EventArgs e)
        {
            if(jumping)
            {
                v += acc;
                trex.Top -= acc;
                acc -= graviti;
                if(trex.Top > 330)
                {
                    trex.Top = 330;
                    v = acc = 0;
                    jumping = false;
                }
            }

            Queue<PictureBox> q = new Queue<PictureBox>();
            int max = 0;
            foreach(PictureBox x in this.Controls.OfType<PictureBox>())
            {
                if(x.Tag.ToString() == "obstacle")
                {
                    if (max < x.Left)
                        max = x.Left;

                    if (trex.Bounds.IntersectsWith(x.Bounds))
                    {
                        Reset();
                        return;
                    }

                    if (x.Left + x.Width < 0)
                    {
                        q.Enqueue(x);
                        scor++;
                    }
                    else
                        x.Left -= gamespeed;
                }
            }

            while(q.Count != 0)
            {
                var x = q.Dequeue();
                int cmp = rand.Next(800, 1200);
                if (max + 200 < cmp)
                    x.Left = cmp;
                else
                    x.Left = max + 200;
            }

            gamespeed = 10 + (scor / 10) * 5;

            lbl.Text = "Scor: " + scor;
        }
    }
}
