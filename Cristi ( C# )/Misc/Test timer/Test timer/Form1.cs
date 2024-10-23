using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Test_timer
{
    public partial class Form1 : Form
    {

        public Form1()
        {
            InitializeComponent();
            Timer tmr = new Timer();
            Timer timer = new Timer();
            timer.Tick += delegate
            {
                rtb.Text += timer.Tag.ToString();
            };
            tmr.Tag = 'A';
            tmr.Interval = 2000;
            tmr.Tick += delegate
            {
                timer.Interval = 1000;
                timer.Tag = Convert.ToChar((char)tmr.Tag + 1);
                timer.Start();

                rtb.Text += tmr.Tag.ToString();
            };
            tmr.Start();
        }
    }
}
