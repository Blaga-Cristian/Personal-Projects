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
            this.lblEmail = new System.Windows.Forms.Label();
            this.dgw1 = new System.Windows.Forms.DataGridView();
            this.dgw2 = new System.Windows.Forms.DataGridView();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.btnGhiceste = new System.Windows.Forms.Button();
            this.btnSarpeEducativ = new System.Windows.Forms.Button();
            this.btnClose = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dgw1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dgw2)).BeginInit();
            this.SuspendLayout();
            // 
            // lblEmail
            // 
            this.lblEmail.AutoSize = true;
            this.lblEmail.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblEmail.Location = new System.Drawing.Point(40, 22);
            this.lblEmail.Name = "lblEmail";
            this.lblEmail.Size = new System.Drawing.Size(86, 31);
            this.lblEmail.TabIndex = 0;
            this.lblEmail.Text = "label1";
            // 
            // dgw1
            // 
            this.dgw1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgw1.Location = new System.Drawing.Point(33, 121);
            this.dgw1.Name = "dgw1";
            this.dgw1.Size = new System.Drawing.Size(317, 150);
            this.dgw1.TabIndex = 1;
            // 
            // dgw2
            // 
            this.dgw2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgw2.Location = new System.Drawing.Point(461, 121);
            this.dgw2.Name = "dgw2";
            this.dgw2.Size = new System.Drawing.Size(317, 150);
            this.dgw2.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(124, 82);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(124, 17);
            this.label1.TabIndex = 3;
            this.label1.Text = "Top scor Ghiceste";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(535, 82);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(175, 17);
            this.label2.TabIndex = 4;
            this.label2.Text = "Top scor Sarpele Educativ";
            // 
            // btnGhiceste
            // 
            this.btnGhiceste.BackColor = System.Drawing.Color.Lime;
            this.btnGhiceste.Location = new System.Drawing.Point(144, 318);
            this.btnGhiceste.Name = "btnGhiceste";
            this.btnGhiceste.Size = new System.Drawing.Size(104, 40);
            this.btnGhiceste.TabIndex = 5;
            this.btnGhiceste.Text = "Ghiceste";
            this.btnGhiceste.UseVisualStyleBackColor = false;
            this.btnGhiceste.Click += new System.EventHandler(this.btnGhiceste_Click);
            // 
            // btnSarpeEducativ
            // 
            this.btnSarpeEducativ.BackColor = System.Drawing.Color.Lime;
            this.btnSarpeEducativ.Location = new System.Drawing.Point(561, 318);
            this.btnSarpeEducativ.Name = "btnSarpeEducativ";
            this.btnSarpeEducativ.Size = new System.Drawing.Size(104, 40);
            this.btnSarpeEducativ.TabIndex = 6;
            this.btnSarpeEducativ.Text = "SarpeEducativ";
            this.btnSarpeEducativ.UseVisualStyleBackColor = false;
            this.btnSarpeEducativ.Click += new System.EventHandler(this.btnSarpeEducativ_Click);
            // 
            // btnClose
            // 
            this.btnClose.BackColor = System.Drawing.Color.Lime;
            this.btnClose.Location = new System.Drawing.Point(671, 18);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(107, 35);
            this.btnClose.TabIndex = 7;
            this.btnClose.Text = "Inchidere Aplicatie";
            this.btnClose.UseVisualStyleBackColor = false;
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // AlegeJoc
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Aqua;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnClose);
            this.Controls.Add(this.btnSarpeEducativ);
            this.Controls.Add(this.btnGhiceste);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.dgw2);
            this.Controls.Add(this.dgw1);
            this.Controls.Add(this.lblEmail);
            this.Name = "AlegeJoc";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "AlegeJoc";
            ((System.ComponentModel.ISupportInitialize)(this.dgw1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dgw2)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblEmail;
        private System.Windows.Forms.DataGridView dgw1;
        private System.Windows.Forms.DataGridView dgw2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button btnGhiceste;
        private System.Windows.Forms.Button btnSarpeEducativ;
        private System.Windows.Forms.Button btnClose;
    }
}