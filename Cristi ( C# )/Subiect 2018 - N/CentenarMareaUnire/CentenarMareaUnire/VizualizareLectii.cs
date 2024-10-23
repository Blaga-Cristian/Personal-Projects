using CentenarMareaUnire.CentenarDBSTableAdapters;
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

namespace CentenarMareaUnire
{
    public partial class VizualizareLectii : Form
    {
        string conStr = $@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\CentenarDB.mdf;Integrated Security=True";
        string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\Resurse_C#\";
        UtilizatoriTableAdapter utilizatoriTableAdapter = new UtilizatoriTableAdapter();
        LectiiTableAdapter lectiiTableAdapter = new LectiiTableAdapter();
        int idUtilizator;

        public VizualizareLectii(int idUtilizator = 1)
        {
            this.idUtilizator = idUtilizator;
            InitializeComponent();
            IncarcaItemi();
        }

        private void IncarcaItemi()
        {
            var dt = lectiiTableAdapter.GetLectii();
            lb.DataSource = dt;
            lb.DisplayMember = "NumeImagine";
            lb.ValueMember = "IdLectie";
        }

        private void btnAfiseaza_Click(object sender, EventArgs e)
        {
            int idLectie = (int)lb.SelectedValue;
            var dt = lectiiTableAdapter.GetLectie(idLectie);
            string numeImagine = (string)dt.Rows[0]["NumeImagine"];
            string regiunea = (string)dt.Rows[0]["Regiune"];
            DateTime dataCreare = (DateTime)dt.Rows[0]["DataCreare"];
            string data = dataCreare.ToString("M/d/yyyy h:mm:ss tt", System.Globalization.CultureInfo.InvariantCulture);
            pb.Image = Image.FromFile(respath + $@"\ContinutLectii\" + numeImagine + ".bmp");
            pb.SizeMode = PictureBoxSizeMode.StretchImage;
            var dt1 = utilizatoriTableAdapter.GetUtilizator(idUtilizator);
            string nume = (string)dt1.Rows[0]["Nume"];
            string email = (string)dt1.Rows[0]["Email"];
            rtbLog.Text = $"{nume}\n{email}\n{regiunea}\n{data}";
        }
    }
}
