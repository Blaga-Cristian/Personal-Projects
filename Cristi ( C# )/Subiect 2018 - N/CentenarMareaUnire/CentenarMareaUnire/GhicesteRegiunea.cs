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
    public partial class GhicesteRegiunea : Form
    {
        string conStr = $@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\CentenarDB.mdf;Integrated Security=True";
        string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\Resurse_C#\";
        List<Point> harta = new List<Point>();
        List<TextBox> capitale = new List<TextBox>();
        bool[] afisat;
        Random rand = new Random();
        int cnt, cntcapitale, nota;
        TextBox cur;
        public GhicesteRegiunea()
        {
            InitializeComponent();
        }

        private void IncarcaHarta()
        {
            var sr = new StreamReader(respath + $@"Harti\" + "RomaniaMare.txt");
            string line;
            string[] s;
            char[] sep = { '*' };

            while((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                int x = int.Parse(s[0]);
                int y = int.Parse(s[1]);
                harta.Add(new Point(x, y));
            }

            var pgb = new PathGradientBrush(harta.ToArray());
            ColorBlend cb = new ColorBlend();
            cb.Colors = new Color[]{ Color.Red, Color.Yellow, Color.Blue};
            cb.Positions = new float[] { 0f, 0.3f, 1f };
            pgb.InterpolationColors = cb;
            var e = pb.CreateGraphics();
            e.FillRectangle(pgb, new Rectangle(0, 0, 900, 900));

            Pen p = new Pen(Color.White, 3f);
            string[] files = Directory.GetFiles(respath + $@"Harti\");
            for(int i = 0; i < files.Length; ++i)
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
                string tag = s[2];
                TextBox txt = new TextBox();
                txt.Location = new Point(x, y);
                txt.Tag = tag;
                txt.Size = new Size(100, 100);
                capitale.Add(txt);

                List<Point> puncte = new List<Point>();

                while((line = sr.ReadLine()) != null)
                {
                    s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                    x = int.Parse(s[0]);
                    y = int.Parse(s[1]);
                    puncte.Add(new Point(x, y));
                }

                e.DrawClosedCurve(p, puncte.ToArray());
            }

            afisat = new bool[capitale.Count + 3];
            cnt = 0;
            cntcapitale = capitale.Count;
        }

        private void btnRaspunde_Click(object sender, EventArgs e)
        {
            var txt = cur;
            if (txt.Text == txt.Tag.ToString())
            {
                nota++;
                txtNota.Text = "" + nota;
            }
            else
            {
                TextBox t = new TextBox();
                t.Size = txt.Size;
                t.Text = txt.Text;
                t.Location = new Point(txt.Location.X, txt.Location.Y - 20);
                t.Font = new Font(FontFamily.GenericSansSerif, 8.25f, FontStyle.Strikeout);
                t.ReadOnly = true;
                pb.Controls.Add(t);
                txt.Text = txt.Tag.ToString();
            }
            txt.ReadOnly = true;

            IncarcaTextBox();
        }

        private void pb_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.FillRectangle(Brushes.Black, new Rectangle(0, 0, 900, 900));
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            btnStart.Enabled = false;
            btnGen.Enabled = false;
            txtNota.Text = "" + nota;
            IncarcaHarta();
            IncarcaTextBox();
        }

        private void IncarcaTextBox()
        {
            if (cnt == cntcapitale)
            {
                btnRaspunde.Enabled = false;
                btnGen.Enabled = true;
                return;
            }
            int ind = 0;
            do
            {
                ind = rand.Next() % capitale.Count;
            } while (afisat[ind]);

            pb.Controls.Add(capitale[ind]);
            cur = capitale[ind];
            afisat[ind] = true;
            cnt++;
        }
    }
}
