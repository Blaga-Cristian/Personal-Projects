using AplicatieBiblioteca.BibliotecaDBTableAdapters;
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
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Window;

namespace AplicatieBiblioteca
{
    public partial class PrevizualizareCarte : Form
    {
        UtilizatoriTableAdapter utilizatoriTableAdapter = new UtilizatoriTableAdapter();
        RezervariTableAdapter rezervariTableAdapter = new RezervariTableAdapter();
        Imprumuturi1TableAdapter imprumuturiTableAdapter = new Imprumuturi1TableAdapter();
        CartiTableAdapter cartiTableAdapter = new CartiTableAdapter();

        string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\ONTI_C#_2019_resurse\";




        bool zoom = false;
        double ration = 0.60;
        double ratioz = 1.00;
        Image img;
        Bitmap bmps;
        int w = 190, h = 190;
        int idCarte;
        public PrevizualizareCarte(int idCarte)
        {
            this.idCarte = idCarte;
            img = Image.FromFile(respath + $@"Imagini\carti\" + $@"{idCarte}.jpg");
            bmps = new Bitmap(img, new Size(200, 200));
            InitializeComponent();
            pbZoom.Image = img;
            SetData();
        }

        private void Draw(int nr,int x,int y, int l, int ximg, int yimg, int limg)
        {
            var g = splitContainer1.Panel2.CreateGraphics();
            g.DrawImage(bmps, new Rectangle(x, y, l, l), new Rectangle(ximg, yimg, limg, limg), GraphicsUnit.Pixel);
            g.Dispose();

            if (nr > 0)
            {
                Draw(nr - 1, x - l / 4, y - l / 4, l / 2, ximg, yimg, limg / 2);
                Draw(nr - 1, x + l - l / 4, y - l / 4, l / 2, ximg + limg / 2, yimg, limg / 2);
                Draw(nr - 1, x + l - l / 4, y + l - l / 4, l / 2, ximg + limg / 2, yimg + limg / 2, limg / 2);
                Draw(nr - 1, x - l / 4, y + l - l / 4,l / 2, ximg, yimg + limg / 2, limg / 2);
            }            
        }

        private void SetData()
        {
            var dt = cartiTableAdapter.GetCarte(idCarte);
            txtTitlu.Text = (string)dt.Rows[0]["Titlu"];
            txtAutor.Text = (string)dt.Rows[0]["Autor"];
            txtNrPag.Text = ((int)dt.Rows[0]["Nrpag"]).ToString();
        }

        private void splitContainer1_Panel2_Paint(object sender, PaintEventArgs e)
        {
            Draw(2, 140, 90, 200, 0, 0, 200);
        }

        private void tb_Scroll(object sender, EventArgs e)
        {
            pbZoom.ClientSize = new Size(w + w * tb.Value / 100, h + h * tb.Value / 100);
        }
    }
}
