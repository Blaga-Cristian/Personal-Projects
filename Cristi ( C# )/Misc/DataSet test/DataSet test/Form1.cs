using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Net.Http.Headers;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DataSet_test
{
    public partial class Form1 : Form
    {
        string conStr = $@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=""E:\Cristi ( C# )\Misc\DataSet test\DataSet test\Scoala.mdf"";Integrated Security=True";
        ScoalaDBTableAdapters.EleviTableAdapter eleviTableAdapter = new ScoalaDBTableAdapters.EleviTableAdapter();
        public Form1()
        {
            InitializeComponent();
            DataTable dt = eleviTableAdapter.GetNume("Ana");
            lbl.Text = dt.Rows.Count.ToString();
        }

    }
}
