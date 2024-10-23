using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Drawing_line
{
    public partial class Form1 : Form
    {
        private Point[] point = new Point[]{ new Point( 30, 30 ), new Point( 300, 300 ) };
        double x, y;
        double dx, dy;
        bool drawing;
        int step;

        Timer timer = new Timer();

        private void btn_Click(object sender, EventArgs e)
        {
            timer.Stop();
            timer.Tick -= TickHandler;
            drawing = true;
            step = 0;
            x = point[0].X;
            y = point[0].Y;
            dx = (double)(point[1].X - point[0].X) / 30;
            dy = (double)(point[1].Y - point[0].Y) / 30;
            timer.Interval = 30;
            timer.Tick += TickHandler;
            timer.Start();
        }

        private void TickHandler(object sender, EventArgs e)
        {
            if (step == 30)
            {
                timer.Stop();
                drawing = false;
                return;
            }
            x += dx;
            y += dy;
            step++;
            pb.Invalidate();
        }

        public Form1()
        {
            InitializeComponent();
        }

        private void pb_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;
            var pen = new Pen(Color.Red, 5f);

            if (drawing)
                e.Graphics.DrawLine(pen, point[0], new PointF((float)x, (float)y));

            e.Graphics.DrawEllipse(pen, new Rectangle(point[0].X - 20, point[0].Y - 20, 40, 40));
            e.Graphics.FillEllipse(Brushes.Transparent, new Rectangle(point[0].X - 20, point[0].Y - 20, 40, 40));
            e.Graphics.DrawEllipse(pen, new Rectangle(point[1].X - 20, point[1].Y - 20, 40, 40));
            e.Graphics.FillEllipse(Brushes.Transparent, new Rectangle(point[1].X - 20, point[1].Y - 20, 40, 40));



            pen.Dispose();
        }

        
    }
}
