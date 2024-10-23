using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fire_Water
{
    public class Character
    {
        public int X { get; set; }
        public int Y { get; set; }
        public int Width { get; set; }
        public int Height { get; set; }
        public Brush Color { get; set; }

        public Character(int x, int y, int width, int height, Brush color)
        {
            X = x;
            Y = y;
            Width = width;
            Height = height;
            Color = color;
        }

        public void Draw(Graphics g)
        {
            g.FillRectangle(Color, X, Y, Width, Height);
        }

        public void MoveUp() => Y -= 5;
        public void MoveDown() => Y += 5;
        public void MoveLeft() => X -= 5;
        public void MoveRight() => X += 5;

        public Rectangle GetBounds()
        {
            return new Rectangle(X, Y, Width, Height);
        }
    }

    public class Fireboy : Character
    {
        public Fireboy(int x, int y) : base(x, y, 20, 20, Brushes.Red) { }

        public new void Draw(Graphics g)
        {
            base.Draw(g);
        }
    }

    public class Watergirl : Character
    {
        public Watergirl(int x, int y) : base(x, y, 20, 20, Brushes.Blue) { }

        public new void Draw(Graphics g)
        {
            base.Draw(g);
        }
    }
}

