using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinFormsApp6
{
    public partial class Form2 : Form
    {
        int valoare = 0;
        public Form2()
        {
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox1.Text = valoare.ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            valoare = Int32.Parse(textBox2.Text);
        }

        public int valoarea
        {
            set { valoare = value; }
            get { return valoare; }
        }

    }
}
