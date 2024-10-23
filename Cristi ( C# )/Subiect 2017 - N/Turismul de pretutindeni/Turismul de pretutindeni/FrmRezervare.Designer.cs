namespace Turismul_de_pretutindeni
{
    partial class FrmRezervare
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
            this.mc = new System.Windows.Forms.MonthCalendar();
            this.label1 = new System.Windows.Forms.Label();
            this.lblNumeVacanta = new System.Windows.Forms.Label();
            this.lblDescriere = new System.Windows.Forms.Label();
            this.lblPret = new System.Windows.Forms.Label();
            this.lblPersoaneDisponibile = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.txtPersoane = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.txtPret = new System.Windows.Forms.TextBox();
            this.btnRezervare = new System.Windows.Forms.Button();
            this.pb = new System.Windows.Forms.PictureBox();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pb)).BeginInit();
            this.SuspendLayout();
            // 
            // mc
            // 
            this.mc.Location = new System.Drawing.Point(18, 270);
            this.mc.Name = "mc";
            this.mc.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(15, 248);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(165, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Selectati data de inceput si sfarsit";
            // 
            // lblNumeVacanta
            // 
            this.lblNumeVacanta.AutoSize = true;
            this.lblNumeVacanta.Location = new System.Drawing.Point(6, 26);
            this.lblNumeVacanta.Name = "lblNumeVacanta";
            this.lblNumeVacanta.Size = new System.Drawing.Size(35, 13);
            this.lblNumeVacanta.TabIndex = 2;
            this.lblNumeVacanta.Text = "label2";
            // 
            // lblDescriere
            // 
            this.lblDescriere.AutoSize = true;
            this.lblDescriere.Location = new System.Drawing.Point(6, 57);
            this.lblDescriere.MaximumSize = new System.Drawing.Size(260, 0);
            this.lblDescriere.Name = "lblDescriere";
            this.lblDescriere.Size = new System.Drawing.Size(35, 13);
            this.lblDescriere.TabIndex = 3;
            this.lblDescriere.Text = "label2";
            // 
            // lblPret
            // 
            this.lblPret.AutoSize = true;
            this.lblPret.Location = new System.Drawing.Point(100, 26);
            this.lblPret.Name = "lblPret";
            this.lblPret.Size = new System.Drawing.Size(35, 13);
            this.lblPret.TabIndex = 4;
            this.lblPret.Text = "label2";
            // 
            // lblPersoaneDisponibile
            // 
            this.lblPersoaneDisponibile.AutoSize = true;
            this.lblPersoaneDisponibile.Location = new System.Drawing.Point(152, 26);
            this.lblPersoaneDisponibile.Name = "lblPersoaneDisponibile";
            this.lblPersoaneDisponibile.Size = new System.Drawing.Size(35, 13);
            this.lblPersoaneDisponibile.TabIndex = 5;
            this.lblPersoaneDisponibile.Text = "label2";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.lblNumeVacanta);
            this.groupBox1.Controls.Add(this.lblPersoaneDisponibile);
            this.groupBox1.Controls.Add(this.lblDescriere);
            this.groupBox1.Controls.Add(this.lblPret);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(280, 181);
            this.groupBox1.TabIndex = 6;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Detalii vacanta";
            // 
            // txtPersoane
            // 
            this.txtPersoane.Location = new System.Drawing.Point(299, 270);
            this.txtPersoane.Name = "txtPersoane";
            this.txtPersoane.Size = new System.Drawing.Size(128, 20);
            this.txtPersoane.TabIndex = 7;
            this.txtPersoane.TextChanged += new System.EventHandler(this.txtPersoane_TextChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(296, 248);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(131, 13);
            this.label2.TabIndex = 8;
            this.label2.Text = "Introduceti nr de persoane";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(296, 308);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(49, 13);
            this.label3.TabIndex = 9;
            this.label3.Text = "Pret total";
            // 
            // txtPret
            // 
            this.txtPret.Location = new System.Drawing.Point(299, 324);
            this.txtPret.Name = "txtPret";
            this.txtPret.ReadOnly = true;
            this.txtPret.Size = new System.Drawing.Size(128, 20);
            this.txtPret.TabIndex = 10;
            // 
            // btnRezervare
            // 
            this.btnRezervare.Location = new System.Drawing.Point(299, 371);
            this.btnRezervare.Name = "btnRezervare";
            this.btnRezervare.Size = new System.Drawing.Size(128, 23);
            this.btnRezervare.TabIndex = 11;
            this.btnRezervare.Text = "Creaza rezervare";
            this.btnRezervare.UseVisualStyleBackColor = true;
            this.btnRezervare.Click += new System.EventHandler(this.btnRezervare_Click);
            // 
            // pb
            // 
            this.pb.Location = new System.Drawing.Point(299, 12);
            this.pb.Name = "pb";
            this.pb.Size = new System.Drawing.Size(166, 181);
            this.pb.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pb.TabIndex = 12;
            this.pb.TabStop = false;
            // 
            // FrmRezervare
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(483, 450);
            this.Controls.Add(this.pb);
            this.Controls.Add(this.btnRezervare);
            this.Controls.Add(this.txtPret);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.txtPersoane);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.mc);
            this.Name = "FrmRezervare";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "FrmRezervare";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pb)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MonthCalendar mc;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label lblNumeVacanta;
        private System.Windows.Forms.Label lblDescriere;
        private System.Windows.Forms.Label lblPret;
        private System.Windows.Forms.Label lblPersoaneDisponibile;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox txtPersoane;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txtPret;
        private System.Windows.Forms.Button btnRezervare;
        private System.Windows.Forms.PictureBox pb;
    }
}