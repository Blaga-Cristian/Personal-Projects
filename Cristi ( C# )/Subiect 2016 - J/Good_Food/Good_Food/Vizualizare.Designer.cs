namespace Good_Food
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
            this.dgw = new System.Windows.Forms.DataGridView();
            this.label1 = new System.Windows.Forms.Label();
            this.txtKcalz = new System.Windows.Forms.TextBox();
            this.txtKcal = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.txtPret = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dgw)).BeginInit();
            this.SuspendLayout();
            // 
            // dgw
            // 
            this.dgw.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgw.Location = new System.Drawing.Point(-2, -1);
            this.dgw.Name = "dgw";
            this.dgw.Size = new System.Drawing.Size(802, 284);
            this.dgw.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(39, 316);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(59, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "kcal zilnice";
            // 
            // txtKcalz
            // 
            this.txtKcalz.Location = new System.Drawing.Point(97, 309);
            this.txtKcalz.Name = "txtKcalz";
            this.txtKcalz.Size = new System.Drawing.Size(140, 20);
            this.txtKcalz.TabIndex = 3;
            // 
            // txtKcal
            // 
            this.txtKcal.Location = new System.Drawing.Point(97, 344);
            this.txtKcal.Name = "txtKcal";
            this.txtKcal.Size = new System.Drawing.Size(140, 20);
            this.txtKcal.TabIndex = 5;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(39, 351);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(50, 13);
            this.label2.TabIndex = 4;
            this.label2.Text = "total kcal";
            // 
            // txtPret
            // 
            this.txtPret.Location = new System.Drawing.Point(97, 386);
            this.txtPret.Name = "txtPret";
            this.txtPret.Size = new System.Drawing.Size(140, 20);
            this.txtPret.TabIndex = 7;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(39, 393);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(48, 13);
            this.label3.TabIndex = 6;
            this.label3.Text = "total pret";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(304, 393);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(92, 31);
            this.button1.TabIndex = 8;
            this.button1.Text = "Finalizeaza";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Vizualizare
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.txtPret);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.txtKcal);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.txtKcalz);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.dgw);
            this.Name = "Vizualizare";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Vizualizare";
            ((System.ComponentModel.ISupportInitialize)(this.dgw)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dgw;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txtKcalz;
        private System.Windows.Forms.TextBox txtKcal;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txtPret;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button button1;
    }
}