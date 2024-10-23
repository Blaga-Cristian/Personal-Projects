using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Spiral
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            DrawSpiral(e.Graphics, Color.Yellow, 2f, 10);
        }

        private void DrawSpiral(Graphics e, Color col, float width, int numrevolutions)
        {
            int cx = ClientSize.Width;
            int cy = ClientSize.Height;
            int nrpoints = 2 * numrevolutions * (cx + cy);
            PointF[] points = new PointF[nrpoints];
            

            float fScale, fAngle;

            for(int i = 0; i < nrpoints; ++i)
            {
                fAngle = (float)(i * 2 * Math.PI / (nrpoints / numrevolutions));
                fScale = 1 - (float)((float)i/ nrpoints);

                points[i].X = (float)(cx / 2 * (1 + fScale * Math.Cos(fAngle)));
                points[i].Y = (float)(cy / 2 * (1 + fScale * Math.Sin(fAngle)));
            }

            e.DrawLines(new Pen(col, width), points);
        }
    }
}
