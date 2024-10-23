using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Bursa_Nume_Prenume
{
    public partial class Grafic_Profit : Form
    {
        List<int> valori;
        public Grafic_Profit(List<int> valori)
        {
            this.valori = valori;
            InitializeComponent();
            IncarcaChart();
        }

        public void Incarca(List<int> valori)
        {
            this.valori = valori;
            IncarcaChart();
        }

        private void IncarcaChart()
        {
            cht.Series[0].Points.Clear();


            for(int i = 0; i < valori.Count; ++i)
                cht.Series[0].Points.AddY(valori[i]);
        }
    }
}
