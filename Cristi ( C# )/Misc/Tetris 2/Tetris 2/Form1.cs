using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.OleDb;
using System.Diagnostics;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Tetris_2
{
    public partial class Form1 : Form
    {
        int cellwidth = 20, cellheight = 20;
        int offsetX = 3, offsetY = 0;

        Cell ulcorner;
        Random rand = new Random();
        int GAMESPEED = 400;
        Timer gameTimer = new Timer();

        bool collisionUp, collisionDown, collisionLeft, collisionRight;

        string currTetromino = "", nextTetromino = "";
        Cell[,] stationaryCells;
        List<Cell> currTetrominoCells = new List<Cell>();
        List<Cell> nextTetrominoCells = new List<Cell>();


        private static Color O_TetrominoColor = Color.Yellow;
        private static Color I_TetrominoColor = Color.Red;
        private static Color T_TetrominoColor = Color.Gold;
        private static Color S_TetrominoColor = Color.Violet;
        private static Color Z_TetrominoColor = Color.DeepSkyBlue;
        private static Color J_TetrominoColor = Color.Cyan;
        private static Color L_TetrominoColor = Color.LightSeaGreen;

        private static Color[] shapeColors = new Color[]
        {
            Color.Transparent,
            O_TetrominoColor,
            I_TetrominoColor,
            T_TetrominoColor,
            S_TetrominoColor,
            Z_TetrominoColor,
            J_TetrominoColor,
            L_TetrominoColor
        };

        private static string[] shapeNames = new string[]
        {
            "",
            "O_Tetromino",
            "I_Tetromino_0",
            "T_Tetromino_0",
            "S_Tetromino_0",
            "Z_Tetromino_0",
            "J_Tetromino_0",
            "L_Tetromino_0"
        };

        #region Tetrominos

        public int[,] O_Tetromino = new int[2, 2]
        {
            {1, 1 },
            {1, 1 }
        };

        public int[,] I_Tetromino_0 = new int[1, 4]
        {
            {1, 1, 1, 1 }
        };
        public int[,] I_Tetromino_90 = new int[4, 1]
        {
            {1 },
            {1 },
            {1 },
            {1 }
        };

        public int[,] T_Tetromino_0 = new int[2, 3]
        {
            {0, 1, 0 },
            {1, 1, 1 }
        };
        public int[,] T_Tetromino_90 = new int[3, 2]
        {
            {1, 0 },
            {1, 1 },
            {1, 0 }
        };
        public int[,] T_Tetromino_180 = new int[2, 3]
        {
            {1, 1, 1 },
            {0, 1, 0 }
        };
        public int[,] T_Tetromino_270 = new int[3, 2]
        {
            {0, 1 },
            {1, 1 },
            {0, 1 }
        };

        public int[,] S_Tetromino_0 = new int[2, 3]
        {
            {0, 1, 1 },
            {1, 1, 0 }
        };
        public int[,] S_Tetromino_90 = new int[3, 2]
        {
            {1, 0 },
            {1, 1 },
            {0, 1 }
        };

        public int[,] Z_Tetromino_0 = new int[2, 3]
        {
            {1, 1, 0 },
            {0, 1, 1 }
        };
        public int[,] Z_Tetromino_90 = new int[3, 2]
        {
            {0, 1 },
            {1, 1},
            {1, 0 }
        };

        public int[,] J_Tetromino_0 = new int[3, 2]
        {
            {0 , 1 },
            {0 , 1 },
            {1, 1 }
        };
        public int[,] J_Tetromino_90 = new int[2, 3]
        {
            {1, 0, 0 },
            {1, 1, 1 }
        };
        public int[,] J_Tetromino_180 = new int[3, 2]
        {
            {1, 1 },
            {1, 0 },
            {1, 0 }
        };
        public int[,] J_Tetromino_270 = new int[2, 3]
        {
            {1, 1, 1 },
            {0, 0, 1 }
        };

        public int[,] L_Tetromino_0 = new int[3, 2]
        {
            {1, 0 },
            {1, 0 },
            {1, 1 }
        };
        public int[,] L_Tetromino_90 = new int[2, 3]
        {
            {1, 1, 1 },
            {1, 0, 0 }
        };
        public int[,] L_Tetromino_180 = new int[3, 2]
        {
            {1, 1 },
            {0, 1 },
            {0, 1 }
        };
        public int[,] L_Tetromino_270 = new int[2, 3]
        {
            {0, 0 ,1 },
            {1, 1, 1 }
        };

        #endregion

        public Form1()
        {
            InitializeComponent();
            this.KeyPreview = true;
        }

        private void GameEvent(object sender, EventArgs e)
        {
            if(currTetromino == "")
            {
                SwapCurWithNext();
                GetNextTetromino();

                foreach(Cell c in currTetrominoCells)
                    if (stationaryCells[c.Col, c.Row].Color != Color.Transparent)
                    {
                        gameTimer.Stop();
                        gameTimer.Tick -= GameEvent;
                        MessageBox.Show("Jocul s-a terminat");
                        btnStart.Enabled = true;

                        return;
                    }
            }

            bool ok = false;
            foreach(Cell c in currTetrominoCells)
            {
                CheckCollision(c.Col, c.Row);
                if (collisionDown) ok = true;
            }

            if (ok)
            {
                foreach (Cell c in currTetrominoCells)
                    stationaryCells[c.Col, c.Row] = new Cell(c.Row, c.Col, c.Color);

                currTetromino = "";
                currTetrominoCells.Clear();
            }
            else
            {
                foreach (Cell c in currTetrominoCells)
                    c.Row++;
                ulcorner.Row++;
            }

            for (int y = 0; y < 20; ++y)
                if (ColCount(y) == 10)
                    Eliminare(y);

            pb.Invalidate();
        }

        private void Eliminare(int y)
        {
            for (int i = y; i > 0; --i)
                for (int x = 0; x < 10; ++x)
                {
                    stationaryCells[x, i] = stationaryCells[x, i - 1];
                    stationaryCells[x, i].Row++;
                }

            for (int x = 0; x < 10; ++x)
                stationaryCells[x, 0] = new Cell(0, x, Color.Transparent);
        }

        private int ColCount(int y)
        {
            int cnt = 0;
            for (int x = 0; x < 10; ++x)
                if (stationaryCells[x, y].Color != Color.Transparent)
                    cnt++;
            return cnt;
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (currTetromino == "") return;

            if(e.KeyCode == Keys.A)
            {
                bool ok = true;
                foreach(Cell c in currTetrominoCells)
                {
                    CheckCollision(c.Col, c.Row);
                    if (collisionLeft)
                        ok = false;
                }

                if (ok)
                {
                    foreach (Cell c in currTetrominoCells)
                        c.Col--;
                    ulcorner.Col--;
                }
            }
            else if (e.KeyCode == Keys.D)
            {
                bool ok = true;
                foreach (Cell c in currTetrominoCells)
                {
                    CheckCollision(c.Col, c.Row);
                    if (collisionRight)
                        ok = false;
                }

                if (ok)
                {
                    foreach (Cell c in currTetrominoCells)
                        c.Col++;
                    ulcorner.Col++;
                }
            }
            else if (e.KeyCode == Keys.S)
            {
                bool ok = true;
                foreach (Cell c in currTetrominoCells)
                {
                    CheckCollision(c.Col, c.Row);
                    if (collisionDown)
                        ok = false;
                }

                if (ok)
                {
                    foreach (Cell c in currTetrominoCells)
                        c.Row++;
                    ulcorner.Row++;
                }
            }

            pb.Invalidate();
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            if(btnStart.Text == "Start")
            {
                stationaryCells = new Cell[10, 20];
                for (int i = 0; i < 10; ++i)
                    for (int j = 0; j < 20; ++j)
                        stationaryCells[i, j] = new Cell(j, i, Color.Transparent);

                currTetromino = nextTetromino = "";
                currTetrominoCells.Clear();
                nextTetrominoCells.Clear();


                btnStart.Enabled = false;
                gameTimer.Interval = GAMESPEED;
                gameTimer.Tick += GameEvent;
                gameTimer.Start();
            }
        }

        private void pbNext_Paint(object sender, PaintEventArgs e)
        {
            foreach (Cell c in nextTetrominoCells)
                e.Graphics.FillRectangle(new SolidBrush(c.Color), new Rectangle(
                    c.Col * cellwidth, c.Row * cellheight, cellwidth, cellheight));
        }

        private void pb_Paint(object sender, PaintEventArgs e)
        {
            if (!gameTimer.Enabled) return;

            foreach (Cell c in currTetrominoCells)
                e.Graphics.FillRectangle(new SolidBrush(c.Color), new Rectangle(
                    c.Col * cellwidth, c.Row * cellheight, cellwidth, cellheight));

            for (int i = 0; i < 10; ++i)
                for(int j = 0; j < 20; ++j)
                    if (stationaryCells[i,j].Color != Color.Transparent)
                        e.Graphics.FillRectangle(new SolidBrush(stationaryCells[i, j].Color), new Rectangle(
                    stationaryCells[i, j].Col * cellwidth, stationaryCells[i, j].Row * cellheight, cellwidth, cellheight));

            pbNext.Invalidate();
        }

        private void CheckCollision(int col, int row)
        {
            collisionRight = collisionLeft = collisionDown = collisionUp = false;

            if (col == 0 || stationaryCells[col - 1, row].Color != Color.Transparent)
                collisionLeft = true;
            if (col == 9 || stationaryCells[col + 1, row].Color != Color.Transparent)
                collisionRight = true;
            if (row == 19 || stationaryCells[col, row + 1].Color != Color.Transparent)
                collisionDown = true;
            if (row == 0 || stationaryCells[col, row - 1].Color != Color.Transparent)
                collisionUp = true;
        }

        private void GetNextTetromino()
        {
            int id = rand.Next(1, 8);
            nextTetromino = shapeNames[id];
            nextTetrominoCells.Clear();

            int[,] arr = this.GetType().GetField(nextTetromino).GetValue(this) as int[,];

            for (int x = 0; x < arr.GetLength(0); ++x)
                for (int y = 0; y < arr.GetLength(1); ++y)
                    if (arr[x, y] == 1)
                        nextTetrominoCells.Add(new Cell(y, x, shapeColors[id]));
        }

        private void SwapCurWithNext()
        {
            currTetromino = nextTetromino;
            ulcorner = new Cell(offsetY, offsetX, Color.Transparent);
            currTetrominoCells.Clear();
            foreach (Cell c in nextTetrominoCells)
                currTetrominoCells.Add(new Cell(c.Row + offsetY, c.Col + offsetX, c.Color));
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            LinearGradientBrush lgb = new LinearGradientBrush(new Point(0, 0), new Point(0, ClientRectangle.Height), Color.DarkSlateBlue, Color.Blue);
            e.Graphics.FillRectangle(lgb, ClientRectangle);
        }

        protected override void OnMouseWheel(MouseEventArgs e)
        {
            if (currTetromino == "") return;

            int move = e.Delta / SystemInformation.MouseWheelScrollDelta;
            int angle = int.Parse(currTetromino.Split('_').Last());
            string[] s = currTetromino.Split('_');

            if (currTetromino == "O_Tetromino") return;

            if (move == 1)
            {
                angle += 90;
                if (currTetromino[0] == 'I' && angle > 90) angle = 0;
                if (currTetromino[0] == 'T' && angle > 270) angle = 0;
                if (currTetromino[0] == 'S' && angle > 90) angle = 0;
                if (currTetromino[0] == 'Z' && angle > 90) angle = 0;
                if (currTetromino[0] == 'J' && angle > 270) angle = 0;
                if (currTetromino[0] == 'L' && angle > 270) angle = 0;
            }    
            else
            {
                angle -= 90;
                if (currTetromino[0] == 'I' && angle < 0) angle = 90;
                if (currTetromino[0] == 'T' && angle < 0) angle = 270;
                if (currTetromino[0] == 'S' && angle < 0) angle = 90;
                if (currTetromino[0] == 'Z' && angle < 0) angle = 90;
                if (currTetromino[0] == 'J' && angle < 0) angle = 270;
                if (currTetromino[0] == 'L' && angle < 0) angle = 270;
            }


            string prefix = s[0] + '_' + s[1];

            string aux = prefix + '_' + angle;

            int[,] arr = this.GetType().GetField(prefix + '_' + angle).GetValue(this) as int[,];

            bool ok = true;
            for(int i = 0; i <  arr.GetLength(0); i++)
                for(int j = 0; j < arr.GetLength(1); ++j)
                    if(ulcorner.Row + i >= 20 || ulcorner.Col + j >= 10 || 
                        stationaryCells[ulcorner.Col + j, ulcorner.Row + i].Color != Color.Transparent)
                            ok = false;

            if(ok)
            {
                currTetromino = s[0] + '_' + s[1] + '_' + angle;
                Color col = currTetrominoCells[0].Color;
                currTetrominoCells.Clear();
                for (int i = 0; i < arr.GetLength(0); i++)
                    for (int j = 0; j < arr.GetLength(1); ++j)
                        if(arr[i,j] == 1)
                            currTetrominoCells.Add(new Cell(ulcorner.Row + i, ulcorner.Col + j, col));
            }

            pb.Invalidate();
        }
    }
}
