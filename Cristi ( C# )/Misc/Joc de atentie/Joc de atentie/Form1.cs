using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Joc_de_atentie
{
    public partial class Form1 : Form
    {
        List<int> numere = new List<int>();
        List<int> sortednumere = new List<int>();
        Random rand = new Random();
        int step = 0;
        public Form1()
        {
            InitializeComponent();
            btnReset_Click(null, null);
        }

        private void btnReset_Click(object sender, MouseEventArgs e)
        {
            numere.Clear();
            sortednumere.Clear();
            step = 0;


            for (int i = 0; i < 9; ++i)
            {
                int x = rand.Next(100);
                numere.Add(x);
            }

            int idx = 9;
            while(idx > 1)
            {
                int k = rand.Next(idx--);
                int tmp = numere[k];
                numere[k] = numere[idx];
                numere[idx] = tmp;
            }

            for (int i = 0; i < 9; ++i)
                sortednumere.Add(numere[i]);

            sortednumere.Sort();

            foreach(Button x in this.Controls.OfType<Button>())
                if(x.Tag == "Play")
                {
                    x.Enabled = true;
                    x.BackColor = default(Color);
                }

            btn1.Text = numere[0].ToString();
            btn2.Text = numere[1].ToString();
            btn3.Text = numere[2].ToString();
            btn4.Text = numere[3].ToString();
            btn5.Text = numere[4].ToString();
            btn6.Text = numere[5].ToString();
            btn7.Text = numere[6].ToString();
            btn8.Text = numere[7].ToString();
            btn9.Text = numere[8].ToString();
        }
        private void button_Click(object sender, MouseEventArgs e)
        {
            var btn = (Button)sender;
            if(int.Parse(btn.Text) == sortednumere[step])
            {
                step++;
                btn.Enabled = false;
                btn.BackColor = Color.Green;
            }
            else
            {
                MessageBox.Show("Ai ratat! Nu ai fost suficient de atent");
                btnReset_Click(null, null);
            }

            if(step ==  sortednumere.Count)
            {
                MessageBox.Show("Ai castigat");
                btnReset_Click(null, null);
            }
        }
    }
}
