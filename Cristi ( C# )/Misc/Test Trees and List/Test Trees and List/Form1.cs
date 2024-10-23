using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Test_Trees_and_List
{
    public partial class Form1 : Form
    {
        float magnitude1 = 1, magnitude2 = 0.5f;
        Point ulcorner = new Point(200, 100);
        int r = 100;
        public Form1()
        {
            InitializeComponent();

            tv.ImageList = new ImageList();
            tv.ImageList.Images.Add(Image.FromFile($@"E:\Cristi ( C# )\Misc\61dX7gfWDwL.jpg"));
            tv.ImageList.Images.Add(Image.FromFile($@"E:\Cristi ( C# )\Misc\184-1842460_flappy-bird-bird-png-transparent-png.png"));
            tv.ImageList.Images.Add(Image.FromFile($@"E:\Cristi ( C# )\Misc\184-1842460_flappy-bird-bird-png-transparent-png.png"));
            tv.ImageList.Images.Add(Image.FromFile($@"E:\Cristi ( C# )\Misc\184-1842460_flappy-bird-bird-png-transparent-png.png"));
            tv.ImageList.Images.Add(Image.FromFile($@"E:\Cristi ( C# )\Misc\61dX7gfWDwL.jpg"));
            tv.ImageList.Images.Add(Image.FromFile($@"E:\Cristi ( C# )\Misc\61dX7gfWDwL.jpg"));
            //tv.ImageList.Images.Clear();
            tv.Nodes.Add("Father");
            tv.Nodes[0].Nodes.Add("Son", "theText", 1, 1);

            tv.BeginUpdate();
            tv.Nodes.Add("daddy");

            tv.EndUpdate();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            int nrPoints = 2 * r;

            Pen[] pens = new Pen[] {Pens.Beige, Pens.Blue,  Pens.Red, Pens.Azure, Pens.Bisque,
                Pens.Black };

            for(int i = 0; i < nrPoints; i += 10)
            {
                float angle = (float)(i * 2 * Math.PI / nrPoints);

                PointF center = new PointF(ulcorner.X + r, ulcorner.Y + r);
                PointF p1 = new PointF((float)(ulcorner.X + r * (1 + magnitude1 * Math.Cos(angle))), (float)(ulcorner.Y + r * (1 + magnitude1 * Math.Sin(angle))));
                PointF p2 = new PointF((float)(ulcorner.X + r * (1 + magnitude2 * Math.Cos(angle + Math.PI / 2))), (float)(ulcorner.Y + r * (1 + magnitude2 * Math.Sin(angle + Math.PI / 2))));
                PointF pUp = new PointF((float)(p1.X + p2.X - ulcorner.X - r), (float)(p1.Y + p2.Y - ulcorner.Y - r));

                e.Graphics.DrawPolygon(Pens.Black, new PointF[] { center, p1, pUp, p2 });

            }
        }

    }
}
