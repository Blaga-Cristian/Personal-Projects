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
        private string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\OTI_2022_C#_resurse\";
        private List<Utilizatori> utilizatori = new List<Utilizatori>();
        PictureBox[] pictureBoxes = new PictureBox[5];
        Point[] locations = new Point[]
        {
            new Point(33, 215),
            new Point(289, 215),
            new Point(568, 215),
            new Point(155, 340),
            new Point(464, 340)
        };

        public Logare()
        {
            InitializeComponent();
            IncarcaUtilizatori();
            PopuleazaCmb();
            IncarcaPictures();
        }

        private void IncarcaPictures()
        {
            for(int i = 0; i < 5; ++i)
            {
                pictureBoxes[i] = new PictureBox();
                pictureBoxes[i].Size = new Size(200, 100);
                pictureBoxes[i].Location = locations[i];
                pictureBoxes[i].Image = Image.FromFile(respath + $@"Background\" + "Back" + (i + 1).ToString() + ".jpg");
                pictureBoxes[i].SizeMode = PictureBoxSizeMode.StretchImage;
                pictureBoxes[i].Click += PictureClickHandler;
                Controls.Add(pictureBoxes[i]);
            }
        }

        private void PictureClickHandler(object sender, EventArgs e)
        {
            string parola = txtParola.Text;
            if(parola == cmb.SelectedValue.ToString())
            {
                var img = ((PictureBox)sender).Image;
                var frm = new InterferenteECO(img);
                this.Visible = false;
                frm.ShowDialog();
                this.Close();
            }
        }

        private void PopuleazaCmb()
        {
            cmb.DataSource = utilizatori;
            cmb.ValueMember = "Parola";
            cmb.DisplayMember = "Nume";
            cmb.DropDownStyle = ComboBoxStyle.DropDownList;
        }

        private void IncarcaUtilizatori()
        {
            var sr = new StreamReader(respath + "Useri.txt");
            string line;
            string[] s;
            char[] sep = { ' ' };

            while ((line = sr.ReadLine()) != null) 
            { 
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                utilizatori.Add(new Utilizatori(s[0], s[1]));
            }
        }
    }
}
