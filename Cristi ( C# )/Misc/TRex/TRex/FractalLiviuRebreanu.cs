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
    public partial class FractalLiviuRebreanu : Form
    {
        private Image img = Image.FromFile($@"E:\Cristi ( C# )\Subiect 2019 - N\ONTI_C#_2019_resurse\Imagini\carti\5.jpg");
        public FractalLiviuRebreanu()
        {
            InitializeComponent();
            var frm = new Zoom();
            frm.ShowDialog();
        }

        private void Draw(int n, int x,int y, int l, int xim, int yim, int lim)
        {
            var e = this.CreateGraphics();
            e.DrawImage(img, new Rectangle(x, y, l, l), new Rectangle(xim, yim, lim, lim), GraphicsUnit.Pixel);
            e.Dispose();

            if (n > 0)
            {
                Draw(n - 1, x - l / 4, y - l / 4, l / 2, xim, yim, lim / 2);
                Draw(n - 1, x + l - l / 4, y - l / 4, l / 2, xim + lim / 2, yim, lim / 2);
                Draw(n - 1, x + l - l / 4, y + l - l / 4, l / 2, xim + lim / 2, yim + lim / 2, lim / 2);
                Draw(n - 1, x - l / 4, y + l - l / 4, l / 2, xim, yim + lim / 2, lim / 2);
            }            
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            Draw(2, 300, 150, 300, 0, 0, 300);
        }
    }
}
