using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calatorie
{
    public partial class ListaCroaziereVizualizare : Form
    {
        DSTimpSpatiuTableAdapters.PorturiTableAdapter pta = new DSTimpSpatiuTableAdapters.PorturiTableAdapter();
        DSTimpSpatiuTableAdapters.DistanteTableAdapter dta = new DSTimpSpatiuTableAdapters.DistanteTableAdapter();
        DSTimpSpatiuTableAdapters.CroaziereTableAdapter cta = new DSTimpSpatiuTableAdapters.CroaziereTableAdapter();

        string[] porturi = new string[]
        {
            "Constanta",
            "Varna",
            "Burgas",
            "Istanbul",
            "Kozlu",
            "Samsun",
            "Batumi",
            "SokHumi",
            "Soci",
            "Anapa",
            "Yalta",
            "Sevastopol",
            "Odessa"
        };

        public ListaCroaziereVizualizare()
        {
            InitializeComponent();
            cmb.SelectedIndex = 0;
        }

        private void cmb_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (cmb.SelectedIndex == 0)
                IncarcaDgw(3);
            else if (cmb.SelectedIndex == 1)
                IncarcaDgw(5);
            else
                IncarcaDgw(8);
        }

        private void IncarcaDgw(int tip)
        {
            dgw.DataSource = null;
            dgw.Columns.Clear();
            dgw.Rows.Clear();

            var col1 = new DataGridViewTextBoxColumn();
            col1.Name = "ID";
            dgw.Columns.Add(col1);
            var col2 = new DataGridViewTextBoxColumn();
            col2.Name = "Circuit";
            dgw.Columns.Add(col2);
            var col3 = new DataGridViewTextBoxColumn();
            col3.Name = "Data Start";
            dgw.Columns.Add(col3);
            var col4 = new DataGridViewTextBoxColumn();
            col4.Name = "Data Final";
            dgw.Columns.Add(col4);
            var col5 = new DataGridViewTextBoxColumn();
            col5.Name = "Pret";
            dgw.Columns.Add(col5);
            var col6 = new DataGridViewTextBoxColumn();
            col6.Name = "Numar Pasageri";
            dgw.Columns.Add(col6);

            dgw.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.AllCells;

            DataTable dt = cta.GetCroaziere(tip);
            foreach(DataRow dr in dt.Rows)
            {
                string cs = (string)dr["List_Porturi"];
                string[] s = cs.Split(new char[]{ ',', ' '}, StringSplitOptions.RemoveEmptyEntries);
                string circuit = "";
                for(int i = 0; i < s.Length; ++i)
                {
                    circuit += porturi[int.Parse(s[i]) - 1];
                    if(i != s.Length - 1)circuit += ", ";
                }

                dgw.Rows.Add(dr["ID_Croaziera"], circuit, dr["Data_Start"], dr["Data_Final"],
                    dr["Pret"], dr["Nr_Pasageri"]);
            }
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
