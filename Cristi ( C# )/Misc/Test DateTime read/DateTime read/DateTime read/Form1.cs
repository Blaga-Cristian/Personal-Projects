using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DateTime_read
{
    public partial class Form1 : Form
    {
        DateDSTableAdapters.DateTableAdapter dta = new DateDSTableAdapters.DateTableAdapter();
        string path = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\Date.txt";
        public Form1()
        {
            InitializeComponent();
            IncarcaDate();
            DataGridView.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            DataGridView.AllowUserToAddRows = false;
            DataGridView.DataSource = dta.GetData();
        }

        private void IncarcaDate()
        {
            var sr = new StreamReader(path);
            string line;

            sr.ReadLine();

            while((line = sr.ReadLine()) != null)
            {
                DateTime dt = DateTime.ParseExact(line, "M/d/yyyy h:mm tt", System.Globalization.CultureInfo.InvariantCulture);
                dta.Insert(dt);
            }
        }
    }
}
