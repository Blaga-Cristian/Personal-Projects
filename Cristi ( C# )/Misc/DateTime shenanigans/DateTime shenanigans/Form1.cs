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

namespace DateTime_shenanigans
{
    public partial class Form1 : Form
    {
        DSTableAdapters.ImaginiTableAdapter ita = new DSTableAdapters.ImaginiTableAdapter();

        public Form1()
        {
            InitializeComponent();

            DateTime date = DateTime.Now;
            DateTime greaterDate = date.AddDays(1);
            TimeSpan ts = greaterDate - date;
            lbl.Text = ts.TotalMinutes.ToString();
            lbl.Text = ts.ToString("G");

            Image img = Image.FromFile($@"E:\Cristi ( C# )\Subiect 2022 - N (redo)\OTI_2022_C#_resurse\Background\Back4.jpg");
            ImageConverter ic = new ImageConverter();
            ita.Insert((byte[])ic.ConvertTo(img, typeof(byte[])));

            pictureBox1.Image = Image.FromStream(new MemoryStream((byte[])ita.GetData().Rows[0]["Imagine"]));

        }
    }
}
