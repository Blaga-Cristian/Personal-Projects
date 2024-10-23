using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fire_Water
{
    public class Hazard
    {
        public int X { get; set; }
        public int Y { get; set; }
        public int Width { get; set; }
        public int Height { get; set; }
        public Brush Color { get; set; }

        private Brush brush;

        public Hazard(int x, int y, int width, int height, Brush brush)
        {
            X = x;
            Y = y;
            Width = width;
            Height = height;
            this.brush = brush;

            //Color nu este initializata
            Color = brush;
        }

        public void Draw(Graphics g)
        {
            g.FillRectangle(brush, X, Y, Width, Height);
        }

        public Rectangle GetBounds()
        {
            return new Rectangle(X, Y, Width, Height);
        }
    }
}
