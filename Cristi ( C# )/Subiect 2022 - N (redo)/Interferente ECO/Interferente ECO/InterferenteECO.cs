using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Schema;

namespace Interferente_ECO
{
    public partial class InterferenteECO : Form
    {
        static string respath = $@"{Directory.GetCurrentDirectory()}\..\..\..\..\OTI_2022_C#_resurse\";

        int prvDir = -1;
        bool[,] viz;
        Image imgInitiala;
        Image[] screenshots = new Image[5];
        int cntscreenshots = 0;
        Timer screenshotTimer = new Timer();
        List<int> steps = new List<int>();
        int idxsteps;
        bool doingLee = false;
        int cntSticla, cntHartie, cntPlastic, cntReciclabile, cntColectate;
        int rowInitial = -1, colInitial = -1;
        bool started = false;
        static int[] dx = new int[] { -1, 0, 1, 0 }, dy = new int[] { 0, 1, 0, -1 };
        static int up = 0, right = 1, down = 2, left = 3;
        int dir;
        PointF pozRobot = new PointF(-100, -100);
        Item robot = new Item("", -1, -1);
        int cnt;
        Image background;
        List<Item> itemi = new List<Item>();
        int currDeflector = 1;
        float cellwidth, cellheight;
        bool drawLines = false;
        bool selectedDeflector;
        Timer timer = new Timer();
        string hartapath;

        int[,] matDef = new int[11, 21];
        int[,] matMeduze = new int[11, 21];
        int[,] matReciclare = new int[11, 21];

        Image[] imgMeduze = new Image[]
        {
            Image.FromFile(respath + $@"Meduze\Meduza1.png"),
            Image.FromFile(respath + $@"Meduze\Meduza2.png"),
            Image.FromFile(respath + $@"Meduze\Meduza3.png"),
            Image.FromFile(respath + $@"Meduze\Meduza4.png")
        };
        Image[] imgReciclabile = new Image[]
        {
            Image.FromFile(respath + $@"MaterialeReciclabile\Hartie.png"),
            Image.FromFile(respath + $@"MaterialeReciclabile\Plastic.png"),
            Image.FromFile(respath + $@"MaterialeReciclabile\Sticla.png")
        };
        Image imgRobot = Image.FromFile(respath + $@"Robot\Robot.png");


        Point[] pointsDeflector = new Point[]
        {
            new Point(30, 115),
            new Point(115, 115),
            new Point(115, 200),
            new Point(30, 200)
        };

        public InterferenteECO(Image background)
        {
            this.background = background;
            InitializeComponent();
            InitSplitter();
        }

        private void InitSplitter()
        {
            cellheight = pb.ClientSize.Height / 10;
            cellwidth = pb.ClientSize.Width / 20;
            pb.Image = background;
            this.SetStyle(ControlStyles.OptimizedDoubleBuffer | ControlStyles.UserPaint | ControlStyles.AllPaintingInWmPaint, true);
            splitContainer1.IsSplitterFixed = true;
        }

        private void splitContainer1_Panel2_Paint(object sender, PaintEventArgs e)
        {
            if (currDeflector == 1)
            {
                if (selectedDeflector)
                    e.Graphics.DrawPolygon(new Pen(Color.Red, 2f),
                    new Point[] { pointsDeflector[0], pointsDeflector[1], pointsDeflector[3] });
                e.Graphics.FillPolygon(Brushes.White,
                new Point[] { pointsDeflector[0], pointsDeflector[1], pointsDeflector[3] });
            }
            if (currDeflector == 2)
            {
                if (selectedDeflector)
                    e.Graphics.DrawPolygon(new Pen(Color.Red, 2f),
                    new Point[] { pointsDeflector[0], pointsDeflector[1], pointsDeflector[2] });
                e.Graphics.FillPolygon(Brushes.White,
                new Point[] { pointsDeflector[0], pointsDeflector[1], pointsDeflector[2] });
            }
            if (currDeflector == 3)
            {
                if (selectedDeflector)
                    e.Graphics.DrawPolygon(new Pen(Color.Red, 2f),
                    new Point[] { pointsDeflector[1], pointsDeflector[2], pointsDeflector[3] });
                e.Graphics.FillPolygon(Brushes.White,
                new Point[] { pointsDeflector[1], pointsDeflector[2], pointsDeflector[3] });
            }
            if (currDeflector == 4)
            {
                if (selectedDeflector)
                    e.Graphics.DrawPolygon(new Pen(Color.Red, 2f),
                    new Point[] { pointsDeflector[0], pointsDeflector[2], pointsDeflector[3] });
                e.Graphics.FillPolygon(Brushes.White,
                new Point[] { pointsDeflector[0], pointsDeflector[2], pointsDeflector[3] });
            }
        }

        private void btnIncarca_Click(object sender, EventArgs e)
        {
            var ofd = new OpenFileDialog();
            ofd.Filter = "Text file (*.txt)|*.txt";
            if (ofd.ShowDialog() == DialogResult.OK)
                IncarcaHarta(ofd.FileName);
        }

        private void IncarcaHarta(string fileName)
        {
            started = false;
            doingLee = false;
            cntSticla = cntHartie = cntPlastic = cntReciclabile = cntColectate = 0;
            hartapath = fileName;
            itemi = new List<Item>();
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

                if (tip == "Hartie" || tip == "Sticla" || tip == "Plastic")
                    cntReciclabile++;

                itemi.Add(new Item(tip, row, col));
            }

            pb.Invalidate();

            var bmp = new Bitmap(pb.Width, pb.Height);
            pb.DrawToBitmap(bmp, pb.Bounds);
            imgInitiala = bmp;
        }

        private void chkGrid_CheckedChanged(object sender, EventArgs e)
        {
            drawLines = chkGrid.Checked;
            pb.Invalidate();
        }

        private void pb_Paint(object sender, PaintEventArgs e)
        {
            InitMat();

            if (drawLines)
                DrawGridLines(e.Graphics);


            foreach (Item x in itemi)
                if (x.Tip == "Path")
                    e.Graphics.FillRectangle(Brushes.Purple,
                        new RectangleF((x.Col - 1) * cellwidth, (x.Row - 1) * cellheight, cellwidth, cellheight));

            e.Graphics.FillRectangle(Brushes.Red,
                new RectangleF((colInitial - 1) * cellwidth, (rowInitial - 1) * cellheight, cellwidth, cellheight));

            foreach(Item x in itemi)
            {
                if (x.Tip == "Path") continue;

                if(x.Tip.IndexOf("Deflector") == 0)
                {
                    DrawDeflector(x, e.Graphics);
                    matDef[x.Row, x.Col] = int.Parse(x.Tip.Substring(9));
                    continue;
                }

                if(x.Tip == "Robot")
                {
                    if (!started)
                    {
                        robot.Row = x.Row;
                        robot.Col = x.Col;
                        robot.Tip = x.Tip;
                        rowInitial = x.Row;
                        colInitial = x.Col;
                        pozRobot = new PointF((x.Col - 1) * cellwidth, (x.Row - 1) * cellheight);
                    }
                    continue;
                }

                Image img = imgRobot;

                if(x.Tip == "Hartie")
                {
                    img = imgReciclabile[0];
                    matReciclare[x.Row,x.Col] = 1;
                }
                else if(x.Tip == "Plastic")
                {
                    img = imgReciclabile[1];
                    matReciclare[x.Row, x.Col] = 2;
                }
                else if(x.Tip == "Sticla")
                {
                    img = imgReciclabile[2];
                    matReciclare[x.Row, x.Col] = 3;
                }
                else if(x.Tip == "Meduza1")
                {
                    img = imgMeduze[0];
                    matMeduze[x.Row, x.Col] = 1;
                }
                else if(x.Tip == "Meduza2")
                {
                    img = imgMeduze[1];
                    matMeduze[x.Row, x.Col] = 1;
                }
                else if(x.Tip == "Meduza3")
                {
                    img = imgMeduze[2];
                    matMeduze[x.Row, x.Col] = 1;
                }
                else if(x.Tip == "Meduza4")
                {
                    img = imgMeduze[3];
                    matMeduze[x.Row, x.Col] = 1;
                }

                e.Graphics.DrawImage(img, new RectangleF((x.Col - 1) * cellwidth, (x.Row - 1) * cellheight, cellwidth, cellheight),
                new Rectangle(0, 0, img.Width, img.Height), GraphicsUnit.Pixel);
            }

            e.Graphics.DrawImage(imgRobot, new RectangleF(pozRobot.X, pozRobot.Y, cellwidth, cellheight),
                new Rectangle(0, 0, imgRobot.Width, imgRobot.Height), GraphicsUnit.Pixel);
        }

        private void DrawDeflector(Item x, Graphics graphics)
        {
            PointF[] points = new PointF[]
            {
                new PointF((x.Col - 1) * cellwidth, (x.Row - 1) * cellheight),
                new PointF(x.Col * cellwidth, (x.Row - 1) * cellheight),
                new PointF(x.Col * cellwidth, x.Row * cellheight),
                new PointF((x.Col - 1) * cellwidth, x.Row * cellheight)
            };

            if (x.Tip == "Deflector1")
                graphics.FillPolygon(Brushes.White, new PointF[]
                    {points[0], points[1], points[3]});
            if (x.Tip == "Deflector2")
                graphics.FillPolygon(Brushes.White, new PointF[]
                    {points[0], points[1], points[2]});
            if (x.Tip == "Deflector3")
                graphics.FillPolygon(Brushes.White, new PointF[]
                    {points[1], points[2], points[3]});
            if (x.Tip == "Deflector4")
                graphics.FillPolygon(Brushes.White, new PointF[]
                    {points[0], points[2], points[3]});
        }

        private void InitMat()
        {
            matDef = new int[11, 21];
            matMeduze = new int[11, 21];
            matReciclare = new int[11, 21];
        }

        private void DrawGridLines(Graphics graphics)
        {
            for (int i = 1; i <= 10; ++i)
                graphics.DrawLine(Pens.White, new PointF(0, i * cellheight), new PointF(900, i * cellheight));

            for (int j = 1; j <= 20; ++j)
                graphics.DrawLine(Pens.White, new PointF(j * cellwidth, 0), new PointF(j * cellwidth, 900));
        }

        private void splitContainer1_Panel2_MouseClick(object sender, MouseEventArgs e)
        {
            var l = e.Location;
            if (l.X >= 35 && l.X <= 115 && l.Y >= 115 && l.Y <= 200)
                selectedDeflector = true;
            else
                selectedDeflector = false;

            splitContainer1.Panel2.Invalidate();
        }

        private void btnRestart_Click(object sender, EventArgs e)
        {
            screenshotTimer.Interval = 6000;
            screenshotTimer.Tick -= Screenshot;
            screenshotTimer.Stop();
            cntscreenshots = 0;

            doingLee = false;

            btnStart.Text = "Start";
            timer.Tick -= SmallMove;
            timer.Tick -= MapEvent;
            timer.Stop();
            started = false;
            btnGen.Enabled = true;

            List<Item> save = new List<Item>();
            foreach (Item x in itemi)
                if (x.Tip.IndexOf("Deflector") == 0)
                    save.Add(x);

            IncarcaHarta(hartapath);

            foreach (Item x in save)
                itemi.Add(x);

            cntSticla = cntHartie = cntPlastic = cntColectate = 0;
            lblHartie.Text = "Paper: " + cntHartie;
            lblPlastic.Text = "Plastic: " + cntPlastic;
            lblSticla.Text = "Bottles: " + cntSticla;

            pb.Invalidate();
        }

        private void Screenshot(object sender, EventArgs e)
        {
            if(cntscreenshots > 0 && cntscreenshots < 4)
            {
                var bmp = new Bitmap(pb.Width, pb.Height);
                pb.DrawToBitmap(bmp, new Rectangle(0, 0, pb.Width, pb.Height));
                screenshots[cntscreenshots] = bmp;
                cntscreenshots++;
            }
        }

        private void btnSalveazaJpg_Click(object sender, EventArgs e)
        {
            var sfd = new SaveFileDialog();
            if (sfd.ShowDialog() != DialogResult.OK) return;
            for (int i = 0; i < 5; ++i)
            {
                string[] s = sfd.FileName.Split('\\');
                string prefix = "";
                for(int j = 0; j < s.Length - 1; ++j)
                    prefix += s[j] + '\\';

                string name = s.Last() + (i + 1) + ".jpg";

                screenshots[i].Save(prefix + name, System.Drawing.Imaging.ImageFormat.Jpeg);
            }
        }

        private void btnGen_Click(object sender, EventArgs e)
        {
            prvDir = -1;
            viz = new bool[11, 21];
            int[,] auxDef = new int[11,21];
            int[,] auxReciclare = new int[11, 21];
            for (int i = 1; i <= 10; ++i)
                for (int j = 1; j <= 20; ++j)
                {
                    auxDef[i, j] = matDef[i, j];
                    auxReciclare[i, j] = matReciclare[i, j];
                }

            for (int i = 1; i <= 10; ++i)
                for (int j = 1; j <= 20; ++j)
                    matDef[i, j] = 0;

            List<Item> reciclabile = new List<Item>();
            foreach(Item i in itemi)
                if(matMeduze[i.Row,i.Col] == 0 && (i.Tip == "Hartie" || i.Tip == "Plastic" || i.Tip == "Sticla"))
                    reciclabile.Add(i);

            int[,] d = new int[11, 21];

            matReciclare[reciclabile[0].Row, reciclabile[0].Col] = 0;
            Bfs(robot.Row, robot.Col, d);
            GetSteps(robot.Row, robot.Col, reciclabile[0].Row, reciclabile[0].Col, d);
            prvDir = steps[0];
            int x = robot.Row, y = robot.Col;
            viz[x, y] = true;
            for(int i = 0; i < steps.Count; ++i)
            {
                

                if (steps[i] != prvDir)
                {
                    if(prvDir == up)
                    {
                        if (steps[i] == right) matDef[x, y] = 1;
                        else if (steps[i] == left) matDef[x, y] = 2;
                    }
                    if(prvDir == right)
                    {
                        if (steps[i] == up) matDef[x, y] = 3;
                        else if (steps[i] == down) matDef[x, y] = 2;
                    }
                    if(prvDir == down)
                    {
                        if (steps[i] == right) matDef[x, y] = 4;
                        else if (steps[i] == left) matDef[x, y] = 3;
                    }
                    if(prvDir == left)
                    {
                        if (steps[i] == up) matDef[x, y] = 4;
                        else if (steps[i] == down) matDef[x, y] = 1;
                    }
                }

                x += dx[steps[i]];
                y += dy[steps[i]];
                viz[x, y] = true;
                prvDir = steps[i];
            }

            matReciclare[reciclabile[0].Row - dx[prvDir], reciclabile[0].Col - dy[prvDir]] = 1;

            for(int k = 1; k < reciclabile.Count; ++k)
            {
                d = new int[11, 21];
                matReciclare[reciclabile[k].Row, reciclabile[k].Col] = 0;


                Bfs(reciclabile[k - 1].Row, reciclabile[k - 1].Col, d);
                GetSteps(reciclabile[k - 1].Row , reciclabile[k - 1].Col,
                    reciclabile[k].Row, reciclabile[k].Col, d);


                x = reciclabile[k - 1].Row;
                y = reciclabile[k - 1].Col;

                viz[x, y] = true;

                for (int i = 0; i < steps.Count; ++i)
                {
                    

                    if (steps[i] != prvDir)
                    {
                        if (prvDir == up)
                        {
                            if (steps[i] == right) matDef[x, y] = 1;
                            else if (steps[i] == left) matDef[x, y] = 2;
                        }
                        if (prvDir == right)
                        {
                            if (steps[i] == up) matDef[x, y] = 3;
                            else if (steps[i] == down) matDef[x, y] = 2;
                        }
                        if (prvDir == down)
                        {
                            if (steps[i] == right) matDef[x, y] = 4;
                            else if (steps[i] == left) matDef[x, y] = 3;
                        }
                        if (prvDir == left)
                        {
                            if (steps[i] == up) matDef[x, y] = 4;
                            else if (steps[i] == down) matDef[x, y] = 1;
                        }
                    }

                    x += dx[steps[i]];
                    y += dy[steps[i]];

                    viz[x, y] = true;

                    prvDir = steps[i];
                }

                matReciclare[reciclabile[k].Row - dx[prvDir], reciclabile[k].Col - dy[prvDir]] = 1;

            }

            Graphics g = Graphics.FromImage(imgInitiala);
            for(int i = 1; i <= 10; ++i)
                for(int j = 1; j <= 20; ++j)
                    if (matDef[i, j] != 0)
                        DrawDeflector(new Item("Deflector" + matDef[i, j], i, j), g);
            DrawGridLines(g);

            var sfd = new SaveFileDialog();
            sfd.Filter = "Image files (*.jpg)|*.jpg";
            if (sfd.ShowDialog() == DialogResult.OK)
                imgInitiala.Save(sfd.FileName, System.Drawing.Imaging.ImageFormat.Jpeg);


            matDef = auxDef;
            matReciclare = auxReciclare;
        }

        private void Bfs(int row, int col, int[,] d)
        {
            for (int i = 1; i <= 10; ++i)
                for (int j = 1; j <= 20; ++j)
                    if (matMeduze[i, j] != 0 || matDef[i, j] != 0 || matReciclare[i,j] != 0 || viz[i,j])
                        d[i, j] = -11;

            d[row, col] = 0;

            Queue<KeyValuePair<int, int>> q = new Queue<KeyValuePair<int, int>>();

            if (prvDir != -1)
            {
                d[row + dx[prvDir], col + dy[prvDir]] = 1;
                q.Enqueue(new KeyValuePair<int, int>(row + dx[prvDir], col + dy[prvDir]));
            }
            else q.Enqueue(new KeyValuePair<int, int>(row, col));


            

            while(q.Count != 0)
            {
                var it = q.Dequeue();
                int x = it.Key;
                int y = it.Value;

                for(int i = 0; i < 4; ++i)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(InMat(nx, ny) && d[nx,ny] == 0)
                    {
                        d[nx,ny] = d[x, y] + 1;
                        q.Enqueue(new KeyValuePair<int, int>(nx, ny));
                    }
                }    
            }

            d[row, col] = 0;

            for(int i = 1; i <= 10; ++i, Console.WriteLine())
                for(int j = 1; j <= 20; ++j)
                    Console.Write(d[i,j] + " ");
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Are you sure you want to close the app?",
                "Confirmation", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
                this.Close();
        }

        private void pb_MouseClick(object sender, MouseEventArgs e)
        {
            int col = (int)(e.Location.X / cellwidth + 1);
            int row = (int)(e.Location.Y / cellheight + 1);

            if (!selectedDeflector || matDef[row,col] != 0 || matMeduze[row,col] != 0 || matReciclare[row,col] != 0) return;

            itemi.Add(new Item("Deflector" + currDeflector, row, col));

            pb.Invalidate();
        }

        private void btnCurata_Click(object sender, EventArgs e)
        {
            screenshotTimer.Interval = 6000;
            screenshotTimer.Tick -= Screenshot;
            screenshotTimer.Stop();
            cntscreenshots = 0;

            doingLee = false;

            cntSticla = cntHartie = cntPlastic = cntReciclabile = cntColectate = 0;

            btnStart.Text = "Start";
            timer.Tick -= SmallMove;
            timer.Tick -= MapEvent;
            timer.Stop();
            started = false;
            pozRobot = new PointF(-100, -100);
            robot = new Item("", -1, -1);
            itemi.Clear();
            pb.Invalidate();
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            cnt = 0;

            if(btnStart.Text == "Start")
            {           

                if(!started)
                {
                    started = true;
                    btnGen.Enabled = false;
                    var frm = new Selecteaza_directia();
                    frm.ShowDialog();
                    dir = frm.Dir;
                }

                btnStart.Text = "Stop";
                timer.Tick += SmallMove;
                timer.Tick += MapEvent;
                timer.Interval = 100;
                timer.Start();

                if (cntscreenshots == 0)
                {
                    var bmp = new Bitmap(pb.Width, pb.Height);
                    pb.DrawToBitmap(bmp, pb.Bounds);
                    screenshots[0] = bmp;
                    cntscreenshots = 1;
                    screenshotTimer.Interval = 6000;
                    screenshotTimer.Tick += Screenshot;
                    screenshotTimer.Start();
                }           
            }
            else
            {
                btnStart.Text = "Start";
                timer.Tick -= SmallMove;
                timer.Tick -= MapEvent;
                timer.Stop();
            }

            pb.Invalidate();
        }

        private void MapEvent(object sender, EventArgs e)
        {
            if (cnt != 10) return;
            cnt = 0;

            robot.Row += dx[dir];
            robot.Col += dy[dir];
            itemi.Add(new Item("Path", robot.Row, robot.Col));

            int x = robot.Row;
            int y = robot.Col;


            if (matReciclare[x, y] != 0)
            {
                int v = matReciclare[x, y];
                string tip = "";
                if (v == 1)
                {
                    cntHartie++;
                    tip = "Hartie";
                }
                else if (v == 2)
                {
                    cntPlastic++;
                    tip = "Plastic";
                }
                else if (v == 3)
                {
                    cntSticla++;
                    tip = "Sticla";
                }

                lblHartie.Text = "Paper: " + cntHartie;
                lblPlastic.Text = "Plastic: " + cntPlastic;
                lblSticla.Text = "Bottle: " + cntSticla;

                for (int i = 0; i < itemi.Count; ++i)
                    if (itemi[i].Row == x && itemi[i].Col == y && itemi[i].Tip == tip)
                        itemi.RemoveAt(i);

                cntColectate++;
            }
            if (matMeduze[x, y] != 0)
            {
                btnStart.Text = "Start";
                timer.Tick -= SmallMove;
                timer.Tick -= MapEvent;
                timer.Stop();

                screenshotTimer.Interval = 6000;
                screenshotTimer.Tick -= Screenshot;
                screenshotTimer.Stop();
                cntscreenshots = 0;

                MessageBox.Show("A medusa was hurt");

                return;
            }
            if (cntColectate == cntReciclabile)
            {
                Lee();
                doingLee = true;
            }
            if(doingLee)
            {
                if(idxsteps == steps.Count)
                {
                    btnStart_Click(new object(), new EventArgs());
                    var bmp = new Bitmap(pb.Width, pb.Height);
                    pb.DrawToBitmap(bmp, new Rectangle(0, 0, pb.Width, pb.Height));
                    screenshots[4] = bmp;
                    cntscreenshots++;
                    return;
                }
                dir = steps[idxsteps];
                idxsteps++;
            }
            

            dir = Coliziune(robot.Row, robot.Col, dir);
            dir = Coliziune(robot.Row, robot.Col, dir);
        }

        private void Lee()
        {
            int[,] matrice = new int[11, 21];
            for (int i = 1; i <= 10; ++i)
                for (int j = 1; j <= 20; ++j)
                    if (matMeduze[i, j] != 0 || matDef[i, j] != 0)
                        matrice[i, j] = -11;

            int cx = robot.Row;
            int cy = robot.Col;
            Queue<KeyValuePair<int, int>> q = new Queue<KeyValuePair<int, int>>();
            q.Enqueue(new KeyValuePair<int, int>(cx, cy));

            while(q.Count != 0)
            {
                var it = q.Dequeue();
                int x = it.Key, y = it.Value;

                for(int i = 0; i < 4; ++i)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(InMat(nx, ny) && matrice[nx,ny] == 0)
                    {
                        matrice[nx, ny] = matrice[x, y] + 1;
                        q.Enqueue(new KeyValuePair<int, int>(nx, ny));
                    }
                }
            }

            matrice[cx, cy] = 0;

            GetSteps(cx, cy, rowInitial, colInitial, matrice);
        }

        private void GetSteps(int xi, int yi, int xf, int yf, int[,] matrice)
        {
            steps = new List<int>();
            idxsteps = 0;

            int x = xf, y = yf;
            while(true)
            {
                for(int i = 0; i < 4; ++i)
                {
                    int px = x - dx[i];
                    int py = y - dy[i];
                    if(InMat(px,py) && matrice[px,py] + 1 == matrice[x, y])
                    {
                        steps.Add(i);
                        x = px;
                        y = py;
                        break;
                    }
                }

                if (x == xi && y == yi) break;
            }

            steps.Reverse();
        }

        private bool InMat(int x, int y)
        {
            return (x >= 1 && x <= 10 && y >= 1 && y <= 20);
        }

        private int Coliziune(int x, int y, int d)
        {      
            if (matDef[x,y] == 1)
            {
                if (d == up)
                    d = right;
                else if (d == left)
                    d = down;
            }
            else if (matDef[x,y] == 2)
            {
                if (d == right)
                    d = down;
                else if (d == up)
                    d = left;
            }
            else if (matDef[x, y] == 3)
            {
                if (d == right)
                    d = up;
                else if (d == down)
                    d = left;
            }
            else if (matDef[x, y] == 4)
            {
                if (d == left)
                    d = up;
                else if (d == down)
                    d = right;
            }

            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 1 || ny < 1 || nx > 10 || ny > 20 ||
               (d == up && (matDef[nx, ny] == 3 || matDef[nx, ny] == 4)) ||
               (d == right && (matDef[nx, ny] == 1 || matDef[nx, ny] == 4)) ||
               (d == down && (matDef[nx, ny] == 1 || matDef[nx, ny] == 2)) ||
               (d == left && (matDef[nx, ny] == 2 || matDef[nx, ny] == 3)))
                d = (d + 2) % 4;

            return d;
        }

        private void SmallMove(object sender, EventArgs e)
        {
            if (cnt == 10) return;
            cnt++;

            int nx = robot.Row + dx[dir];
            int ny = robot.Col + dy[dir];

            pozRobot = new PointF((robot.Col - 1) * cellwidth + ((ny - 1) * cellwidth - (robot.Col - 1) * cellwidth) * cnt / 10,
                (robot.Row - 1) * cellheight + ((nx - 1) * cellheight - (robot.Row - 1) * cellheight) * cnt / 10);

            pb.Invalidate();
        }

        private void btnRoteste_Click(object sender, EventArgs e)
        {
            currDeflector++;
            if (currDeflector > 4) currDeflector = 1;
            splitContainer1.Panel2.Invalidate();
        }
    }
}
