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
            this.splitter1 = new System.Windows.Forms.Splitter();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.pb = new System.Windows.Forms.PictureBox();
            this.btnLoad = new System.Windows.Forms.Button();
            this.lblPlastic = new System.Windows.Forms.Label();
            this.lblHartie = new System.Windows.Forms.Label();
            this.lblSticle = new System.Windows.Forms.Label();
            this.btnGen = new System.Windows.Forms.Button();
            this.btnSave = new System.Windows.Forms.Button();
            this.btnRestart = new System.Windows.Forms.Button();
            this.btnStart = new System.Windows.Forms.Button();
            this.btnClear = new System.Windows.Forms.Button();
            this.btnRoteste = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.chk = new System.Windows.Forms.CheckBox();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pb)).BeginInit();
            this.SuspendLayout();
            // 
            // splitter1
            // 
            this.splitter1.Location = new System.Drawing.Point(0, 0);
            this.splitter1.Name = "splitter1";
            this.splitter1.Size = new System.Drawing.Size(3, 450);
            this.splitter1.TabIndex = 0;
            this.splitter1.TabStop = false;
            // 
            // splitContainer1
            // 
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point(3, 0);
            this.splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.pb);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.btnLoad);
            this.splitContainer1.Panel2.Controls.Add(this.lblPlastic);
            this.splitContainer1.Panel2.Controls.Add(this.lblHartie);
            this.splitContainer1.Panel2.Controls.Add(this.lblSticle);
            this.splitContainer1.Panel2.Controls.Add(this.btnGen);
            this.splitContainer1.Panel2.Controls.Add(this.btnSave);
            this.splitContainer1.Panel2.Controls.Add(this.btnRestart);
            this.splitContainer1.Panel2.Controls.Add(this.btnStart);
            this.splitContainer1.Panel2.Controls.Add(this.btnClear);
            this.splitContainer1.Panel2.Controls.Add(this.btnRoteste);
            this.splitContainer1.Panel2.Controls.Add(this.label1);
            this.splitContainer1.Panel2.Controls.Add(this.chk);
            this.splitContainer1.Panel2.Paint += new System.Windows.Forms.PaintEventHandler(this.splitContainer1_Panel2_Paint);
            this.splitContainer1.Panel2.MouseClick += new System.Windows.Forms.MouseEventHandler(this.splitContainer1_Panel2_MouseClick);
            this.splitContainer1.Size = new System.Drawing.Size(797, 450);
            this.splitContainer1.SplitterDistance = 616;
            this.splitContainer1.TabIndex = 1;
            // 
            // pb
            // 
            this.pb.Location = new System.Drawing.Point(-3, 0);
            this.pb.Name = "pb";
            this.pb.Size = new System.Drawing.Size(616, 450);
            this.pb.TabIndex = 0;
            this.pb.TabStop = false;
            this.pb.Paint += new System.Windows.Forms.PaintEventHandler(this.pb_Paint);
            this.pb.MouseClick += new System.Windows.Forms.MouseEventHandler(this.pb_MouseClick);
            // 
            // btnLoad
            // 
            this.btnLoad.Location = new System.Drawing.Point(25, 46);
            this.btnLoad.Name = "btnLoad";
            this.btnLoad.Size = new System.Drawing.Size(103, 26);
            this.btnLoad.TabIndex = 11;
            this.btnLoad.Text = "Incarca harta";
            this.btnLoad.UseVisualStyleBackColor = true;
            this.btnLoad.Click += new System.EventHandler(this.btnLoad_Click);
            // 
            // lblPlastic
            // 
            this.lblPlastic.AutoSize = true;
            this.lblPlastic.BackColor = System.Drawing.Color.Transparent;
            this.lblPlastic.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblPlastic.ForeColor = System.Drawing.Color.White;
            this.lblPlastic.Location = new System.Drawing.Point(32, 295);
            this.lblPlastic.Name = "lblPlastic";
            this.lblPlastic.Size = new System.Drawing.Size(46, 17);
            this.lblPlastic.TabIndex = 10;
            this.lblPlastic.Text = "label4";
            // 
            // lblHartie
            // 
            this.lblHartie.AutoSize = true;
            this.lblHartie.BackColor = System.Drawing.Color.Transparent;
            this.lblHartie.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblHartie.ForeColor = System.Drawing.Color.White;
            this.lblHartie.Location = new System.Drawing.Point(32, 269);
            this.lblHartie.Name = "lblHartie";
            this.lblHartie.Size = new System.Drawing.Size(46, 17);
            this.lblHartie.TabIndex = 9;
            this.lblHartie.Text = "label3";
            // 
            // lblSticle
            // 
            this.lblSticle.AutoSize = true;
            this.lblSticle.BackColor = System.Drawing.Color.Transparent;
            this.lblSticle.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblSticle.ForeColor = System.Drawing.Color.White;
            this.lblSticle.Location = new System.Drawing.Point(32, 244);
            this.lblSticle.Name = "lblSticle";
            this.lblSticle.Size = new System.Drawing.Size(46, 17);
            this.lblSticle.TabIndex = 8;
            this.lblSticle.Text = "label2";
            // 
            // btnGen
            // 
            this.btnGen.Location = new System.Drawing.Point(35, 412);
            this.btnGen.Name = "btnGen";
            this.btnGen.Size = new System.Drawing.Size(103, 35);
            this.btnGen.TabIndex = 7;
            this.btnGen.Text = "Genereaza traseu";
            this.btnGen.UseVisualStyleBackColor = true;
            this.btnGen.Click += new System.EventHandler(this.btnGen_Click);
            // 
            // btnSave
            // 
            this.btnSave.Location = new System.Drawing.Point(35, 388);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(103, 26);
            this.btnSave.TabIndex = 6;
            this.btnSave.Text = "Salveaza jpg";
            this.btnSave.UseVisualStyleBackColor = true;
            this.btnSave.Click += new System.EventHandler(this.btnSave_Click);
            // 
            // btnRestart
            // 
            this.btnRestart.Location = new System.Drawing.Point(35, 365);
            this.btnRestart.Name = "btnRestart";
            this.btnRestart.Size = new System.Drawing.Size(103, 26);
            this.btnRestart.TabIndex = 5;
            this.btnRestart.Text = "Restart";
            this.btnRestart.UseVisualStyleBackColor = true;
            this.btnRestart.Click += new System.EventHandler(this.btnRestart_Click);
            // 
            // btnStart
            // 
            this.btnStart.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnStart.Location = new System.Drawing.Point(35, 326);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(103, 45);
            this.btnStart.TabIndex = 4;
            this.btnStart.Text = "Start";
            this.btnStart.UseVisualStyleBackColor = true;
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // btnClear
            // 
            this.btnClear.Location = new System.Drawing.Point(35, 200);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(103, 26);
            this.btnClear.TabIndex = 3;
            this.btnClear.Text = "Curata tot";
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // btnRoteste
            // 
            this.btnRoteste.Location = new System.Drawing.Point(35, 168);
            this.btnRoteste.Name = "btnRoteste";
            this.btnRoteste.Size = new System.Drawing.Size(103, 26);
            this.btnRoteste.TabIndex = 2;
            this.btnRoteste.Text = "Roteste deflector";
            this.btnRoteste.UseVisualStyleBackColor = true;
            this.btnRoteste.Click += new System.EventHandler(this.btnRoteste_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.White;
            this.label1.Location = new System.Drawing.Point(22, 75);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(116, 17);
            this.label1.TabIndex = 1;
            this.label1.Text = "Adauga deflector";
            // 
            // chk
            // 
            this.chk.AutoSize = true;
            this.chk.BackColor = System.Drawing.Color.Transparent;
            this.chk.ForeColor = System.Drawing.Color.White;
            this.chk.Location = new System.Drawing.Point(25, 14);
            this.chk.Name = "chk";
            this.chk.Size = new System.Drawing.Size(118, 17);
            this.chk.TabIndex = 0;
            this.chk.Text = "Afiseaza linii de grid";
            this.chk.UseVisualStyleBackColor = false;
            this.chk.CheckedChanged += new System.EventHandler(this.chk_CheckedChanged);
            // 
            // InterferenteECO
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoValidate = System.Windows.Forms.AutoValidate.EnableAllowFocusChange;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.splitContainer1);
            this.Controls.Add(this.splitter1);
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

        private System.Windows.Forms.Splitter splitter1;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.CheckBox chk;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnRoteste;
        private System.Windows.Forms.Label lblPlastic;
        private System.Windows.Forms.Label lblHartie;
        private System.Windows.Forms.Label lblSticle;
        private System.Windows.Forms.Button btnGen;
        private System.Windows.Forms.Button btnSave;
        private System.Windows.Forms.Button btnRestart;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.Button btnLoad;
        private System.Windows.Forms.PictureBox pb;
    }
}