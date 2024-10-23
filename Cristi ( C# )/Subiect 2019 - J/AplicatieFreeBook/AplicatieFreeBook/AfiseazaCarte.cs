using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AplicatieFreeBook
{
    public partial class AfiseazaCarte : Form
    {
        private static string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\csarp\";
        string connStr = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\FreeBook.mdf;Integrated Security = True; Connect Timeout = 30";
        private string bookpath = respath + @"cartipdf\";
        public AfiseazaCarte(string titlu)
        {
            InitializeComponent();

            string path = bookpath + GetIdCarte(titlu) + ".pdf";
            wbCarte.Navigate($@"file:///{path}");
        }

        private int GetIdCarte(string titlu)
        {
            SqlConnection con = new SqlConnection(connStr);
            con.Open();
            string query = "SELECT Id_carte FROM carti WHERE titlu = @titlu";
            SqlCommand cmd = new SqlCommand(query, con);
            cmd.Parameters.AddWithValue("@titlu", titlu);
            var cr = cmd.ExecuteReader();
            cr.Read();
            int id = (int)cr[0];
            return id;
        }

    }
}
