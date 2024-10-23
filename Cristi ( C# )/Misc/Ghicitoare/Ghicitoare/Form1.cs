using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Ghicitoare
{
    public partial class Form1 : Form
    {
        int nr;
        Random rand = new Random();
        Point[] points = new Point[]
        {
            new Point(100, 40),
            new Point(130, 40),
            new Point(160, 40),
            new Point(100, 70),
            new Point(130, 70),
            new Point(160, 70)
        };
        Graphics e;
        public Form1()
        {
            InitializeComponent();
            Reset();
        }                
        private void Reset()
        {
            var graphics = this.CreateGraphics();
            nr = rand.Next(100);
            txt.Text = string.Empty;
            btnTry.Enabled = false;
            graphics.DrawString("?", new Font(FontFamily.GenericSansSerif, 20f, FontStyle.Bold), Brushes.Black, 100, 40);
        }

        private void btnTry_Click(object sender, EventArgs e)
        {
            try
            {
                int x = int.Parse(txt.Text);
                var graphics = this.CreateGraphics();
                if (x == nr)
                {
                    MessageBox.Show("Ai castigat");
                    Reset();
                    return;
                }
                else if (x > nr)
                    graphics.FillPolygon(Brushes.Green, new Point[] { points[0], points[2], points[4] });
                else
                    graphics.FillPolygon(Brushes.Red, new Point[] { points[3], points[1], points[5] });
            }
            catch
            {
                MessageBox.Show("Format incorect");
            }
        }

        private void txt_TextChanged(object sender, EventArgs e)
        {
            if (txt.Text.Length > 0)
                btnTry.Enabled = true;
            else
                btnTry.Enabled = false;
            this.Invalidate();
        }
    }
}
