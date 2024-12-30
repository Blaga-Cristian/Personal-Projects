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

namespace Interferente_ECO
{
    public partial class Logare : Form
    {
        string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\OTI_2022_C#_resurse\";
        public Logare()
        {
            InitializeComponent();
            PopuleazaCmb();
        }

        private void PopuleazaCmb()
        {
            var sr = new StreamReader(respath + "Useri.txt");
            string line;
            string[] s;
            char[] sep = { ' ' };

            while((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                cmbUseri.Items.Add(new KeyValuePair<string, string>(s[0], s[1]));
            }

            cmbUseri.DisplayMember = "Key";
            cmbUseri.ValueMember = "Value";
            cmbUseri.SelectedIndex = 0;

            cmbUseri.DropDownStyle = ComboBoxStyle.DropDownList;
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            string parola = txtParola.Text;
            if(parola != ((KeyValuePair<string,string>)cmbUseri.SelectedItem).Value)
            {
                MessageBox.Show("Incorrect password");
                return;
            }

            PictureBox pb = (PictureBox)sender;

            var frm = new InterferenteECO(pb.Image);
            this.Visible = false;
            frm.ShowDialog();
            this.Close();
        }
    }
}
