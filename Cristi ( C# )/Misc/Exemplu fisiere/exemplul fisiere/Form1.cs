using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Runtime.InteropServices;
using System.Data.SqlClient;

namespace exemplul_fisiere
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            StreamReader sr = new StreamReader("meniu.txt");

            sr.ReadLine();
            string linie;
            int id, kcal, pret, felul;
            string denumire_produs, descriere;
            int i = 0;
            string aux = "";

            SqlConnection conn = new SqlConnection("Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\\Produse.mdf;Integrated Security=True");
            conn.Open();

           

            while ((linie = sr.ReadLine()) != null)
            {
                i = 0;
                aux = "";
                if (linie.Length < 1) break;
               // MessageBox.Show(linie);
                     //**** ICI SA EXTRAGEM ID
                     while (linie[i] != ';')
                     { aux = aux + linie[i]; i++; }
                     //MessageBox.Show(aux);

                     id = Int32.Parse(aux);


                     //**** ICI SA EXTRAGEM DENUMIRE PRODUS
                     aux = "";
                     i++;
                     while (linie[i] != ';')
                     { aux = aux + linie[i]; i++; }


                     denumire_produs = aux;
                    // MessageBox.Show("denumirea produsului " + denumire_produs);

                     //**** ICI SA EXTRAGEM DEscriere PRODUS adica RETETA
                     aux = "";
                     i++;
                     while (linie[i] != ';')
                     { aux = aux + linie[i]; i++; }


                     descriere = aux;
                     //MessageBox.Show("reteta secreta  " + descriere);

                     //******************************************************
                     //**** ICI SA EXTRAGEM PRET
                     aux = "";
                     i++;
                     while (linie[i] != ';')
                     { aux = aux + linie[i]; i++; }


                     pret = Convert.ToInt32(aux);
                     //MessageBox.Show("pretul " + aux);

                     //******************************************************
                     //**** ICI SA EXTRAGEM KCAL
                     aux = "";
                     i++;
                     while (linie[i] != ';')
                     { aux = aux + linie[i]; i++; }


                     kcal = Convert.ToInt32(aux);
                     //MessageBox.Show("Kcal   " + aux);

                     //******************************************************
                     //**** ICI SA EXTRAGEM si ii facem felul
                     aux = "";
                     i++;
                     while (linie[i] != ';')
                     { aux = aux + linie[i]; i++; }


                     felul = Convert.ToInt32(aux);
                // MessageBox.Show("felul " + aux);
                string commanda_insert = "insert into meniul(id_produs,denumire_produs,descriere,pret,kcal,felul) values(" + id.ToString() + ",'" + denumire_produs + "','" + descriere + "'," + pret.ToString() + "," + kcal.ToString() + "," + felul.ToString() + ");";

                SqlCommand comanda = new SqlCommand(commanda_insert, conn);
                comanda.ExecuteNonQuery();


            }
            conn.Close();
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}
