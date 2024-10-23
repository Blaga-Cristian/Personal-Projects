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

namespace TableImages
{
    public partial class Form1 : Form
    {

        private PictureBox[,] pb = null;
        private int n = 7;
        private int m = 7;
        private string path = null;
        private string[] files = null;
        private Random rd = null;
        public Form1()
        {
            InitializeComponent();

            path = Directory.GetCurrentDirectory();
            path += @"\foto\";

            files = Directory.GetFiles(path);
          //  string fileName = Path.GetFileName(files[0]);
          //  string extension = Path.GetExtension(files[1]);
            
            rd = new Random();
            pb = new PictureBox[n, m];
            DrawPictures(false);

        }

        private void DrawPictures(bool created)
        {
            for (int j = 0; j < m; ++j)
                for (int i = 0; i < n; ++i)
                {
                    if (!created)
                        pb[i, j] = new PictureBox();
                        
                    pb[i, j].Click += pictureBox_Click;
                    pb[i, j].Size = new Size(70, 70);

                    pb[i, j].SizeMode = PictureBoxSizeMode.StretchImage;
                    pb[i, j].Image = Image.FromFile(files[rd.Next() % files.Length]);
                    table.Controls.Add(pb[i, j], j, i);
                }
        }

        private void BrnChange_Click(object sender, EventArgs e)
        {
            
            this.table.Controls.Clear();
            this.table.SuspendLayout();
            DrawPictures(true);
            this.table.ResumeLayout(false);

        }

        private void pictureBox_Click(object sender, EventArgs e)
        {
            PictureBox pb = (PictureBox)sender;

            pb.Image = Image.FromFile(files[rd.Next() % files.Length]);

        }

        private void BtnNew_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    pb[i, j].Image =
                        Image.FromFile(files[rd.Next() % files.Length]);
        }
    }
   
}

