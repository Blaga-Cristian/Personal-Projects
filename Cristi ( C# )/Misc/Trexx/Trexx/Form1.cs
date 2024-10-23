using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Trexx
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        int[] x = new int[100];
        float[] y = new float[100];
        float a, b, c;
        int cnt = 0;
        Color[] colors = new Color[]
        {
            Color.AliceBlue,
            Color.Aqua,
            Color.Red,
            Color.Green,
            Color.Blue,
            Color.Magenta,
            Color.Pink,
            Color.Orange,
            Color.Orchid,
            Color.Beige
        };

        private void btnStart_Click(object sender, EventArgs e)
        {
            if(cnt > 8)
            {
                if(MessageBox.Show("Stergeti linii inatinte sa mai adaugati", "Prea multe linii", MessageBoxButtons.OKCancel)
                    == DialogResult.OK)
                    Reset(new object(), new MouseEventArgs(MouseButtons.Left, 0, 0, 0, 0));
                return;
            }
            var graphics = p1.CreateGraphics();
            float a = float.Parse(txtA.Text);
            float b = float.Parse(txtB.Text);
            float c = float.Parse(txtC.Text);
            for(int i = 0; i <= 80; ++i)
            {
                int v = i - 40;
                x[i] = v;
                y[i] = a * v * v + b * v + c;
            }

            DrawLine(graphics);
            AddToLegend(a, b, c);
            cnt++;
        }

        private void AddToLegend(float a, float b, float c)
        {
            string f = "f(x) = " + a + " * x^2 + " + b + " * x + " + c;
            listBox1.Items.Add(f);
        }

        private void DrawLine(Graphics e)
        {
            Pen p = new Pen(colors[cnt], 3f);
            for (int i = 0; i < 80; ++i)
                e.DrawLine(p, (40 - x[i]) * 10, (18.5f - y[i]) * 10, (40 - x[i + 1]) * 10, (18.5f - y[i + 1]) * 10);
            p.Dispose();
        }

        private void p1_Paint(object sender, PaintEventArgs e)
        {
            DrawAxis(e.Graphics);
            //DrawArt();
        }

        private void DrawArt()
        {
            var points = new Point[]
            {
                new Point(100, 100),
                new Point(150, 100),
                new Point(150, 150),
                new Point(100, 150)
            };

            var pgb = new PathGradientBrush(points);
            var cb = new ColorBlend();
            cb.Colors = new Color[] { Color.Blue, Color.Yellow, Color.Red };
            cb.Positions = new float[] { 0f, 0.7f, 1f };
            pgb.InterpolationColors = cb;
            var e = p1.CreateGraphics();
            //e.FillRectangle(pgb, new Rectangle(0, 0, 900, 900));

            //e.DrawBezier(new Pen(Color.Red, 3f), points[0], points[1], points[2], points[3]);
            e.DrawCurve(new Pen(Color.Red, 3f), points);
        }

        private void DrawAxis(Graphics e)
        {
            Pen p = new Pen(Brushes.Black, 2f);
            e.DrawLine(p, 0, 185, 800, 185);
            e.DrawLine(p, 400, 0, 400, 370);

            for (int i = 0; i <= 800; i += 10)
                e.DrawLine(p, i, 180, i, 190);

            for (int i = 0; i <= 370; i += 10)
                e.DrawLine(p, 395, i, 405, i);
        }

        private void Reset(object sender, MouseEventArgs e)
        {
            cnt = 0;
            listBox1.Items.Clear();
            p1.Invalidate();
        }
    }
}
