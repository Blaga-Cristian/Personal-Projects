using JocEducativ.DSJocEducativTableAdapters;
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

namespace JocEducativ
{
    public partial class Ghiceste : Form
    {

        ItemiTableAdapter ita = new ItemiTableAdapter();
        RezultateTableAdapter rta = new RezultateTableAdapter();
        UtilizatoriTableAdapter uta = new UtilizatoriTableAdapter();
        static string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\csarp\";

        int w = 30, h = 30;
        string email;
        int scor = 100;
        int stagiu = 5;
        string cuvant;
        char[] alphabet = new char[] {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
        'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
        'R', 'S', 'T', 'U', 'V', 'X', 'Y', 'Z'};
        Button[] buttons = new Button[24];
        Label[] labels;
        Label[] indicators;
        Image[] stagii = new Image[]
        {
            Image.FromFile(respath + $@"StadiiFloare\1.png"),
            Image.FromFile(respath + $@"StadiiFloare\2.png"),
            Image.FromFile(respath + $@"StadiiFloare\3.png"),
            Image.FromFile(respath + $@"StadiiFloare\4.png"),
            Image.FromFile(respath + $@"StadiiFloare\5.png"),
            Image.FromFile(respath + $@"StadiiFloare\6.png")
        };
        

        public Ghiceste(string email)
        {
            this.email = email;
            InitializeComponent();
            lblPunctaj.Text = $@"Punctaj: {scor}";
            pb.Image = stagii[stagiu];
            GetCuvant();
        }

        private void GetCuvant()
        {
            List<string> optiuni = new List<string>();
            var sr = new StreamReader(respath + "Cuvinte.txt");
            string line;

            while((line = sr.ReadLine()) != null)
                optiuni.Add(line);

            Random rand = new Random();

            cuvant = optiuni[rand.Next(optiuni.Count)];

            labels = new Label[optiuni.Count];
            indicators = new Label[optiuni.Count];
            for(int i = 0; i < optiuni.Count; ++i)
            {
                labels[i] = new Label();
                labels[i].Size = new Size(w, h);
                labels[i].Location = new Point(35 + w * i, 150);
                this.Controls.Add(labels[i]);

                indicators[i] = new Label();
                indicators[i].Size = new Size(w, h);
                indicators[i].Text = "_";
                indicators[i].Location = new Point(35 + w * i, 200);
                this.Controls.Add(indicators[i]);
            } 

            for(int i = 0; i < 24; ++i)
            {
                buttons[i] = new Button();
                buttons[i].Size = new Size(w, h);
                buttons[i].Text = alphabet[i].ToString();
                buttons[i].Location = new Point(35 + (i % 8) * w, 300 + (i / 8) * h);
                buttons[i].Click += TryLetter;
                this.Controls.Add(buttons[i]);
            }
        }

        private void TryLetter(object sender, EventArgs e)
        {
            Button btn = (Button)sender;
            btn.Enabled = false;
            char c = btn.Text.ToCharArray()[0];

            bool ok = false;
            for(int i = 0; i < cuvant.Length; ++i)
                if (char.ToUpper(cuvant[i]) == c)
                {
                    ok = true;
                    labels[i].Text = c.ToString();
                }

            if(!ok)
            {
                stagiu--;
                if(stagiu == -1)
                {
                    scor = 0;
                    lblPunctaj.Text = $@"Punctaj: {scor}";
                    MessageBox.Show("Ai pierdut", "Ghiceste", MessageBoxButtons.OK);

                    rta.Insert(0, email, scor);

                    this.Close();
                    return;
                }

                scor -= 4;
                pb.Image = stagii[stagiu];
                lblPunctaj.Text = $@"Punctaj: {scor}";
            }
            else
            {
                bool over = true;
                for (int i = 0; i < cuvant.Length; ++i)
                    if (labels[i].Text == "")
                        over = false;

                if(over)
                {
                    MessageBox.Show("Jocul s-a terminat", "Ghiceste", MessageBoxButtons.OK);

                    rta.Insert(0, email, scor);

                    this.Close();
                }
            }            
        }
    }
}
