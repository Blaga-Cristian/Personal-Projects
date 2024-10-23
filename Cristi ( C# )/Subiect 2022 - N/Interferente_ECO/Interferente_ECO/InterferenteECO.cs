using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Interferente_ECO
{
    public partial class InterferenteECO : Form
    {
        private static string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\OTI_2022_C#_resurse\";
        int deflector = 1;
        bool started = false;
        bool selectDeflector;
        int[] dx = { -1, 0, 1, 0 }, dy = { 0, 1, 0, -1 };
        static int up = 0, right = 1, down = 2, left = 3;
        int dir = up;
        double w, h;
        bool lines = false;
        int cnt = 0;
        Point[] deflectors = new Point[]
        {
            new Point(60, 100),
            new Point(110, 100),
            new Point(110, 150),
            new Point(60, 150)
        };
        private Image img;
        List<Item> itemi = new List<Item>();
        Item probot = new Item("", -1, -1);
        int colinitial = -1, rowinitial = -1;

        int[][] matmeduze = new int[10][];
        int[][] matdef = new int[10][];
        int[][] matreciclare = new int[10][];
        int[][] lee = new int[10][];
        int[,] viz;
        int ind = 0;
        List<int> steps = new List<int>();
        Timer timer = new Timer();
        int dur = 1000;
        PointF pozr = new PointF( -100, -100 );
        Image imgRobot = Image.FromFile(respath + $@"Robot\Robot.png");
        Image[] images = new Image[]
        {
            Image.FromFile(respath + $@"Meduze\Meduza1.png"),
            Image.FromFile(respath + $@"Meduze\Meduza2.png"),
            Image.FromFile(respath + $@"Meduze\Meduza3.png"),
            Image.FromFile(respath + $@"Meduze\Meduza4.png"),
            Image.FromFile(respath + $@"MaterialeReciclabile\Hartie.png"),
            Image.FromFile(respath + $@"MaterialeReciclabile\Plastic.png"),
            Image.FromFile(respath + $@"MaterialeReciclabile\Sticla.png")
        };
        int cntHartie, cntPlastic, cntSticla;
        int cntReciclabile;
        int cntReciclabiletot;
        bool doingLee = false;

        int[][][] D;
        List<Item> reciclabile;

        int cntimg = 0;
        Timer screenShotTimer = new Timer();
        Bitmap[] saved;


        public InterferenteECO(Image img)
        {
            this.img = img;
            this.DoubleBuffered = true;
            InitializeComponent();
            this.SetStyle(ControlStyles.OptimizedDoubleBuffer | ControlStyles.DoubleBuffer | ControlStyles.UserPaint | ControlStyles.AllPaintingInWmPaint, true);
            IncarcaSplit();
            Imat();
            InitMat();
            SetLabels();
            SetSavedImg();
        }

        private void SetSavedImg()
        {
            saved = new Bitmap[5];
            for (int i = 0; i < 5; ++i)
                saved[i] = new Bitmap(pb.Image, pb.Size);
        }

        private void SetLabels()
        {
            lblHartie.Text = "Hartie: " + cntHartie;
            lblPlastic.Text = "Plastic: " + cntPlastic;
            lblSticle.Text = "Sticle: " + cntSticla;
        }

        private void Imat()
        {
            for (int i = 0; i < 10; ++i)
                matmeduze[i] = new int[20];
            for (int i = 0; i < 10; ++i)
                matdef[i] = new int[20];
            for (int i = 0; i < 10; ++i)
                matreciclare[i] = new int[20];
        }

        private void InitMat()
        {
            for (int i = 0; i < 10; ++i)
                for (int j = 0; j < 20; ++j)
                    matmeduze[i][j] = 0;
            for (int i = 0; i < 10; ++i)
                for (int j = 0; j < 20; ++j)
                    matdef[i][j] = 0;
            for (int i = 0; i < 10; ++i)
                for (int j = 0; j < 20; ++j)
                    matreciclare[i][j] = 0;
        }

        private void IncarcaSplit()
        {
            splitContainer1.IsSplitterFixed = true;
            splitContainer1.Panel2.BackgroundImage = Image.FromFile(respath + $@"Wood\Wood1.jpg");
            splitContainer1.Panel1.BackgroundImage = img;
            splitContainer1.Panel1.BackgroundImageLayout = ImageLayout.Stretch;
            w = splitContainer1.Panel1.ClientSize.Width / 20.0;
            h = splitContainer1.Panel1.ClientSize.Height / 10.0;
            pb.Image = img;
            pb.SizeMode = PictureBoxSizeMode.StretchImage;
        }

        private void splitContainer1_Panel2_MouseClick(object sender, MouseEventArgs e)
        {
            int X = e.Location.X;
            int Y = e.Location.Y;
            selectDeflector = (X >= 60 && X <= 110 && Y >= 100 && Y <= 150);
            splitContainer1.Panel2.Invalidate();
        }

        private void btnRoteste_Click(object sender, EventArgs e)
        {
            deflector = deflector % 4 + 1;
            splitContainer1.Panel2.Invalidate();
        }

        private void chk_CheckedChanged(object sender, EventArgs e)
        {
            lines = ((CheckBox)sender).Checked;
            pb.Invalidate();
        }

        private void DrawLines(PaintEventArgs e)
        {
            var graphics = e.Graphics;
            for (int i = 0; i < 20; ++i)
                graphics.DrawLine(Pens.White, new PointF((float)w * i, 0), new PointF((float)w * i, 900));
            for (int i = 0; i < 10; ++i)
                graphics.DrawLine(Pens.White, new PointF(0, (float)h * i), new PointF(900, (float)h * i));
        }

        private void pb_Paint(object sender, PaintEventArgs e)
        {
            InitMat();

            if (lines)
                DrawLines(e);



            foreach (var x in itemi)
                if (x.Tip == "path")
                    e.Graphics.FillRectangle(Brushes.Blue, new RectangleF((float)w * x.Col, (float)h * x.Row, (float)w, (float)h));

            
            e.Graphics.FillRectangle(Brushes.Red, new RectangleF((float)w * colinitial, (float)h * rowinitial, (float)w, (float)h));

            foreach (var x in itemi)
            {
                if (x.Tip == "path") continue;
                if (x.Tip == "deflector1" || x.Tip == "deflector2" || x.Tip == "deflector3" || x.Tip == "deflector4")
                {
                    int nr = int.Parse(x.Tip.Substring(9, 1));
                    int r = x.Row, c = x.Col;
                    matdef[r][c] = nr;
                    DrawDeflector(x, e);
                    continue;
                }



                int col = x.Col;
                int row = x.Row;
                if (x.Tip == "Robot")
                {
                    if (!started)
                    {
                        probot = new Item(x.Tip, x.Col - 1, x.Row - 1);
                        colinitial = x.Col - 1;
                        rowinitial = x.Row - 1;
                        pozr = new PointF((float)((x.Col - 1)* w), (float)((x.Row - 1) * h));
                    }
                    continue;
                }
                if (x.Tip == "Meduza1")
                {
                    e.Graphics.DrawImage(images[0], new RectangleF((float)w * (col - 1), (float)h * (row - 1), (float)w, (float)h), new Rectangle(0, 0, images[0].Size.Width, images[0].Size.Height), GraphicsUnit.Pixel);
                    matmeduze[x.Row - 1][x.Col - 1] = 1;
                }
                if (x.Tip == "Meduza2")
                {
                    e.Graphics.DrawImage(images[1], new RectangleF((float)w * (col - 1), (float)h * (row - 1), (float)w, (float)h), new Rectangle(0, 0, images[1].Size.Width, images[1].Size.Height), GraphicsUnit.Pixel);
                    matmeduze[x.Row - 1][x.Col - 1] = 1;
                }
                if (x.Tip == "Meduza3")
                {
                    e.Graphics.DrawImage(images[2], new RectangleF((float)w * (col - 1), (float)h * (row - 1), (float)w, (float)h), new Rectangle(0, 0, images[2].Size.Width, images[2].Size.Height), GraphicsUnit.Pixel);
                    matmeduze[x.Row - 1][x.Col - 1] = 1;
                }
                if (x.Tip == "Meduza4")
                {
                    e.Graphics.DrawImage(images[3], new RectangleF((float)w * (col - 1), (float)h * (row - 1), (float)w, (float)h), new Rectangle(0, 0, images[3].Size.Width, images[3].Size.Height), GraphicsUnit.Pixel);
                    matmeduze[x.Row - 1][x.Col - 1] = 1;
                }
                if (x.Tip == "Hartie")
                {
                    e.Graphics.DrawImage(images[4], new RectangleF((float)w * (col - 1), (float)h * (row - 1), (float)w, (float)h), new Rectangle(0, 0, images[4].Size.Width, images[4].Size.Height), GraphicsUnit.Pixel);
                    matreciclare[x.Row - 1][x.Col - 1] = 1;
                }
                if (x.Tip == "Plastic")
                {
                    e.Graphics.DrawImage(images[5], new RectangleF((float)w * (col - 1), (float)h * (row - 1), (float)w, (float)h), new Rectangle(0, 0, images[5].Size.Width, images[5].Size.Height), GraphicsUnit.Pixel);
                    matreciclare[x.Row - 1][x.Col - 1] = 2;
                }
                if (x.Tip == "Sticla")
                {
                    e.Graphics.DrawImage(images[6], new RectangleF((float)w * (col - 1), (float)h * (row - 1), (float)w, (float)h), new Rectangle(0, 0, images[6].Size.Width, images[6].Size.Height), GraphicsUnit.Pixel);
                    matreciclare[x.Row - 1][x.Col - 1] = 3;
                }
            }

            e.Graphics.DrawImage(imgRobot, new RectangleF(pozr.X, pozr.Y, (float)w, (float)h), new Rectangle(0, 0, imgRobot.Size.Width, imgRobot.Size.Height), GraphicsUnit.Pixel);
        }

        private void DrawDeflector(Item x, PaintEventArgs e)
        {
            int row = x.Row;
            int col = x.Col;

            PointF[] p = new PointF[4];
            for (int i = row; i <= row + 1; ++i)
                for (int j = col; j <= col + 1; ++j)
                    p[2 * (i - row) + (j - col)] = new PointF((float)(j * w), (float)(i * h));

            PointF[] draw = new PointF[3];
            if (x.Tip == "deflector1")
                draw = new PointF[] { p[0], p[1], p[2] };
            if (x.Tip == "deflector2")
                draw = new PointF[] { p[0], p[1], p[3] };
            if (x.Tip == "deflector3")
                draw = new PointF[] { p[1], p[2], p[3] };
            if (x.Tip == "deflector4")
                draw = new PointF[] { p[0], p[2], p[3] };

            e.Graphics.DrawPolygon(Pens.White, draw);
            e.Graphics.FillPolygon(Brushes.White, draw);
        }

        private void btnLoad_Click(object sender, EventArgs e)
        {
            var ofd = new OpenFileDialog();
            ofd.Filter = "Fisiere text (*.txt)|*.txt";
            if (ofd.ShowDialog() == DialogResult.OK)
                DrawHarta(ofd.FileName);
        }

        private void DrawHarta(string fileName)
        {
            itemi.Clear();
            probot = new Item("", -1, -1);
            colinitial = -1;
            rowinitial = -1;

            var sr = new StreamReader(fileName);
            string line;
            string[] s;
            char[] sep = { ' ' };

            while((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                string tip = s[0];
                int col = int.Parse(s[1]);
                int row = int.Parse(s[2]);
                itemi.Add(new Item(tip, col, row));
                if (tip == "Hartie" || tip == "Sticla" || tip == "Plastic")
                    cntReciclabiletot++;
            }

            pb.Invalidate();
        }

        private void btnGen_Click(object sender, EventArgs e)
        {
            viz = new int[10, 20];
            int[][] d = new int[10][];
            for (int i = 0; i < 10; ++i)
                d[i] = new int[20];

            for (int i = 0; i < 10; ++i)
                for (int j = 0; j < 20; ++j)
                    if (matmeduze[i][j] != 0)
                        d[i][j] = -7;

            Bfs(rowinitial, colinitial, d);

            reciclabile = new List<Item>();
            for (int i = 0; i < 10; ++i)
                for (int j = 0; j < 20; ++j)
                    if (matreciclare[i][j] != 0)
                        reciclabile.Add(new Item("", j, i));

            reciclabile.Sort((a, b) => d[a.Row][a.Col].CompareTo(d[b.Row][b.Col]));

            D = new int[reciclabile.Count + 2][][];
            for (int i = 0; i < reciclabile.Count; ++i)
            {
                D[i] = new int[10][];
                for (int j = 0; j < 10; ++j)
                    D[i][j] = new int[20];
            }

            for (int k = 0; k < reciclabile.Count; ++k)
                for (int i = 0; i < 10; ++i)
                    for (int j = 0; j < 20; ++j)
                        if (matmeduze[i][j] != 0)
                            D[k][i][j] = -8;

            for (int i = 0; i < reciclabile.Count; ++i)
                Bfs(reciclabile[i].Row, reciclabile[i].Col, D[i]);

            reciclabile.Sort((a, b) => d[a.Row][a.Col].CompareTo(d[b.Row][b.Col]));

            for (int i = 0; i < reciclabile.Count; ++i)
            {
                Console.Write($"{reciclabile[i].Row} {reciclabile[i].Col} \n");
                for (int j = 0; j < 10; ++j, Console.WriteLine())
                    for (int k = 0; k < 20; ++k)
                        Console.Write(D[i][j][k] + " ");

                Console.WriteLine();
                Console.WriteLine();
            }

            var frm = new SelectDirection();
            frm.ShowDialog();
            int direction = frm.Dir;

            int idx = 0, prvidx = 0;
            int ndirection = PutDeflectors(probot.Row, probot.Col, reciclabile[0].Row, reciclabile[0].Col, direction, 0).Value;
            viz[reciclabile[0].Row, reciclabile[0].Col] = 1;

            for (int i = 1; i < reciclabile.Count; ++i)
            {
                idx = NextI(idx);
                ndirection = PutDeflectors(reciclabile[prvidx].Row, reciclabile[prvidx].Col, reciclabile[idx].Row, reciclabile[idx].Col, ndirection, idx).Value;
                prvidx = idx;
            }
            pb.Invalidate();
        }


        private int NextI(int idx)
        {
            int min = 99999;
            int nxt = -1;
            for (int i = 0; i < reciclabile.Count; ++i)
                if (viz[reciclabile[i].Row, reciclabile[i].Col] == 0 && D[idx][reciclabile[i].Row][reciclabile[i].Col] < min)
                {
                    min = D[idx][reciclabile[i].Row][reciclabile[i].Col];
                    nxt = i;
                }

            viz[reciclabile[nxt].Row, reciclabile[nxt].Col] = 1;
            return nxt;
        }


        private KeyValuePair<bool,int> PutDeflectors(int i, int j, int row, int col, int dir, int ind)
        {
            if(!InMat(i,j) || matmeduze[i][j] != 0)return new KeyValuePair<bool, int>(false, -9);
            if (i == row && j == col) return new KeyValuePair<bool, int>(true, dir);

            viz[i, j] = 1;

            dir = HitDeflector(dir, i, j);

            int nx = i + dx[dir];
            int ny = j + dy[dir];


            int auxdir = dir;
            int auxnx = nx;
            int auxny = ny;


            if (matdef[i][j] != 0 && (D[ind][i][j] != D[ind][nx][ny] + 1 || !InMat(nx,ny) || viz[nx,ny] == 1 || matmeduze[nx][ny] != 0))
                return new KeyValuePair<bool, int>(false, -9);
            else if ((viz[nx,ny] == 1 || !InMat(nx,ny) || D[ind][i][j] != D[ind][nx][ny] + 1 || matmeduze[nx][ny] != 0) && matdef[i][j] == 0)
            {
                if (dir == left)
                {
                    //Deflector de tip 1
                    matdef[i][j] = 1;
                    nx = i + dx[down];
                    ny = j + dy[down];
                    if (InMat(nx, ny) && matmeduze[nx][ny] == 0 && D[ind][i][j] == D[ind][nx][ny] + 1)
                    {
                        itemi.Add(new Item("deflector1", j, i));
                        return PutDeflectors(nx, ny, row, col, down, ind);
                    }
                    matdef[i][j] = 0;

                    //Deflector de tip 4
                    matdef[i][j] = 4;
                    nx = i + dx[up];
                    ny = j + dy[up];
                    if (InMat(nx, ny) && matmeduze[nx][ny] == 0 && D[ind][i][j] == D[ind][nx][ny] + 1)
                    {
                        itemi.Add(new Item("deflector4", j, i));
                        return PutDeflectors(nx, ny, row, col, up, ind);
                    }
                    matdef[i][j] = 0;
                }
                else if (dir == up)
                {
                    //Deflector de tip 1
                    matdef[i][j] = 1;
                    nx = i + dx[right];
                    ny = j + dy[right];
                    if (InMat(nx, ny) && matmeduze[nx][ny] == 0 && D[ind][i][j] == D[ind][nx][ny] + 1)
                    {
                        itemi.Add(new Item("deflector1", j, i));
                        return PutDeflectors(nx, ny, row, col, right, ind);
                    }
                    matdef[i][j] = 0;

                    //Deflector de tip 2
                    matdef[i][j] = 2;
                    nx = i + dx[left];
                    ny = j + dy[left];
                    if (InMat(nx, ny) && matmeduze[nx][ny] == 0 && D[ind][i][j] == D[ind][nx][ny] + 1)
                    {
                        itemi.Add(new Item("deflector2", j, i));
                        return PutDeflectors(nx, ny, row, col, left, ind);
                    }
                    matdef[i][j] = 0;
                }
                else if (dir == right)
                {
                    //Deflector de tip 2
                    matdef[i][j] = 2;
                    nx = i + dx[down];
                    ny = j + dy[down];
                    if (InMat(nx, ny) && matmeduze[nx][ny] == 0 && D[ind][i][j] == D[ind][nx][ny] + 1)
                    {
                        itemi.Add(new Item("deflector2", j, i));
                        return PutDeflectors(nx, ny, row, col, down, ind);
                    }
                    matdef[i][j] = 0;

                    //Deflector de tip 3
                    matdef[i][j] = 3;
                    nx = i + dx[up];
                    ny = j + dy[up];
                    if (InMat(nx, ny) && matmeduze[nx][ny] == 0 && D[ind][i][j] == D[ind][nx][ny] + 1)
                    {
                        itemi.Add(new Item("deflector3", j, i));
                        return PutDeflectors(nx, ny, row, col, up, ind);
                    }
                    matdef[i][j] = 0;
                }
                else if (dir == down)
                {
                    //Deflector de tip 3
                    matdef[i][j] = 3;
                    nx = i + dx[left];
                    ny = j + dy[left];
                    if (InMat(nx, ny) && matmeduze[nx][ny] == 0 && D[ind][i][j] == D[ind][nx][ny] + 1)
                    {
                        itemi.Add(new Item("deflector3", j, i));
                        return PutDeflectors(nx, ny, row, col, left, ind);
                    }
                    matdef[i][j] = 0;

                    //Deflector de tip 4
                    matdef[i][j] = 4;
                    nx = i + dx[right];
                    ny = j + dy[right];
                    if (InMat(nx, ny) && matmeduze[nx][ny] == 0 && D[ind][i][j] == D[ind][nx][ny] + 1)
                    {
                        itemi.Add(new Item("deflector4", j, i));
                        return PutDeflectors(nx, ny, row, col, right, ind);
                    }
                    matdef[i][j] = 0;
                }
            }

            return PutDeflectors(auxnx, auxny, row, col, auxdir, ind);
        }

        private int HitDeflector(int dir, int i, int j)
        {
            if (matdef[i][j] == 1)
            {
                if (dir == left)
                    dir = down;
                else
                    dir = right;
            }
            else if (matdef[i][j] == 2)
            {
                if (dir == right)
                    dir = down;
                else
                    dir = left;
            }
            else if (matdef[i][j] == 3)
            {
                if (dir == right)
                    dir = up;
                else
                    dir = left;
            }
            else if (matdef[i][j] == 4)
            {
                if (dir == left)
                    dir = up;
                else
                    dir = right;
            }


            return dir;
        }

        private void Bfs(int i, int j, int[][] d)
        {
            Queue<KeyValuePair<int,int> > q = new Queue<KeyValuePair<int,int>>();
            q.Enqueue(new KeyValuePair<int, int>(i, j));

            while(q.Count != 0)
            {
                var it = q.Dequeue();

                for(int k = 0; k < 4; ++k)
                {
                    int nx = it.Key + dx[k];
                    int ny = it.Value + dy[k];

                    if (InMat(nx, ny) && matmeduze[nx][ny] == 0 && d[nx][ny] == 0)
                    {
                        d[nx][ny] = d[it.Key][it.Value] + 1;
                        q.Enqueue(new KeyValuePair<int, int>(nx, ny));
                    }
                }
            }

            d[i][j] = 0;
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            btnStart.Text = "Start";
            timer.Stop();
            timer.Tick -= OnTimerTick;
            timer.Tick -= SmallMove;

            screenShotTimer.Stop();
            screenShotTimer.Tick -= ScreenShot;
            cntimg = 0;

            pozr = new PointF(-100, -100);
            probot = new Item("", -1, -1);
            colinitial = -1;
            rowinitial = -1;
            started = false;
            itemi.Clear();
            InitMat();

            for (int i = 0; i < 10; ++i)
                for (int j = 0; j < 20; ++j)
                    matmeduze[i][j] = matdef[i][j] = matreciclare[i][j] = 0;

            pb.Invalidate();
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            var sfd = new SaveFileDialog();
            if (sfd.ShowDialog() != DialogResult.OK) return;
            string path = sfd.FileName;
            for (int i = 0; i < 5; ++i)
                saved[i].Save(path + (i + 1) + ".png", ImageFormat.Png);
        }

        private void btnRestart_Click(object sender, EventArgs e)
        {
            btnStart.Text = "Start";
            timer.Stop();
            timer.Tick -= OnTimerTick;
            timer.Tick -= SmallMove;

            screenShotTimer.Stop();
            screenShotTimer.Tick -= ScreenShot;
            cntimg = 0;

            started = false;
            List<Item> remove = new List<Item>();
            foreach (Item x in itemi)
                if (x.Tip == "path")
                    remove.Add(x);
            foreach (Item x in remove)
                itemi.Remove(x);

            pb.Invalidate();
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            if (btnStart.Text == "Start")
            {
                btnStart.Text = "Stop";
                if (!started)
                {
                    var frm = new SelectDirection();
                    frm.ShowDialog();
                    dir = frm.Dir;
                }
                started = true;
                timer.Interval = dur / 10;
                timer.Tick += OnTimerTick;
                timer.Tick += SmallMove;
                timer.Start();

                pb.DrawToBitmap(saved[cntimg++], pb.ClientRectangle);
                screenShotTimer.Interval = 3000;
                screenShotTimer.Tick += ScreenShot;
                screenShotTimer.Start();
            }
            else
            {
                btnStart.Text = "Start";
                timer.Stop();
                timer.Tick -= OnTimerTick;
                timer.Tick -= SmallMove;

                screenShotTimer.Stop();
                screenShotTimer.Tick -= ScreenShot;
            }
        }

        private void ScreenShot(object sender, EventArgs e)
        {
            if(cntimg < 4)
                pb.DrawToBitmap(saved[cntimg++], pb.ClientRectangle);
        }

        private void OnTimerTick(object sender, EventArgs e)
        {
            if (cnt != 10) return;
            cnt = 0;

            probot.Row = probot.Row + dx[dir];
            probot.Col = probot.Col + dy[dir];

            if (matmeduze[probot.Row][probot.Col] == 1)
            {
                btnRestart_Click(new object(), new EventArgs());
                MessageBox.Show("Jocul s-a terminat", "Game Over", MessageBoxButtons.OK);
                return;
            }

            itemi.Add(new Item("path", probot.Col, probot.Row));

            if (matreciclare[probot.Row][probot.Col] == 1)
            {
                cntHartie++;
                cntReciclabile++;
                for (int i = 0; i < itemi.Count; ++i)
                    if (itemi[i].Tip == "Hartie" && itemi[i].Col == probot.Col + 1 && itemi[i].Row == probot.Row + 1)
                    {
                        itemi.RemoveAt(i);
                        break;
                    }
            }
            if (matreciclare[probot.Row][probot.Col] == 2)
            {
                cntPlastic++;
                cntReciclabile++;
                for (int i = 0; i < itemi.Count; ++i)
                    if (itemi[i].Tip == "Plastic" && itemi[i].Col == probot.Col + 1 && itemi[i].Row == probot.Row + 1)
                    {
                        itemi.RemoveAt(i);
                        break;
                    }
            }
            if (matreciclare[probot.Row][probot.Col] == 3)
            {
                cntSticla++;
                cntReciclabile++;
                for(int i = 0; i < itemi.Count; ++i)
                    if (itemi[i].Tip == "Sticla" && itemi[i].Col == probot.Col + 1 && itemi[i].Row == probot.Row + 1)
                    {
                        itemi.RemoveAt(i);
                        break;
                    }
            }
            SetLabels();

            

            if (cntReciclabile == cntReciclabiletot && !doingLee)
            {
                DoLee();
            }

            if (doingLee)
            {
                if (ind == steps.Count)
                {
                    pb.DrawToBitmap(saved[4], pb.ClientRectangle);
                    btnStart_Click(new object(), new EventArgs());
                    started = false;
                    return;
                }
                dir = steps[ind];
                pozr.X = (float)(probot.Col * w);
                pozr.Y = (float)(probot.Row * h);
                ind++;
                return;
            }


            if (matdef[probot.Row][probot.Col] == 1)
            {
                if (dir == left)
                    dir = down;
                else
                    dir = right;
            }
            else if (matdef[probot.Row][probot.Col] == 2)
            {
                if (dir == right)
                    dir = down;
                else
                    dir = left;
            }
            else if (matdef[probot.Row][probot.Col] == 3)
            {
                if (dir == right)
                    dir = up;
                else
                    dir = left;
            }
            else if (matdef[probot.Row][probot.Col] == 4)
            {
                if (dir == left)
                    dir = up;
                else
                    dir = right;
            }

            int nrow = probot.Row + dx[dir];
            int ncol = probot.Col + dy[dir];

            if(nrow < 0 || nrow >= 10 || ncol < 0 || ncol >= 20 ||
                (dir == up && (matdef[nrow][ncol] == 3 || matdef[nrow][ncol] == 4)) ||
                (dir == right && (matdef[nrow][ncol] == 1 || matdef[nrow][ncol] == 4)) ||
                (dir == down && (matdef[nrow][ncol] == 1 || matdef[nrow][ncol] == 2)) ||
                (dir == left && (matdef[nrow][ncol] == 2 || matdef[nrow][ncol] == 3)))
            {
                dir = (dir + 2) % 4;
                nrow = probot.Row + dx[dir];
                ncol = probot.Col + dy[dir];
            }

            pozr.X = (float)(probot.Col * w);
            pozr.Y = (float)(probot.Row * h);
        }

        private void DoLee()
        {
            steps.Clear();
            ind = 0;

            for (int i = 0; i < 10; ++i)
                lee[i] = new int[20];

            int x = probot.Row, y = probot.Col;
            Queue<Item> q = new Queue<Item>();
            q.Enqueue(new Item("", y, x));

            while(q.Count != 0)
            {
                var it = q.Dequeue();
                x = it.Row;
                y = it.Col;
                for(int k = 0; k < 4; ++k)
                {
                    int nx = it.Row + dx[k];
                    int ny = it.Col + dy[k];
                    if(InMat(nx, ny) && lee[nx][ny] == 0 && matdef[nx][ny] == 0 && matmeduze[nx][ny] == 0)
                    {
                        lee[nx][ny] = lee[x][y] + 1;
                        q.Enqueue(new Item("", ny, nx));
                    }
                }
            }

            lee[probot.Row][probot.Col] = 0;
            int rowi = rowinitial;
            int coli = colinitial;
            while(true)
            {
                for (int k = 0; k < 4; ++k)
                {
                    int px = rowi - dx[k];
                    int py = coli - dy[k];
                    if (InMat(px, py) && lee[px][py] == lee[rowi][coli] - 1 && matdef[px][py] == 0 && matmeduze[px][py] == 0)
                    {
                        steps.Add(k);
                        rowi = px;
                        coli = py;
                        break;
                    }
                }
                if (rowi == probot.Row && coli == probot.Col)
                    break;
            }

            steps.Reverse();
            doingLee = true;
        }

        private bool InMat(int nx, int ny)
        {
            return (nx >= 0 && nx < 10 && ny >= 0 && ny < 20);
        }

        private void SmallMove(object sender, EventArgs e)
        {
            cnt++;
            int nrow = probot.Row + dx[dir];
            int ncol = probot.Col + dy[dir];
            pozr.X = (float)(probot.Col * w + (ncol - probot.Col) * w * cnt / 10);
            pozr.Y = (float)(probot.Row * h + (nrow - probot.Row) * h * cnt / 10);
                
            pb.Invalidate();
        }

        private void pb_MouseClick(object sender, MouseEventArgs e)
        {
            if (!selectDeflector) return;

            int col = (int)((double)e.Location.X / w);
            int row = (int)((double)e.Location.Y / h);

            itemi.Add(new Item("deflector" + deflector, col, row));
            pb.Invalidate();
        }

        private void splitContainer1_Panel2_Paint(object sender, PaintEventArgs e)
        {
            Point[] points = new Point[0];
            Pen p = new Pen(Color.White, 2f);
            if(selectDeflector)
                p.Color = Color.Red;

            if(deflector == 1)
                points = new Point[] { deflectors[0], deflectors[1], deflectors[3] };
            if (deflector == 2)
                points = new Point[] { deflectors[0], deflectors[1], deflectors[2] };
            if (deflector == 3)
                points = new Point[] { deflectors[1], deflectors[2], deflectors[3] };
            if (deflector == 4)
                points = new Point[] { deflectors[0], deflectors[2], deflectors[3] };

            e.Graphics.DrawPolygon(p, points);
            e.Graphics.FillPolygon(Brushes.White, points);
        }
    }
}
