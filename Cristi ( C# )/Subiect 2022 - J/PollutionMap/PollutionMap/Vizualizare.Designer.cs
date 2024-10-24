namespace PollutionMap
{
    partial class Vizualizare
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Vizualizare));
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.btnClose = new System.Windows.Forms.Button();
            this.btnReseteaza = new System.Windows.Forms.Button();
            this.cmbFiltru = new System.Windows.Forms.ComboBox();
            this.label4 = new System.Windows.Forms.Label();
            this.dtp = new System.Windows.Forms.DateTimePicker();
            this.label3 = new System.Windows.Forms.Label();
            this.cmbHarti = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.lbl = new System.Windows.Forms.Label();
            this.pb = new System.Windows.Forms.PictureBox();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.pbTraseu = new System.Windows.Forms.PictureBox();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pb)).BeginInit();
            this.tabPage2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pbTraseu)).BeginInit();
            this.SuspendLayout();
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControl1.Location = new System.Drawing.Point(0, 0);
            this.tabControl1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(1241, 625);
            this.tabControl1.TabIndex = 0;
            this.tabControl1.SelectedIndexChanged += new System.EventHandler(this.tabControl1_SelectedIndexChanged);
            // 
            // tabPage1
            // 
            this.tabPage1.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("tabPage1.BackgroundImage")));
            this.tabPage1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.tabPage1.Controls.Add(this.btnClose);
            this.tabPage1.Controls.Add(this.btnReseteaza);
            this.tabPage1.Controls.Add(this.cmbFiltru);
            this.tabPage1.Controls.Add(this.label4);
            this.tabPage1.Controls.Add(this.dtp);
            this.tabPage1.Controls.Add(this.label3);
            this.tabPage1.Controls.Add(this.cmbHarti);
            this.tabPage1.Controls.Add(this.label2);
            this.tabPage1.Controls.Add(this.lbl);
            this.tabPage1.Controls.Add(this.pb);
            this.tabPage1.Location = new System.Drawing.Point(4, 25);
            this.tabPage1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.tabPage1.Size = new System.Drawing.Size(1233, 596);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Harta";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(39, 542);
            this.btnClose.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(275, 44);
            this.btnClose.TabIndex = 10;
            this.btnClose.Text = "Inchide aplicatie";
            this.btnClose.UseVisualStyleBackColor = true;
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // btnReseteaza
            // 
            this.btnReseteaza.Location = new System.Drawing.Point(167, 479);
            this.btnReseteaza.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnReseteaza.Name = "btnReseteaza";
            this.btnReseteaza.Size = new System.Drawing.Size(135, 41);
            this.btnReseteaza.TabIndex = 9;
            this.btnReseteaza.Text = "Reseteaza filtru";
            this.btnReseteaza.UseVisualStyleBackColor = true;
            this.btnReseteaza.Click += new System.EventHandler(this.btnReseteaza_Click);
            // 
            // cmbFiltru
            // 
            this.cmbFiltru.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmbFiltru.FormattingEnabled = true;
            this.cmbFiltru.Items.AddRange(new object[] {
            "Niciun filtru",
            "Valoare < 20",
            "20 <= Valoare <= 40",
            "Valoare > 40"});
            this.cmbFiltru.Location = new System.Drawing.Point(35, 421);
            this.cmbFiltru.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.cmbFiltru.Name = "cmbFiltru";
            this.cmbFiltru.Size = new System.Drawing.Size(265, 24);
            this.cmbFiltru.TabIndex = 8;
            this.cmbFiltru.SelectedIndexChanged += new System.EventHandler(this.cmbFiltru_SelectedIndexChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(31, 401);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(35, 16);
            this.label4.TabIndex = 7;
            this.label4.Text = "Filtru";
            // 
            // dtp
            // 
            this.dtp.Location = new System.Drawing.Point(35, 240);
            this.dtp.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.dtp.Name = "dtp";
            this.dtp.Size = new System.Drawing.Size(265, 22);
            this.dtp.TabIndex = 6;
            this.dtp.ValueChanged += new System.EventHandler(this.dtp_ValueChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(31, 199);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(36, 16);
            this.label3.TabIndex = 4;
            this.label3.Text = "Data";
            // 
            // cmbHarti
            // 
            this.cmbHarti.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmbHarti.FormattingEnabled = true;
            this.cmbHarti.Location = new System.Drawing.Point(35, 122);
            this.cmbHarti.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.cmbHarti.Name = "cmbHarti";
            this.cmbHarti.Size = new System.Drawing.Size(265, 24);
            this.cmbHarti.TabIndex = 3;
            this.cmbHarti.SelectedIndexChanged += new System.EventHandler(this.cmbHarti_SelectedIndexChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(31, 102);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(35, 16);
            this.label2.TabIndex = 2;
            this.label2.Text = "Harti";
            // 
            // lbl
            // 
            this.lbl.AutoSize = true;
            this.lbl.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl.Location = new System.Drawing.Point(8, 21);
            this.lbl.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lbl.Name = "lbl";
            this.lbl.Size = new System.Drawing.Size(31, 25);
            this.lbl.TabIndex = 1;
            this.lbl.Text = "lbl";
            // 
            // pb
            // 
            this.pb.Image = ((System.Drawing.Image)(resources.GetObject("pb.Image")));
            this.pb.Location = new System.Drawing.Point(373, 0);
            this.pb.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.pb.Name = "pb";
            this.pb.Size = new System.Drawing.Size(853, 591);
            this.pb.TabIndex = 0;
            this.pb.TabStop = false;
            this.pb.Paint += new System.Windows.Forms.PaintEventHandler(this.pb_Paint);
            this.pb.MouseClick += new System.Windows.Forms.MouseEventHandler(this.pb_MouseClick);
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.pbTraseu);
            this.tabPage2.Location = new System.Drawing.Point(4, 25);
            this.tabPage2.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.tabPage2.Size = new System.Drawing.Size(1233, 596);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Traseu";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // pbTraseu
            // 
            this.pbTraseu.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pbTraseu.Location = new System.Drawing.Point(4, 4);
            this.pbTraseu.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.pbTraseu.Name = "pbTraseu";
            this.pbTraseu.Size = new System.Drawing.Size(1225, 588);
            this.pbTraseu.TabIndex = 0;
            this.pbTraseu.TabStop = false;
            this.pbTraseu.MouseClick += new System.Windows.Forms.MouseEventHandler(this.pbTraseu_MouseClick);
            // 
            // Vizualizare
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1241, 625);
            this.Controls.Add(this.tabControl1);
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "Vizualizare";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Vizualizare";
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pb)).EndInit();
            this.tabPage2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pbTraseu)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.PictureBox pb;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.DateTimePicker dtp;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ComboBox cmbHarti;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label lbl;
        private System.Windows.Forms.Button btnReseteaza;
        private System.Windows.Forms.ComboBox cmbFiltru;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.PictureBox pbTraseu;
        private System.Windows.Forms.Button btnClose;
    }
}