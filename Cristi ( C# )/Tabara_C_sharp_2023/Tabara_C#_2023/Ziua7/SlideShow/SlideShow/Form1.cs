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
using System.Data.SqlTypes;

namespace SlideShow
{
    public partial class Form1 : Form
    {
        private string[] files;
        Timer timer = new Timer();

        public Form1()
        {
            InitializeComponent();
            pbImage.SizeMode = PictureBoxSizeMode.Zoom;
            timer.Interval = 300;
            timer.Tick += OnTimerTick;
        }

        int index = 0;
        private void OnTimerTick(object sender, EventArgs e)
        {
            ++index;
            if (index == files.Length)
                index = 0;
            pbImage.Image = Image.FromFile(files[index]);
            pbImage.Invalidate();
        }

        private void btnChoose_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog dlg = new FolderBrowserDialog();
            DialogResult dr = dlg.ShowDialog();
            if (dr == DialogResult.OK)
            {
                string path = dlg.SelectedPath;
                files = Directory.GetFiles(path);
                pbImage.Image = Image.FromFile(files[0]);
                pbImage.Invalidate();
            }
        }

        private void btnstart_Click(object sender, EventArgs e)
        {
            timer.Start();
        }

        private void btnStop_Click(object sender, EventArgs e)
        {
            timer.Stop();
        }
    }
}
