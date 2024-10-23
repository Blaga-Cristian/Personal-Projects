﻿using System;
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
    public partial class SelectDirection : Form
    {
        public int Dir { get; set; }
        public SelectDirection()
        {
            InitializeComponent();
        }

        private void btnLeft_Click(object sender, EventArgs e)
        {
            Dir = 3;
            this.Close();
        }

        private void btnDown_Click(object sender, EventArgs e)
        {
            Dir = 2;
            this.Close();
        }

        private void btnRight_Click(object sender, EventArgs e)
        {
            Dir = 1;
            this.Close();
        }

        private void btnUp_Click(object sender, EventArgs e)
        {
            Dir = 0;
            this.Close();
        }
    }
}