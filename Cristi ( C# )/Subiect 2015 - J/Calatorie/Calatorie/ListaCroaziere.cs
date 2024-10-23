using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calatorie
{
    public partial class ListaCroaziere : Form
    {
        string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\csarp\Resurse_C#\";

        DSTimpSpatiuTableAdapters.PorturiTableAdapter pta = new DSTimpSpatiuTableAdapters.PorturiTableAdapter();
        DSTimpSpatiuTableAdapters.DistanteTableAdapter dta = new DSTimpSpatiuTableAdapters.DistanteTableAdapter();
        DSTimpSpatiuTableAdapters.CroaziereTableAdapter cta = new DSTimpSpatiuTableAdapters.CroaziereTableAdapter();

        bool initializare;
        List<Point> puncte;
        int[] b;

        string[] porturi = new string[]
        {
            "Constanta",
            "Varna",
            "Burgas",
            "Istanbul",
            "Kozlu",
            "Samsun",
            "Batumi",
            "SokHumi",
            "Soci",
            "Anapa",
            "Yalta",
            "Sevastopol",
            "Odessa"
        };

        public ListaCroaziere()
        {
            InitializeComponent();
        }

        private void btnInit_Click(object sender, EventArgs e)
        {
            puncte = new List<Point>();
            lblX.Text = lblY.Text = "";
            initializare = true;
        }

        private void pb_MouseClick(object sender, MouseEventArgs e)
        {
            if (!initializare) return;

            lblX.Text = "" + e.Location.X;
            lblY.Text = "" + e.Location.Y;
            puncte.Add(e.Location);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (puncte == null) return;
            if (puncte.Count != 13)
            {
                MessageBox.Show("Puncte incorecte");
                return;
            }

            pta.TruncateTable(0, 0, "", 0, 0, 0, 0);
            for (int i = 0; i < 13; ++i)
                pta.Insert(porturi[i], puncte[i].X, puncte[i].Y);
        }

        private void btnActualizare_Click(object sender, EventArgs e)
        {
            dta.TruncateTable();

            var sr = new StreamReader(respath + "Harta_Distantelor.txt");
            string line;
            string[] s;
            char[] sep = { ' ' };

            int i = 1;
            while((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);

                for (int j = 0; j < 13; ++j)
                    dta.InsertDistanta(i, j + 1, porturi[j], int.Parse(s[j]));

                ++i;
            }

        }

        private void button3_Click(object sender, EventArgs e)
        {
            cta.TruncateTable(0, 0, 0, 0, "", 0, DateTime.Now, 0, DateTime.Now, 0, 0, 0, 0);

            b = new int[10];
            Back(0, 1);
        }

        private void Back(int x,int ind)
        {
            if (x > 8) return;
            if(x == 3 || x == 5 || x == 8)
            {
                string listporturi = "1, ";
                int distanta = (int)dta.GetDistanta(1, b[0]).Rows[0]["Distanta"];

                for (int i = 1; i < x; ++i)
                {
                    listporturi += $@"{b[i]}, ";
                    distanta += (int)dta.GetDistanta(b[i-1], b[i]).Rows[0]["Distanta"];
                }
                listporturi += "1";
                distanta += (int)dta.GetDistanta(b[x - 1], 1).Rows[0]["Distanta"];

                cta.Insert(x, listporturi, null, null, 2 * distanta, null);
            }

            for(int i = ind; i < 13; ++i)
            {
                b[x] = i + 1;
                Back(x + 1, i + 1);
                b[x] = -1;
            }
        }

        private void btnLista_Click(object sender, EventArgs e)
        {
            var frm = new ListaCroaziereVizualizare();
            frm.ShowDialog();
        }
    }
}
