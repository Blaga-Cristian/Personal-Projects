namespace Good_Food
{
    partial class Start
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.btnInreg = new System.Windows.Forms.Button();
            this.btnAuten = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Comic Sans MS", 13F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(145, 37);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(540, 50);
            this.label1.TabIndex = 0;
            this.label1.Text = "Meniuri diverse caracterizate de transparentra si excelenta\r\n\r\n";
            // 
            // label2
            // 
            this.label2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(255)))));
            this.label2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label2.Location = new System.Drawing.Point(162, 110);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(475, 170);
            this.label2.TabIndex = 1;
            // 
            // label3
            // 
            this.label3.BackColor = System.Drawing.Color.Fuchsia;
            this.label3.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 40F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(197, 135);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(413, 111);
            this.label3.TabIndex = 2;
            this.label3.Text = "(GOOD FOOD)";
            this.label3.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // btnInreg
            // 
            this.btnInreg.Location = new System.Drawing.Point(150, 364);
            this.btnInreg.Name = "btnInreg";
            this.btnInreg.Size = new System.Drawing.Size(167, 39);
            this.btnInreg.TabIndex = 3;
            this.btnInreg.Text = "Inregistrare";
            this.btnInreg.UseVisualStyleBackColor = true;
            this.btnInreg.Click += new System.EventHandler(this.btnInreg_Click);
            // 
            // btnAuten
            // 
            this.btnAuten.Location = new System.Drawing.Point(518, 364);
            this.btnAuten.Name = "btnAuten";
            this.btnAuten.Size = new System.Drawing.Size(167, 39);
            this.btnAuten.TabIndex = 4;
            this.btnAuten.Text = "Autentificare";
            this.btnAuten.UseVisualStyleBackColor = true;
            this.btnAuten.Click += new System.EventHandler(this.btnAuten_Click);
            // 
            // Start
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnAuten);
            this.Controls.Add(this.btnInreg);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Start";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Start";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button btnInreg;
        private System.Windows.Forms.Button btnAuten;
    }
}

