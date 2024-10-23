using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fire_Water
{
    public class Diamond
    {
        public int X { get; set; }
        public int Y { get; set; }
        public bool IsCollected { get; set; }
        private int size = 10;
        private Brush brush;

        // Adăugăm o proprietate pentru culoare
        public Brush Color { get { return brush; } }

        public Diamond(int x, int y, Brush brush)
        {
            X = x;
            Y = y;
            this.brush = brush;
            IsCollected = false;
        }

        public void Draw(Graphics g)
        {
            if (!IsCollected)
            {
                g.FillEllipse(brush, X, Y, size, size);
            }
        }

        public Rectangle GetBounds()
        {
            return new Rectangle(X, Y, size, size);
        }
    }
}
