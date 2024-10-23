namespace Turismul_de_pretutindeni
{
    partial class FrmVacanta
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FrmVacanta));
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.adaugaAdminNouToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.adaugaVacanteNoiToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.vacanteleMeleToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.emailToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.deconectareToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.iesireToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.pb = new System.Windows.Forms.PictureBox();
            this.pbStanga = new System.Windows.Forms.PictureBox();
            this.pbDreapta = new System.Windows.Forms.PictureBox();
            this.lblNume = new System.Windows.Forms.Label();
            this.lblPret = new System.Windows.Forms.Label();
            this.lblNrLocuri = new System.Windows.Forms.Label();
            this.lblDescriere = new System.Windows.Forms.Label();
            this.btnRezerva = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.chk = new System.Windows.Forms.CheckBox();
            this.menuStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pb)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbStanga)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbDreapta)).BeginInit();
            this.SuspendLayout();
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(61, 4);
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.vacanteleMeleToolStripMenuItem,
            this.emailToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(400, 24);
            this.menuStrip1.TabIndex = 1;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.adaugaAdminNouToolStripMenuItem,
            this.adaugaVacanteNoiToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // adaugaAdminNouToolStripMenuItem
            // 
            this.adaugaAdminNouToolStripMenuItem.Name = "adaugaAdminNouToolStripMenuItem";
            this.adaugaAdminNouToolStripMenuItem.Size = new System.Drawing.Size(179, 22);
            this.adaugaAdminNouToolStripMenuItem.Text = "Adauga admin nou";
            this.adaugaAdminNouToolStripMenuItem.Click += new System.EventHandler(this.adaugaAdminNouToolStripMenuItem_Click);
            // 
            // adaugaVacanteNoiToolStripMenuItem
            // 
            this.adaugaVacanteNoiToolStripMenuItem.Name = "adaugaVacanteNoiToolStripMenuItem";
            this.adaugaVacanteNoiToolStripMenuItem.Size = new System.Drawing.Size(179, 22);
            this.adaugaVacanteNoiToolStripMenuItem.Text = "Adauga vacante noi";
            this.adaugaVacanteNoiToolStripMenuItem.Click += new System.EventHandler(this.adaugaVacanteNoiToolStripMenuItem_Click);
            // 
            // vacanteleMeleToolStripMenuItem
            // 
            this.vacanteleMeleToolStripMenuItem.Name = "vacanteleMeleToolStripMenuItem";
            this.vacanteleMeleToolStripMenuItem.Size = new System.Drawing.Size(98, 20);
            this.vacanteleMeleToolStripMenuItem.Text = "Vacantele mele";
            this.vacanteleMeleToolStripMenuItem.Click += new System.EventHandler(this.vacanteleMeleToolStripMenuItem_Click);
            // 
            // emailToolStripMenuItem
            // 
            this.emailToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.deconectareToolStripMenuItem,
            this.iesireToolStripMenuItem});
            this.emailToolStripMenuItem.Name = "emailToolStripMenuItem";
            this.emailToolStripMenuItem.Size = new System.Drawing.Size(48, 20);
            this.emailToolStripMenuItem.Text = "email";
            // 
            // deconectareToolStripMenuItem
            // 
            this.deconectareToolStripMenuItem.Name = "deconectareToolStripMenuItem";
            this.deconectareToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.deconectareToolStripMenuItem.Text = "Deconectare";
            this.deconectareToolStripMenuItem.Click += new System.EventHandler(this.deconectareToolStripMenuItem_Click);
            // 
            // iesireToolStripMenuItem
            // 
            this.iesireToolStripMenuItem.Name = "iesireToolStripMenuItem";
            this.iesireToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.iesireToolStripMenuItem.Text = "Iesire";
            this.iesireToolStripMenuItem.Click += new System.EventHandler(this.iesireToolStripMenuItem_Click);
            // 
            // pb
            // 
            this.pb.Location = new System.Drawing.Point(107, 27);
            this.pb.Name = "pb";
            this.pb.Size = new System.Drawing.Size(199, 357);
            this.pb.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pb.TabIndex = 2;
            this.pb.TabStop = false;
            // 
            // pbStanga
            // 
            this.pbStanga.Image = ((System.Drawing.Image)(resources.GetObject("pbStanga.Image")));
            this.pbStanga.Location = new System.Drawing.Point(42, 169);
            this.pbStanga.Name = "pbStanga";
            this.pbStanga.Size = new System.Drawing.Size(59, 50);
            this.pbStanga.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbStanga.TabIndex = 3;
            this.pbStanga.TabStop = false;
            this.pbStanga.Click += new System.EventHandler(this.pbStanga_Click);
            // 
            // pbDreapta
            // 
            this.pbDreapta.Image = ((System.Drawing.Image)(resources.GetObject("pbDreapta.Image")));
            this.pbDreapta.Location = new System.Drawing.Point(312, 169);
            this.pbDreapta.Name = "pbDreapta";
            this.pbDreapta.Size = new System.Drawing.Size(59, 50);
            this.pbDreapta.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbDreapta.TabIndex = 4;
            this.pbDreapta.TabStop = false;
            this.pbDreapta.Click += new System.EventHandler(this.pbDreapta_Click);
            // 
            // lblNume
            // 
            this.lblNume.AutoSize = true;
            this.lblNume.BackColor = System.Drawing.Color.Transparent;
            this.lblNume.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblNume.ForeColor = System.Drawing.Color.White;
            this.lblNume.Location = new System.Drawing.Point(12, 12);
            this.lblNume.Name = "lblNume";
            this.lblNume.Size = new System.Drawing.Size(41, 13);
            this.lblNume.TabIndex = 5;
            this.lblNume.Text = "label1";
            // 
            // lblPret
            // 
            this.lblPret.AutoSize = true;
            this.lblPret.BackColor = System.Drawing.Color.Transparent;
            this.lblPret.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblPret.ForeColor = System.Drawing.Color.White;
            this.lblPret.Location = new System.Drawing.Point(12, 43);
            this.lblPret.Name = "lblPret";
            this.lblPret.Size = new System.Drawing.Size(41, 13);
            this.lblPret.TabIndex = 6;
            this.lblPret.Text = "label1";
            // 
            // lblNrLocuri
            // 
            this.lblNrLocuri.AutoSize = true;
            this.lblNrLocuri.BackColor = System.Drawing.Color.Transparent;
            this.lblNrLocuri.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblNrLocuri.ForeColor = System.Drawing.Color.White;
            this.lblNrLocuri.Location = new System.Drawing.Point(12, 80);
            this.lblNrLocuri.Name = "lblNrLocuri";
            this.lblNrLocuri.Size = new System.Drawing.Size(41, 13);
            this.lblNrLocuri.TabIndex = 7;
            this.lblNrLocuri.Text = "label1";
            // 
            // lblDescriere
            // 
            this.lblDescriere.AutoSize = true;
            this.lblDescriere.BackColor = System.Drawing.Color.Transparent;
            this.lblDescriere.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblDescriere.ForeColor = System.Drawing.Color.White;
            this.lblDescriere.Location = new System.Drawing.Point(12, 115);
            this.lblDescriere.MaximumSize = new System.Drawing.Size(150, 6000);
            this.lblDescriere.Name = "lblDescriere";
            this.lblDescriere.Size = new System.Drawing.Size(41, 13);
            this.lblDescriere.TabIndex = 8;
            this.lblDescriere.Text = "label1";
            // 
            // btnRezerva
            // 
            this.btnRezerva.Location = new System.Drawing.Point(144, 290);
            this.btnRezerva.Name = "btnRezerva";
            this.btnRezerva.Size = new System.Drawing.Size(129, 32);
            this.btnRezerva.TabIndex = 9;
            this.btnRezerva.Text = "Rezerva acum";
            this.btnRezerva.UseVisualStyleBackColor = true;
            this.btnRezerva.Click += new System.EventHandler(this.btnRezerva_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(144, 328);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(129, 32);
            this.button1.TabIndex = 10;
            this.button1.Text = "Poster";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // chk
            // 
            this.chk.AutoSize = true;
            this.chk.Location = new System.Drawing.Point(314, 361);
            this.chk.Name = "chk";
            this.chk.Size = new System.Drawing.Size(68, 17);
            this.chk.TabIndex = 11;
            this.chk.Text = "AutoPlay";
            this.chk.UseVisualStyleBackColor = true;
            this.chk.CheckedChanged += new System.EventHandler(this.chk_CheckedChanged);
            // 
            // FrmVacanta
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(400, 396);
            this.Controls.Add(this.chk);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.btnRezerva);
            this.Controls.Add(this.lblDescriere);
            this.Controls.Add(this.lblNrLocuri);
            this.Controls.Add(this.lblPret);
            this.Controls.Add(this.lblNume);
            this.Controls.Add(this.pbDreapta);
            this.Controls.Add(this.pbStanga);
            this.Controls.Add(this.pb);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "FrmVacanta";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "FrmVacanta";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pb)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbStanga)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbDreapta)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem adaugaAdminNouToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem adaugaVacanteNoiToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem vacanteleMeleToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem emailToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem deconectareToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem iesireToolStripMenuItem;
        private System.Windows.Forms.PictureBox pb;
        private System.Windows.Forms.PictureBox pbStanga;
        private System.Windows.Forms.PictureBox pbDreapta;
        private System.Windows.Forms.Label lblNume;
        private System.Windows.Forms.Label lblPret;
        private System.Windows.Forms.Label lblNrLocuri;
        private System.Windows.Forms.Label lblDescriere;
        private System.Windows.Forms.Button btnRezerva;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.CheckBox chk;
    }
}