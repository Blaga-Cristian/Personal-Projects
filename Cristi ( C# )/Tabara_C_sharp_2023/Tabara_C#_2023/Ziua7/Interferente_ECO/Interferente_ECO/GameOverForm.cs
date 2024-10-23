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
    public partial class GameOverForm : Form
    {
        public bool Restart { get; set; } = false;
        public GameOverForm()
        {
            InitializeComponent();
            lblQuestion.BackColor = Color.Transparent;
            lblStop.BackColor = Color.Transparent;
        }

        private void btnRestart_Click(object sender, EventArgs e)
        {
            Restart = true;
            Close();
        }

        private void btnExitAppp_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
