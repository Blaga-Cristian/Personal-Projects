using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fire_Water
{
    public class Barrier
    {
        public int X { get; set; }
        public int Y { get; set; }
        public int Width { get; set; }
        public int Height { get; set; }
        public bool IsOpen { get; set; }

        public Barrier(int x, int y, int width, int height)
        {
            X = x;
            Y = y;
            Width = width;
            Height = height;
            IsOpen = false;
        }

        public void Draw(Graphics g)
        {
            if (!IsOpen)
            {
                g.FillRectangle(Brushes.Gray, X, Y, Width, Height);
            }
        }

        public Rectangle GetBounds()
        {
            return new Rectangle(X, Y, Width, Height);
        }
    }
}
