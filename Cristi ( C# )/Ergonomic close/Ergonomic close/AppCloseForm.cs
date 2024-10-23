using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Ergonomic_close
{
    public partial class AppCloseForm : Form
    {
        private Timer timer = new Timer();

        public AppCloseForm()
        {
            InitializeComponent();
            timer.Interval = 3000;
            timer.Start();
            timer.Tick += HandleTimerTick;
        }

        private void HandleTimerTick(object sender, EventArgs e)
        {
            timer.Stop();
            this.Close();
        }
    }
}
