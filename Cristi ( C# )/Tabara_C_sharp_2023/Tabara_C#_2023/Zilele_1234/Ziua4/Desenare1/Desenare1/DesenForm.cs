using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlTypes;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace Desenare1
{
    public partial class DesenForm : Form
    {
        public DesenForm()
        {
            InitializeComponent();
        }

        private void DesenForm_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.SmoothingMode = SmoothingMode.AntiAlias;
            DrawLine(e);
            DrawLines(e);
            DrawEllipse(e);
            
        }

        private void DrawEllipse(PaintEventArgs e)
        {
            
            Rectangle rect = new Rectangle(100, 100, 200, 200);
            Pen pen = new Pen(Color.Green, 5f);
            //e.Graphics.DrawEllipse(pen, rect);
            e.Graphics.FillEllipse(Brushes.Red, rect);
            pen.Dispose();
        }

        private void DrawLines(PaintEventArgs e)
        {
            Point[] points = 
            {
                new Point(10, 10),
                new Point(50, 80),
                new Point(100, 120),
                new Point(250, 400)
            };

            Pen pen = new Pen(Color.Blue, 5);
            e.Graphics.DrawLines(pen, points);
            pen.Dispose();
        }

        private static void DrawLine(PaintEventArgs e)
        {
            int x1 = 50, y1 = 400, x2 = 600, y2 = 100;
            Pen pen = new Pen(Color.Red, 4f);
            e.Graphics.DrawLine(pen, x1, y1, x2, y2);
            pen.Dispose();
        }
    }
}
