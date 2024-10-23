using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Text;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace JocEducativ
{
    public partial class GhicesteCuvant : Form
    {
        private string conStr = $@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\JocEducativ.mdf;Integrated Security=True";
        private string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\csarp\";

        private JocEducativDBTableAdapters.RezultateTableAdapter rezultateTableAdapter = new JocEducativDBTableAdapters.RezultateTableAdapter();
        string emailUtilizator;
        int stage = 6;
        int scor = 100;
        string cuvant;
        Button[] buttons = new Button[24];
        Label[] labels;
        Label[] empty;
        Random rand = new Random();
        char[] alphabet = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N'
        , 'O', 'P', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
        List<bool> ghicit = new List<bool>();

        public GhicesteCuvant(string emailUtilizator)
        {
            InitializeComponent();
            this.emailUtilizator = emailUtilizator;
            SetScor();
            SetImagine();
            GetCuvant();
            LoadButtons();
            LoadLabels();
            LoadEmpty();
        }

        private void SetImagine()
        {
            pb.Image = Image.FromFile(respath + @"StadiiFloare\" + stage + ".png");
            pb.SizeMode = PictureBoxSizeMode.StretchImage;
        }

        private void SetScor()
        {
            lblPunctaj.Text = "Punctaj: " + scor;
        }

        private void LoadLabels()
        {
            int w = 30, h = 30;
            int x = 30, y = 150;
            for(int i = 0; i < cuvant.Length; ++i)
            {
                labels[i] = new Label();
                labels[i].Size = new Size(w, h);
                labels[i].Location = new Point(x + i * w, y);
                labels[i].Text = "";
                Controls.Add(labels[i]);
            }
        }

        private void LoadEmpty()
        {
            int w = 30, h = 30;
            int x = 30, y = 200;
            for(int i = 0; i < cuvant.Length; ++i)
            {
                empty[i] = new Label();
                empty[i].Size = new Size(w, h);
                empty[i].Location = new Point(x + i * w, y);
                empty[i].Text = "_";
                Controls.Add(empty[i]);
            }
        }

        private void LoadButtons()
        {
            int w = 30, h = 30;
            int x = 50, y = 300;
            for(int i = 0; i < 24; ++i)
            {
                buttons[i] = new Button();
                buttons[i].Size = new Size(w, h);
                buttons[i].Location = new Point(x + (i % 8) * w, y + (i / 8) * h);
                buttons[i].Text = alphabet[i].ToString();
                buttons[i].Click += ButtonClickHandler;
                this.Controls.Add(buttons[i]);
            }
        }

        private void ButtonClickHandler(object sender, EventArgs e)
        {
            var btn = (Button)sender;
            char[] litera = btn.Text.ToCharArray();
            char[] cuvantchar = cuvant.ToCharArray();
            bool ok = false;
            bool gata = true;
            for (int i = 0; i < cuvant.Length; ++i)
                if (char.ToUpper(litera[0]) == char.ToUpper(cuvantchar[i]))
                {
                    ok = true;
                    ghicit[i] = true;
                }

            for (int i = 0; i < cuvant.Length; ++i)
                if (!ghicit[i])
                    gata = false;

            if(ok == false)
            {
                scor -= 4;
                stage--;
                if (stage == 0)
                    scor = 0;
            }

            IncarcaLabels();
            SetScor();

            if (stage == 0 || gata)
            {
                MessageBox.Show("Jocul s-a terminat", "Game Over", MessageBoxButtons.OK);
                rezultateTableAdapter.InsertRezultat(0, emailUtilizator, scor);
                this.Close();
                return;
            }


            
            SetImagine();
            btn.Enabled = false;
        }

        private void IncarcaLabels()
        {
            char[] cuvantchar = cuvant.ToCharArray();
            for (int i = 0; i < cuvant.Length; ++i)
                if (ghicit[i])
                    labels[i].Text = char.ToUpper(cuvantchar[i]).ToString();
        }

        private void GetCuvant()
        {
            List<string> cuvinte = new List<string>();
            var sr = new StreamReader(respath + "Cuvinte.txt");
            string line;

            while((line = sr.ReadLine()) != null)
                cuvinte.Add(line);

            cuvant = cuvinte[rand.Next() % cuvinte.Count];
            labels = new Label[cuvant.Length];
            empty = new Label[cuvant.Length];
            for (int i = 0; i < cuvant.Length; ++i)
                ghicit.Add(false);
        }
    }
}
