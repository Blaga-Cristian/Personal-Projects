using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Drawing;

namespace Tetris_2
{
    public class Cell
    {
        public Cell()
        {
            Color = Color.Transparent;
        }

        public Cell(int row, int col, Color color)
        {
            Row = row;
            Col = col;
            Color = color;
        }

        public int Row { get; set; }
        public int Col { get; set; }
        public Color Color { get; set; }
    }
}