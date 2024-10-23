using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CelMaiMareDivComun
{
    public partial class GcdForm : Form
    {
        public GcdForm()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int a = int.Parse(txtFirst.Text);
            int b = int.Parse(txtSecond.Text);
            int gcd = Gcd(a, b);
            txtGcd.Text = Convert.ToString(gcd);  
        }

        private int Gcd(int a, int b)
        {
            if (b == 0) return a;
            return Gcd(b, a % b);
        }
    }
}
