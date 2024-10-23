using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PollutionMap
{
    public class Cerc
    {
        public string Harta { get; set; }
        public int X { get; set; } // pozitia  centrului
        public int Y { get; set; }
        public int P { get; set; }  // poluarea
        public DateTime Dt { get; set; }
        public Color C { get; set; } // culoarea

        public Cerc() { }

        public Cerc(string harta, int x, int y, int p, DateTime dt)
        {
            Harta = harta;
            X = x;
            Y = y;
            P = p;
            if (P < 20)
                C = Color.Green;
            if (P >= 20 && P <= 40)
                C = Color.Yellow;
            if (p > 40)
                C = Color.Red;
            Dt = dt;
        }
    }
}
