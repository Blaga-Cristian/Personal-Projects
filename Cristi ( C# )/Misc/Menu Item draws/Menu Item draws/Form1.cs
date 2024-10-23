using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Menu_Item_draws
{
    public partial class Form1 : Form
    {
        int cxImage = 32, cyImage = 32;
        int cxCheck = SystemInformation.MenuCheckSize.Width;
        int cyCheck = SystemInformation.MenuCheckSize.Height;
        int count = Enum.GetValues(typeof(HatchStyle)).Length;

        public Form1()
        {
            InitializeComponent();

            Menu = new MainMenu();
            Menu.MenuItems.Add(new MenuItem("Brushes"));
            this.Menu.MenuItems[0].Click += IncarcaTot;

            EventHandler ehClick = new EventHandler(MenuClick);
            MeasureItemEventHandler mehMeasure = new MeasureItemEventHandler(MenuMeasureItem);
            DrawItemEventHandler dehPaint = new DrawItemEventHandler(PaintItem);

            MenuItem[] ami = new MenuItem[count];

            for(int i = 0; i < count; ++i)
            {
                ami[i] = new MenuItem();
                ami[i].OwnerDraw = true;
                ami[i].RadioCheck = true;
                ami[i].Click += ehClick;
                ami[i].MeasureItem += mehMeasure;
                ami[i].DrawItem += dehPaint;
                if (i % 10 == 0)
                    ami[i].BarBreak = true;
            }


            Menu.MenuItems[0].MenuItems.AddRange(ami);
        }

        private void IncarcaTot(object sender, EventArgs e)
        {
            foreach (MenuItem mi in Menu.MenuItems[0].MenuItems)
                mi.PerformSelect();
        }

        private void MenuMeasureItem(object sender, MeasureItemEventArgs e)
        {
            e.ItemWidth = 2 * cxImage - cxCheck;
            e.ItemHeight = cyImage;
        }

        private void MenuClick(object sender, EventArgs e)
        {
            var g = this.CreateGraphics();
            MenuItem mi = (MenuItem)sender;
            g.FillEllipse(new HatchBrush((HatchStyle)mi.Index, DefaultForeColor, DefaultBackColor),ClientRectangle);
        }

        private void PaintItem(object sender, DrawItemEventArgs e)
        {
            e.DrawBackground();


            MenuItem mi = (MenuItem)sender;
            int i = mi.Index;

            try
            {
                HatchBrush hb = new HatchBrush((HatchStyle)mi.Index, DefaultForeColor, DefaultBackColor);
                e.Graphics.FillRectangle(hb, e.Bounds.X + cxImage, e.Bounds.Y, cxImage, cyImage);
            }
            catch { }
        }
    }
}
