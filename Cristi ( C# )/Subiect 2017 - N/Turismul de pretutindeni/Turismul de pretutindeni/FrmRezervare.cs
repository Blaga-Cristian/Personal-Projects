using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Turismul_de_pretutindeni
{
    public partial class FrmRezervare : Form
    {
        static TurismDSTableAdapters.VacanteTableAdapter vtb = new TurismDSTableAdapters.VacanteTableAdapter();
        static TurismDSTableAdapters.UtilizatoriTableAdapter utb = new TurismDSTableAdapters.UtilizatoriTableAdapter();
        static TurismDSTableAdapters.RezervariTableAdapter rtb = new TurismDSTableAdapters.RezervariTableAdapter();


        int idVacanta;
        int locuriDisponibile;
        float pret;
        string email;

        public FrmRezervare(int idVacanta, string email)
        {
            InitializeComponent();
            this.idVacanta = idVacanta;
            this.email = email;
            mc.ShowToday = false;
            IncarcaDetalii();
        }

        private void IncarcaDetalii()
        {
            DataTable dt = vtb.GetVacanta(idVacanta);
            pb.Image = Image.FromFile((string)dt.Rows[0]["CaleFisier"]);
            lblNumeVacanta.Text = (string)dt.Rows[0]["NumeVacanta"];
            lblPret.Text = "" + (float)dt.Rows[0]["Pret"] + " lei";
            pret = (float)dt.Rows[0]["Pret"];
            lblDescriere.Text = (string)dt.Rows[0]["Descriere"];
            DataTable dt1 = rtb.GetRezervariVacanta(idVacanta);
            int ocupate = 0;
            foreach (DataRow row in dt1.Rows)
                ocupate += (int)row["NrPersoane"];
            locuriDisponibile = (int)dt.Rows[0]["NrLocuri"] - ocupate;
            lblPersoaneDisponibile.Text = "" + locuriDisponibile + " locuri disponibile";
        }

        private void btnRezervare_Click(object sender, EventArgs e)
        {
            try
            {
                int nrPersoane = int.Parse(txtPersoane.Text);
                if (nrPersoane > locuriDisponibile) throw new Exception();
                int idUser = (int)utb.GetUtilizator(email).Rows[0]["IdUser"];
                DateTime dataInceput = mc.SelectionStart;
                DateTime dataSfarsit = mc.SelectionEnd;
                float pretTotal = nrPersoane * pret;

                rtb.InsertRezervare(idVacanta, idUser, dataInceput, dataSfarsit, nrPersoane, pretTotal);
                this.Close();
            }
            catch
            {
                MessageBox.Show("Informatii invalide");
            }
        }

        private void txtPersoane_TextChanged(object sender, EventArgs e)
        {
            try
            {
                int x = int.Parse(txtPersoane.Text);
                txtPret.Text = "" + x * pret + " lei";
            }
            catch
            {
                txtPret.Text = string.Empty;
            }
        }
    }
}
