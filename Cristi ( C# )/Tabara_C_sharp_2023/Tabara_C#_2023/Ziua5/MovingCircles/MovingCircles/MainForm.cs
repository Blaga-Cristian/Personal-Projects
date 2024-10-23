using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MovingCircles
{
    public partial class MainForm : Form
    {
        private List<Circle> circles = new List<Circle>();
        private List<KeyValuePair<Circle, Circle>> lines = new List<KeyValuePair<Circle, Circle>>();
        private Circle circle = null;
        private Circle c1 = null, c2 = null; // cercurile intre care se traseaza linie
        private Point old;
        private Point startL;
        private double xa, ya, xb, yb;
        private double x1, y1, x2, y2;  // cordonatele segmentului care uneste doua cercuri
        private bool mouseMove = false;
        private bool mouseDown = false;
        private bool mouseUp = false;

        public MainForm()
        {
            InitializeComponent();
            ReadCircles();
            DoubleBuffered = true; // IMPORTANT !
        }

        private void ReadCircles()
        {
            StreamReader sr = new StreamReader("circles.txt");
            string line = null;
            char[] sep = { ' ' };
            while ((line = sr.ReadLine()) != null)
            {
                string[] s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                int R = int.Parse(s[2]);
                int X = int.Parse(s[0]) - R;
                int Y = int.Parse(s[1]) - R;
                circles.Add(new Circle(X, Y, R));
            }

            sr.Close();
            sr.Dispose();
        }
        private void MainForm_MouseMove(object sender, MouseEventArgs e)
        {
            if (!mouseDown || mouseUp) return;
            mouseMove = true;
            if (ModifierKeys == Keys.Control && circle != null)
            {
                Coordinates(e.X, e.Y);


                Invalidate();
                return;
            }
            //  now = e.Location;
            if (circle != null && ModifierKeys != Keys.Control)
            {
                int dx = e.X - old.X;
                int dy = e.Y - old.Y;
                circle.X += dx;
                circle.Y += dy;
                old = e.Location;
                Invalidate();
            }
        }

        private bool Hit(Circle c, int x, int y)
        {
            // centrul cercului
            int x0 = c.X + c.R;
            int y0 = c.Y + c.R;
            // daca distanta dintre centru si (x, y) e mai mica decat raza
            return (x - x0) * (x - x0) + (y - y0) * (y - y0) <= c.R * c.R;
        }

        private void LineCoordinates(Circle c1, Circle c2)
        {
            double A = c1.Y + c1.R - c2.Y - c2.R;
            double B = c2.X + c2.R - c1.X - c1.R;
            double alpha = Math.Atan2(A, B);
            x1 = c1.X + c1.R + c1.R * Math.Cos(alpha);
            y1 = c1.Y + c1.R - c1.R * Math.Sin(alpha);
            x2 = c2.X + c2.R - c2.R * Math.Cos(alpha);
            y2 = c2.Y + c2.R + c2.R * Math.Sin(alpha);
        }
        private void Coordinates(int x, int y)
        {
            if (circle == null) return;

            double A = circle.Y + circle.R - y;
            double B = x - circle.R - circle.X;
            double alpha = Math.Atan2(A, B);
            xa = circle.X + circle.R + (double)(circle.R) * Math.Cos(alpha);
            ya = circle.Y + circle.R - circle.R * Math.Sin(alpha);
            xb = x; yb = y;
        }
        private void MainForm_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.SmoothingMode = SmoothingMode.AntiAlias;
            Circle cr = null;
            using (Pen pen = new Pen(Color.Empty, 4f))
            {
                // desenez cercurile
                foreach (Circle c in circles)
                {
                    cr = c;
                    pen.Color = c.C;
                    e.Graphics.DrawEllipse(pen, new Rectangle(c.X, c.Y, 2 * c.R, 2 * c.R));
                    using (Font font = new Font("Arial", 24, GraphicsUnit.Pixel))
                        e.Graphics.DrawString(c.R.ToString(), font, new SolidBrush(c.C),
                            (float)(c.X + c.R - 16), (float)(c.Y + c.R - 12));
                }

                // desenez linia variabila care porneste de pe cercul selectat
                // si se opreste la cursor (in timpul miscarii mouse-ului)
                pen.Color = Color.Red;
                if (circle != null && mouseMove && mouseDown && xa != -1)
                    e.Graphics.DrawLine(pen, (float)xa, (float)ya, (float)xb, (float)yb);

                
                // desenez muchiile intre noduri (cercuri)
                if (lines.Count != 0)
                {
                    foreach (var line in lines)
                    {
                        LineCoordinates(line.Key, line.Value);
                        e.Graphics.DrawLine(pen, (float)x1, (float)y1, (float)x2, (float)y2);
                    }

                    Invalidate();
                }
            }
        }

        private void MainForm_MouseDown(object sender, MouseEventArgs e)
        {
            mouseDown = true;
            mouseUp = false;
            circle = circles.Find(c => Hit(c, e.X, e.Y));

            if (circle != null)
            {
                old = e.Location;
                if (ModifierKeys == Keys.Control)
                {
                    c1 = circle; // cercul de start  
                }

            }
        }

        private void MainForm_MouseUp(object sender, MouseEventArgs e)
        {
            mouseDown = false;
            mouseUp = true;
            circle = null;
            xa = -1; ya = -1; xb = -1; yb = -1;
            if (ModifierKeys == Keys.Control && e.Button == MouseButtons.Left)
            {
                c2 = circles.Find(c => Hit(c, e.X, e.Y));
                if (c2 != null)
                {
                    LineCoordinates(c1, c2);
                    lines.Add(new KeyValuePair<Circle, Circle>(c1, c2));
                    Invalidate();
                }

            }

            if (ModifierKeys != Keys.Control)
                circle = null;
        }
    }
}
