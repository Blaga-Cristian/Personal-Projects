using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Speech.Synthesis;

namespace SpeechSynthetizer
{
    public partial class Form1 : Form
    {
        Point poz;
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            var ss = new SpeechSynthesizer();
            ss.SpeakAsync(txt.Text);
            //ss.SetOutputToDefaultAudioDevice();
            //ss.SpeakAsync(txt.Text);
        }

        private void Form1_MouseEnter(object sender, EventArgs e)
        {
            //poz = MousePosition;   
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            //Cursor.Position = poz;
        }
    }
}
