using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
//using System.Threading.Tasks;
using System.Windows.Forms;

namespace PM
{
    public partial class VizualizareForm : Form
    {
        private Timer timer = new Timer();
        public VizualizareForm()
        {
            InitializeComponent();
            timer.Interval = 10;
            timer.Tick += HandleTick;
        }

        float X = 0;
        float Y = 0;
        int cnt = 0;
        private void HandleTick(object sender, EventArgs e)
        {
            if (draw)
            {
                X += dx;
                Y += dy;


                cnt++;
                if (cnt == 30)
                {                    //timer.Enabled = false;
                    timer.Stop();
                    draw = false;
                    done = true;
                    cnt = 0;
                }
                pbDraw.Invalidate();
            }
        }

        int x1 = 100, y1 = 350, r = 20, x2 = 500, y2 = 90;
        double alpha;
        float dx, dy;
        double x0;
        double y0;
        bool draw = false;
        private void btnDraw_Click(object sender, EventArgs e)
        {
            alpha = Math.Atan2((double)(y2 - y1), (double)(x2 - x1));
            x0 = r * Math.Cos(alpha);
            y0 = r * Math.Sin(alpha);
            float DX = (float)(x2 - x0) - (float)(x1 + x0);
            float DY = (float)(y2 - y0) - (float)(y1 + y0);
            dx = DX / 30;
            dy = DY / 30;

            X = (float)x1 + (float)x0;
            Y = (float)y1 + (float)y0;
            draw = true;
           
            timer.Start();
        }

        bool done = false;
        private void pbDraw_Paint(object sender, PaintEventArgs e)
        {
            
            e.Graphics.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;
            e.Graphics.DrawEllipse(new Pen(Color.Red, 2F),
                x1 - r, y1 - r, 2 * r, 2 * r);

            e.Graphics.DrawEllipse(new Pen(Color.Red, 2F),
                x2 - r, y2 - r, 2 * r, 2 * r);

           
           if (draw)
                e.Graphics.DrawLine(new Pen(Color.Red, 2F), (float)(x1 + x0), 
                (float)(y1 + y0), X, Y);
           if (done)
                e.Graphics.DrawLine(new Pen(Color.Red, 2F), (float)(x1 + x0),
              (float)(y1 + y0), (float)(x2 - x0), (float)(y2 - y0));
        }
    }
}
