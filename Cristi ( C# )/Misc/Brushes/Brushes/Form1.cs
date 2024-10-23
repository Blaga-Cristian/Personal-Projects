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

namespace Brushes
{
    public partial class Form1 : Form
    {
        
        public Form1()
        {
            InitializeComponent();
        }

        private void DoHatch()
        {
            HatchBrush hb = new HatchBrush(HatchStyle.Sphere, DefaultForeColor, DefaultBackColor);
            Graphics gr = this.CreateGraphics();
            gr.FillRectangle(hb, ClientRectangle);
        }

        private void DoTexture()
        {
            TextureBrush tb = new TextureBrush(Image.FromFile($@"E:\Cristi ( C# )\Misc\61dX7gfWDwL.jpg"));
            tb.ScaleTransform(0.1f, 0.1f);
            Graphics gr = this.CreateGraphics();
            gr.FillRectangle(tb, ClientRectangle);
        }

        private void DoLinearGradient()
        {
            int cx = ClientRectangle.Width;
            int cy = ClientRectangle.Height;

            LinearGradientBrush lgb = new LinearGradientBrush(
                new Point(cx / 4, cy / 4),
                new Point(cx * 3 / 4, cy * 3 / 4), 
                Color.Red, 
                Color.Blue);

            lgb.WrapMode = WrapMode.TileFlipX;

            Graphics gr = this.CreateGraphics();
            gr.FillRectangle(lgb, ClientRectangle);
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            //DoHatch();
            //DoTexture();
            //DoLinearGradient();
            //DrawStar();
            //DrawBall();
            //DoDashOfStyle();
        }

        private void DoDashOfStyle()
        {
            LinearGradientBrush lgb = new LinearGradientBrush(new Point(0,0), new Point(ClientRectangle.Width, ClientRectangle.Height), Color.Red, Color.Blue);
            Pen pen = new Pen(lgb, 12f);
            pen.DashStyle = DashStyle.Dot;
            pen.DashCap = DashCap.Round;

            Graphics gr = this.CreateGraphics();
            gr.DrawLine(pen, 0, 0, ClientRectangle.Width, ClientRectangle.Height);
        }

        private void DrawBall()
        {
            int cx = ClientRectangle.Width;
            int cy = ClientRectangle.Height;

            GraphicsPath path = new GraphicsPath();
            path.AddEllipse(new Rectangle(0, 0, 100, 100));

            PathGradientBrush pgb = new PathGradientBrush(path);
            pgb.CenterColor = Color.White;
            pgb.SurroundColors = new Color[]{ Color.Black };
            pgb.CenterPoint = new Point(30, 30);

            Graphics gr = this.CreateGraphics();
            gr.FillRectangle(pgb, ClientRectangle);
        }

        private void DrawStar()
        {
            Point[] points = new Point[]
            {
                new Point(323, 72),
                new Point(276, 245),
                new Point(422, 142),
                new Point(232, 157),
                new Point(396, 243)
            };

            Graphics gr = this.CreateGraphics();
            gr.FillPolygon(new SolidBrush(Color.Red), points, FillMode.Winding);
        }

    }
}
