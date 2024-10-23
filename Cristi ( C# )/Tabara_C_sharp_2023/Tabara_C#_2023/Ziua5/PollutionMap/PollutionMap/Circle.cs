using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PollutionMap
{
    public class Circle
    {
        public int X { get; set; }
        public int Y { get; set; }
        public float P { get; set; }
        public Color C { get; set; }
        public DateTime Dt { get; set; }
        public string Harta { get; set; }
        public Circle()
        {
            X = 0;
            Y = 0;
            P = 0;
            C = Color.Transparent;
        }

        public Circle(int x, int y, float p, DateTime dt, string harta)
        {
            X = x;
            Y = y;
            P = p;
            this.Dt = dt;
            Harta = harta;
            if (P < 20)
                C = Color.Green;
            if (P >= 20 && P <= 40)
                C = Color.Yellow;
            if (P > 40)
                C = Color.Red;
        }

    }
}
