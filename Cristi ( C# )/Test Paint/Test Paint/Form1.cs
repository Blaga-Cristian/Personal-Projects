using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Test_Paint
{
    public partial class Form1 : Form
    {
        static Point center = new Point(400, 300);
        static int size = 300;

        public Form1()
        {
            InitializeComponent();
            this.Invalidate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            GraphicsPath gp = new GraphicsPath();
            gp.AddEllipse(new Rectangle(center.X - size, center.Y - size, 2 * size, 2 * size));

            ColorBlend cb = new ColorBlend();
            cb.Colors = new Color[] { Color.Red, Color.Yellow, Color.Blue };
            cb.Positions = new float[] { 0.0f, 0.3f, 1f };
            PathGradientBrush pgb = new PathGradientBrush(gp);
            pgb.InterpolationColors = cb;

            e.Graphics.FillRectangle(pgb, ClientRectangle);


            List<Point> points = new List<Point>();

            for (int i = 0; i < 1000; ++i)
            {
                double angle = 2 * Math.PI * i / 100;
                points.Add(new Point((int)(center.X + size * Math.Cos(angle) * i / 1000),
                    (int)(center.Y + size * Math.Sin(angle) * i / 1000)));
            }

            e.Graphics.DrawLines(Pens.White, points.ToArray());
        }
    }
}
