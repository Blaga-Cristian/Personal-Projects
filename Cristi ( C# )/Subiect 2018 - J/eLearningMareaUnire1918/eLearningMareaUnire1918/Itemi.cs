using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace eLearningMareaUnire1918
{
    class Item
    {
        public Item()
        {
        }

        public Item(int tip, string r1, string r2, string r3, string r4, string rcorect)
        {
            Tip = tip;
            R1 = r1;
            R2 = r2;
            R3 = r3;
            R4 = r4;
            Rcorect = rcorect;
        }

        public int Tip { get; set; }
        public string R1 { get; set; }
        public string R2 { get; set; }
        public string R3 { get; set; }
        public string R4 { get; set; }
        public string Rcorect { get; set; }
    }
}
