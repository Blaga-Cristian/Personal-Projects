using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Interferente_ECO
{
    public partial class Selecteaza_directia : Form
    {
        public int Dir { get; set; }
        public Selecteaza_directia()
        {
            InitializeComponent();
        }

        private void btnLeft_MouseClick(object sender, MouseEventArgs e)
        {
            Button btn = (Button)sender;
            if (btn.Text == "Up")
                Dir = 0;
            else if (btn.Text == "Right")
                Dir = 1;
            else if (btn.Text == "Down")
                Dir = 2;
            else if (btn.Text == "Left")
                Dir = 3;

            this.Close();
        }
    }
}
