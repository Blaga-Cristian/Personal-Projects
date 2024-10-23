using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ButtonMatrix
{
    public partial class Form1 : Form
    {
        private int n = 5;
        private int m = 5;
        private PictureBox[,] btn = null;
        private TableLayoutPanel tbl = null;
        float sizeCell = 0;



        public Form1()
        {
            InitializeComponent();
            
            sizeCell = Math.Min(ClientSize.Height, ClientSize.Width) / Math.Max(n, m);
            tbl = new TableLayoutPanel()
            {
                Dock = DockStyle.Fill,
                
            };

      
            btn = new PictureBox[n, m];

            for (int j = 0; j < m; ++j)
                tbl.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, sizeCell));

            for (int i = 0; i < n; ++i)
            {
                tbl.RowStyles.Add(new RowStyle(SizeType.Percent, sizeCell));
                for (int j = 0; j < m; ++j)
                {
                    tbl.Controls.Add(btn[i, j] = new PictureBox()
                    {
                        Dock = DockStyle.Fill,
                        BackColor = Color.Aquamarine,
                        Margin = new Padding(0),
                        Padding = new Padding(5),
                        
                    },
                    j, i);

                    btn[i, j].Paint += OnButtonPaint; // new PaintEventHandler(OnButtonPaint);
              //     btn[i, j].Resize += OnPictResize; //new  EventHandler(OnPictResize);
                    btn[i, j].Click += OnPictClick;  //new EventHandler(OnPictClick);
                }

            }
            this.Controls.Add(tbl);
        }

        string text = "W";
        private void OnPictClick(object sender, EventArgs e)
        {
            PictureBox p = (PictureBox)sender;
            text = "X";
            p.Invalidate();
            
        }

        private void OnPictResize(object sender, EventArgs e)
        {
            PictureBox p = (PictureBox)sender;
            p.Refresh();
        }

        private void OnButtonPaint(object sender, PaintEventArgs e)
        {
            //base.OnPaint(e);
            PictureBox b = (PictureBox)sender;

            
            Font font = new Font(new FontFamily("Wingdings"), Math.Min(b.Height, b.Width),
                FontStyle.Bold);

            SolidBrush brush = new SolidBrush(Color.Red);
            StringFormat format = new StringFormat();
            format.Alignment = StringAlignment.Center;
            
            e.Graphics.DrawString(text, font, brush, b.ClientRectangle, format);
           
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            //for (int i = 0; i < n; ++i)
            //    for (int j = 0; j < m; ++j)
            //        btn[i, j].Invalidate();
        }
    }
}
