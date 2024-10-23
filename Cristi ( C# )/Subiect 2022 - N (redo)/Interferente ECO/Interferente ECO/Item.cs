using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interferente_ECO
{
    public class Item
    {
        public Item(){}

        public Item(string tip, int row, int col)
        {
            Tip = tip;
            Row = row;
            Col = col;
        }

        public string Tip { get; set; }
        public int Row { get; set; }
        public int Col { get; set; }
    }
}
