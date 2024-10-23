namespace Turismul_Durabil
{
    partial class GenerarePoster
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
            this.pb = new System.Windows.Forms.PictureBox();
            this.label1 = new System.Windows.Forms.Label();
            this.cmbLocalitate = new System.Windows.Forms.ComboBox();
            this.cmbIm = new System.Windows.Forms.ComboBox();
            this.cmbImagine = new System.Windows.Forms.Label();
            this.btnAdauga = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.lstbFisiere = new System.Windows.Forms.ListBox();
            this.label4 = new System.Windows.Forms.Label();
            this.txtTitlu = new System.Windows.Forms.TextBox();
            this.btnGen = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pb)).BeginInit();
            this.SuspendLayout();
            // 
            // pb
            // 
            this.pb.Location = new System.Drawing.Point(319, 28);
            this.pb.Name = "pb";
            this.pb.Size = new System.Drawing.Size(469, 338);
            this.pb.TabIndex = 0;
            this.pb.TabStop = false;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(33, 28);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(53, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Localitate";
            // 
            // cmbLocalitate
            // 
            this.cmbLocalitate.FormattingEnabled = true;
            this.cmbLocalitate.Location = new System.Drawing.Point(36, 52);
            this.cmbLocalitate.Name = "cmbLocalitate";
            this.cmbLocalitate.Size = new System.Drawing.Size(131, 21);
            this.cmbLocalitate.TabIndex = 2;
            this.cmbLocalitate.SelectedIndexChanged += new System.EventHandler(this.cmbLocalitate_SelectedIndexChanged);
            // 
            // cmbIm
            // 
            this.cmbIm.FormattingEnabled = true;
            this.cmbIm.Location = new System.Drawing.Point(36, 157);
            this.cmbIm.Name = "cmbIm";
            this.cmbIm.Size = new System.Drawing.Size(131, 21);
            this.cmbIm.TabIndex = 4;
            this.cmbIm.SelectedIndexChanged += new System.EventHandler(this.comboBox2_SelectedIndexChanged);
            // 
            // cmbImagine
            // 
            this.cmbImagine.AutoSize = true;
            this.cmbImagine.Location = new System.Drawing.Point(33, 133);
            this.cmbImagine.Name = "cmbImagine";
            this.cmbImagine.Size = new System.Drawing.Size(44, 13);
            this.cmbImagine.TabIndex = 3;
            this.cmbImagine.Text = "Imagine";
            // 
            // btnAdauga
            // 
            this.btnAdauga.Location = new System.Drawing.Point(179, 217);
            this.btnAdauga.Name = "btnAdauga";
            this.btnAdauga.Size = new System.Drawing.Size(120, 35);
            this.btnAdauga.TabIndex = 5;
            this.btnAdauga.Text = "Adauga";
            this.btnAdauga.UseVisualStyleBackColor = true;
            this.btnAdauga.Click += new System.EventHandler(this.btnAdauga_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(33, 260);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(64, 13);
            this.label3.TabIndex = 6;
            this.label3.Text = "Lista imagini";
            // 
            // lstbFisiere
            // 
            this.lstbFisiere.FormattingEnabled = true;
            this.lstbFisiere.Location = new System.Drawing.Point(36, 288);
            this.lstbFisiere.Name = "lstbFisiere";
            this.lstbFisiere.Size = new System.Drawing.Size(202, 95);
            this.lstbFisiere.TabIndex = 7;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(31, 422);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(27, 13);
            this.label4.TabIndex = 8;
            this.label4.Text = "Titlu";
            // 
            // txtTitlu
            // 
            this.txtTitlu.Location = new System.Drawing.Point(111, 421);
            this.txtTitlu.Name = "txtTitlu";
            this.txtTitlu.Size = new System.Drawing.Size(127, 20);
            this.txtTitlu.TabIndex = 9;
            // 
            // btnGen
            // 
            this.btnGen.Location = new System.Drawing.Point(479, 398);
            this.btnGen.Name = "btnGen";
            this.btnGen.Size = new System.Drawing.Size(140, 37);
            this.btnGen.TabIndex = 10;
            this.btnGen.Text = "Genereaza  Poster";
            this.btnGen.UseVisualStyleBackColor = true;
            this.btnGen.Click += new System.EventHandler(this.btnGen_Click);
            // 
            // GenerarePoster
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnGen);
            this.Controls.Add(this.txtTitlu);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.lstbFisiere);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.btnAdauga);
            this.Controls.Add(this.cmbIm);
            this.Controls.Add(this.cmbImagine);
            this.Controls.Add(this.cmbLocalitate);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.pb);
            this.Name = "GenerarePoster";
            this.Text = "Genereaza poster";
            ((System.ComponentModel.ISupportInitialize)(this.pb)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pb;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox cmbLocalitate;
        private System.Windows.Forms.ComboBox cmbIm;
        private System.Windows.Forms.Label cmbImagine;
        private System.Windows.Forms.Button btnAdauga;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ListBox lstbFisiere;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox txtTitlu;
        private System.Windows.Forms.Button btnGen;
    }
}

