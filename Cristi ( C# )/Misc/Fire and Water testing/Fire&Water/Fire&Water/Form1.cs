using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Fire_Water
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            fireboy = new Fireboy(35, 405);
            watergirl = new Watergirl(75, 405);
            obstacles = new List<Obstacle>
            {
                //new Obstacle(137, 411, 10, 10),
                //new Obstacle(205, 411, 10, 10),
                
                // Adaugă mai multe obstacole aici
            };
            diamonds = new List<Diamond>
            {
                new Diamond(137, 424, Brushes.Red),
                new Diamond(205, 424, Brushes.Red),

                new Diamond(133, 382, Brushes.LightSkyBlue),
                new Diamond(204, 378, Brushes.LightSkyBlue),

                new Diamond(457, 381, Brushes.Red),
                new Diamond(387, 381, Brushes.Red),

                new Diamond(457, 427, Brushes.LightSkyBlue),
                new Diamond(386, 427, Brushes.LightSkyBlue),

                new Diamond(457, 300, Brushes.Red),
                new Diamond(386, 300, Brushes.LightSkyBlue),

                new Diamond(247, 300, Brushes.Red),
                new Diamond(167, 300, Brushes.LightSkyBlue),

                new Diamond(303, 207, Brushes.Red),
                new Diamond(335, 207, Brushes.LightSkyBlue),

                new Diamond(295, 80, Brushes.Red),
                new Diamond(327, 80, Brushes.LightSkyBlue),
            };
            hazards = new List<Hazard>
            {
                new Hazard(125, 436, 100, 5, Brushes.Red), // Foc,et1
                new Hazard(125, 385, 100, 5, Brushes.Blue), // Apă,et1
                new Hazard(380, 385, 100, 5, Brushes.Red), // Foc,et1
                new Hazard(380, 436, 100, 5, Brushes.Blue), //Apa,et1
                new Hazard(378, 235, 100, 5, Brushes.Green), //Acid
                new Hazard(140, 235, 130, 5, Brushes.Green), //Acid
            };
            button = new Button(515, 295);
            button1 = new Button(95, 295);
            barrier = new Barrier(319, 253, 10, 60);
            // Inițializează pereții
            walls = new List<Rectangle>
            {
               new Rectangle(614, 0, 12, 500), //perete dreapta
               new Rectangle(0, 0, 20, 500),//perete stanga
               new Rectangle(0, 440, 650, 20),//jos
               new Rectangle(560, 400, 55, 50), //perete dreapta+
               new Rectangle(590, 370, 30, 30), //perete dreapta+
               new Rectangle(0, 0, 650, 20),//sus
               new Rectangle(0, 315, 550, 13),//etaj1
               new Rectangle(0, 315, 550, 13),//etaj1
               new Rectangle(0, 270, 70, 50),//etaj1+
               new Rectangle(99, 245, 549, 10),//etaj2
               new Rectangle(270, 223, 110, 30),//etaj2+
               new Rectangle(105, 235, 40, 15),//etaj2+
               new Rectangle(480, 235, 150, 15),//etaj2+
               new Rectangle(532, 190, 85, 60),//etaj2+
               new Rectangle(565, 140, 50, 60),//etaj2+
               new Rectangle(170, 200, 58, 10),//etaj2+
               new Rectangle(410, 205, 58, 10),//etaj2+
               new Rectangle(0, 85, 280, 17),//etaj3
               new Rectangle(359, 85, 120, 17),//etaj3
               new Rectangle(465, 115, 65, 17),//etaj3+
               new Rectangle(440, 100, 65, 17),//etaj3+
               new Rectangle(415, 85, 65, 17),//etaj3+
            };
            this.pictureBox1.Paint += new PaintEventHandler(this.pictureBox1_Paint);
            this.KeyDown += new KeyEventHandler(this.Form1_KeyDown);
            this.KeyUp += new KeyEventHandler(this.Form1_KeyUp);

            Timer timer = new Timer();
            timer.Interval = 50; // 50 ms
            timer.Tick += new EventHandler(this.timer1_Tick);
            timer.Start();
        }

        //Varaibila asta spune timer-ului sa astepte pana cand pozitiile sunt resetate
        //Timer-ul ar fi putut fi oprit daca ar fi fost declarat global
        private bool should_reset = false;

        private Fireboy fireboy;
        private Watergirl watergirl;
        private List<Obstacle> obstacles;
        private List<Diamond> diamonds;
        private List<Hazard> hazards;
        private Button button;
        private Button button1;
        private Barrier barrier;
        private List<Rectangle> walls;

        private bool fireboyMovingLeft, fireboyMovingRight;
        private bool watergirlMovingLeft, watergirlMovingRight;

        private bool isJumpingWatergirl = false;
        private int jumpSpeedWatergirl = 0;
        private int gravity = 2; // Gravitația
        private int jumpHeight = 25; // Înălțimea săriturii
        private bool isJumpingFireboy = false;
        private int jumpSpeedFireboy = 0;

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.A:
                    watergirlMovingLeft = true;
                    break;
                case Keys.D:
                    watergirlMovingRight = true;
                    break;
                case Keys.Left:
                    fireboyMovingLeft = true;
                    break;
                case Keys.Right:
                    fireboyMovingRight = true;
                    break;
                case Keys.W:
                    if (!isJumpingWatergirl)
                    {
                        isJumpingWatergirl = true;
                        jumpSpeedWatergirl = jumpHeight;
                    }
                    break;
                case Keys.Up:
                    if (!isJumpingFireboy)
                    {
                        isJumpingFireboy = true;
                        jumpSpeedFireboy = jumpHeight;
                    }
                    break;
            }
        }

        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.A:
                    watergirlMovingLeft = false;
                    break;
                case Keys.D:
                    watergirlMovingRight = false;
                    break;
                case Keys.Left:
                    fireboyMovingLeft = false;
                    break;
                case Keys.Right:
                    fireboyMovingRight = false;
                    break;
            }

        }

        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            fireboy.Draw(e.Graphics);
            watergirl.Draw(e.Graphics);
            foreach (var obstacle in obstacles) obstacle.Draw(e.Graphics);
            foreach (var diamond in diamonds) diamond.Draw(e.Graphics);
            foreach (var hazard in hazards) hazard.Draw(e.Graphics);
            button.Draw(e.Graphics);
            button1.Draw(e.Graphics);
            barrier?.Draw(e.Graphics);

            using (Brush wallBrush = new SolidBrush(Color.Transparent))
            {
                foreach (var wall in walls) e.Graphics.FillRectangle(wallBrush, wall);
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (should_reset) return;

            // Mișcarea laterală pentru watergirl
            MoveCharacter(watergirl, watergirlMovingLeft, watergirlMovingRight);

            // Mișcarea laterală pentru fireboy
            MoveCharacter(fireboy, fireboyMovingLeft, fireboyMovingRight);

            // Sărit pentru watergirl
            HandleJump(watergirl, ref isJumpingWatergirl, ref jumpSpeedWatergirl);

            // Sărit pentru fireboy
            HandleJump(fireboy, ref isJumpingFireboy, ref jumpSpeedFireboy);

            CheckCollisions(); // Verificăm coliziunile
            pictureBox1.Invalidate(); // Re-desenăm PictureBox-ul
        }
        private void HandleJump(Character character, ref bool isJumping, ref int jumpSpeed)
        {
            if (isJumping)
            {
                if (jumpSpeed > 0)
                {
                    if (CanMove(character, 0, -5)) character.MoveUp();
                    jumpSpeed -= gravity;
                }
                else
                {
                    isJumping = false;
                    jumpSpeed = jumpHeight; // Resetează viteza de sărit pentru următoarea săritură
                }
            }
            else
            {
                if (CanMove(character, 0, gravity)) character.MoveDown();
            }
        }
        private void MoveCharacter(Character character, bool movingLeft, bool movingRight)
        {
            if (movingLeft && CanMove(character, -5, 0)) character.MoveLeft();
            if (movingRight && CanMove(character, 5, 0)) character.MoveRight();
        }


        private bool CanMove(Character character, int offsetX, int offsetY)
        {
            Rectangle newBounds = new Rectangle(character.X + offsetX, character.Y + offsetY, 20, 20);

            // Verificăm coliziunea cu obstacolele
            foreach (var obstacle in obstacles)
            {
                if (newBounds.IntersectsWith(obstacle.GetBounds())) return false;
            }

            // Verificăm coliziunea cu hazardurile
            foreach (var hazard in hazards)
            {
                if (newBounds.IntersectsWith(hazard.GetBounds()))
                {
                    //Trebuie sa lasi personajul sa se intersecteze cu pericol pentru a putea muri
                    if (character is Fireboy && (hazard.Color == Brushes.Blue || hazard.Color == Brushes.Green)) return true;
                    if (character is Watergirl && (hazard.Color == Brushes.Red || hazard.Color == Brushes.Green)) return true;
                    return false; // Personajul nu poate trece peste pericole
                }
                //if (character is Fireboy && (hazard.Color == Brushes.Blue || hazard.Color == Brushes.Green) && newBounds.IntersectsWith(hazard.GetBounds())) return false;
                //if (character is Watergirl && (hazard.Color == Brushes.Red || hazard.Color == Brushes.Green) && newBounds.IntersectsWith(hazard.GetBounds())) return false;
            }

            // Verificăm coliziunea cu pereții
            foreach (var wall in walls)
            {
                if (newBounds.IntersectsWith(wall)) return false;
            }

            // Verificăm coliziunea cu bariera
            if (barrier != null && newBounds.IntersectsWith(barrier.GetBounds())) return false;

            // Verificăm dacă personajul nu depășește marginea stângă sau dreaptă a ecranului
            if (newBounds.Left < 0 || newBounds.Right > pictureBox1.Width)
            {
                return false;
            }

            return true;
        }

        private void CheckCollisions()
        {
            // Coliziunea cu diamantele
            for (int i = diamonds.Count - 1; i >= 0; i--)
            {
                if (diamonds[i].Color == Brushes.LightSkyBlue && watergirl.GetBounds().IntersectsWith(diamonds[i].GetBounds()))
                {
                    diamonds.RemoveAt(i); // Watergirl colectează diamantul albastru
                }
                else if (diamonds[i].Color == Brushes.Red && fireboy.GetBounds().IntersectsWith(diamonds[i].GetBounds()))
                {
                    diamonds.RemoveAt(i); // Fireboy colectează diamantul roșu
                }
            }

            // Verificare coliziuni cu hazardurile
            if (hazards.Any(hazard => fireboy.GetBounds().IntersectsWith(hazard.GetBounds()) && hazard.Color == Brushes.Blue) ||
                hazards.Any(hazard => fireboy.GetBounds().IntersectsWith(hazard.GetBounds()) && hazard.Color == Brushes.Green))
            {
                // Fireboy dies
                should_reset = true;
                MessageBox.Show("Fireboy died!");
                ResetCharacters(); // Reset position
            }

            if (hazards.Any(hazard => watergirl.GetBounds().IntersectsWith(hazard.GetBounds()) && hazard.Color == Brushes.Red) ||
                hazards.Any(hazard => watergirl.GetBounds().IntersectsWith(hazard.GetBounds()) && hazard.Color == Brushes.Green))
            {
                // Watergirl dies
                should_reset = true;
                MessageBox.Show("Watergirl died!");
                ResetCharacters(); // Reset position
            }

            pictureBox1.Invalidate(); // Force the pictureBox to redraw

            // Verificăm coliziunea cu butoanele
            bool isButtonPressed = button != null && (fireboy.GetBounds().IntersectsWith(button.GetBounds()) || watergirl.GetBounds().IntersectsWith(button.GetBounds()));
            bool isButton1Pressed = button1 != null && (fireboy.GetBounds().IntersectsWith(button1.GetBounds()) || watergirl.GetBounds().IntersectsWith(button1.GetBounds()));

            if (button != null)
            {
                button.IsPressed = isButtonPressed;
            }

            if (button1 != null)
            {
                button1.IsPressed = isButton1Pressed;
            }

            if (barrier != null)
            {
                barrier.IsOpen = isButtonPressed || isButton1Pressed;
            }

            // Actualizăm starea barierei
            if (barrier != null && barrier.IsOpen)
            {
                barrier = null; // Eliminăm bariera dacă este deschisă
            }
            else if (barrier == null && !(isButtonPressed || isButton1Pressed))
            {
                // Reinstate barrier if it's closed (assuming initial barrier position and size are known)
                barrier = new Barrier(319, 253, 10, 60);
            }

            pictureBox1.Invalidate(); // Re-desenăm PictureBox-ul
        }

        private void ResetCharacters()
        {
            fireboy.X = 35;
            fireboy.Y = 405;
            watergirl.X = 75;
            watergirl.Y = 405;
            should_reset = false;
        }
    }
}
