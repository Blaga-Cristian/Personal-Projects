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


namespace Interferente_ECO
{
    public enum Directie
    {
        Sus, Dreapta, Jos, Stanga, Stop
    };

    public partial class InterfeteEcoForm : Form
    {
        private static readonly int n = 10, m = 20;
        private Cell[,] c = null;
        private bool gridVisible = false;
        private string currentMap = null;  // fisierul hartii incarcate curent
        private string meduze = null;
        private string roboti = null;
        private string reciclabile = null;  // hartii + sticle + plastic la un moment dat
        private string appPath = Directory.GetCurrentDirectory();
        private int rotatie = 0;     // 0..3 - pozitia curenta a triungiului din panoul dreapta 
        private bool triunghiSelected = false;

        private int I, J;
        private int sticle = 0, hartii = 0, plastic = 0; // contoare de afisat in label-uri
        private Timer timer = new Timer();
        private Timer timer2 = new Timer();
        private float x = 0, y = 0, dx = 0, dy = 0;  // (x, y) coltul stanga sus al celulei cu robot in miscare
                                                     // (dx, dy) deplasarea la fiecare Tick
        private int increment = 7; // nu mai umblu aici (afecteaza contoarele)
        List<Cell> listC = new List<Cell>();
        public Directie directie;
        private Image robo;
        private int cntReciclabile = 0, CntReciclabile = 0; // cate culeg/cate erau
        private bool gameStart;

        private int iRobot, jRobot, iStop, jStop; // poz initiala si finala a robotului
        private bool[][] obst; // obstacolele (deflectoare, meduze) la intoarcerea pe drumul minim
        private int[][] d;    // matricea distantelor minime
        private bool[][] rec; // tin minte unde erau reciclabilele
        private int[][] dir;  // directia pe care doresti sa iesi din celula [i, j]
        private readonly int[] di = { -1, 0, 1, 0 };
        private readonly int[] dj = { 0, 1, 0, -1 };
        private readonly int Inf = Int32.MaxValue / 3;
        private bool runLee = false;
        private bool runBfs = false;
        private List<Cell> celuleTraseu = new List<Cell>();  // pt primul Lee si Back
        
        private bool gataLee = false;
        private int[][][] D = null; // D[k] = matr distantelor minime in raport cu reciclabilul k
        private int[][] traseu_anterior;  // retine directiile de deplasare la Bfs anterior

        public InterfeteEcoForm(Image img)
        {
            InitializeComponent();
            pb.Image = img;
            lblHartie.BackColor = Color.Transparent;
            lblPlastic.BackColor = Color.Transparent;
            lblSticle.BackColor = Color.Transparent;
            meduze = $@"{appPath}\..\..\Resurse\Meduze\";
            roboti = $@"{appPath}\..\..\Resurse\Robot\";
            reciclabile = $@"{appPath}\..\..\Resurse\MaterialeReciclabile\";
            robo = Image.FromFile(roboti + "Robot.png");
            c = new Cell[n, m];
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                {
                    c[i, j] = new Cell();
                    c[i, j].i = i;
                    c[i, j].j = j;
                    listC.Add(c[i, j]);
                }
            cbShowGrid.BackColor = Color.Transparent;
            lblAddDeflector.BackColor = Color.Transparent;

            // EnableDoubleBuffering();
            //this.DoubleBuffered = true; // nu am vazut mare diferenta 
            SetStyle(ControlStyles.OptimizedDoubleBuffer, true);
            timer.Interval = 20;
            timer.Tick += TimerTick;
            timer2.Interval = 20;
            timer2.Tick += new EventHandler(Timer2Tick);
            InitializeLeeData();

        }

        public void EnableDoubleBuffering()
        {
            // Set the value of the double-buffering style bits to true.
            this.SetStyle(ControlStyles.DoubleBuffer |
               ControlStyles.UserPaint |
               ControlStyles.AllPaintingInWmPaint,
               true);
            this.UpdateStyles();
        }

        private void InitializeLeeData()
        {
            d = new int[n][];
            obst = new bool[n][];
            rec = new bool[n][];
            for (int i = 0; i < n; ++i)
            {
                d[i] = new int[m];
                obst[i] = new bool[m];
                rec[i] = new bool[m];
            }

            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                {
                    d[i][j] = Inf;
                    rec[i][j] = false;
                }
        }

        Cell FindCellWithTriangleVisible()
        {
            var cl = listC.Find(cel => cel.TriangleVisible && x + cel.W / 2 >= cel.X0
                               && x + cel.W / 2 <= cel.X0 + cel.W && y + cel.H / 2 >= cel.Y0
                               && y + cel.H / 2 <= cel.Y0 + cel.H);
            return cl;
        }

        Cell FindCellWithRobot(List<Cell> list)
        {                 // daca mijlocul robotului se gaseste in celula cel
            var cl = list.Find(cel => x + cel.W / 2 >= cel.X0
                               && x + cel.W / 2 <= cel.X0 + cel.W && y + cel.H / 2 >= cel.Y0
                               && y + cel.H / 2 <= cel.Y0 + cel.H);
            return cl;
        }

        private bool RobotInsideCell(Cell c)
        {
            return c != null && Math.Abs(x - c.X0) < 4 && Math.Abs(y - c.Y0) < 4;
            //return c != null && x + c.W / 2 >= c.X0
            //                    && x + c.W / 2 <= c.X0 + c.W && y + c.H / 2 >= c.Y0
            //                    && y + c.H / 2 <= c.Y0 + c.H;
        }

        private void TimerTick(object sender, EventArgs e)
        {

            Cell cl = FindCellWithTriangleVisible();
            Cell cr = FindCellWithRobot(listC);
            // daca celula are robot si centrul robotului se gaseste in celula
            if (RobotInsideCell(cr))
                c[cr.i, cr.j].hasColor = true;

            if (RobotInsideCell(cl) && cl.Rot != -1) // default value pt cell se returneaza in caz ca nu gaseste
            {
                // daca centrul robotului se gaseste in celula cu triungi  
                if (Math.Abs(x - cl.X0) < 4 && Math.Abs(y - cl.Y0) < 4)
                {
                    x = cl.X0; y = cl.Y0;
                    if (directie == Directie.Sus)
                    {
                        if (cl.Rot == 0) // deviaza spre dreapta
                        {
                            dx = increment;
                            dy = 0;
                            directie = Directie.Dreapta;
                        }
                        if (cl.Rot == 1) // deviaza spre stanga
                        {
                            dx = -increment;
                            dy = 0;
                            directie = Directie.Stanga;
                        }
                        if (cl.Rot == 2 || cl.Rot == 3) // il reflecta in jos
                        {
                            dx = 0;
                            dy = -increment;
                            directie = Directie.Jos;
                        }
                    }
                    else
                    if (directie == Directie.Dreapta)
                    {
                        if (cl.Rot == 0 || cl.Rot == 3) // reflecta spre stanga
                        {
                            dx = -increment;
                            dy = 0;
                            directie = Directie.Stanga;
                        }
                        if (cl.Rot == 1) // deviaza in jos
                        {
                            dx = 0;
                            dy = increment;
                            directie = Directie.Jos;
                        }
                        if (cl.Rot == 2) // il deviaza in sus
                        {
                            dx = 0;
                            dy = -increment;
                            directie = Directie.Sus;
                        }
                    }
                    else
                    if (directie == Directie.Jos)
                    {
                        if (cl.Rot == 0 || cl.Rot == 1) // respinge in sus
                        {
                            dx = 0;
                            dy = -increment;
                            directie = Directie.Sus;
                        }
                        if (cl.Rot == 2) // deviaza stanga
                        {
                            dx = -increment;
                            dy = 0;
                            directie = Directie.Stanga;
                        }
                        if (cl.Rot == 3) // deviaza drepata
                        {
                            dx = increment;
                            dy = 0;
                            directie = Directie.Dreapta;
                        }
                    }
                    else
                    if (directie == Directie.Stanga)
                    {
                        if (cl.Rot == 1 || cl.Rot == 2) // respinge in sus
                        {
                            dx = -increment;
                            dy = 0;
                            directie = Directie.Sus;
                        }
                        if (cl.Rot == 0) // deviaza jos
                        {
                            dx = 0;
                            dy = increment;
                            directie = Directie.Jos;
                        }
                        if (cl.Rot == 3) // deviaza sus
                        {
                            dx = 0;
                            dy = -increment;
                            directie = Directie.Sus;
                        }
                    }
                }
            }

            bool gata = false;
            for (int i = 0; i < n && !gata; ++i)
                for (int j = 0; j < m && !gata; ++j)
                    if (RobotInsideCell(c[i, j]))
                    {
                        if (c[i, j].file == reciclabile + "Hartie.png")
                        {
                            hartii++;
                            cntReciclabile++;
                            lblHartie.Text = "Hartie " + hartii.ToString();
                            lblHartie.Refresh();
                            c[i, j].ObjectVisible = false;
                        }

                        if (c[i, j].file == reciclabile + "Sticla.png")
                        {
                            sticle++;
                            cntReciclabile++;
                            lblSticle.Text = "Sticle " + sticle.ToString();
                            lblSticle.Refresh();
                            c[i, j].ObjectVisible = false;
                        }

                        if (c[i, j].file == reciclabile + "Plastic.png")
                        {
                            plastic++;
                            cntReciclabile++;
                            lblPlastic.Text = "Plastic " + plastic.ToString();
                            lblPlastic.Refresh();
                            c[i, j].ObjectVisible = false;
                        }

                        // opresc animatia daca am colectat toate deseurile
                        if (cntReciclabile == CntReciclabile)
                        {
                            gameStart = false;
                            timer.Enabled = false;
                            timer.Stop();
                            FinishForm frm = new FinishForm();
                            frm.ShowDialog();
                            CollectObstaclesLee();
                            runLee = true;
                            Lee(iStop, jStop);

                            celuleTraseu = GetCeluleTraseu(iRobot, jRobot);
                            celuleTraseu.Reverse(); // pornim de la poz actuala a robotului spre poz de initiala de plecare
                            I = iStop; J = jStop;
                            x = c[I, J].X0; y = c[I, J].Y0;
                            gataLee = true;
                            timer2.Enabled = true;
                            timer2.Start();
                            return;
                        }

                        // opresc animatia daca intalnesc o meduza
                        string s = c[i, j].file;
                        if (s != null && s.Substring(s.Length - 11, 6) == "Meduza")
                        {
                            gameStart = false;
                            timer.Enabled = false;
                            timer.Stop();
                            GameOverForm frm = new GameOverForm();
                            frm.ShowDialog();
                            return;
                        }

                        if (i == 0 && directie == Directie.Sus)
                        {
                            dy = -increment;
                            directie = Directie.Jos;
                            gata = true;
                        }
                        else
                        if (j == 0 && directie == Directie.Stanga)
                        {
                            dx = increment;
                            directie = Directie.Dreapta;
                            gata = true;
                        }
                        else
                        if (i == n - 1 && directie == Directie.Jos)
                        {
                            dy = -increment;
                            directie = Directie.Sus;
                            gata = true;
                        }
                        else
                        if (j == m - 1 && directie == Directie.Dreapta)
                        {
                            dx = -increment;
                            directie = Directie.Stanga;
                            gata = true;
                        }

                    }
            pb.Invalidate();
            x += dx;  // AICI
            y += dy;
        }

        private List<Cell> GetCeluleTraseu(int i0, int j0)
        {
            celuleTraseu.Clear();
            int i = i0, j = j0, iv = -1, jv = -1;
            float w, h;
            w = (float)pb.Width / m; h = (float)pb.Height / n;
            celuleTraseu.Add(new Cell(i, j, c[i, j].X0, c[i, j].Y0, w, h, Directie.Dreapta, true));
            while (true)
            {

                for (int p = 0; p < 4; ++p)
                {
                    iv = i + di[p];
                    jv = j + dj[p];
                    if (Ok(iv, jv) && d[i][j] == d[iv][jv] + 1)
                    {
                        if (p == 0) directie = Directie.Jos;
                        if (p == 1) directie = Directie.Stanga;
                        if (p == 2) directie = Directie.Sus;
                        if (p == 3) directie = Directie.Dreapta;
                        w = (float)pb.Width / m; h = (float)pb.Height / n;
                        celuleTraseu.Add(new Cell(iv, jv, c[iv, jv].X0, c[iv, jv].Y0, w, h, directie, true));
                        i = iv;
                        j = jv;
                        break;
                    }
                }
                if (runBfs && i == iRobot && j == jRobot) // numai pt Lee2
                    break;
                if (!gataLee && i == iStop && j == jStop) // numai pt Lee1
                    break;

            }
            return celuleTraseu;
        }

        private void Lee(int iStart, int jStart)
        {
            int i = 0, j = 0, iv = 0, jv = 0;
            Queue<KeyValuePair<int, int>> Q = new Queue<KeyValuePair<int, int>>();
            d[iStart][jStart] = 1;
            Q.Enqueue(new KeyValuePair<int, int>(iStart, jStart));
            while (Q.Count != 0)
            {
                var top = Q.Dequeue();
                i = top.Key;
                j = top.Value;
                for (int p = 0; p < 4; ++p)
                {
                    iv = i + di[p];
                    jv = j + dj[p];
                    if (Ok(iv, jv) && d[iv][jv] > d[i][j] + 1)
                    {
                        d[iv][jv] = d[i][j] + 1;
                        Q.Enqueue(new KeyValuePair<int, int>(iv, jv));
                    }
                }
            }
        }

        private bool ConfictCuTraseulAnterior(int i, int j, int p) // p => sunt in (i, j) si incerc sa merg in directia p
        {
            if (c[i, j].hasTriangle) return true;   // triunghi
         
            // daca intru pe traseul anterior si incerc sa merg in sens opus, nu e ok, pt ca ma aduce de unde am venit
            if (p == 3 && traseu_anterior[i][j] == 1) return true; 
            if (p == 1 && traseu_anterior[i][j] == 3) return true;
            if (p == 0 && traseu_anterior[i][j] == 2) return true;
            if (p == 2 && traseu_anterior[i][j] == 0) return true;
            return false;
        }

        private bool OkBfs(int i, int j, int p)
        {
            if (i < 0 || i >= n || j < 0 || j >= m)
                return false;
            if (obst[i][j]) return false;  // meduza sau alt animal sfant protejat de UE

            if (ConfictCuTraseulAnterior(i, j, p)) 
                return false; // pt generare traseu
            return true;
        }

        private bool Ok(int i, int j)
        {
            if (i < 0 || i >= n || j < 0 || j >= m)
                return false;
            if (obst[i][j]) return false;

            return true;
        }
        private Cell FindCellMatchingRobot()
        {
            Cell cr = null;
            foreach (var c in celuleTraseu)
                if (Math.Abs(x - c.X0) < 4 && Math.Abs(y - c.Y0) < 4)
                {
                    cr = c;
                    break;
                }
            return cr;
        }

        private void Timer2Tick(object sender, EventArgs e)
        {
            pb.Invalidate();
            Cell cr = FindCellMatchingRobot();
            if (cr != null)
            {
                x = cr.X0; y = cr.Y0;
                directie = cr.directie;
                if (directie == Directie.Stop)
                {
                    timer2.Stop();
                    return;
                }

                if (directie == Directie.Sus)
                {
                    dx = 0;
                    dy = -increment;
                }

                if (directie == Directie.Dreapta)
                {
                    dx = increment;
                    dy = 0;
                }

                if (directie == Directie.Jos)
                {
                    dx = 0;
                    dy = increment;
                }

                if (directie == Directie.Stanga)
                {
                    dx = -increment;
                    dy = 0;
                }
            }
            pb.Invalidate();
            cr = FindCellMatchingRobot();
            if (cr != null && cr.Equals(celuleTraseu[celuleTraseu.Count - 1])) // daca am ajuns la destinatie
            {
                timer2.Enabled = false;

                return;
            }
            x += dx;
            y += dy;
        }

        private void CollectObstaclesBfs()
        {
            dir = new int[n][];
            traseu_anterior = new int[n][];
            for (int i = 0; i < n; ++i)
            {
                dir[i] = new int[m];
                traseu_anterior[i] = new int[m];
                for (int j = 0; j < m; ++j)
                {
                    dir[i][j] = -1;
                    traseu_anterior[i][j] = -1      ;
                }
            }
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                {
                    c[i, j].hasTriangle = false;
                    c[i, j].TriangleVisible = false;
                    c[i, j].Rot = -1;
                    if (c[i, j].file != null && c[i, j].file.Contains("Robot"))
                    {
                        iRobot = i; jRobot = j;
                    }

                    if (c[i, j].hasObject && c[i, j].file.Contains("Meduza"))
                        obst[i][j] = true;
                    if (c[i, j].file != null &&
                        (c[i, j].file.Contains("Hartie") ||
                        c[i, j].file.Contains("Plastic") ||
                        c[i, j].file.Contains("Sticla")))
                        rec[i][j] = true;
                }
        }

        private void CollectObstaclesLee()
        {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                {
                    if (c[i, j].file != null && c[i, j].file.Contains("Robot"))
                    {
                        iRobot = i; jRobot = j;
                    }

                    if (c[i, j].hasTriangle)
                        obst[i][j] = true;

                    if (c[i, j].hasObject && c[i, j].file.Contains("Meduza"))
                        obst[i][j] = true;

                    if (RobotInsideCell(c[i, j]))
                    {
                        iStop = i; jStop = j;
                    }
                }
        }

        void DrawRobot(PaintEventArgs e) // deseneaza robotul in miscare
        {
            if (gameStart || runLee)
            {
                float w = (float)pb.Width / m, h = (float)pb.Height / n;
                RectangleF r = new RectangleF(x, y, w, h);
                e.Graphics.DrawImage(robo, r);
            }
        }

        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            int W = pb.Size.Width;
            int H = pb.Size.Height;
            float x0, y0, w, h;

            for (int i = 0; i <= n; ++i)
                for (int j = 0; j <= m; ++j)
                {
                    if (gridVisible)
                        DrawLines(e, W, H, i, j);

                    x0 = (float)(j * W) / m; y0 = (float)(i * H) / n;
                    w = (float)W / m; h = (float)H / n;
                    if (i == n || j == m)
                        break;

                    c[i, j].X0 = x0; c[i, j].Y0 = y0;
                    c[i, j].W = w; c[i, j].H = h;

                    if (c[i, j].hasColor)
                        DrawBackground(c[i, j], Color.Aqua, e);


                    if (c[i, j].TriangleVisible)
                        DrawTriangle(c[i, j], e.Graphics);

                    if (c[i, j].ObjectVisible)
                        DrawObject(c[i, j], e.Graphics);
                }

            if (runLee) // desenez traseul de intoarcere pana la momentul curent
            {
                var c = FindCellWithRobot(celuleTraseu);
                foreach (Cell cel in celuleTraseu)
                {
                    DrawBackground(cel, Color.Red, e);
                    if (cel.Equals(c))
                        break;
                }
            }
            DrawRobot(e);
        }

        // deseneaza meduze, robot, reciclabile
        private void DrawObject(Cell c, Graphics g)
        {
            if (c.file == null)
                return;
            if (!c.ObjectVisible)// || (gameStart && pozInitRobot.Equals(c)))
                return;

            if (c.file.Contains("Robot") && (gameStart || runLee))
                return;
            RectangleF r = new RectangleF(c.X0, c.Y0, c.W, c.H);
            var img = Bitmap.FromFile(c.file);
            g.DrawImage(img, r);
            img.Dispose();
        }

        private void DrawBackground(Cell cel, Color color, PaintEventArgs e)
        {
            Pen pen = new Pen(Color.White, 3F);

            e.Graphics.DrawRectangle(pen, cel.X0, cel.Y0, cel.W, cel.H);
            SolidBrush brush = new SolidBrush(color);
            e.Graphics.FillRectangle(brush, cel.X0, cel.Y0, cel.W, cel.H);
            pen.Dispose();
        }

        private void cbShowGrid_CheckedChanged(object sender, EventArgs e)
        {
            if (cbShowGrid.Checked)
                gridVisible = true;
            else
                gridVisible = false;
            pb.Invalidate();
        }

        // deseneaza grid
        private void DrawLines(PaintEventArgs e, int W, int H, int i, int j)
        {
            Pen pen = new Pen(Color.White, 3F);
            e.Graphics.DrawLine(pen,
            new PointF(0F, ((float)(i * H) / n)),
            new PointF(1F * W, ((float)(i * H)) / n));

            e.Graphics.DrawLine(pen,
                new PointF(((float)(j * W) / m), 0F),
                new PointF(((float)(j * W) / m), (float)H));
            pen.Dispose();
        }

        // deseneaza triunghiul din dreapta
        private void splitContainer1_Panel2_Paint(object sender, PaintEventArgs e)
        {
            DrawTriangle(new Point(lblAddDeflector.Location.X + lblAddDeflector.Size.Width / 3,
                lblAddDeflector.Location.Y + 30), e.Graphics);
        }

        private void btnLoadMap_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFile = new OpenFileDialog();
            string dir = Directory.GetParent(Directory.GetCurrentDirectory()).Parent.FullName;
            openFile.InitialDirectory = dir;
            openFile.Filter = "Fisiere text (*.txt)|*.txt|Toate Fisierele (*.*)|*.*";
            var res = openFile.ShowDialog();
            if (res == DialogResult.OK)
            {
                currentMap = openFile.FileName;
                var sr = new StreamReader(currentMap);
                string line = string.Empty;
                string[] s = null;
                char[] sep = { ' ' };

                while ((line = sr.ReadLine()) != null)
                {
                    s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                    if (s[0] == "Robot")
                    {
                        I = int.Parse(s[2]) - 1;  // liniile si coloanele sunt inversate in desenul oficial
                        J = int.Parse(s[1]) - 1;
                    }

                    if (s[0] == "Hartie" || s[0] == "Plastic" || s[0] == "Sticla")
                        CntReciclabile++;

                    // in printscreen-ul din enunt liniile sunt inversate cu coloanele in raport cu fisierele de date 
                    AddObject(s[0], int.Parse(s[2]), int.Parse(s[1]));
                }
            }
            InitMatrDistMinimeSiDeflectoare(CntReciclabile, n, m);
            pb.Invalidate();
        }

        private void AddObject(string obj, int i, int j)
        {
            string file = null;

            if (obj == "Robot")
            {
                file = roboti + "Robot.png";
            }
            else
            if (obj.Substring(0, obj.Length - 1) == "Meduza")
                file = meduze + obj + ".png";
            else
                file = reciclabile + obj + ".png";

            c[i - 1, j - 1].file = file;
            c[i - 1, j - 1].ObjectVisible = true;
            c[i - 1, j - 1].hasObject = true;
        }

        private void btnRotate_Click(object sender, EventArgs e)
        {
            rotatie++;
            if (rotatie == 4) rotatie = 0;
            splitContainer1.Panel2.Invalidate();
        }

        private void btnGenerTraseu_Click(object sender, EventArgs e)
        {
            CollectObstaclesBfs();
            gataLee = true;
            runLee = false;
            runBfs = true;

            Bfs(iRobot, jRobot, d);

            // rec[k].Key, rec[k].Value = linia/coloana reciclabilului i
            List<KeyValuePair<int, int>> rc = new List<KeyValuePair<int, int>>();
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    if (rec[i][j])
                        rc.Add(new KeyValuePair<int, int>(i, j));

            rc.Sort((r1, r2) => d[r1.Key][r1.Value].CompareTo(d[r2.Key][r2.Value]));
            //     rc.Reverse(); // sorteze descrescator dupa distantele la robot

            for (int i = 0; i < rc.Count; ++i)
            {
                Bfs(rc[i].Key, rc[i].Value, D[i]);
            }
            
            int I = rc[rc.Count - 1].Key, J = rc[rc.Count - 1].Value;
            
            for (int p = 0; p < 4; ++p)
            {
                int iv = I + di[p];
                int jv = J + dj[p];
                if (OkBfs(iv, jv, p) && D[rc.Count - 2][iv][jv] + 1 == D[rc.Count - 2][I][J])//d[iv][jv] + 1 == d[I][J])
                {
                    I = iv;
                    J = jv;
                    dir[I][J] = p;
                    Console.WriteLine("DA");
                    break;
                }
            }

            // aici stiu de unde am sosit
            runBfs = true;
            int I1, J1;
            I1 = rc[rc.Count - 2].Key; J1 = rc[rc.Count - 2].Value;
            PutDeflectors(I, J, I1, J1, D[rc.Count - 2]); //
            
            WriteToConsole(dir);
            
            for (int i = rc.Count - 2; i >= 1; --i)
            {
                ResetVisitatedCells();
                I = rc[i].Key; J = rc[i].Value;
                I1 = rc[i - 1].Key; J1 = rc[i - 1].Value;
                PutDeflectors(I, J, I1, J1, D[i - 1]);
                WriteToConsole(dir);
            }
            ResetVisitatedCells();
            I = rc[0].Key; J = rc[0].Value;
            PutDeflectors(I, J, iRobot, jRobot, d);
            WriteToConsole(dir);
           
            pb.Invalidate();
            SaveFile("Traseu_deflectoare_generate.jpeg");
        }

        private void WriteToConsole(int[][] dir)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                    Console.Write(String.Format("{0, 3}", dir[i][j]));
                Console.WriteLine();
            }
            Console.WriteLine(); Console.WriteLine();
        }

        // am ajuns la linia (i, j) venind pe directia dir
        private void ResetVisitatedCells()
        {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    if (dir[i][j] == -1)
                        traseu_anterior[i][j] = -1;
                    else
                        traseu_anterior[i][j] = dir[i][j];
        }

        private bool PutDeflectors(int i, int j, int i1, int j1, int[][] d)
        {
            if (i == i1 && j == j1) return true;
            bool ok = false;
            int I = 0, J = 0;
            for (int p = 0; p < 4; ++p)
            {
                int iv = i + di[p];
                int jv = j + dj[p];
   
                if (!OkBfs(iv, jv, p)) continue;

                if (d[iv][jv] + 1 == d[i][j])
                {
                    I = iv; J = jv;
                    if (p == dir[i][j] )// || (I == i1 && J == j1))
                    {
                        dir[I][J] = dir[i][j];  
                        ok = PutDeflectors(I, J, i1, j1, d);
                        if (ok)
                            return true;
                    }
                }
                if (Inside(iv, jv) && dir[iv][jv] + 1 != d[i][j])
                    continue;
            }

            // n-am putut inainta pe aceeasi directie, incerc sa schimb directia
            for (int p = 0; p < 4; ++p)
            {
                int iv = i + di[p];
                int jv = j + dj[p];
                if (Inside(iv, jv) && d[iv][jv] + 1 != d[i][j])
                    continue;
                if (!OkBfs(iv, jv, p)) continue;

                if (d[iv][jv] + 1 == d[i][j])
                {
                    I = iv; J = jv;
           
                    dir[I][J] = dir[i][j];
                    
                    if (dir[i][j] == 0) // mergeam spre nord (veneam de jos)
                    {
                        dir[I][J] = dir[i][j];
                        if (p == 1) { c[i, j].Rot = 0; dir[I][J] = 1;  } // nord si dreapta                                                                   
                        if (p == 3) { c[i, j].Rot = 1; dir[I][J] = 3; } // nord si stanga
                        c[i, j].hasTriangle = true;
                        c[i, j].TriangleVisible = true;
                      
                        ok = PutDeflectors(I, J, i1, j1, d);
                        if (ok) return true;
                        continue;
                    }

                    if (dir[i][j] == 1) // mergeam spre  dreapta  celula (i, j)
                    {
                        dir[I][J] = dir[i][j];
                        if (p == 0) { c[i, j].Rot = 2; dir[I][J] = 0; } // dreapta spre nord
                        if (p == 2) { c[i, j].Rot = 1; dir[I][J] = 2; }// dreapta si jos

                        c[i, j].hasTriangle = true;
                        c[i, j].TriangleVisible = true;
                       
                        ok = PutDeflectors(I, J, i1, j1, d);
                        if (ok) return true;
                        continue;
                    }

                    if (dir[i][j] == 2) // mergeam in jos
                    {
                        dir[I][J] = dir[i][j];
                        if (p == 1) { c[i, j].Rot = 3; dir[I][J] = 1; }  // deviez drepta
                        if (p == 3) { c[i, j].Rot = 2; dir[I][J] = 3; } // deviez stanga
                        c[i, j].hasTriangle = true;
                        c[i, j].TriangleVisible = true;
                      
                        ok = PutDeflectors(I, J, i1, j1, d);
                        if (ok) return true;
                        continue;
                    }

                    if (dir[i][j] == 3) // mergeam spre stanga
                    {
                        dir[I][J] = dir[i][j];
                        if (p == 0) { c[i, j].Rot = 3; dir[I][J] = 0; }// deviez in sus
                        if (p == 2) { c[i, j].Rot = 0; dir[I][J] = 2; } // deviez jos

                        c[i, j].hasTriangle = true;
                        c[i, j].TriangleVisible = true;
                       
                        ok = PutDeflectors(I, J, i1, j1, d);
                        if (ok) return true;
                        continue;
                    }
                }
            }

            return ok;
        }

        private bool Inside(int i, int j)
        {
            return i >= 0 && i < n && j >= 0 && j < m;
        }

        private void InitMatrDistMinimeSiDeflectoare(int cntReciclabile, int n, int m)
        {
            d = new int[n][];
            for (int i = 0; i < n; ++i)
                d[i] = new int[m];

            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    d[i][j] = Inf;

            D = new int[CntReciclabile][][];
            for (int k = 0; k < CntReciclabile; ++k)
            {
                D[k] = new int[n][];
                for (int i = 0; i < n; ++i)
                    D[k][i] = new int[m];
            }

            for (int k = 0; k < CntReciclabile; ++k)
                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < m; ++j)
                        D[k][i][j] = Inf;

        }

        private void Bfs(int iStart, int jStart, int[][] d)
        {
            int i = 0, j = 0, iv = 0, jv = 0;
            Queue<KeyValuePair<int, int>> Q = new Queue<KeyValuePair<int, int>>();
            d[iStart][jStart] = 1;
            Q.Enqueue(new KeyValuePair<int, int>(iStart, jStart));

            while (Q.Count != 0)
            {
                var top = Q.Dequeue();
                i = top.Key;
                j = top.Value;
                for (int p = 0; p < 4; ++p)
                {
                    iv = i + di[p];
                    jv = j + dj[p];
                    if (Ok(iv, jv) && d[iv][jv] > d[i][j] + 1)
                    {
                        d[iv][jv] = d[i][j] + 1;
                        Q.Enqueue(new KeyValuePair<int, int>(iv, jv));
                    }
                }
            }
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            ExitApplicationForm frm = new ExitApplicationForm();
            frm.ShowDialog();
        }

        private void btnSaveJPG_Click(object sender, EventArgs e)
        {
            SaveFile(null);
        }

        int cntImg = 0;
        private void SaveFile(string fileName)
        {
            cntImg++;
            SaveFileDialog dlg = new SaveFileDialog();
            dlg.InitialDirectory = Directory.GetCurrentDirectory();
            dlg.Filter = "Fisiere Imagine (*.jpeg)|*.jpeg";
            if (fileName != null)
                dlg.FileName = fileName;
            else
                dlg.FileName = $"nume{cntImg}.jpeg";
            DialogResult dr = dlg.ShowDialog();

            if (dr == DialogResult.Cancel) return;
            for (int i = 0; i < 80000000; ++i)
            {
                i++; i--;
            }
            Rectangle rect = this.ClientRectangle;
            using (Bitmap bitmap = new Bitmap(rect.Width, rect.Height))
            {
                using (Graphics g = Graphics.FromImage(bitmap))
                {
                    g.CopyFromScreen(new Point(this.Left +
                        this.ClientRectangle.Left + pb.ClientRectangle.Left +
                        splitContainer1.Panel1.Left,
                        this.Top + this.ClientRectangle.Top + pb.ClientRectangle.Top +
                        splitContainer1.Panel1.Top + 30), Point.Empty, this.splitContainer1.Size);
                }
                if (fileName != null)
                    bitmap.Save(fileName, System.Drawing.Imaging.ImageFormat.Jpeg);
                else
                    bitmap.Save(string.Format("captura_{0}.jpeg", cntImg.ToString()), System.Drawing.Imaging.ImageFormat.Jpeg);
            }
        }

        private void btnRestart_Click(object sender, EventArgs e)
        {
            ReloadInitialState();
        }

        private void ReloadInitialState()
        {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                {
                    c[i, j].hasColor = false;
                    if (c[i, j].hasObject)
                        c[i, j].ObjectVisible = true;
                    if (c[i, j].hasTriangle)
                    c[i, j].TriangleVisible = true; 
                }
            gameStart = false;
            pb.Invalidate();
        }

        private void pb_MouseClick(object sender, MouseEventArgs e)
        {
            if (!triunghiSelected) return; // nu desenez triunghi la click decat daca triunghiul din drepata 
                                           // este selectat

            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    if (c[i, j].X0 <= e.X && c[i, j].Y0 <= e.Y && 
                        c[i, j].X0 + c[i, j].W >= e.X && c[i, j].Y0 + c[i, j].H >= e.Y)
                    {
                        c[i, j].TriangleVisible = true;
                        c[i, j].hasTriangle = true;
                        c[i, j].Rot = rotatie;
                        break;
                        
                    }
            pb.Invalidate();
        }

        private void splitContainer1_Panel2_MouseClick(object sender, MouseEventArgs e)
        {
            float X0 = (float)lblAddDeflector.Location.X + (float)lblAddDeflector.Size.Width / 3;
            float Y0 = (float)(lblAddDeflector.Location.Y + 30);
            float W = (float)pb.Size.Width;
            float H = (float)pb.Size.Height;
            float w = (float)W / m, h = (float)H / n;
            if (e.X >= X0 && e.X <= X0 + w && e.Y >= Y0 && e.Y <= Y0 + h)
            {
                triunghiSelected = !triunghiSelected; // inversez starea de selectare
                splitContainer1.Panel2.Invalidate();
            }
        }

        private void btnClean_Click(object sender, EventArgs e)
        {
            cntReciclabile = 0;
            lblHartie.Text = "Hartie ";
            lblPlastic.Text = "Plastic ";
            lblSticle.Text = "Sticle ";
            hartii = 0;
            plastic = 0;
            sticle = 0;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                {
                    c[i, j].ObjectVisible = false;
                    c[i, j].TriangleVisible = false;
                    c[i, j].hasTriangle = false;
                    c[i, j].Rot = -1;
                    c[i, j].hasColor = false;
               //     c[i, j].file = null;
                    if (dir != null) /// trebuie
                        dir[i][j] = -1;
                }
            runLee = false;
            runBfs = false;
            rotatie = 0;
            triunghiSelected = false;
            gridVisible = false;
            cbShowGrid.Checked = false;
            pb.Invalidate();
            currentMap = null;
            splitContainer1.Panel2.Invalidate();  
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            
            if (currentMap == null)
                return;
            if (btnStart.Text == "Start")
            {
                cntReciclabile = 0;
                btnStart.Text = "Stop";
                x = c[I, J].X0;
                y = c[I, J].Y0;
               
                DirectieRobotForm frm = new DirectieRobotForm();
                frm.ShowDialog();
                directie = frm.directie;
                switch (directie)
                {
                    case Directie.Sus:
                        dx = 0;
                        dy = -increment;
                        break;
                    case Directie.Dreapta:
                        dx = increment;
                        dy = 0;
                        break;
                    case Directie.Jos:
                        dx = 0;
                        dy = increment;
                        break;
                    case Directie.Stanga:
                        dx = -increment;
                        dy = 0;
                        break;
                }

                gameStart = true;

                timer.Enabled = true;
                timer.Start();
            }
            else
            {
                gameStart = false;
                timer.Stop();
                timer.Enabled = false;
                btnStart.Text = "Start";
            }
        }

        private void DrawTriangle(Cell c, Graphics g)
        {
            Pen pen = new Pen(Color.White, 3);

            float x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
            if (c.Rot == 0)
            {
                x1 = c.X0; y1 = c.Y0;
                x2 = x1 + c.W; y2 = y1;
                x3 = x1; y3 = y1 + c.H;
            }
            if (c.Rot == 1)
            {
                x1 = c.X0; y1 = c.Y0;
                x2 = x1 + c.W; y2 = y1;
                x3 = x1 + c.W; y3 = y1 + c.H;
            }

            if (c.Rot == 2)
            {
                x1 = c.X0 + c.W; y1 = c.Y0;
                x2 = x1; y2 = y1 + c.H;
                x3 = x1 - c.W; y3 = y1 + c.H;
            }

            if (c.Rot == 3)
            {
                x1 = c.X0; y1 = c.Y0;
                x2 = x1 + c.W; y2 = y1 + c.H;
                x3 = x1; y3 = y1 + c.H;
            }
            PointF p1 = new PointF(x1, y1);
            PointF p2 = new PointF(x2, y2);
            PointF p3 = new PointF(x3, y3);
            PointF[] triangle = { p1, p2, p3 };

            g.DrawPolygon(pen, triangle);
            SolidBrush brush = new SolidBrush(Color.White);
            g.FillPolygon(brush, triangle);
            pen.Dispose();
            brush.Dispose();
        }
        // 
        private void DrawTriangle(Point p, Graphics g)
        {
            float W = (float)pb.Size.Width;
            float H = (float)pb.Size.Height;
            float w = (float)W / m, h = (float)H / n;

            Pen pen = null;
            if (triunghiSelected)
                pen = new Pen(Color.Red, 5);
            else
                pen = new Pen(Color.White, 5);

            float x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
            if (rotatie == 0)
            {
                x1 = (float)p.X; y1 = (float)p.Y;
                x2 = x1 + w; y2 = y1;
                x3 = x1; y3 = y1 + h;
            }
            if (rotatie == 1)
            {
                x1 = (float)p.X; y1 = (float)p.Y;
                x2 = x1 + w; y2 = y1;
                x3 = x1 + w; y3 = y1 + h;
            }

            if (rotatie == 2)
            {
                x1 = (float)p.X + w; y1 = (float)p.Y;
                x2 = x1; y2 = y1 + h;
                x3 = x1 - w; y3 = y1 + h;
            }

            if (rotatie == 3)
            {
                x1 = (float)p.X; y1 = (float)p.Y;
                x2 = x1 + w; y2 = y1 + h;
                x3 = x1; y3 = y1 + h;
            }

            PointF p1 = new PointF(x1, y1);
            PointF p2 = new PointF(x2, y2);
            PointF p3 = new PointF(x3, y3);
            PointF[] triangle = { p1, p2, p3 };

            g.DrawPolygon(pen, triangle);
            SolidBrush brush = new SolidBrush(Color.White);
            g.FillPolygon(brush, triangle);
            pen.Dispose();
            brush.Dispose();

        }
    }
}
