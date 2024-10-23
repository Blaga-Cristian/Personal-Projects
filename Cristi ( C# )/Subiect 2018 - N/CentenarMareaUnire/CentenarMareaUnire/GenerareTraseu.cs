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

namespace CentenarMareaUnire
{
    public partial class GenerareTraseu : Form
    {
        string conStr = $@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\CentenarDB.mdf;Integrated Security=True";
        string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\Resurse_C#\";
        List<Point> harta = new List<Point>();
        List<List<Point>> capitaleoutline = new List<List<Point>>();
        List<Point> capitale = new List<Point>();
        List<string> numeCapitale = new List<string>();
        bool[] viz;
        Timer tmr = new Timer();
        int cur;
        int next;
        List<KeyValuePair<Point, Point>> lines = new List<KeyValuePair<Point, Point>>();
        int cnt;
        bool looped = false;

        public GenerareTraseu()
        {
            InitializeComponent();
            this.SetStyle(ControlStyles.UserPaint | ControlStyles.OptimizedDoubleBuffer | ControlStyles.AllPaintingInWmPaint, true);
            IncarcaHarta();
        }

        private void IncarcaHarta()
        {
            List<KeyValuePair<string, int>> lst = new List<KeyValuePair<string, int>>();
            var sr = new StreamReader(respath + $@"Harti\" + "RomaniaMare.txt");
            string line;
            string[] s;
            char[] sep = { '*' };

            while ((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                int x = int.Parse(s[0]);
                int y = int.Parse(s[1]);
                harta.Add(new Point(x, y));
            }

            Pen p = new Pen(Color.White, 3f);
            string[] files = Directory.GetFiles(respath + $@"Harti\");
            for (int i = 0; i < files.Length; ++i)
            {
                string str = files[i];
                string aux = str.Split('\\').Last();
                if (aux == "RomaniaMare.txt") continue;

                int x, y;
                sr = new StreamReader(str);
                line = sr.ReadLine();
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                x = int.Parse(s[0]);
                y = int.Parse(s[1]);
                string numeCapitala = s[2];
                Pen pen = new Pen(Color.Black, 2f);
                lst.Add(new KeyValuePair<string, int>(numeCapitala, capitale.Count));
                capitale.Add(new Point(x, y));
                numeCapitale.Add(numeCapitala);

                List<Point> puncte = new List<Point>();

                while ((line = sr.ReadLine()) != null)
                {
                    s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                    x = int.Parse(s[0]);
                    y = int.Parse(s[1]);
                    puncte.Add(new Point(x, y));
                }

                capitaleoutline.Add(puncte.ToList());
            }

            viz = new bool[capitale.Count + 5];
            cmb.DataSource = lst;
            cmb.DisplayMember = "Key";
            cmb.ValueMember = "Value";
        }

        private void bntGen_Click(object sender, EventArgs e)
        {
            pb.Invalidate();

            viz = new bool[capitale.Count + 5];
            looped = false;
            cnt = 0;
            tmr.Stop();
            tmr.Tick -= MapEvent;
            tmr.Tick -= SmallMove;


            cur = (int)cmb.SelectedValue;
            next = cur;
            viz[cur] = true;
            double dist2 = double.MaxValue;
            next = -1;
            for (int i = 0; i < capitale.Count; ++i)
            {
                if (viz[i] || i == cur) continue;
                if (dist2 > Dist(capitale[i], capitale[cur]))
                {
                    dist2 = Dist(capitale[i], capitale[cur]);
                    next = i;
                }
            }


            tmr.Interval = 200;
            tmr.Tick += MapEvent;
            tmr.Tick += SmallMove;
            tmr.Start();
        }

        private void SmallMove(object sender, EventArgs e)
        {
            if (next == -1) return;
            if (cnt >= 10) return;
            cnt++;

            Point p = new Point(
                capitale[cur].X + (capitale[next].X - capitale[cur].X) * cnt / 10,
                capitale[cur].Y + (capitale[next].Y - capitale[cur].Y) * cnt / 10);

            Graphics g = pb.CreateGraphics();
            Pen pen = new Pen(Color.Green, 3f);
            g.DrawLine(pen, capitale[cur], p);

            g.Dispose();
            pen.Dispose();
        }

        private void MapEvent(object sender, EventArgs e)
        {
            if (cnt != 10) return;
            cnt = 0;

            viz[next] = true;
            cur = next;

            double dist2 = double.MaxValue;
            next = -1;
            for(int i = 0; i < capitale.Count; ++i)
            {
                if (viz[i] == true || i == cur) continue;
                if(dist2 > Dist(capitale[i], capitale[cur]))
                {
                    dist2 = Dist(capitale[i], capitale[cur]);
                    next = i;
                }
            }

            if (next == -1 && !looped)
            {
                looped = true;
                next = (int)cmb.SelectedValue;
            }
            else if(next == -1)
                ((Timer)sender).Stop();
        }


        private double Dist(Point p1, Point p2)
        {
            return Math.Sqrt((p1.X - p2.X) * (p1.X - p2.X) + (p1.Y - p2.Y) * (p1.Y - p2.Y));
        }

        private void pb_Paint(object sender, PaintEventArgs e)
        {
            var pgb = new PathGradientBrush(harta.ToArray());
            var cb = new ColorBlend();
            cb.Colors = new Color[] { Color.Red, Color.Yellow, Color.Blue };
            cb.Positions = new float[]{ 0f, 0.3f, 1f};
            pgb.InterpolationColors = cb;
            e.Graphics.FillRectangle(pgb, new Rectangle(0, 0, 900, 900));

            Pen pen = new Pen(Color.White, 3f);
            foreach (var x in capitaleoutline)
                e.Graphics.DrawClosedCurve(pen, x.ToArray());

            pen = new Pen(Color.Black, 3f);
            for(int i = 0; i < capitale.Count; ++i)
            {
                e.Graphics.DrawEllipse(pen, new Rectangle(
                    capitale[i].X - 5 , capitale[i].Y - 5, 10, 10));
                e.Graphics.DrawString(numeCapitale[i], new Font(FontFamily.GenericSansSerif, 10f), Brushes.Black,
                    capitale[i].X + 5, capitale[i].Y - 8);
            }
        }
    }
}
