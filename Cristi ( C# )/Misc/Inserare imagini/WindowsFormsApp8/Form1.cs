using System;
using System.Data.SqlClient;
using System.Drawing;
using System.IO;
using System.Windows.Forms;

namespace WindowsFormsApp8
{
    public partial class Form1 : Form
    {
        private SqlConnection connection = new SqlConnection("Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=|DataDirectory|\\Database1.mdf;Integrated Security=True;");
        public Form1()
        {
            InitializeComponent();
        }
        private void ReloadData()
        {
            this.imagesTableAdapter.Fill(this.database1DataSet.Images);
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog dialog = new OpenFileDialog();
            dialog.Filter = "Image Files (*.jpg, *.jpeg, *.png, *.gif) | *.jpg; *.jpeg; *.png; *.gif";
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                string imagePath = dialog.FileName;
                Image img = Image.FromFile(imagePath);
                ImageConverter ic = new ImageConverter();
                var imageData = (byte[])ic.ConvertTo(img, typeof(byte[]));
                SqlCommand command = new SqlCommand("INSERT INTO Images (ImageData) VALUES (@ImageData)", connection);
                command.Parameters.AddWithValue("@ImageData", imageData);
                connection.Open();
                command.ExecuteNonQuery();
                connection.Close();
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'database1DataSet.Images' table. You can move, or remove it, as needed.
            this.imagesTableAdapter.Fill(this.database1DataSet.Images);
            ReloadData();
        }

     

        private void imagesBindingSource_CurrentChanged(object sender, EventArgs e)
        {

        }
        private void button2_Click(object sender, EventArgs e)
        {
            ReloadData();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (dataGridView1.CurrentRow != null)
            {
                int id = (int)dataGridView1.CurrentRow.Cells["idDataGridViewTextBoxColumn"].Value;
                SqlCommand command = new SqlCommand("SELECT ImageData FROM Images WHERE Id=@Id", connection);
                command.Parameters.AddWithValue("@Id", id);
                connection.Open();
                var rd = command.ExecuteReader();
                rd.Read();
                byte[] imageData = (byte[])rd[0];
                connection.Close();
                Image image = (Image)new ImageConverter().ConvertFrom(imageData);
                pictureBox1.Image = image;
            }
        }
    }
}
