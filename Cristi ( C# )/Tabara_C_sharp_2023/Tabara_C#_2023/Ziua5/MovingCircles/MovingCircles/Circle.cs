using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MovingCircles
{
    internal class Circle : Control
    {
        public int X { get; set; }
        public int Y { get; set; }
        public int R { get; set; }
        public Color C  { get; set; }

        public Circle(int x, int y, int r)
        {
            X = x;
            Y = y;
            R = r;
            if (R <= 30)
                C = Color.Green;
            if (R > 30 && R <= 50)
                C = Color.Blue;
            if (R > 50)
                C = Color.Red;
        }

        public Circle(int x, int y, int r, Color c)
        {
            X = x;
            Y = y;
            R = r;
            C = c;
        }

        public Circle()
        {
            X = 0;
            Y = 0;
            R = 0;
            C = Color.Blue;
            
        }

        
    }
}
