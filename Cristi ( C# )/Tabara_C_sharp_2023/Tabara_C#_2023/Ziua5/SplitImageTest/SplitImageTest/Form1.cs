using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SplitImageTest
{
    public partial class Form1 : Form
    {
        string imgFile = @"Pisica.jpg";
       
        Bitmap[,] bmp = null;
        PictureBox[,] pb = null;
 
        public Form1()
        {
            InitializeComponent();
           
        }

        private void HandlePBClick(object sender, EventArgs e)
        {
            PictureBox pb = (PictureBox)sender;
            //pb.Image = null;
            pb.Image.Dispose();
            pb.Invalidate();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Image img = Image.FromFile(imgFile);
            int W = this.ClientRectangle.Width;
            int H = this.ClientRectangle.Height;
            int n = 10, m = 10;
            int h = H / n;
            int w = W / m;
            pb = new PictureBox[n, m];
            bmp = new Bitmap[n, m];
            
            Bitmap b = new Bitmap(W, H);
            Graphics gr = Graphics.FromImage(b);

            gr.DrawImage(img, new Rectangle(0, 0, W, H), new Rectangle(0, 0, img.Width, img.Height),
                GraphicsUnit.Pixel);
            gr.Dispose();
           
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                {  
                    bmp[i, j] = new Bitmap(w, h);
                    Graphics g = Graphics.FromImage(bmp[i, j]);
                    g.DrawImage(b, new Rectangle(0, 0, w, h), new Rectangle(j * w, i * h, w, h), GraphicsUnit.Pixel);
                    g.Dispose();

                    pb[i, j] = new PictureBox();
                    pb[i, j].Location = new Point(j * w, i * h);
                    pb[i, j].Image = bmp[i, j];
                    pb[i, j].Click += HandlePBClick;
                    Controls.Add(pb[i, j]);

                }
        }
    }
}
