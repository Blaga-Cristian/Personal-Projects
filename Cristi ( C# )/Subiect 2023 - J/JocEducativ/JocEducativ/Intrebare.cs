using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace JocEducativ
{
    public partial class Intrebare : Form
    {
        private string conStr = $@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\JocEducativ.mdf;Integrated Security=True";
        private string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\csarp\";
        string enuntItem, raspuns1, raspuns2, raspuns3;
        int raspunsCorect, punctaj = 0;

        private void btnAns_Click(object sender, EventArgs e)
        {
            if (rb1.Checked && raspunsCorect == 1)
                ScorExtra = punctaj;
            if (rb2.Checked && raspunsCorect == 2)
                ScorExtra = punctaj;
            if (rb3.Checked && raspunsCorect == 3)
                ScorExtra = punctaj;

            this.Close();
        }

        public int ScorExtra { get; set; }
        public Intrebare()
        {
            ScorExtra = 0;
            InitializeComponent();
            IncarcaIntrebare();
            rtb.Text = enuntItem;
            rb1.Text = raspuns1;
            rb2.Text = raspuns2;
            rb3.Text = raspuns3;
        }

        private void IncarcaIntrebare()
        {
            var con = new SqlConnection(conStr);
            con.Open();
            string query = "SELECT TOP 1 * FROM Itemi ORDER BY NEWID()";
            var cmd = new SqlCommand(query, con);
            var rd = cmd.ExecuteReader();
            rd.Read();
            enuntItem = rd[1].ToString();
            raspuns1 = rd[2].ToString();
            raspuns2 = rd[3].ToString();
            raspuns3 = rd[4].ToString();
            raspunsCorect = int.Parse(rd[5].ToString());
            punctaj = int.Parse(rd[6].ToString());

            con.Close();
            con.Dispose();
            cmd.Dispose();
        }
    }
}
