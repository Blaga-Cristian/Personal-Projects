
namespace Interferente_ECO
{
    partial class InterfeteEcoForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(InterfeteEcoForm));
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.pb = new System.Windows.Forms.PictureBox();
            this.btnExit = new System.Windows.Forms.Button();
            this.btnGenerTraseu = new System.Windows.Forms.Button();
            this.btnSaveJPG = new System.Windows.Forms.Button();
            this.btnRestart = new System.Windows.Forms.Button();
            this.btnStart = new System.Windows.Forms.Button();
            this.lblPlastic = new System.Windows.Forms.Label();
            this.lblHartie = new System.Windows.Forms.Label();
            this.lblSticle = new System.Windows.Forms.Label();
            this.btnClean = new System.Windows.Forms.Button();
            this.btnRotate = new System.Windows.Forms.Button();
            this.lblAddDeflector = new System.Windows.Forms.Label();
            this.cbShowGrid = new System.Windows.Forms.CheckBox();
            this.btnLoadMap = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pb)).BeginInit();
            this.SuspendLayout();
            // 
            // splitContainer1
            // 
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point(0, 0);
            this.splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.pb);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("splitContainer1.Panel2.BackgroundImage")));
            this.splitContainer1.Panel2.Controls.Add(this.btnExit);
            this.splitContainer1.Panel2.Controls.Add(this.btnGenerTraseu);
            this.splitContainer1.Panel2.Controls.Add(this.btnSaveJPG);
            this.splitContainer1.Panel2.Controls.Add(this.btnRestart);
            this.splitContainer1.Panel2.Controls.Add(this.btnStart);
            this.splitContainer1.Panel2.Controls.Add(this.lblPlastic);
            this.splitContainer1.Panel2.Controls.Add(this.lblHartie);
            this.splitContainer1.Panel2.Controls.Add(this.lblSticle);
            this.splitContainer1.Panel2.Controls.Add(this.btnClean);
            this.splitContainer1.Panel2.Controls.Add(this.btnRotate);
            this.splitContainer1.Panel2.Controls.Add(this.lblAddDeflector);
            this.splitContainer1.Panel2.Controls.Add(this.cbShowGrid);
            this.splitContainer1.Panel2.Controls.Add(this.btnLoadMap);
            this.splitContainer1.Panel2.Paint += new System.Windows.Forms.PaintEventHandler(this.splitContainer1_Panel2_Paint);
            this.splitContainer1.Panel2.MouseClick += new System.Windows.Forms.MouseEventHandler(this.splitContainer1_Panel2_MouseClick);
            this.splitContainer1.Size = new System.Drawing.Size(1370, 715);
            this.splitContainer1.SplitterDistance = 1170;
            this.splitContainer1.TabIndex = 0;
            // 
            // pb
            // 
            this.pb.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pb.Image = ((System.Drawing.Image)(resources.GetObject("pb.Image")));
            this.pb.Location = new System.Drawing.Point(0, 0);
            this.pb.Name = "pb";
            this.pb.Size = new System.Drawing.Size(1170, 715);
            this.pb.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pb.TabIndex = 0;
            this.pb.TabStop = false;
            this.pb.Paint += new System.Windows.Forms.PaintEventHandler(this.pictureBox1_Paint);
            this.pb.MouseClick += new System.Windows.Forms.MouseEventHandler(this.pb_MouseClick);
            // 
            // btnExit
            // 
            this.btnExit.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.btnExit.BackColor = System.Drawing.Color.Brown;
            this.btnExit.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnExit.ForeColor = System.Drawing.Color.White;
            this.btnExit.Location = new System.Drawing.Point(23, 666);
            this.btnExit.Name = "btnExit";
            this.btnExit.Size = new System.Drawing.Size(157, 40);
            this.btnExit.TabIndex = 12;
            this.btnExit.Text = "Iesire Aplicatie";
            this.btnExit.UseVisualStyleBackColor = false;
            this.btnExit.Click += new System.EventHandler(this.btnExit_Click);
            // 
            // btnGenerTraseu
            // 
            this.btnGenerTraseu.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.btnGenerTraseu.BackColor = System.Drawing.Color.Brown;
            this.btnGenerTraseu.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnGenerTraseu.ForeColor = System.Drawing.Color.White;
            this.btnGenerTraseu.Location = new System.Drawing.Point(23, 608);
            this.btnGenerTraseu.Name = "btnGenerTraseu";
            this.btnGenerTraseu.Size = new System.Drawing.Size(157, 40);
            this.btnGenerTraseu.TabIndex = 11;
            this.btnGenerTraseu.Text = "Genereaza traseu";
            this.btnGenerTraseu.UseVisualStyleBackColor = false;
            this.btnGenerTraseu.Click += new System.EventHandler(this.btnGenerTraseu_Click);
            // 
            // btnSaveJPG
            // 
            this.btnSaveJPG.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.btnSaveJPG.BackColor = System.Drawing.Color.Brown;
            this.btnSaveJPG.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnSaveJPG.ForeColor = System.Drawing.Color.White;
            this.btnSaveJPG.Location = new System.Drawing.Point(23, 560);
            this.btnSaveJPG.Name = "btnSaveJPG";
            this.btnSaveJPG.Size = new System.Drawing.Size(157, 40);
            this.btnSaveJPG.TabIndex = 10;
            this.btnSaveJPG.Text = "Salveaza JPG";
            this.btnSaveJPG.UseVisualStyleBackColor = false;
            this.btnSaveJPG.Click += new System.EventHandler(this.btnSaveJPG_Click);
            // 
            // btnRestart
            // 
            this.btnRestart.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.btnRestart.BackColor = System.Drawing.Color.Brown;
            this.btnRestart.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnRestart.ForeColor = System.Drawing.Color.White;
            this.btnRestart.Location = new System.Drawing.Point(23, 511);
            this.btnRestart.Name = "btnRestart";
            this.btnRestart.Size = new System.Drawing.Size(157, 40);
            this.btnRestart.TabIndex = 9;
            this.btnRestart.Text = "Restart";
            this.btnRestart.UseVisualStyleBackColor = false;
            this.btnRestart.Click += new System.EventHandler(this.btnRestart_Click);
            // 
            // btnStart
            // 
            this.btnStart.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.btnStart.BackColor = System.Drawing.Color.Brown;
            this.btnStart.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnStart.ForeColor = System.Drawing.Color.White;
            this.btnStart.Location = new System.Drawing.Point(23, 463);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(157, 40);
            this.btnStart.TabIndex = 8;
            this.btnStart.Text = "Start";
            this.btnStart.UseVisualStyleBackColor = false;
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // lblPlastic
            // 
            this.lblPlastic.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblPlastic.ForeColor = System.Drawing.Color.White;
            this.lblPlastic.Location = new System.Drawing.Point(23, 409);
            this.lblPlastic.Name = "lblPlastic";
            this.lblPlastic.Size = new System.Drawing.Size(176, 23);
            this.lblPlastic.TabIndex = 7;
            this.lblPlastic.Text = "Plastic";
            this.lblPlastic.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblHartie
            // 
            this.lblHartie.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblHartie.ForeColor = System.Drawing.Color.White;
            this.lblHartie.Location = new System.Drawing.Point(23, 377);
            this.lblHartie.Name = "lblHartie";
            this.lblHartie.Size = new System.Drawing.Size(176, 23);
            this.lblHartie.TabIndex = 6;
            this.lblHartie.Text = "Hartie";
            this.lblHartie.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblSticle
            // 
            this.lblSticle.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblSticle.ForeColor = System.Drawing.Color.White;
            this.lblSticle.Location = new System.Drawing.Point(23, 345);
            this.lblSticle.Name = "lblSticle";
            this.lblSticle.Size = new System.Drawing.Size(176, 23);
            this.lblSticle.TabIndex = 5;
            this.lblSticle.Text = "Sticle";
            this.lblSticle.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // btnClean
            // 
            this.btnClean.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.btnClean.BackColor = System.Drawing.Color.Brown;
            this.btnClean.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnClean.ForeColor = System.Drawing.Color.White;
            this.btnClean.Location = new System.Drawing.Point(23, 279);
            this.btnClean.Name = "btnClean";
            this.btnClean.Size = new System.Drawing.Size(157, 40);
            this.btnClean.TabIndex = 4;
            this.btnClean.Text = "Curata tot";
            this.btnClean.UseVisualStyleBackColor = false;
            this.btnClean.Click += new System.EventHandler(this.btnClean_Click);
            // 
            // btnRotate
            // 
            this.btnRotate.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.btnRotate.BackColor = System.Drawing.Color.Brown;
            this.btnRotate.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnRotate.ForeColor = System.Drawing.Color.White;
            this.btnRotate.Location = new System.Drawing.Point(23, 224);
            this.btnRotate.Name = "btnRotate";
            this.btnRotate.Size = new System.Drawing.Size(157, 40);
            this.btnRotate.TabIndex = 3;
            this.btnRotate.Text = "Roteste deflector";
            this.btnRotate.UseVisualStyleBackColor = false;
            this.btnRotate.Click += new System.EventHandler(this.btnRotate_Click);
            // 
            // lblAddDeflector
            // 
            this.lblAddDeflector.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblAddDeflector.ForeColor = System.Drawing.Color.White;
            this.lblAddDeflector.Location = new System.Drawing.Point(23, 105);
            this.lblAddDeflector.Name = "lblAddDeflector";
            this.lblAddDeflector.Size = new System.Drawing.Size(176, 23);
            this.lblAddDeflector.TabIndex = 2;
            this.lblAddDeflector.Text = "Adauga deflector";
            this.lblAddDeflector.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // cbShowGrid
            // 
            this.cbShowGrid.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cbShowGrid.ForeColor = System.Drawing.Color.White;
            this.cbShowGrid.Location = new System.Drawing.Point(23, 12);
            this.cbShowGrid.Name = "cbShowGrid";
            this.cbShowGrid.Size = new System.Drawing.Size(176, 24);
            this.cbShowGrid.TabIndex = 1;
            this.cbShowGrid.Text = "Afiseaza linii de grid";
            this.cbShowGrid.UseVisualStyleBackColor = false;
            this.cbShowGrid.CheckedChanged += new System.EventHandler(this.cbShowGrid_CheckedChanged);
            // 
            // btnLoadMap
            // 
            this.btnLoadMap.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.btnLoadMap.BackColor = System.Drawing.Color.Brown;
            this.btnLoadMap.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnLoadMap.ForeColor = System.Drawing.Color.White;
            this.btnLoadMap.Location = new System.Drawing.Point(23, 42);
            this.btnLoadMap.Name = "btnLoadMap";
            this.btnLoadMap.Size = new System.Drawing.Size(157, 40);
            this.btnLoadMap.TabIndex = 0;
            this.btnLoadMap.Text = "Incarca Harta";
            this.btnLoadMap.UseVisualStyleBackColor = false;
            this.btnLoadMap.Click += new System.EventHandler(this.btnLoadMap_Click);
            // 
            // InterfeteEcoForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1370, 715);
            this.Controls.Add(this.splitContainer1);
            this.Name = "InterfeteEcoForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Interfete ECO";
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pb)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.PictureBox pb;
        private System.Windows.Forms.CheckBox cbShowGrid;
        private System.Windows.Forms.Button btnLoadMap;
        private System.Windows.Forms.Label lblAddDeflector;
        private System.Windows.Forms.Button btnClean;
        private System.Windows.Forms.Button btnRotate;
        private System.Windows.Forms.Button btnExit;
        private System.Windows.Forms.Button btnGenerTraseu;
        private System.Windows.Forms.Button btnSaveJPG;
        private System.Windows.Forms.Button btnRestart;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.Label lblPlastic;
        private System.Windows.Forms.Label lblHartie;
        private System.Windows.Forms.Label lblSticle;
    }
}

