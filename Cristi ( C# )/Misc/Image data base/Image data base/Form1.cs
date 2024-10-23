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

namespace Image_data_base
{
    public partial class Form1 : Form
    {
        ImaginiDSTableAdapters.ImaginiTableAdapter ita = new ImaginiDSTableAdapters.ImaginiTableAdapter();
        public Form1()
        {
            InitializeComponent();
        }


        private void btnAdd_Click(object sender, EventArgs e)
        {
            var ofd = new OpenFileDialog();
            ofd.Filter = "Fisiere imagine(*.jpg, *.bmp, *.jpeg)|*.jpg;*.bmp;*.jpeg";
            if (ofd.ShowDialog() != DialogResult.OK) return;

            byte[] bytes = File.ReadAllBytes(ofd.FileName);

            ita.Insert(bytes);

            txtId.Text = "" + (ita.GetData().Rows.Count);

            this.imaginiTableAdapter.Fill(this.imaginiDataSet.Imagini);

            ((DataGridViewImageColumn)dgw.Columns[dgw.Columns.Count - 1]).AutoSizeMode = DataGridViewAutoSizeColumnMode.Fill;
        }

        private void btnSet_Click(object sender, EventArgs e)
        {
            int id = int.Parse(txtId.Text);
            DataTable dt = ita.GetData();
            foreach (DataRow row in dt.Rows)
                if ((int)row["Id"] == id)
                    pb.Image = Image.FromStream(new MemoryStream((byte[])row["Imagine"]));
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'imaginiDataSet.Imagini' table. You can move, or remove it, as needed.
            this.imaginiTableAdapter.Fill(this.imaginiDataSet.Imagini);

        }
    }
}
