using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TRex
{
    public partial class Zoom : Form
    {
        Bitmap bmp;
        public Zoom()
        {
            InitializeComponent();
            PictureBox pb = new PictureBox();
            pb.Dock = DockStyle.Fill;
            pb.SizeMode = PictureBoxSizeMode.AutoSize;
            pb.Image = Image.FromFile($@"E:\Cristi ( C# )\Subiect 2019 - N\ONTI_C#_2019_resurse\Imagini\carti\6.jpg");
            panel1.Controls.Add(pb);
            panel1.AutoScrollMinSize = new System.Drawing.Size(300, 300);
        }

        private void btnZoom_Click(object sender, EventArgs e)
        {
            var pb = panel1.Controls.OfType<PictureBox>().ToArray()[0];
            var bmp = new Bitmap(pb.Image, pb.Image.Width * 2, pb.Image.Height * 2);
            pb.Image = bmp;
            panel1.AutoScrollMinSize = new Size(bmp.Width, bmp.Height);
        }
    }
}
