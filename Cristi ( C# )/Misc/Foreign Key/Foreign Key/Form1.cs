using Foreign_Key.ScoalaDSTableAdapters;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Foreign_Key
{
    public partial class Form1 : Form
    {
        ImageTableAdapter itd = new ImageTableAdapter();
        public Form1()
        {
            InitializeComponent();
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            var ofd = new OpenFileDialog();
            ofd.Filter = "Fisiere imagine (*.jpg)|*.jpg";
            if(ofd.ShowDialog() == DialogResult.OK)
            {
                var img = Image.FromFile(ofd.FileName);
                var arr = (byte[])(new ImageConverter().ConvertTo(img, typeof(byte[])));
                itd.InsertImagine(arr);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            DataTable dt = itd.GetData();
            var img = Image.FromStream(new MemoryStream((byte[])dt.Rows[0]["Imagine"]));
            pb.Image = img;
        }

        private void btnCreaza_Click(object sender, EventArgs e)
        {
            string nume = txtNume.Text;
            Directory.CreateDirectory(nume);

            MessageBox.Show("Ai creat un folder");
        }

        private void btnSterge_Click(object sender, EventArgs e)
        {
            string nume = txtSterge.Text;
            if(Directory.Exists(nume))
                Directory.Delete(nume);
        }

        private void btnStergeFisier_Click(object sender, EventArgs e)
        {
            string nume = txtFisier.Text;
            try { File.Delete(nume); }
            catch { }
        }

        private void btnCopy_Click(object sender, EventArgs e)
        {
            string nume = txtFisierCopiaza.Text;
            string dest = Directory.GetCurrentDirectory() + $@"\123\{nume}";

            string[] files = Directory.GetFiles(Directory.GetCurrentDirectory());

            try { File.Copy(nume, dest); } catch { }
        }

        private void btnCheck_Click(object sender, EventArgs e)
        {
            string exp = txtExp.Text;
            Regex regex = new Regex($@".*@.*\..*");
            if (regex.IsMatch(exp))
                MessageBox.Show("este match");
        }
    }
}
