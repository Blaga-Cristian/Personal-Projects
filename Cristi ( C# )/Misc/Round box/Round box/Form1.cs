using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Round_box
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Pen pen = new Pen(Color.Black, 3f);

            int w = ClientRectangle.Width;
            int h = ClientRectangle.Height;

            e.Graphics.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;

            e.Graphics.DrawArc(pen, new Rectangle(0, 0, 200, 200), 180, 90);
            e.Graphics.DrawLine(pen, new Point(100, 0), new Point(w - 100, 0));
            e.Graphics.DrawArc(pen, new Rectangle(w - 200, 0, 200, 200), 270, 90);
            e.Graphics.DrawLine(pen, new Point(w, 100), new Point(w, h - 100));
            e.Graphics.DrawArc(pen, new Rectangle(w - 200, h - 200, 200, 200), 0, 90);
            e.Graphics.DrawLine(pen, new Point(w - 100, h), new Point(100, h));
            e.Graphics.DrawArc(pen, new Rectangle(0, h - 200, 200, 200), 90, 90);
            e.Graphics.DrawLine(pen, new Point(0, h - 100), new Point(0, 100));

            DrawSpiral(20, new Point(200, 30), new Size(400, 400), e.Graphics, pen);
        }

        private void DrawSpiral(int revs, Point point, Size size, Graphics g, Pen pen)
        {
            int nrPoints = revs * 2 * size.Width;

            int cx = size.Width / 2;
            int cy = size.Height / 2;

            PointF[] points = new PointF[nrPoints];

            for(int i = 0; i < nrPoints; ++i)
            {
                float scale = (float)((nrPoints - i) / (float)nrPoints);
                float angle = (float)(2 * Math.PI * ((float)i / (2 * size.Width)));

                points[i] = new PointF(
                    (float)(point.X + cx * (1 + scale * Math.Cos(angle))),
                    (float)(point.Y + cy * (1 + scale * Math.Sin(angle))));
            }

            g.DrawLines(pen, points);
        }
    }
}
