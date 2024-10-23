using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Fractal
{
    public partial class Form1 : Form
    {
        int m = 8;
        public Form1()
        {
            InitializeComponent();
        }

        private void patrat(int n, int x,int y,int l)
        {
            if(n > 0)
            {
                patrat(n - 1, x - l / 4, y - l / 4, l / 2);
                patrat(n - 1, x - l / 4, y + l - l / 4, l / 2);
                patrat(n - 1, x + l - l / 4, y - l / 4, l / 2);
                patrat(n - 1, x + l - l / 4, y + l - l / 4, l / 2);
            }

            Pen p;
            if (n % 2 == 0)
                p = new Pen(Color.Red, 3f);
            else
                p = new Pen(Color.Blue, 3f);

            var e = this.CreateGraphics();
            Point[] points = new Point[]
            {
                new Point(x , y),
                new Point(x + l, y),
                new Point(x + l, y + l),
                new Point(x, y + l)
            };
            e.DrawPolygon(p, points);
            e.Dispose();
            p.Dispose();
        }

        private void btnStartFractal_Click(object sender, EventArgs e)
        {
            patrat(8, 200, 200, 100);
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {}

        private void pb_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.FillRectangle(Brushes.Black, new Rectangle(0, 0, 900, 900));
        }
    }
}
