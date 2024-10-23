using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace Guessing_game
{
    public partial class Form1 : Form
    {
        List<Image> images = new List<Image>();
        Image questionMark = Image.FromFile($@"E:\Cristi ( C# )\Misc\Guessing game\descărcare.png");
        Random rand = new Random();
        bool can_click = true;
        PictureBox first, second;
        Timer penalty = new Timer();
        Timer gameTimer = new Timer();
        int time = 30;

        public Form1()
        {
            InitializeComponent();
            IncarcaImagini();
            penalty.Interval = 1000;
            penalty.Tick += PenaltyOver;
            gameTimer.Interval = 1000;
            gameTimer.Tick += GameTick;
            btnReset_Click(new object(), new EventArgs());
        }

        private void GameTick(object sender, EventArgs e)
        {
            time--;
            TimeSpan ts = TimeSpan.FromSeconds(time);
            lbl.Text = ts.ToString($@"mm\:ss");

            if(!PictureBoxes.Any(pb => pb.Visible == true))
            {
                gameTimer.Stop();
                MessageBox.Show("Ati castigat");
                btnReset_Click(new object(), new EventArgs());
                return;
            }

            if(time <= 0)
            {
                gameTimer.Stop();
                MessageBox.Show("Timpul s-a terminat");                
                btnReset_Click(new object(), new EventArgs());
            }
        }

        private void PenaltyOver(object sender, EventArgs e)
        {
            first.Image = second.Image = questionMark;
            first = second = null;
            can_click = true;
            penalty.Stop();
        }

        private void IncarcaImagini()
        {
            string[] files = Directory.GetFiles($@"E:\Cristi ( C# )\Misc\Guessing game\Images");
            for (int i = 0; i < files.Count(); ++i)
                images.Add(Image.FromFile(files[i]));
        }

        private PictureBox[] PictureBoxes
        {
            get { return this.Controls.OfType<PictureBox>().ToArray(); }
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            gameTimer.Start();

            foreach (var img in images)
            {
                GetFreeSlot().Tag = img;
                GetFreeSlot().Tag = img;
            }

            foreach (PictureBox pb in PictureBoxes)
                pb.Image = questionMark;
        }

        private PictureBox GetFreeSlot()
        {
            int num;
            do
            {
                num = rand.Next(0, PictureBoxes.Count());
            } while (PictureBoxes[num].Tag != null);
            return PictureBoxes[num];
        }

        private void btnReset_Click(object sender, EventArgs e)
        {
            penalty.Stop();
            gameTimer.Stop();
            time = 30;
            first = second = null;
            can_click = true;
            lbl.Text = "";
            
            foreach(PictureBox pb in PictureBoxes)
            {
                pb.Visible = true;
                pb.Image = null;
                pb.Tag = null;
            }
        }

        private void btnStart_MouseHover(object sender, EventArgs e)
        {
            ToolTip tp = new ToolTip();
            tp.SetToolTip((Control)sender, "Incepeti jocul");
        }

        private void pictureBox1_MouseClick(object sender, MouseEventArgs e)
        {
            if (!can_click) return;

            var pb = (PictureBox)sender;
            pb.Image = (Image)pb.Tag;


            if(first == null)
            {
                first = pb;
                return;
            }
            else
            {
                second = pb;

                if (first == second) return;


                if (first.Tag == second.Tag)
                {
                    first.Visible = second.Visible = false;
                    first = second = null;
                }
                else
                {
                    can_click = false;
                    penalty.Start();
                }
            }
        }
    }
}
