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

namespace PathGRadientBrushHarta
{
    public partial class Form1 : Form
    {
       
        private List<PointF> points = new List<PointF>();
        private PointF[] pcts = null;
        public Form1()
        {
            InitializeComponent();
            ReadPoints();
            pcts = points.ToArray();
        }
        private void ReadPoints()
        {
            StreamReader sr = new StreamReader("RomaniaMare.txt");
            string line = null;
            char[] sep = { '*' };
            while ((line = sr.ReadLine()) != null)
            {
                string[] s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);

                int X = int.Parse(s[0]);
                int Y = int.Parse(s[1]);
                points.Add(new PointF(X, Y));
            }

            sr.Close();
            sr.Dispose();

        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.SmoothingMode= SmoothingMode.AntiAlias;  
            PathGradientBrush brush = new PathGradientBrush(pcts);

            Color[] colors = { Color.Red, Color.Yellow, Color.Blue };
            // rosu        galben la 40% din  Albastru la punctul central.
            // la margine  distanta la centru 
            float[] positions = { 0f, 0.5f, 1.0f };

            ColorBlend colorBlend = new ColorBlend();
            colorBlend.Colors = colors;
            colorBlend.Positions = positions;
            brush.InterpolationColors = colorBlend;

            // ce e in afara punctelor nu se va desena
            e.Graphics.DrawClosedCurve(new Pen(Color.YellowGreen, 5f), pcts, 0.4f, FillMode.Alternate);
            e.Graphics.FillRectangle(brush, 0, 0, 900, 800);
            
        }
    }
}
