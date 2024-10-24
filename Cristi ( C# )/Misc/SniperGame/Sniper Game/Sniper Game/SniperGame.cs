using System;
using System.CodeDom;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net.Http.Headers;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Sniper_Game
{
    public partial class SniperGame : Form
    {
        static string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\Resurse\";

        int missed, scored;

        Image ghost = Image.FromFile(respath + "ghost.png");
        Image sniperAim = Image.FromFile(respath + "sniper-aim.png");
        Image background = Image.FromFile(respath + "background.png");
        Image[] dummies = new Image[]
        {
            Image.FromFile(respath + "dummy01.png"),
            Image.FromFile(respath + "dummy02.png"),
            Image.FromFile(respath + "dummy03.png"),
            Image.FromFile(respath + "dummy04.png")
        };

        int[] times = new int[6];
        Timer countdown = new Timer();
        Random rand = new Random();
        Timer mouseMove = new Timer();
        int decayTime = 6;
        int spawnChance = 2;

        Timer gameTimer = new Timer();

        public SniperGame()
        {
            InitializeComponent();
            Cursor.Hide();

            mouseMove.Tick += Reposition;
            mouseMove.Interval = 10;
            mouseMove.Start();

            countdown.Tick += Decay;
            countdown.Interval = 1000;
            countdown.Start();

            gameTimer.Tick += GameEvent;
            gameTimer.Interval = 1000;
            gameTimer.Start();

            Width = Aim.Width; Height = Aim.Height;
            using (var graphics = Graphics.FromImage(sniperAim))
            {
                graphics.DrawImage(sniperAim, new Rectangle(0, 0, Width, Height));
                graphics.FillRectangle(Brushes.Red, new Rectangle(0, 0, Width / 2, Height / 2));
            }

        }

        private void Reposition(object sender, EventArgs e)
        {
            Point p = PointToClient(MousePosition);
            Aim.Location = new Point(p.X - Aim.Size.Width / 2, p.Y - Aim.Size.Height / 2);
        } 

        private void Decay(object sender, EventArgs e)
        {
            for(int i = 0; i < times.Count(); ++i)
                if (times[i] != 0)
                {
                    times[i]--;
                    if (times[i] == 0 && PictureBoxes[i].Visible)
                    {
                        missed++;
                        lblMissed.Text = "Missed: " + missed;
                        PictureBoxes[i].Tag = "empty";
                        PictureBoxes[i].Image = null;
                        PictureBoxes[i].Visible = false;
                    }
                }
        }

        private PictureBox[] PictureBoxes
        {
            get { return this.Controls.OfType<PictureBox>().Where(x => x.Tag != null).ToArray(); }
        }

        private void pb_MouseClick(object sender, MouseEventArgs e)
        {

            for(int i = 0; i < PictureBoxes.Count(); ++i)
            {
                PictureBox pic = PictureBoxes[i];
                var x = pic.Bounds;

                if (!pic.Bounds.Contains(PointToClient(MousePosition))) continue;

                if(pic.Tag == "dummy")
                {
                    Timer t = new Timer();
                    PictureBox picb = new PictureBox();
                    picb.Location = pic.Location;
                    picb.Size = pic.Size;
                    picb.BackColor = Color.Transparent;
                    picb.Image = ghost;
                    picb.SizeMode = PictureBoxSizeMode.StretchImage;
                    picb.Tag = 5;
                    pb.Controls.Add(picb);
                    picb.BringToFront();
                    t.Tag = picb;
                    t.Interval = 100;
                    t.Tick += GhostAnimation;
                    t.Start();

                    scored++;
                    lblScored.Text = "Scored: " + scored;
                    times[i] = 0;
                    pic.Tag = "empty";
                    pic.Image = null;
                    pic.Visible = false;
                }
            }
        }

        private void GhostAnimation(object sender, EventArgs e)
        {
            Timer t = (Timer)sender;
            PictureBox picb = (PictureBox)t.Tag;
            if((int)picb.Tag == 0)
            {
                t.Stop();
                t.Dispose();
                pb.Controls.Remove(picb);
                picb.Dispose();
                return;
            }

            picb.Tag = (int)picb.Tag - 1;
            picb.Location = new Point(picb.Location.X + 5, picb.Location.Y - 25);
        }

        private void GameEvent(object sender, EventArgs e)
        {
            lblMissed.Text = "Missed: " + missed;
            lblScored.Text = "Scored: " + scored;

            for (int i = 0; i < PictureBoxes.Count(); ++i)
            {
                PictureBox pic = PictureBoxes[i];

                if (pic.Tag == "empty" && rand.Next(spawnChance) == 0)
                {
                    pic.Visible = true;
                    pic.Tag = "dummy";
                    pic.Image = dummies[rand.Next(4)];
                    times[i] = decayTime;
                }
            }
        }
    }
}
