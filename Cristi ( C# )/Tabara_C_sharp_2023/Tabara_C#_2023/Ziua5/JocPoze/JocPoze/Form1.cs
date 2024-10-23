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

namespace JocPoze
{
    public partial class Form1 : Form
    {

        int n = 8, m = 8;
        PictureBox[,] pb = new PictureBox[8, 8];
        Random rd = new Random();
        string path = "";
        string[] files = null;

        private void btnNew_Click(object sender, EventArgs e)
        {
             for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                {
                    pb[i, j].Image = Image.FromFile(files[rd.Next() % files.Length]);
                    pb[i, j].SizeMode = PictureBoxSizeMode.StretchImage;
                }
        }

        private void pictureBox_Click(object sender, EventArgs e)
        {
            PictureBox pb = (PictureBox)sender;
            pb.Image = Image.FromFile(files[rd.Next() % files.Length]);
        }

        private void btnReset_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                {
                    // 
                }
        }

        public Form1()
        {
            InitializeComponent();
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                {
                    pb[i, j] = new PictureBox();
                    pb[i, j].BorderStyle = BorderStyle.FixedSingle;
                    tableLayoutPanel1.Controls.Add(pb[i, j], j, i);
                    pb[i, j].Dock = DockStyle.Fill;
                    pb[i, j].Size = new System.Drawing.Size(64, 64);
                    pb[i, j].TabStop = false;
                    pb[i, j].Click += new EventHandler(pictureBox_Click);
                }

            path = Directory.GetCurrentDirectory() + @"\foto\";
            files = Directory.GetFiles(path);
        }
    }
}
