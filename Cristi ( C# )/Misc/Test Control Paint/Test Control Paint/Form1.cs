using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Test_Control_Paint
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Point p = PointToScreen(new Point(50, 50));
            ControlPaint.DrawReversibleFrame(new Rectangle(p.X, p.Y, 100, 100), Color.Black, FrameStyle.Dashed);
        }
    }
}
