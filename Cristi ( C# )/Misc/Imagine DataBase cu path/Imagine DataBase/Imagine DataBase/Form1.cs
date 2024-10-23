using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Imagine_DataBase
{
    public partial class Form1 : Form
    {
        ImaginiDSTableAdapters.ImagineTableAdapter itd = new ImaginiDSTableAdapters.ImagineTableAdapter();

        string path = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\Imagini";
        Image img;
        public Form1()
        {
            InitializeComponent();
            IncarcaDate();
            IncarcaDgw();
        }

        private void IncarcaDgw()
        {
            dgw.DataSource = null;
            dgw.Columns.Clear();
            dgw.Rows.Clear();

            var col1 = new DataGridViewTextBoxColumn();
            col1.Name = "Id";
            dgw.Columns.Add(col1);
            var col2 = new DataGridViewImageColumn();
            col2.ImageLayout = DataGridViewImageCellLayout.Stretch;
            col2.Name = "Imagine";
            dgw.Columns.Add(col2);

            dgw.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;

            DataTable dt = itd.GetData();
            foreach (DataRow row in dt.Rows)
            {
                int id = (int)row["IdImagine"];
                img = Image.FromFile((string)row["CaleFisier"]);

                dgw.Rows.Add(id, img);
            }
        }

        private void IncarcaDate()
        {
            string[] cai = Directory.GetFiles(path);

            for (int i = 0; i < cai.Count(); ++i)
                itd.Insert(cai[i]);            
        }
    }
}
