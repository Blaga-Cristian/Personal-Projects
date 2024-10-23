using CentenarMareaUnire.CentenarDBSTableAdapters;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CentenarMareaUnire
{
    public partial class CreareLectie : Form
    {
        string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\Resurse_C#\";

        Control ctrl;
        int w = 550, h = 350;
        LectiiTableAdapter ltb = new LectiiTableAdapter();

        public CreareLectie()
        {
            InitializeComponent();
        }

        private void btnRN_Click(object sender, EventArgs e)
        {
            tlp.RowCount++;
        }


        private void btnSR_Click(object sender, EventArgs e)
        {
            if (tlp.RowCount == 1) return;
            List<Control> remove = new List<Control>();
            foreach (Control x in tlp.Controls)
                if (tlp.GetPositionFromControl(x).Row == tlp.RowCount - 1)
                    remove.Add(x);
            foreach (var x in remove)
                tlp.Controls.Remove(x);

            tlp.RowCount--;
        }

        private void btnCN_Click(object sender, EventArgs e)
        {
            tlp.ColumnCount++;
        }

        private void btnSC_Click(object sender, EventArgs e)
        {
            if (tlp.ColumnCount == 1) return;
            List<Control> remove = new List<Control>();
            foreach (Control x in tlp.Controls)
                if (tlp.GetPositionFromControl(x).Column == tlp.ColumnCount - 1)
                    remove.Add(x);
            foreach (var x in remove)
                tlp.Controls.Remove(x);

            tlp.ColumnCount--;
        }

        private void btnSControl_Click(object sender, EventArgs e)
        {
            if(ctrl == null) return;
            tlp.Controls.Remove(ctrl);
            ctrl = null;
        }

        private void btnCI_Click(object sender, EventArgs e)
        {
            tlp.Height += 10;
        }

        private void btnSI_Click(object sender, EventArgs e)
        {
            tlp.Height -= 10;
        }

        private void btnCL_Click(object sender, EventArgs e)
        {
            tlp.Width += 10;
        }

        private void btnSL_Click(object sender, EventArgs e)
        {
            tlp.Height -= 10;
        }

        private void btnText_Click(object sender, EventArgs e)
        {
            if (tlp.Controls.Count >= tlp.RowCount * tlp.ColumnCount) return;
            var rtb = new RichTextBox();
            rtb.Dock = DockStyle.Fill;
            rtb.MouseClick += SelectControl;
            var free = GetFree();
            tlp.Controls.Add(rtb, free.Value, free.Key);
        }

        private void btnPoza_Click(object sender, EventArgs e)
        {
            if (tlp.Controls.Count >= tlp.RowCount * tlp.ColumnCount) return;
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = "Fisiere imagine (*.bmp;*.jpg) | *.bmp; *.jpg";
            if(ofd.ShowDialog() == DialogResult.OK)
            {
                PictureBox pb = new PictureBox();
                pb.Image = Image.FromFile(ofd.FileName);
                pb.SizeMode = PictureBoxSizeMode.StretchImage;
                pb.Dock = DockStyle.Fill;
                pb.MouseClick += SelectControl;
                KeyValuePair<int, int> free = GetFree();
                tlp.Controls.Add(pb, free.Value, free.Key);
            }
        }

        private void SelectControl(object sender, MouseEventArgs e)
        {
            ctrl = (Control)sender;
        }

        private void btnSalveaza_Click(object sender, EventArgs e)
        {
            var bmp = new Bitmap(tlp.Width, tlp.Height);
            var g = Graphics.FromImage(bmp);
            tlp.DrawToBitmap(bmp, new Rectangle(0, 0, tlp.Width, tlp.Height));
            string titlu = txtTitlu.Text;
            string regiune = txtRegiune.Text;
            DateTime dataCreare = DateTime.Now;
            string numeImagine = titlu;
            bmp.Save(respath + $@"ContinutLectii\" + numeImagine + ".bmp", ImageFormat.Bmp);
            ltb.InsertLectie(0, titlu, regiune, dataCreare, numeImagine);
        }

        private KeyValuePair<int, int> GetFree()
        {
            for (int i = 0; i < tlp.RowCount; i++)
                for (int j = 0; j < tlp.ColumnCount; j++)
                    if (tlp.GetControlFromPosition(j, i) == null)
                        return new KeyValuePair<int, int>(i, j);
            return new KeyValuePair<int, int>(-1, -1);
        }
    }
}
