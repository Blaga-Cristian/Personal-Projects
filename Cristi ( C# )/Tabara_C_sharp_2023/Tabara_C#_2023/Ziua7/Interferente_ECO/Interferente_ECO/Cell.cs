using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;
using System.Threading.Tasks;

namespace Interferente_ECO
{
    class Cell
    {
        public float X0, Y0, W, H;
        public bool TriangleVisible = false;
        public bool hasTriangle = false;
        
        public bool ObjectVisible = false;
        public bool hasObject = false;
        public int Rot;
        public string file = null;
        public bool hasColor = false;
        public int i = -1, j = -1;
        public Directie directie;
        public Cell()
        {
            X0 = 0;
            Y0 = 0;
            W = 0;
            H = 0;
            TriangleVisible = false;
        }

        public Cell(int i, int j, float x0, float y0, float w, float h, Directie directie, bool hasColor)
        {
            this.i = i;
            this.j = j;
            this.X0 = x0;
            this.Y0 = y0;
            this.W = w;
            this.H = h;
            this.hasColor = hasColor;
            this.directie = directie;
        }
        public Cell(float x0, float y0, float w, float h)
        {
            X0 = x0;
            Y0 = y0;
            W = w;
            H = h;
            TriangleVisible = false;
            Rot = -1;
        }
        public Cell(float x0, float y0, float w, float h, int rot, bool visible)
        {
            X0 = x0;
            Y0 = y0;
            W = w;
            H = h;
            Rot = rot;
        }
    }
}
