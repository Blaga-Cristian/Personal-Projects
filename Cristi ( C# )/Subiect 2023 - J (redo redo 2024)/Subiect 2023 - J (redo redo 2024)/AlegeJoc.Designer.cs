namespace Subiect_2023___J__redo_redo_2024_
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
            this.dgwGhiceste = new System.Windows.Forms.DataGridView();
            this.dgwSarpeEducativ = new System.Windows.Forms.DataGridView();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.lbl = new System.Windows.Forms.Label();
            this.btnGhiceste = new System.Windows.Forms.Button();
            this.btnSarpeEducativ = new System.Windows.Forms.Button();
            this.NumeUtilizator = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Emai = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Punctaj = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            ((System.ComponentModel.ISupportInitialize)(this.dgwGhiceste)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dgwSarpeEducativ)).BeginInit();
            this.SuspendLayout();
            // 
            // dgwGhiceste
            // 
            this.dgwGhiceste.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dgwGhiceste.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgwGhiceste.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.NumeUtilizator,
            this.Emai,
            this.Punctaj});
            this.dgwGhiceste.Location = new System.Drawing.Point(12, 102);
            this.dgwGhiceste.Name = "dgwGhiceste";
            this.dgwGhiceste.RowHeadersWidth = 51;
            this.dgwGhiceste.Size = new System.Drawing.Size(484, 243);
            this.dgwGhiceste.TabIndex = 0;
            // 
            // dgwSarpeEducativ
            // 
            this.dgwSarpeEducativ.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dgwSarpeEducativ.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgwSarpeEducativ.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Column1,
            this.Column2,
            this.Column3});
            this.dgwSarpeEducativ.Location = new System.Drawing.Point(576, 102);
            this.dgwSarpeEducativ.Name = "dgwSarpeEducativ";
            this.dgwSarpeEducativ.RowHeadersWidth = 51;
            this.dgwSarpeEducativ.Size = new System.Drawing.Size(542, 243);
            this.dgwSarpeEducativ.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label1.Location = new System.Drawing.Point(56, 66);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(251, 36);
            this.label1.TabIndex = 2;
            this.label1.Text = "Top scor ghiceste";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label2.Location = new System.Drawing.Point(659, 66);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(342, 36);
            this.label2.TabIndex = 3;
            this.label2.Text = "Top scor Sarpe Educativ";
            // 
            // lbl
            // 
            this.lbl.AutoSize = true;
            this.lbl.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.lbl.Location = new System.Drawing.Point(20, 9);
            this.lbl.Name = "lbl";
            this.lbl.Size = new System.Drawing.Size(101, 36);
            this.lbl.TabIndex = 4;
            this.lbl.Text = "label3";
            // 
            // btnGhiceste
            // 
            this.btnGhiceste.BackColor = System.Drawing.Color.Lime;
            this.btnGhiceste.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.btnGhiceste.ForeColor = System.Drawing.Color.White;
            this.btnGhiceste.Location = new System.Drawing.Point(62, 383);
            this.btnGhiceste.Name = "btnGhiceste";
            this.btnGhiceste.Size = new System.Drawing.Size(319, 55);
            this.btnGhiceste.TabIndex = 5;
            this.btnGhiceste.Text = "Ghiceste";
            this.btnGhiceste.UseVisualStyleBackColor = false;
            this.btnGhiceste.Click += new System.EventHandler(this.btnGhiceste_Click);
            // 
            // btnSarpeEducativ
            // 
            this.btnSarpeEducativ.BackColor = System.Drawing.Color.Lime;
            this.btnSarpeEducativ.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.btnSarpeEducativ.ForeColor = System.Drawing.Color.White;
            this.btnSarpeEducativ.Location = new System.Drawing.Point(682, 383);
            this.btnSarpeEducativ.Name = "btnSarpeEducativ";
            this.btnSarpeEducativ.Size = new System.Drawing.Size(319, 55);
            this.btnSarpeEducativ.TabIndex = 6;
            this.btnSarpeEducativ.Text = "Sarpe Educativ";
            this.btnSarpeEducativ.UseVisualStyleBackColor = false;
            this.btnSarpeEducativ.Click += new System.EventHandler(this.btnSarpeEducativ_Click);
            // 
            // NumeUtilizator
            // 
            this.NumeUtilizator.HeaderText = "Nume Utilizator";
            this.NumeUtilizator.MinimumWidth = 6;
            this.NumeUtilizator.Name = "NumeUtilizator";
            // 
            // Emai
            // 
            this.Emai.HeaderText = "Email Utilizator";
            this.Emai.MinimumWidth = 6;
            this.Emai.Name = "Emai";
            // 
            // Punctaj
            // 
            this.Punctaj.HeaderText = "Punctaj Joc";
            this.Punctaj.MinimumWidth = 6;
            this.Punctaj.Name = "Punctaj";
            // 
            // Column1
            // 
            this.Column1.HeaderText = "NumeUtilizator";
            this.Column1.MinimumWidth = 6;
            this.Column1.Name = "Column1";
            // 
            // Column2
            // 
            this.Column2.HeaderText = "EmailUtilizator";
            this.Column2.MinimumWidth = 6;
            this.Column2.Name = "Column2";
            // 
            // Column3
            // 
            this.Column3.HeaderText = "PunctajJoc";
            this.Column3.MinimumWidth = 6;
            this.Column3.Name = "Column3";
            // 
            // AlegeJoc
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Cyan;
            this.ClientSize = new System.Drawing.Size(1130, 524);
            this.Controls.Add(this.btnSarpeEducativ);
            this.Controls.Add(this.btnGhiceste);
            this.Controls.Add(this.lbl);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.dgwSarpeEducativ);
            this.Controls.Add(this.dgwGhiceste);
            this.Name = "AlegeJoc";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "AlegeJoc";
            ((System.ComponentModel.ISupportInitialize)(this.dgwGhiceste)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dgwSarpeEducativ)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dgwGhiceste;
        private System.Windows.Forms.DataGridView dgwSarpeEducativ;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label lbl;
        private System.Windows.Forms.Button btnGhiceste;
        private System.Windows.Forms.Button btnSarpeEducativ;
        private System.Windows.Forms.DataGridViewTextBoxColumn NumeUtilizator;
        private System.Windows.Forms.DataGridViewTextBoxColumn Emai;
        private System.Windows.Forms.DataGridViewTextBoxColumn Punctaj;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column1;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column2;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column3;
    }
}