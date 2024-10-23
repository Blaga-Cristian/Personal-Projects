using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calatorie
{
    public partial class Vizualizare : Form
    {
        DSTimpSpatiuTableAdapters.PorturiTableAdapter pta = new DSTimpSpatiuTableAdapters.PorturiTableAdapter();
        DSTimpSpatiuTableAdapters.DistanteTableAdapter dta = new DSTimpSpatiuTableAdapters.DistanteTableAdapter();
        DSTimpSpatiuTableAdapters.CroaziereTableAdapter cta = new DSTimpSpatiuTableAdapters.CroaziereTableAdapter();





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

        string traseu;

        List<Point> puncte;
        List<Point> puncteTraseu;


        public Vizualizare(string traseu)
        {
            this.traseu = traseu;
            InitializeComponent();
            DeseneazaTraseu();
        }

        private void DeseneazaTraseu()
        {
            puncteTraseu = new List<Point>();
            puncte = new List<Point>();
            DataTable dt = pta.GetData();
            foreach (DataRow dr in dt.Rows)
                puncte.Add(new Point((int)dr["Pozitie_X"], (int)dr["Pozitie_Y"]));

            string[] s = traseu.Split(new char[] { '-', ' ' }, StringSplitOptions.RemoveEmptyEntries);

            for (int i = 0; i < s.Length; ++i)
            {
                int j = porturi.TakeWhile(x => x != s[i]).Count();
                puncteTraseu.Add(puncte[j]);
            }

            pb.Invalidate();
        }

        private void btnInchidere_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void pb_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.DrawLines(new Pen(Color.Red, 4f), puncteTraseu.ToArray());
        }
    }
}
