namespace WinFormsApp6
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        Form2 f = new Form2();
        private void button1_Click(object sender, EventArgs e)
        {

            f.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            f.valoarea = Int32.Parse(textBox1.Text);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            textBox2.Text = f.valoarea.ToString();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}