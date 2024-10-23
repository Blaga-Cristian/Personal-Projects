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

namespace Aplicatie_Biblioteca
{
    public partial class PrevizualizareCarte : Form
    {
        DSBibliotecaTableAdapters.CartiTableAdapter cta = new DSBibliotecaTableAdapters.CartiTableAdapter();
        DSBibliotecaTableAdapters.ImprumuturiTableAdapter ita = new DSBibliotecaTableAdapters.ImprumuturiTableAdapter();
        DSBibliotecaTableAdapters.RezervariTableAdapter rta = new DSBibliotecaTableAdapters.RezervariTableAdapter();
        DSBibliotecaTableAdapters.UtilizatoriTableAdapter uta = new DSBibliotecaTableAdapters.UtilizatoriTableAdapter();
        string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\ONTI_C#_2019_resurse\";

        int idCarte;
        DataRow carte;
        int w, h;
        Bitmap bmp;

        public PrevizualizareCarte(int idCarte)
        {
            InitializeComponent();
            this.idCarte = idCarte;
            IncarcaData();
        }

        private void tbZoom_Scroll(object sender, EventArgs e)
        {
            pb.ClientSize = new Size(w + w * tbZoom.Value / tbZoom.Maximum, h + h * tbZoom.Value / tbZoom.Maximum);
        }

        private void PrevizualizareCarte_Paint(object sender, PaintEventArgs e)
        {
            bmp = new Bitmap(pb.Image, new Size(200, 200));
            DrawRecursiv(2, 500, 100, 200, 0, 0, 200, e.Graphics);
        }

        private void DrawRecursiv(int n, int x, int y, int l, int ximg, int yimg, int limg, Graphics g)
        {
            if(n > 0)
            {
                DrawRecursiv(n - 1, x - l / 4, y - l / 4, l / 2, ximg, yimg, limg / 2, g);
                DrawRecursiv(n - 1, x + l - l / 4, y - l / 4, l / 2, ximg + limg / 2, yimg, limg / 2, g);
                DrawRecursiv(n - 1, x + l - l / 4, y + l - l / 4, l / 2, ximg + limg / 2, yimg + limg / 2, limg / 2, g);
                DrawRecursiv(n - 1, x - l / 4, y + l - l / 4, l / 2, ximg, yimg + limg / 2, limg / 2, g);
            }

            g.DrawImage(bmp, new Rectangle(x, y, l, l), new Rectangle(ximg, yimg, limg, limg), GraphicsUnit.Pixel);
        }

        private void IncarcaData()
        {
            carte = cta.GetById(idCarte).Rows[0];
            txtAutor.Text = (string)carte["Autor"];
            txtTitlu.Text = (string)carte["Titlu"];
            txtNrPag.Text = "" + (int)carte["NrPag"];
            pb.Image = Image.FromFile(respath + $@"Imagini\carti\{idCarte}.jpg");
            w = pb.Width;
            h = pb.Height;
        }
    }
}
