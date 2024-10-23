using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Tic_Tac_Toe
{
    public partial class Form1 : Form
    {
        Player currentPlayer;
        Timer aiTimer = new Timer();
        bool canClick = true;
        public Form1()
        {
            InitializeComponent();
            resetGame(new object(), new EventArgs());
            aiTimer.Interval = 1000;
            aiTimer.Tick += AiMove;
        }

        private void AiMove(object sender, EventArgs e)
        {
            string txt = Player.O.ToString();
            foreach(Button x in this.Controls.OfType<Button>())
                if(x.Enabled == true && x.Tag == "Play")
                {
                    x.Enabled = false;
                    x.Text = Player.O.ToString();
                    x.BackColor = Color.Red;
                    if(Wins(Player.O.ToString()))
                    {
                        WON();
                        lbl1.Text = "O wins";
                        aiTimer.Stop();
                    }
                    aiTimer.Stop();
                    break;
                }

            canClick = true;
        }

        private void resetGame(object sender, EventArgs e)
        {
            foreach(Button x in this.Controls.OfType<Button>())
                if(x.Tag == "Play")
                {
                    x.Enabled = true;
                    x.Text = "?";
                    x.BackColor = Color.Gray;
                }
            lbl1.Text = "??";
            canClick = true;
        }

        public enum Player { X, O };
        private void buttonClick(object sender, MouseEventArgs e)
        {
            if (!canClick) return;
            var btn = (Button)sender;
            string txt = currentPlayer.ToString();
            btn.Text = txt;
            btn.BackColor = Color.Green;
            btn.Enabled = false;
            canClick = false;
            if(Wins(txt))
            {
                WON();
                lbl1.Text = "X wins";
                aiTimer.Stop();
                return;
            }
            aiTimer.Start();
        }

        private void WON()
        {
            foreach(Button x in this.Controls.OfType<Button>())
            {
                if (x.Tag != "Play") continue;
                x.Enabled = false;
                x.BackColor = default(Color);
            }
        }

        private bool Wins(string txt)
        {
            if ((btn1.Text == txt && btn2.Text == txt && btn3.Text == txt) ||
                (btn1.Text == txt && btn5.Text == txt && btn9.Text == txt) ||
                (btn4.Text == txt && btn5.Text == txt && btn6.Text == txt) ||
                (btn7.Text == txt && btn8.Text == txt && btn9.Text == txt) ||
                (btn7.Text == txt && btn5.Text == txt && btn3.Text == txt) ||
                (btn1.Text == txt && btn4.Text == txt && btn7.Text == txt) ||
                (btn2.Text == txt && btn5.Text == txt && btn8.Text == txt) ||
                (btn3.Text == txt && btn6.Text == txt && btn9.Text == txt))
                return true;
            return false;
        }
    }
}
