namespace Interferente_ECO
{
    partial class InterferenteECO
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(InterferenteECO));
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.pb = new System.Windows.Forms.PictureBox();
            this.btnGen = new System.Windows.Forms.Button();
            this.btnSalveazaJpg = new System.Windows.Forms.Button();
            this.btnRestart = new System.Windows.Forms.Button();
            this.btnStart = new System.Windows.Forms.Button();
            this.lblPlastic = new System.Windows.Forms.Label();
            this.lblHartie = new System.Windows.Forms.Label();
            this.lblSticla = new System.Windows.Forms.Label();
            this.btnCurata = new System.Windows.Forms.Button();
            this.btnRoteste = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.btnIncarca = new System.Windows.Forms.Button();
            this.chkGrid = new System.Windows.Forms.CheckBox();
            this.btnClose = new System.Windows.Forms.Button();
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
            this.splitContainer1.Panel2.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.splitContainer1.Panel2.Controls.Add(this.btnClose);
            this.splitContainer1.Panel2.Controls.Add(this.btnGen);
            this.splitContainer1.Panel2.Controls.Add(this.btnSalveazaJpg);
            this.splitContainer1.Panel2.Controls.Add(this.btnRestart);
            this.splitContainer1.Panel2.Controls.Add(this.btnStart);
            this.splitContainer1.Panel2.Controls.Add(this.lblPlastic);
            this.splitContainer1.Panel2.Controls.Add(this.lblHartie);
            this.splitContainer1.Panel2.Controls.Add(this.lblSticla);
            this.splitContainer1.Panel2.Controls.Add(this.btnCurata);
            this.splitContainer1.Panel2.Controls.Add(this.btnRoteste);
            this.splitContainer1.Panel2.Controls.Add(this.label1);
            this.splitContainer1.Panel2.Controls.Add(this.btnIncarca);
            this.splitContainer1.Panel2.Controls.Add(this.chkGrid);
            this.splitContainer1.Panel2.ForeColor = System.Drawing.Color.White;
            this.splitContainer1.Panel2.Paint += new System.Windows.Forms.PaintEventHandler(this.splitContainer1_Panel2_Paint);
            this.splitContainer1.Panel2.MouseClick += new System.Windows.Forms.MouseEventHandler(this.splitContainer1_Panel2_MouseClick);
            this.splitContainer1.Size = new System.Drawing.Size(800, 527);
            this.splitContainer1.SplitterDistance = 625;
            this.splitContainer1.TabIndex = 0;
            // 
            // pb
            // 
            this.pb.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pb.Location = new System.Drawing.Point(0, 0);
            this.pb.Name = "pb";
            this.pb.Size = new System.Drawing.Size(625, 527);
            this.pb.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pb.TabIndex = 0;
            this.pb.TabStop = false;
            this.pb.Paint += new System.Windows.Forms.PaintEventHandler(this.pb_Paint);
            this.pb.MouseClick += new System.Windows.Forms.MouseEventHandler(this.pb_MouseClick);
            // 
            // btnGen
            // 
            this.btnGen.BackColor = System.Drawing.Color.Maroon;
            this.btnGen.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnGen.Location = new System.Drawing.Point(11, 485);
            this.btnGen.Name = "btnGen";
            this.btnGen.Size = new System.Drawing.Size(148, 29);
            this.btnGen.TabIndex = 11;
            this.btnGen.Text = "Genereaza traseu\r\n";
            this.btnGen.UseVisualStyleBackColor = false;
            this.btnGen.Click += new System.EventHandler(this.btnGen_Click);
            // 
            // btnSalveazaJpg
            // 
            this.btnSalveazaJpg.BackColor = System.Drawing.Color.Maroon;
            this.btnSalveazaJpg.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnSalveazaJpg.Location = new System.Drawing.Point(11, 459);
            this.btnSalveazaJpg.Name = "btnSalveazaJpg";
            this.btnSalveazaJpg.Size = new System.Drawing.Size(148, 29);
            this.btnSalveazaJpg.TabIndex = 10;
            this.btnSalveazaJpg.Text = "Salveaza jpg";
            this.btnSalveazaJpg.UseVisualStyleBackColor = false;
            this.btnSalveazaJpg.Click += new System.EventHandler(this.btnSalveazaJpg_Click);
            // 
            // btnRestart
            // 
            this.btnRestart.BackColor = System.Drawing.Color.Maroon;
            this.btnRestart.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnRestart.Location = new System.Drawing.Point(11, 436);
            this.btnRestart.Name = "btnRestart";
            this.btnRestart.Size = new System.Drawing.Size(148, 29);
            this.btnRestart.TabIndex = 9;
            this.btnRestart.Text = "Restart";
            this.btnRestart.UseVisualStyleBackColor = false;
            this.btnRestart.Click += new System.EventHandler(this.btnRestart_Click);
            // 
            // btnStart
            // 
            this.btnStart.BackColor = System.Drawing.Color.Maroon;
            this.btnStart.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnStart.Location = new System.Drawing.Point(11, 394);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(148, 45);
            this.btnStart.TabIndex = 8;
            this.btnStart.Text = "Start";
            this.btnStart.UseVisualStyleBackColor = false;
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // lblPlastic
            // 
            this.lblPlastic.AutoSize = true;
            this.lblPlastic.BackColor = System.Drawing.Color.Transparent;
            this.lblPlastic.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblPlastic.Location = new System.Drawing.Point(8, 359);
            this.lblPlastic.Name = "lblPlastic";
            this.lblPlastic.Size = new System.Drawing.Size(49, 17);
            this.lblPlastic.TabIndex = 7;
            this.lblPlastic.Text = "Plastic";
            // 
            // lblHartie
            // 
            this.lblHartie.AutoSize = true;
            this.lblHartie.BackColor = System.Drawing.Color.Transparent;
            this.lblHartie.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblHartie.Location = new System.Drawing.Point(8, 328);
            this.lblHartie.Name = "lblHartie";
            this.lblHartie.Size = new System.Drawing.Size(46, 17);
            this.lblHartie.TabIndex = 6;
            this.lblHartie.Text = "Hartie";
            // 
            // lblSticla
            // 
            this.lblSticla.AutoSize = true;
            this.lblSticla.BackColor = System.Drawing.Color.Transparent;
            this.lblSticla.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblSticla.Location = new System.Drawing.Point(8, 298);
            this.lblSticla.Name = "lblSticla";
            this.lblSticla.Size = new System.Drawing.Size(42, 17);
            this.lblSticla.TabIndex = 5;
            this.lblSticla.Text = "Sticle";
            // 
            // btnCurata
            // 
            this.btnCurata.BackColor = System.Drawing.Color.Maroon;
            this.btnCurata.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnCurata.Location = new System.Drawing.Point(11, 253);
            this.btnCurata.Name = "btnCurata";
            this.btnCurata.Size = new System.Drawing.Size(148, 29);
            this.btnCurata.TabIndex = 4;
            this.btnCurata.Text = "Curata tot";
            this.btnCurata.UseVisualStyleBackColor = false;
            this.btnCurata.Click += new System.EventHandler(this.btnCurata_Click);
            // 
            // btnRoteste
            // 
            this.btnRoteste.BackColor = System.Drawing.Color.Maroon;
            this.btnRoteste.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnRoteste.Location = new System.Drawing.Point(11, 218);
            this.btnRoteste.Name = "btnRoteste";
            this.btnRoteste.Size = new System.Drawing.Size(148, 29);
            this.btnRoteste.TabIndex = 3;
            this.btnRoteste.Text = "Roteste deflector";
            this.btnRoteste.UseVisualStyleBackColor = false;
            this.btnRoteste.Click += new System.EventHandler(this.btnRoteste_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(21, 90);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(132, 17);
            this.label1.TabIndex = 2;
            this.label1.Text = "Adauga deflector";
            // 
            // btnIncarca
            // 
            this.btnIncarca.BackColor = System.Drawing.Color.Maroon;
            this.btnIncarca.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnIncarca.ForeColor = System.Drawing.Color.Transparent;
            this.btnIncarca.Location = new System.Drawing.Point(11, 27);
            this.btnIncarca.Name = "btnIncarca";
            this.btnIncarca.Size = new System.Drawing.Size(148, 29);
            this.btnIncarca.TabIndex = 1;
            this.btnIncarca.Text = "Incarca harta";
            this.btnIncarca.UseVisualStyleBackColor = false;
            this.btnIncarca.Click += new System.EventHandler(this.btnIncarca_Click);
            // 
            // chkGrid
            // 
            this.chkGrid.AutoSize = true;
            this.chkGrid.BackColor = System.Drawing.Color.Transparent;
            this.chkGrid.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkGrid.ForeColor = System.Drawing.Color.White;
            this.chkGrid.Location = new System.Drawing.Point(11, 4);
            this.chkGrid.Name = "chkGrid";
            this.chkGrid.Size = new System.Drawing.Size(157, 19);
            this.chkGrid.TabIndex = 0;
            this.chkGrid.Text = "Afiseaza linii de grid";
            this.chkGrid.UseVisualStyleBackColor = false;
            this.chkGrid.CheckedChanged += new System.EventHandler(this.chkGrid_CheckedChanged);
            // 
            // btnClose
            // 
            this.btnClose.BackColor = System.Drawing.Color.Maroon;
            this.btnClose.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnClose.ForeColor = System.Drawing.Color.Transparent;
            this.btnClose.Location = new System.Drawing.Point(11, 58);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(148, 29);
            this.btnClose.TabIndex = 12;
            this.btnClose.Text = "Inchide aplicatie";
            this.btnClose.UseVisualStyleBackColor = false;
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // InterferenteECO
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 527);
            this.Controls.Add(this.splitContainer1);
            this.Name = "InterferenteECO";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "InterferenteECO";
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel2.ResumeLayout(false);
            this.splitContainer1.Panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pb)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.Label lblPlastic;
        private System.Windows.Forms.Label lblHartie;
        private System.Windows.Forms.Label lblSticla;
        private System.Windows.Forms.Button btnCurata;
        private System.Windows.Forms.Button btnRoteste;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnIncarca;
        private System.Windows.Forms.CheckBox chkGrid;
        private System.Windows.Forms.Button btnSalveazaJpg;
        private System.Windows.Forms.Button btnRestart;
        private System.Windows.Forms.Button btnGen;
        private System.Windows.Forms.PictureBox pb;
        private System.Windows.Forms.Button btnClose;
    }
}