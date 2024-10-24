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
    public partial class LogareBilblioteca : Form
    {
        DSBibliotecaTableAdapters.CartiTableAdapter cta = new DSBibliotecaTableAdapters.CartiTableAdapter();
        DSBibliotecaTableAdapters.ImprumuturiTableAdapter ita = new DSBibliotecaTableAdapters.ImprumuturiTableAdapter();
        DSBibliotecaTableAdapters.RezervariTableAdapter rta = new DSBibliotecaTableAdapters.RezervariTableAdapter();
        DSBibliotecaTableAdapters.UtilizatoriTableAdapter uta = new DSBibliotecaTableAdapters.UtilizatoriTableAdapter();
        string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\ONTI_C#_2019_resurse\";


        public LogareBilblioteca()
        {
            InitializeComponent();
        }

        private void btnLogare_Click(object sender, EventArgs e)
        {
            string email = txtEmail.Text;
            string parola = txtParola.Text;
            DataTable dt = uta.GetUtilizator(email);

            if (dt.Rows.Count == 1 && 
               Cifru(parola) == (string)dt.Rows[0]["Parola"] && 
               (int)dt.Rows[0]["TipUtiliator"] == 1)
            {
                var frm = new BibliotecarBiblioteca(email);
                this.Visible = false;
                frm.ShowDialog();
                this.Close();
            }
            else
            {
                MessageBox.Show("Email si/sau parola incorecta");
                txtEmail.Text = txtParola.Text = "";
            }    
        }

        private string Cifru(string parola)
        {
            char[] arr = parola.ToCharArray();

            for(int i = 0; i < arr.Length; ++i)
            {
                if (arr[i] >= 'a' && arr[i] <= 'z')
                    if (arr[i] == 'z') arr[i] = 'a';
                    else arr[i]++;
                else if (arr[i] >= 'A' && arr[i] <= 'Z')
                    if (arr[i] == 'A') arr[i] = 'Z';
                    else arr[i]--;
                else if (char.IsDigit(arr[i]))
                    arr[i] = (char)('9' - arr[i] + '0');
            }

            return new string(arr);
        }

        private void btnRenunta_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
