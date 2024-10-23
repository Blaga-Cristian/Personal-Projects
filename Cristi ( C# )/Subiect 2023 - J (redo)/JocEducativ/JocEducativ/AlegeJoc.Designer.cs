namespace JocEducativ
{
    partial class AlegeJoc
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
            this.lbl = new System.Windows.Forms.Label();
            this.dgwGhiceste = new System.Windows.Forms.DataGridView();
            this.dgwSarpeEducativ = new System.Windows.Forms.DataGridView();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.NumeUtilizatorGhiceste = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.EmailUtilizatorGhiceste = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.PunctajJocGhiceste = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.NumeUtilizatorSarpe = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.EmailUtilizatorSarpe = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.PunctajJocSarpe = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dgwGhiceste)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dgwSarpeEducativ)).BeginInit();
            this.SuspendLayout();
            // 
            // lbl
            // 
            this.lbl.AutoSize = true;
            this.lbl.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl.Location = new System.Drawing.Point(33, 23);
            this.lbl.Name = "lbl";
            this.lbl.Size = new System.Drawing.Size(86, 31);
            this.lbl.TabIndex = 0;
            this.lbl.Text = "label1";
            // 
            // dgwGhiceste
            // 
            this.dgwGhiceste.AllowUserToAddRows = false;
            this.dgwGhiceste.AllowUserToDeleteRows = false;
            this.dgwGhiceste.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dgwGhiceste.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgwGhiceste.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.NumeUtilizatorGhiceste,
            this.EmailUtilizatorGhiceste,
            this.PunctajJocGhiceste});
            this.dgwGhiceste.Location = new System.Drawing.Point(58, 143);
            this.dgwGhiceste.Name = "dgwGhiceste";
            this.dgwGhiceste.ReadOnly = true;
            this.dgwGhiceste.Size = new System.Drawing.Size(309, 164);
            this.dgwGhiceste.TabIndex = 1;
            // 
            // dgwSarpeEducativ
            // 
            this.dgwSarpeEducativ.AllowUserToAddRows = false;
            this.dgwSarpeEducativ.AllowUserToDeleteRows = false;
            this.dgwSarpeEducativ.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dgwSarpeEducativ.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgwSarpeEducativ.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.NumeUtilizatorSarpe,
            this.EmailUtilizatorSarpe,
            this.PunctajJocSarpe});
            this.dgwSarpeEducativ.Location = new System.Drawing.Point(458, 143);
            this.dgwSarpeEducativ.Name = "dgwSarpeEducativ";
            this.dgwSarpeEducativ.ReadOnly = true;
            this.dgwSarpeEducativ.Size = new System.Drawing.Size(309, 164);
            this.dgwSarpeEducativ.TabIndex = 2;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(122, 115);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(167, 25);
            this.label2.TabIndex = 3;
            this.label2.Text = "Top scor ghiceste";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(502, 115);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(222, 25);
            this.label3.TabIndex = 4;
            this.label3.Text = "Top scor SarpeEducativ";
            // 
            // NumeUtilizatorGhiceste
            // 
            this.NumeUtilizatorGhiceste.HeaderText = "NumeUtilizator";
            this.NumeUtilizatorGhiceste.Name = "NumeUtilizatorGhiceste";
            // 
            // EmailUtilizatorGhiceste
            // 
            this.EmailUtilizatorGhiceste.HeaderText = "EmailUtilizator";
            this.EmailUtilizatorGhiceste.Name = "EmailUtilizatorGhiceste";
            // 
            // PunctajJocGhiceste
            // 
            this.PunctajJocGhiceste.HeaderText = "PunctajJoc";
            this.PunctajJocGhiceste.Name = "PunctajJocGhiceste";
            // 
            // NumeUtilizatorSarpe
            // 
            this.NumeUtilizatorSarpe.HeaderText = "NumeUtilizator";
            this.NumeUtilizatorSarpe.Name = "NumeUtilizatorSarpe";
            // 
            // EmailUtilizatorSarpe
            // 
            this.EmailUtilizatorSarpe.HeaderText = "EmailUtilizator";
            this.EmailUtilizatorSarpe.Name = "EmailUtilizatorSarpe";
            // 
            // PunctajJocSarpe
            // 
            this.PunctajJocSarpe.HeaderText = "PunctajJoc";
            this.PunctajJocSarpe.Name = "PunctajJocSarpe";
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.Lime;
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.ForeColor = System.Drawing.Color.White;
            this.button1.Location = new System.Drawing.Point(127, 347);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(165, 76);
            this.button1.TabIndex = 5;
            this.button1.Text = "Ghiceste";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.BackColor = System.Drawing.Color.Lime;
            this.button2.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button2.ForeColor = System.Drawing.Color.White;
            this.button2.Location = new System.Drawing.Point(549, 347);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(165, 76);
            this.button2.TabIndex = 6;
            this.button2.Text = "SarpeEducativ";
            this.button2.UseVisualStyleBackColor = false;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // AlegeJoc
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Cyan;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.dgwSarpeEducativ);
            this.Controls.Add(this.dgwGhiceste);
            this.Controls.Add(this.lbl);
            this.Name = "AlegeJoc";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "AlegeJoc";
            ((System.ComponentModel.ISupportInitialize)(this.dgwGhiceste)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dgwSarpeEducativ)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lbl;
        private System.Windows.Forms.DataGridView dgwGhiceste;
        private System.Windows.Forms.DataGridViewTextBoxColumn NumeUtilizatorGhiceste;
        private System.Windows.Forms.DataGridViewTextBoxColumn EmailUtilizatorGhiceste;
        private System.Windows.Forms.DataGridViewTextBoxColumn PunctajJocGhiceste;
        private System.Windows.Forms.DataGridView dgwSarpeEducativ;
        private System.Windows.Forms.DataGridViewTextBoxColumn NumeUtilizatorSarpe;
        private System.Windows.Forms.DataGridViewTextBoxColumn EmailUtilizatorSarpe;
        private System.Windows.Forms.DataGridViewTextBoxColumn PunctajJocSarpe;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
    }
}