﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Elevi_table_adapter
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'scoalaDataSet.Elevi' table. You can move, or remove it, as needed.
            this.eleviTableAdapter.Fill(this.scoalaDataSet.Elevi);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //eleviTableAdapter.
        }
    }
}
