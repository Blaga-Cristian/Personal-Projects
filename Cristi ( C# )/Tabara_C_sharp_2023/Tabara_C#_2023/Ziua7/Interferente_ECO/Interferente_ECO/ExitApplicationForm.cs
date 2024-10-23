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
    public partial class ExitApplicationForm : Form
    {
        private Timer timer = null;
        
        public ExitApplicationForm()
        {
            InitializeComponent();
            lblExit.BackColor = Color.Transparent;
            timer = new Timer();
            timer.Tick += TimerTick;
            timer.Interval = 2500;
            timer.Enabled = true; // sau timer.Start();
        }

        private void TimerTick(object sender, EventArgs e)
        {
            timer.Enabled = false; // timer.Stop();
            Application.Exit();

        }
    }
}
