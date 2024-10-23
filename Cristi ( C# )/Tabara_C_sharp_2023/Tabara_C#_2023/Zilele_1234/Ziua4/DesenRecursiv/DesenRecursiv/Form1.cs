using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DesenRecursiv
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
           
        }

        // ONTI 2019
        private void Draw(int k, float x, float y, float L, Image img, PaintEventArgs e)
        {
            if (k == 0) return;

            e.Graphics.DrawImage(img, x, y, L, L);
            Bitmap img1 = CropFrom(img, new RectangleF(0, 0, L / 2, L / 2));
            Draw(k - 1, x - L / 4, y - L / 4, L / 2, img1, e);  // img1 = stanga-sus

            var img2 = CropFrom(img, new RectangleF(L / 2, L / 2, L / 2, L / 2));
            Draw(k - 1, x + 3 * L / 4, y + 3 * L / 4, L / 2, img2, e); // img2 - dreapta-jos (decupata din img)

            var img3 = CropFrom(img, new RectangleF(0, L / 2, L / 2, L / 2));
            Draw(k - 1, x - L / 4, y + 3 * L / 4, L / 2, img3, e); // img3 - decupata din img - stanga jos

            var img4 = CropFrom(img, new RectangleF(L / 2, 0, L / 2, L / 2)); // 

            Draw(k - 1, x + 3 * L / 4, y - L / 4, L / 2, img4, e); // img4 - dreapta jos

        }
        // "taie" dreptunghiul source din img si plaseaza intr-un bitmap
        Bitmap CropFrom(Image img, RectangleF source)
        {
            Bitmap bmp = new Bitmap((int)source.Width, (int)source.Height);
            // g este asociat bitmap-ului bmp (deseneaza pe bmp)
            using (Graphics g = Graphics.FromImage(bmp))
            {
                g.DrawImage(img, new RectangleF(0, 0, bmp.Width, bmp.Height), source, GraphicsUnit.Pixel);
            }
            return bmp;
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Image img = Bitmap.FromFile("5.jpg");
            int x = 120, y = 120;
            int L = img.Width;
            Draw(3, x, y, L, img, e);
            
        }
    }
}
