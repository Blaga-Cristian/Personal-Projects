using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlTypes;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TestDB1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'scoalaDBDataSet.Elevi' table. You can move, or remove it, as needed.
            this.eleviTableAdapter.Fill(this.scoalaDBDataSet.Elevi);

        }

        private void btnAdauga_Click(object sender, EventArgs e)
        {
            string nume = txtNume.Text;
            string clasa = txtClasa.Text;
            float media = float.Parse(txtMedia.Text);
            DateTime dataNasterii = dtpDataN.Value;

            InsertElev(nume, clasa, media, dataNasterii);
        }

        private void InsertElev(string nume, string clasa, float media, DateTime dataNasterii)
        {
            eleviTableAdapter.InsertElev(nume, clasa, media, dataNasterii);
            eleviTableAdapter.Fill(scoalaDBDataSet.Elevi);
        }

        private void btnModifica_Click(object sender, EventArgs e)
        {
            int id = int.Parse(txtID.Text);
            string nume = txtNumeNou.Text;
            string clasa = txtClasaNou.Text;
            float media = float.Parse(txtMediaNou.Text);
            DateTime dataNasterii = dtpDataNou.Value;
            UpdateElev(id, nume, clasa, media, dataNasterii);

        }

        private void UpdateElev(int id, string nume, string clasa, float media, DateTime dataNasterii)
        {
            eleviTableAdapter.UpdateElev(nume, clasa, media, dataNasterii, id);
            eleviTableAdapter.Fill(scoalaDBDataSet.Elevi);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            eleviTableAdapter.DeleteElev(int.Parse(txtDel.Text));
            eleviTableAdapter.Fill(scoalaDBDataSet.Elevi);
        }
    }
}
