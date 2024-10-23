using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Clock
{
    public partial class Form1 : Form
    {
        int r = 200;
        Timer tmr = new Timer();

        public Form1()
        {
            InitializeComponent();
            this.SetStyle(ControlStyles.OptimizedDoubleBuffer |
                ControlStyles.UserPaint |
                ControlStyles.AllPaintingInWmPaint, true);

            tmr.Interval = 1000;
            tmr.Tick += delegate { this.Invalidate(); };
            tmr.Start();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;


            Point center = new Point(100 + r, r);

            e.Graphics.DrawEllipse(Pens.Black, new Rectangle(100, 0, 2 * r, 2 * r));

            DateTime now = DateTime.Now;

            int h = (now.Hour % 12) * 60 + now.Minute;

            float angle = (float)(2 * Math.PI * h / 720 - Math.PI / 2);
            PointF p = new PointF(
               100 + (float)(r * (1 + Math.Cos(angle))),
                 0 + (float)(r * (1 + Math.Sin(angle))));

            e.Graphics.DrawLine(new Pen(Color.Black, 4f), center, p);



            int m = now.Minute * 60 + now.Second;

            angle = (float)(2 * Math.PI * m / 3600 - Math.PI / 2);
            p = new PointF(
               100 + (float)(r * (1 + Math.Cos(angle))),
                 0 + (float)(r * (1 + Math.Sin(angle))));

            e.Graphics.DrawLine(new Pen(Color.Black, 2f), center, p);


            int s = now.Second;

            angle = (float)(2 * Math.PI * s / 60 - Math.PI / 2);
            p = new PointF(
               100 + (float)(r * (1 + Math.Cos(angle))),
                 0 + (float)(r * (1 + Math.Sin(angle))));

            e.Graphics.DrawLine(new Pen(Color.Red, 3f), center, p);

            for(int i = 1; i <= 12; ++i)
            {
                angle = (float)(2 * Math.PI * i / 12 - Math.PI / 2);
                p = new PointF(
                    85 + (float)(r * (1 + Math.Cos(angle))),
                    0 + (float)(r * (1 + Math.Sin(angle))));
                e.Graphics.DrawString("" + i, new Font(FontFamily.GenericSansSerif, 15f), Brushes.Red, p);
            }
        }
    }
}
