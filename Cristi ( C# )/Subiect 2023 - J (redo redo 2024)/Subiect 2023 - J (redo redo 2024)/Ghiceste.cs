using Subiect_2023___J__redo_redo_2024_.DSJocEducativTableAdapters;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net.Configuration;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Subiect_2023___J__redo_redo_2024_
{
    public partial class Ghiceste : Form
    {
        UtilizatoriTableAdapter uta = new UtilizatoriTableAdapter();
        ItemiTableAdapter ita = new ItemiTableAdapter();
        RezulateTableAdapter rta = new RezulateTableAdapter();

        static string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\csarp\csarp\";

        string email;

        int offx = 50, offy = 150, w = 30, h = 30, padding = 10, stagiu = 5;
        int SCOR = 100;
        string cuvant;
        Label[] letters, undscore;
        Button[] btns;

        Image[] stadii = {
            Image.FromFile(respath + $@"StadiiFloare\1.png"),
            Image.FromFile(respath + $@"StadiiFloare\2.png"),
            Image.FromFile(respath + $@"StadiiFloare\3.png"),
            Image.FromFile(respath + $@"StadiiFloare\4.png"),
            Image.FromFile(respath + $@"StadiiFloare\5.png"),
            Image.FromFile(respath + $@"StadiiFloare\6.png")};

        public Ghiceste(string email)
        {
            InitializeComponent();
            this.email = email;
            LoadCuvant();
            LoadButtons();
            ResetLabel();
        }

        void LoadCuvant()
        {
            var sr = new StreamReader(respath + "Cuvinte.txt");
            List<string> lst = new List<string>();

            string line;
            while ((line = sr.ReadLine()) != null) lst.Add(line);

            Random rnd = new Random();
            cuvant = lst[rnd.Next(lst.Count)];

            letters = new Label[cuvant.Length];
            undscore = new Label[cuvant.Length];

            for(int i = 0; i < cuvant.Length; ++i)
            {
                letters[i] = new Label();
                letters[i].Size = new Size(w, h);
                letters[i].Location = new Point(offx + (w + padding) * i, offy);
                letters[i].Font = new Font("arial", 10);
                this.Controls.Add(letters[i]);

                undscore[i] = new Label();
                undscore[i].Size = new Size(w, h);
                undscore[i].Location = new Point(offx + (w + padding) * i, offy + 40);
                undscore[i].Font = new Font("arial", 10);
                undscore[i].Text = "_";
                this.Controls.Add(undscore[i]);
            }
        }

        void LoadButtons()
        {
            btns = new Button[26];
            for (int i = 0; i < 26; ++i)
            {
                btns[i] = new Button();
                btns[i].Size = new Size(w, h);
                btns[i].Location = new Point(offx + (w + padding) * (i % 8), offy + 100 + (h + padding) * (i / 8));
                btns[i].Text = ((char)('A' + i)).ToString();
                btns[i].Click += Button_Click;
                this.Controls.Add(btns[i]);
            }
        }

        private void Button_Click(object sender, EventArgs e)
        {
            var btn = (Button)sender;
            btn.Enabled = false;
            this.ActiveControl = pbFloare;

            bool ok = false;
            for(int i = 0; i < cuvant.Length; ++i)
                if (char.ToUpper(cuvant[i]) == btn.Text.ToCharArray()[0])
                {
                    letters[i].Text = char.ToUpper(cuvant[i]).ToString();
                    ok = true;
                }

            if(ok)
            {
                stagiu = Math.Min(stagiu + 1, 5);

                bool is_over = true;
                for (int i = 0; i < cuvant.Length; ++i)
                    if (letters[i].Text.Length == 0)
                        is_over = false;

                if (is_over) AddScore();
            }
            else
            {
                stagiu--;
                SCOR -= 4;
                if(stagiu == 0)
                {
                    SCOR = 0;
                    AddScore();
                }
            }

            ResetLabel();
        }

        void ResetLabel()
        {
            lblScor.Text = $@"Scor: {SCOR}";
            pbFloare.Image = stadii[stagiu];
            pbFloare.SizeMode = PictureBoxSizeMode.StretchImage;
        }

        void AddScore()
        {
            rta.Insert(0, email, SCOR);
            MessageBox.Show("Jocul s-a terminat", "Game Over", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            this.Close();
        }
    }
}
