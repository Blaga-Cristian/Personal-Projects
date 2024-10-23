using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fire_Water
{
    public class Button
    {
        public int X { get; set; }
        public int Y { get; set; }
        public bool IsPressed { get; set; }
        private int size = 10;

        public Button(int x, int y)
        {
            X = x;
            Y = y;
            IsPressed = false;
        }

        public void Draw(Graphics g)
        {
            g.FillRectangle(IsPressed ? Brushes.Green : Brushes.White, X, Y, size, size);
        }

        public Rectangle GetBounds()
        {
            return new Rectangle(X, Y, size, size);
        }
    }
}
